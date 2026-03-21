#include<iostream>

int main(){
    int player_count = 5;
    double accuracy = 0.95; // 95%
    float speed = 1.12; // 112%

    std::cout << "There are " << player_count << " players having an accuracy of ";
    std::cout << accuracy << " running at " << (speed*100) << std::endl;

    return 0;
}