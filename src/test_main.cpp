#include <print_container/print_container.h>
#include <ros/ros.h>

struct Foo{
    friend std::ostream& operator<<(std::ostream& os, Foo& f){
        os << "i'm foo!!! ";
        return os;
    }
};

int main(int argc, char *argv[]){
    ros::init(argc, argv, "test_main");
    ros::NodeHandle nh;

    
    std::vector<int> intVec{1,2,3,4,5,6,7,10};
    std::vector<double> doubleVec{3.3, 2,1, 5.6};
    std::vector<std::string> strVec{"I", "Love", "VisionLab"};    
    std::vector<Foo> fooVec{Foo(), Foo()};
    int ary[] = {5,1,2,3,6,2,3};

    ROS_INFO_CONTAINER(intVec.begin(), intVec.end());
    ROS_INFO_CONTAINER("doublevec", doubleVec.begin(), doubleVec.end());
    ROS_INFO_CONTAINER(strVec.begin(), strVec.end());
    ROS_INFO_CONTAINER("foovec", fooVec.begin(), fooVec.end());
    ROS_INFO_CONTAINER("intary", ary, ary+7);
    ROS_INFO_DATA(3, 5.0, "hmm", "I want you!");

    for(int i = 0 ; i < 10; ++i){
        ROS_INFO("----------------------------------");
        for(auto& intVal : ary)
            ROS_INFO("%d", intVal);
    }
}