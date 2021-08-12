#include <iostream>
#include <string>
#include <thread>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/view.h>
#include <geometry_msgs/Pose.h>


#include <boost/filesystem.hpp>
#include "parameters_json.h"
#include <sensor_msgs/Imu.h>

int main(int argc, char ** argv) {
    std::cout<<"IMU to TXT"<<std::endl;
    Params params;

    std::string curr_path = boost::filesystem::current_path().parent_path().string();

    if(!params.read_data(curr_path + "/parameters/parameters.json")) {
        std::cout<<"Failed to open parameters"<<std::endl;
        return 1;
    }


    std::string bag_path = params.IOParam.input_bag;
    std::string gps_topic = "/gx5/filtered/imu/data";
    std::string output_dir = params.IOParam.output_dir;

    boost::filesystem::path outpath(output_dir);
    if (!boost::filesystem::exists(outpath))
    {
        if (!boost::filesystem::create_directories(outpath))
        {
            std::cerr << "Error creating directory " << output_dir << std::endl;
            return (-1);
        }
        std::cerr << "Creating directory " << output_dir << std::endl;
    }

    rosbag::Bag rb;
    rosbag::View view;
    rosbag::View::iterator view_it;

    try{
        std::cout<<"Opening Bag"<<std::endl;
        rb.open(bag_path, rosbag::bagmode::Read);
        std::cout<<"Bag Opened"<<std::endl;
    } catch(const rosbag::BagException&) {
        std::cout<<"Error Opening File "<<bag_path<<std::endl;
        return -1;
    }

    std::string output_file = output_dir + "/imu.txt";
    std::ofstream write_file(output_file.c_str());

    view.addQuery(rb, rosbag::TopicQuery(gps_topic));
    view_it = view.begin();

    double initial_time = view.getBeginTime().toSec();
    double final_time = view.getEndTime().toSec();

    while(view_it != view.end()) {
        sensor_msgs::Imu::ConstPtr imu_ptr = view_it->instantiate<sensor_msgs::Imu>();
        if(imu_ptr==NULL) {
            ++view_it;
            continue;
        }

        sensor_msgs::Imu imu_msg = *imu_ptr;
        double time = imu_msg.header.stamp.toSec();

        double percent = (time - initial_time)/(final_time-initial_time)*100.0f;
        char c_percent[256];
        sprintf(c_percent, "%.2f", percent);
        std::cout<<c_percent<<"% Done"<<std::endl;
        char c_time[256];
        sprintf(c_time, "%.9f", time);
        std::string s_time = std::string(c_time);

        write_file << s_time;

        ++view_it;
    }
    write_file.close();
    return 0;
}