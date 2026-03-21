#include<iostream>
#include<random>

// declare the function
int randomGen(int a, int b);

int main(){
    // this is a cpp program to generate a random number between the user entered two numbers.
    int a, b;

    std::cout << "Please enter two numbers: ";
    std::cin >> a;
    std::cin >> b;

    // obtain the random number and display it to screen to user

    std::cout << "Random number between " << a << " and " << b << " is: " << randomGen(a, b) << "." << std::endl;

    return 0;
}

int randomGen(int a, int b){
    // obtain a seed from the device that is random?
    std::random_device rd;

    // initialize a generator to use this created seed
    std::mt19937 gen(rd()); // using Mersenne Twister thing idk what...

    // now define the range of the random numbers
    std::uniform_int_distribution<int> distr(a, b);

    // return the randomly generated number within the user specified limits
    return distr(gen);
}