#pragma once

#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <math.h>

struct IOParameters{
    std::string input_bag = "";
    std::string output_dir = "";

    void PrintStuff(){
        std::cout<<"Thermal Parmeters"<<std::endl;
        std::cout<<"input_bag: "<<input_bag<<std::endl;
        std::cout<<"output_dir: "<<output_dir<<std::endl;
    }

};

class Params{
public:
    Params();
    ~Params();
    bool read_data(std::string json_dir);

    IOParameters IOParam;
};