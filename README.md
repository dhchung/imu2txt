## ROSBag IMU data to txt

Todo : Change /parameters/parameters.json (rosbag file and output folder)
- You might need to install jsoncpp
    - sudo apt install libjsoncpp-dev


Data Format (Tab Delimited)

1. Timestamp [s] with 9 decimal points
2. orientation x [m] with 16 decimal points
3. orientation y [m] with 16 decimal points
4. orientation z [m] with 16 decimal points
5. orientation w [m] with 16 decimal points

6~14. orientation covariance (9 tuple vector) with 16 decimal points

15.  angular velocity x [rad/s] with 16 decimal points
16.  angular velocity y [rad/s] with 16 decimal points
17.  angular velocity z [rad/s] with 16 decimal points

18~26. angular velocity covariance (9 tuple vector) with 2 decimal points

27.  linear acceleration x [m/s^2] with 16 decimal points
28.  linear acceleration y [m/s^2] with 16 decimal points
29.  linear acceleration z [m/s^2] with 16 decimal points

30~38. linear acceleration covariance (9 tuple vector) with 2 decimal points
