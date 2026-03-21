#include<iostream>

int main(){
    int password = 18456;
    int input;
    while(true){
        std::cout << "Please enter your password: ";
        std::cin >> input;
        std::cout << std::endl;
        if(input == password) break;
        else std::cout << "Incorrect password, Please enter again" << std::endl;
    }
    std::cout << "Congrats you've entered the correct password" << std::endl;
    return 0;
}