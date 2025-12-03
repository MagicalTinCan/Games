#include <iostream>
#include <cstdlib>
#include "data.h"
#include "files.h"
#include "item.h"

#include "sokoban.cpp"

/*

This file was made entirely by Samuel Campbell

*/

void clear() { //C++ throws a hissy fit if this is put in data.h, but doesn't if its here. Barbaric.
    std::cout << "Test" << std::endl; //clear removes all lines except for the very last one, dunno why.
    files Files;
    std::string clearCommand = Files.batchClear;
    system(clearCommand.c_str());
}

struct game {
    data Data;
    files Files;
    item items[1] = {{"Apple", 3, 4}};
    // item name : string, buy value : float, sell value : float.
    
    std::string username;
    std::string password;
    std::string accountDataFile;
    // used for data-saving purposes, disregard if your name isn't Samuel.

    void streets() {
        int minigamesPlayed = 0;
        int minigamesNecessaryToEarn = 3;
        std::string lookPrompts[3] = {"You take shallow breaths, the air smells horrid.", "You hear cars passing by, wonder if they'll let you hitchhike to Mnt. Sorrori", "You stand next to a gas station with a cup out in hand"};
        std::string action;
        do {
            clear();
            std::string chosenPrompt = lookPrompts[rand() % (sizeof(lookPrompts) / sizeof(lookPrompts[0]))];
            std::cout << chosenPrompt << std::endl;
            std::cout << "\t1) Beg for money" << std::endl;
            std::cout << "\t           (" << minigamesPlayed << "/" << minigamesNecessaryToEarn << ")" << std::endl;
            std::cout << "\t2) Leave" << std::endl;
            if (chosenPrompt == lookPrompts[1]) {
                std::cout << "\t3) Scream at the cars passing by" << std::endl;
            }
            std::cout << ":";
            std::cin >> action;
            if (action == "1") {
                // PLAY GAMES HERE
                int chosenGame = std::rand() % 1;
                bool wonGame;
                if (chosenGame == 0) {
                    sokobanGame sokoban;
                    wonGame = sokoban.playGame();
                }
                if (wonGame) {
                    wonGame = false;
                    minigamesPlayed += 1;
                    if (minigamesPlayed == minigamesNecessaryToEarn) {
                        minigamesPlayed = 0;
                        double moneyEarned = (std::rand() % 80)/10 + 3; //3.0 to 10.0 dollars
                        std::string moneyPrompt[1][2] = {{"A man walks by you and throws a crumpled lump of paper and coins at your feet\nYou pick it up and it adds up to ","$."}};
                        int chosenMoneyPrompt = rand() % (sizeof(moneyPrompt) / sizeof(moneyPrompt[0]));
                        std::cout << moneyPrompt[chosenMoneyPrompt][0] << moneyEarned << moneyPrompt[chosenMoneyPrompt][1] << std::endl;
                        Data.money += moneyEarned;
                        std::cin.get();
                    }
                }
            } else if (action == "3" && chosenPrompt == lookPrompts[1]) {
                clear();
                std::cout << "You scream at the top of your lungs at a particularly reddish looking carrivan, they started laughing at you as they peeled off, weirdo." << std::endl;
                std::cout << "...";
                std::cin.get();
                std::cout << "But you know deep down... they were in pure terror at the sights of the likes of you."; // Delusional ending, achieved!
                std::cout << "...";
                std::cin.get();
            }
        } while (action != "2");
    }

    void market() {
        std::string lookPrompts[3] = {"You look around, you see many people shuffling around. The market must be hot today...", "You look up, the sun beaming down on your face is scaulding.", "You overhear a conversation between two disgruntled people, you ought to get moving..."};
        std::string action = "-1";
        do {
            std::cout << lookPrompts[rand() % (sizeof(lookPrompts) / sizeof(lookPrompts[0]))] << std::endl; //randomizes each go
            std::cout << "\t1) Buy some stuff" << std::endl;
            std::cout << "\t2) Sell some stuff" << std::endl;
            std::cout << "\t3) Leave" << std::endl;
            std::cout << ":";
        } while (action != "3");
        std::string troixlookPrompts[3] = {"You turn around and head back, the smell of fruits and whole sales meat eventually disappearing...", "You look both ways before crossing, which is odd because you're walking on the sidewalk.", "You got chased out of the market by a group of ducks. Congradulations."};
        std::string chosenPrompt = troixlookPrompts[rand() % (sizeof(troixlookPrompts) / sizeof(troixlookPrompts[0]))];
    }

    void main() {
        Data.username = username; // This one you can use :P
        Data.accountDataFile = accountDataFile; // used for data-saving purposes, disregard if your name isn't Samuel. If it is, get rekt lmao
        std::string action = "-1";
        do {
            clear();
            std::string lookPrompts[3] = {"You look around, you can see 3 places nearby:", "You look around, you can see 3 places nearby:", "You look around, you can see 3 places nearby:"};
            std::cout << lookPrompts[rand() % (sizeof(lookPrompts) / sizeof(lookPrompts[0]))] << std::endl; //picks a random look prompt from list
            std::cout << "\t1) The streets (beg for money)" << std::endl;
            std::cout << "\t2) The market" << std::endl;
            std::cout << "\t3) The casino (go into debt)" << std::endl;
            std::cout << "\ts) Save game" << std::endl;
            std::cout << "\tl) Leave game" << std::endl; //changing input from e to l just incase people fat finger s and hit e.
            std::cout << ":";
            std::cin >> action;
            std::cout << action;
            std::cin.get();
            if (action == "1") {
                streets();
            } else if (action == "2") {
                market();
            } else if (action == "3") {
                //
            } else if (action == "s") {
                Data.exportData(accountDataFile);
            }
        } while (action != "l");
    }
};