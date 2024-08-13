#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <vector>

std::string words[] = {
    "keyboard",
    "laptop",
    "motorcycle",
    "window",
    "cupboard"
};

std::string selectingWord() {
    int wordsLength = sizeof(words) / sizeof(words[0]);

    std::srand(std::time(0));
    int wordIndex = std::rand() % wordsLength;

    return words[wordIndex];
}

std::string convertToLowercase(const std::string &str) {
    std::string result = {};
    
    for (char ch : str) {
        result += tolower(ch);
    }

    return result;
}

int main() {
    int chance = 5;
    std::string word = selectingWord();

    // result vector with underscore "_"
    std::vector<std::string> result;
    for (int i = 0; i < word.length(); i++) {
        result.push_back("_");
    }

    std::string userInput {};
    std::string message = "";

    // main loop
    while (userInput != "exit")
    {
        system("cls");  // clear screen

        bool isWin = true;

        // Iterating result
        std::vector<std::string>::iterator resultIter = result.begin();
        std::cout << "result : ";
        for (resultIter; resultIter < result.end(); resultIter++) {
            std::cout << *resultIter << " ";
            if (*resultIter == "_") {
                isWin = false;
            }
        }
        std::cout << std::endl;

        std::cout << "Chance : " << chance << std::endl;

        if (message != "") {
            std::cout << message << std::endl;
            message = "";
        }

        if (isWin) {
            std::cout << std::endl;  // extra line
            std::cout << "*** Congratulations, You win. ***" << std::endl;
            break;
        }

        std::cout << "Please enter one character (type 'exit' if you want to exit) : ";
        std::cin >> userInput;

        std::cout << std::endl; // extra line

        
        // input validation
        int userInputLength = userInput.length();
        if (userInput == "exit") {
            std::cout << "Well Played. Thank you and goodbye." << std::endl;
            break;
        }
        if (userInputLength > 1) {
            message = "Invalid Input. Please enter one character";
            continue;
        }

        userInput = convertToLowercase(userInput);

        // check if input is found
        bool isFound = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == userInput[0]) {
                isFound = true;
                result[i] = userInput[0];
            }
        }

        if (!isFound) {
            chance--;
            message = "Wrong guess.";
        }
        if (chance == 0) {
            std::cout << "*** You Lose! ***";
            break;
        }   
    }

    return 0;
}

