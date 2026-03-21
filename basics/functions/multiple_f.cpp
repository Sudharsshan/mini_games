#include<iostream>

int password = 9999;

bool isPasswordCorrect(int input);
std::string result(int input);

int main(){
    // This code contains multiple functions to help understand the funciton call and parameter syntax

    int userInput;

    while(true){
        std::cout << "Please enter the password ";
        std::cin >> userInput;
        
        // check if password is correct or not and alert the user
        std::cout << result(userInput) << std::endl;

        // next either terminate or continue program based on user input
        if(isPasswordCorrect(userInput)) break;
    }

    return 0;
}

bool isPasswordCorrect(int input){
    return input == password;
}

std::string result(int input){
    std::string outcome;
    if(isPasswordCorrect(input)) outcome = "Correct pasword";
    else outcome = "Incorrect Password";

    return outcome;
}