#include <iostream>
#include <sstream>
#include <ros/ros.h>

template <class InputIt>
void ROS_INFO_CONTAINER(InputIt first, InputIt last){
    std::stringstream ss;
    for(; first != last; ++first)
        ss << *first << ' ';
    ROS_INFO("%s", ss.str().c_str());
}

template <class InputIt>
void ROS_INFO_CONTAINER(std::string name, InputIt first, InputIt last){
    std::stringstream ss;
    for(; first != last; ++first)
        ss << *first;
    ROS_INFO("%s : %s", name.c_str(), ss.str().c_str());
}