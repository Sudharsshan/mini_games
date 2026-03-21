#include<iostream>
#include<random> // for generating random numbers for bot

// define functions
int botHand(); // provides CPU's play
int humanHand(); // provides player's play

// CPU and Player both are limited to 10 runs from 1, so that's the limit used for random generator using MT (Mersenne Twister one)
int minRun = 1, maxRun = 10;

int botHand(){
    // obtain device seed first
    std::random_device randomDevice;

    // use the seed to prepare a MT generator
    std::mt19937 gen(randomDevice());

    // now define the limits
    std::uniform_int_distribution<int> distribute(minRun, maxRun);

    // now return the generated random runs played by CPU between 1 and 10
    return distribute(gen);
}

int humanHand(){
    int humanPlay;
    std::cin >> humanPlay;

    return humanPlay;
}

int main(){
    bool batting = true; // defaulted, wil change laterOn.

    // now how to flip a coin?
    // we don't, let player bat first

    int playerScore = 0, CPUscore = 0;

    std::cout << "====================================================================" << std::endl;
    std::cout << "Hello dear player! Please enter your name to begin the game: ";
    std::string playerName;
    std::cin >> playerName;
    std::cout << std::endl; // give a line break for better readibility.

    std::cout << "====================================================================" << std::endl;
    std::cout << "Hey " << playerName << ", welcome to the Hand Cricket game!" << std::endl;
    std::cout << std::endl;
    std::cout << "The rules of the game is simple:" << std::endl;
    std::cout << "1. Player shall play batting first." << std::endl;
    std::cout << "2. Both CPU and player shall enter runs from 1 to 10 ONLY." << std::endl;
    std::cout << "3. No more rules, enjoy the game, since rest all are known already : )" << std::endl;

    while(true){
        std::cout << "";
    }
}