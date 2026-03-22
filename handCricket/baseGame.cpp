#include<iostream>
#include<random> // for generating random numbers for bot

// define functions
int botHand(); // provides CPU's play
int humanHand(); // provides player's play

// CPU and Player both are limited to 10 runs from 1, so that's the limit used for random generator using MT (Mersenne Twister one)
int minRun = 1, maxRun = 10;

int botHand(){
    // obtain device seed first
    static std::random_device randomDevice;

    // use the seed to prepare a MT generator
    static std::mt19937 gen(randomDevice());

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
    bool gameOver = false; // for formality purposes

    // now how to flip a coin?
    // we don't, let player bat first

    int playerScore = 0, CPUscore = 0, playerRun, CPURun;

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
    std::cout << "3. If the entered number matches, it's an OUT. Who ever scores higher, wins." << std::endl;
    std::cout << "4. No more rules, enjoy the game, since rest all are known already : )" << std::endl;

    std::string playerTurn;

    /* 
        while taking turns, the usually the CPU makes a guess first, 
        and then the player shall provide their guess
    */
    while(true){
        if(batting){
            playerTurn = "batting";
        } else {
            playerTurn = "bowling";
        }

        std::cout << "====================================================================" << std::endl;
        
        // Let the CPU guess it's run first
        CPURun = botHand();

        std::cout << "Now it's your turn for " << playerTurn << std::endl;

        // ask the player for their run
        std::cout << "Enter your run: ";
        std::cin >> playerRun;

        // ensure player enters a number between 1 to 10 only. NO CHEATING...
        if(playerRun < 1 || playerRun > 10){
            std::cout << "You have entered a number beyond the limits! Please enter between 1-10 only." << std::endl;
            playerRun = 0; // neutralize the false run entered by player.
            continue;
        }

        std::cout << std::endl;

        std::cout << "CPU's guessed run is: " << CPURun << std::endl;

        // check if CPU and player runs match, if so end the game with current score.
        if(playerRun == CPURun && batting){
                // player's batting time's over
                std::cout << "Oops! You are out. Now it's your turn to bowl." << std::endl;
                std::cout << "Your final score is: " << playerScore << std::endl;
                batting = !batting; // change from player batting to CPU batting
        } else if ((CPUscore > playerScore && !batting) || playerRun == CPURun){
                // Now that both player and CPU batting is done, the game ends
                std::cout << "Game Over." << std::endl;

                std::string whoWon = (playerScore>CPUscore)? "you have defeated the CPU" : "the CPU has deafeated you";
                std::cout << "Oops! Looks like " << whoWon << "." << std::endl;

                std::cout << "This was a good game! If you enjoyed playing, it means a lot!" << std::endl;
                std::cout << "Thank you for playing this game." << std::endl;

                // Take the player to credits scene and end the game.
                gameOver = true;
        }

        // add the scores
        if(!batting) CPUscore += CPURun; // add the CPU score only when it is playing the batting role
        else playerScore += playerRun; // add the player score only when they're playing the batting role

        // show them to the player
        std::cout << "Player runs: " << playerScore << " || CPU runs: " << CPUscore << std::endl;

        if(gameOver) break; // end the game if the turns are over.
    }

    std::cout << "====================================================================" << std::endl;
    std::cout << "Developed by: S. Y. Sudharsshan" << std::endl;
    std::cout << "====================================================================" << std::endl;

    return 0;
}