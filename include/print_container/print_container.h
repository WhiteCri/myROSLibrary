#include <iostream>
#include <sstream>
#include <ros/ros.h>

static std::stringstream ss;

template <class T>
inline std::string mergeDataToString(T t){
    ss << t;
    std::string str = ss.str();
    ss.str("");
    return str;
}

template <class T, class ...Types>
inline std::string mergeDataToString(T t, Types ... args){
    ss << t << ' '; 
    return mergeDataToString(args...);
}

template <class ... Types>
void ROS_INFO_DATA(Types ...args){
    ROS_INFO("%s", mergeDataToString(args...).c_str());
}

template <class InputIt>
inline std::string mergeContainerToString(InputIt first, InputIt last){
    std::stringstream ss;
    for(; first != last; ++first)
        ss << *first << ' ';
    return ss.str();
}

template <class InputIt>
inline void ROS_INFO_CONTAINER(InputIt first, InputIt last){
    ROS_INFO("%s", mergeContainerToString(first, last).c_str());
}

template <class InputIt>
void ROS_INFO_CONTAINER(std::string name, InputIt first, InputIt last){
    ROS_INFO("%s : %s", name.c_str(), mergeContainerToString(first, last).c_str());
}