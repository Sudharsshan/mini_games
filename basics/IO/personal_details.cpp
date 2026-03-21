#include<stdio.h>
#include <iostream>
#include <string>

int main(){
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Your name is: " << name << std::endl;

    std::cout << "Please enter your age: ";
    int age;
    std::cin >> age;
    std::cout << "You are " << age << " years old." << std::endl;
    return 0;
}