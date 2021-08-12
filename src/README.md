## ROSBag IMU data to txt

Todo : Change /parameters/parameters.json (rosbag file and output folder)
- You might need to install jsoncpp
    - sudo apt install libjsoncpp-dev


Data Format (Tab Delimited)

1. Timestamp [s] with 9 decimal points
2. orientation [x] with 16 decimal points
3. orientation [y] with 16 decimal points
4. orientation [z] with 16 decimal points
5. orientation [w] with 16 decimal points
6~14. orientation covariance (9 tuple vector) with 16 decimal points
15. angular velocity [x] with 16 decimal points
16. angular velocity [y] with 16 decimal points
17. angular velocity [z] with 16 decimal points
18~26. angular velocity covariance (9 tuple vector) with 2 decimal points
27. linear velocity [x] with 16 decimal points
28. linear velocity [y] with 16 decimal points
29. linear velocity [z] with 16 decimal points
30~38. linear velocity covariance (9 tuple vector) with 2 decimal points
