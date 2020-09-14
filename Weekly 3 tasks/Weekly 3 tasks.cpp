//Written by Mathias Fredriksen
#include <iostream>
#include <vector>
#include <time.h> 



int difficulty{ 0 };
std::vector<int> highscore = { 999,999,999,999,999 };


void Task1()
{
    //Difficulty
    int highestNumber;

    switch (difficulty)
    {
    case 1:
        highestNumber = 10;
        break;

    case 2:
        highestNumber = 50;
        break;

    case 3:
        highestNumber = 100;
        break;

    default:
        highestNumber = 10;
        break;
    }

    srand(time(0));


    int randomNumber{ 0 };
    int playersNumber{ 0 };
    int guessCounter{ 0 };

    randomNumber = rand() % highestNumber + 1;

    //Game loop. The player will have to guess continuously till they find the random number 
    do
    {
        std::cout << "Guess the random number between (1 and " << highestNumber << "): ";
        std::cin >> playersNumber;

        while (std::cin.fail() || playersNumber > highestNumber || playersNumber <= 0)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

            std::cout << "That's not a valid number\n";
            std::cout << "Guess the random number (between 1 and " << highestNumber << "): ";
            std::cin >> playersNumber;
        }

        std::cout << "\n";

        if (playersNumber < randomNumber)
        {
            guessCounter++;
            std::cout << "Your number is too low!\n";
        }
        else if (playersNumber > randomNumber)
        {
            guessCounter++;
            std::cout << "Your number is too high!\n";
        }

    } while (playersNumber != randomNumber);

    system("cls");
    guessCounter++;
    std::cout << "Well done! You found the random number '" << randomNumber << "'!\nWith only '" << guessCounter << "' attempts!\n\n";

    //Highscore
    bool scorePosFound{false}; //Used to stop the players score form being implemented multiple times
    char scoreSymbol{ '-' };
    int playerScorePlacement;
    std::cout << "HIGHSCORE:\n";
    for (int i = 0; i < 5; i++)
    {
        if(highscore[i] > guessCounter && scorePosFound == false)
        {
            highscore.insert(highscore.begin()+i, guessCounter);
            scoreSymbol = '=';
            playerScorePlacement = i+1;
            scorePosFound = true;
        }

        if(highscore[i] != 999) // The program counts 999 as being an empty space.
        {
            std::cout << i + 1 << ". " << scoreSymbol << highscore[i] << scoreSymbol << std::endl;
        }
        else
        {
            std::cout << i + 1 << ". " << scoreSymbol << " " << scoreSymbol << std::endl;
        }
        
        scoreSymbol = '-';
    }
    if(scorePosFound)
    {
        std::cout << "\nYou came on " << playerScorePlacement << ". place!\n";
    }

    scorePosFound = false;
    
    //Restart
    std::string input;
    std::cout << "\nType 'R' to retry or '0' to choose a different task: ";
    std::cin >> input;

    while (std::cin.fail() || input != "R" && input != "r" && input != "0")
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

        std::cout << "\nType 'R' to retry or '0' to choose a different task: ";
        std::cin >> input;
    }
    
    if (input == "R" || input == "r")
    {
        system("cls");
        Task1();
    }
}

int main()
{
    std::cout << "Welcome to the Number Guesser!\n\n";
    std::cout << "Difficulty:\n1. Easy (1-10)\n2. Normal (1-50)\n3. Hard (1-100)\n\n";

    std::cout << "Type which difficulty you'd like to play on: ";
    std::cin >> difficulty;

    while (std::cin.fail() || difficulty <= 0 || difficulty > 3)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

        std::cout << "Type which difficulty you'd like to play on: ";;
        std::cin >> difficulty;
    }
    system("cls");
    Task1();
}