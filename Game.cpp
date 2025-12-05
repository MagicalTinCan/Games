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

std::string canAfford(double moneyz, double cost) {
    if (moneyz >= cost) {
        return "\033[32m";
    } else {
        return "\033[31m";
    }
}

std::string hasItem(int units) {
    if (units != 0) {
        return "\033[32m";
    } else {
        return "\033[31m";
    }
}

struct game {
    data Data;
    files Files;
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
            std::cout << "Your wallet: \033[33m" << Data.money << "$\033[m" << std::endl;
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
            clear();
            std::cout << lookPrompts[rand() % (sizeof(lookPrompts) / sizeof(lookPrompts[0]))] << std::endl; //randomizes each go
            std::cout << "\t1) Buy some stuff" << std::endl;
            std::cout << "\t2) Sell some stuff" << std::endl;
            std::cout << "\t3) Leave" << std::endl;
            std::cout << ":";
            std::cin >> action;
            if (action == "1") {
                bool wannaBeHere = true;
                std::cin.get(); //for some reason the first .get() just gets completely ignored so WHAAATever
                while (wannaBeHere) {
                    clear();
                    std::cout << " _____                                                                                       _____ \n( ___ )                                                                                     ( ___ )\n |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n |   |   ____  _        _       _                                        _                   |   | \n |   |  / ___|| | _____| |_ ___| |__  _   _  __   ____ _ _ __  ____  ___| |__   ___  _ __    |   | \n |   |  \\___ \\| |/ / _ \\ __/ __| '_ \\| | | | \\ \\ / / _` | '_ \\|_  / / __| '_ \\ / _ \\| '_ \\   |   | \n |   |   ___) |   <  __/ || (__| | | | |_| |  \\ V / (_| | | | |/ /  \\__ \\ | | | (_) | |_) |  |   | \n |   |  |____/|_|\\_\\___|\\__\\___|_| |_|\\__, |   \\_/ \\__,_|_| |_/___| |___/_| |_|\\___/| .__/   |   | \n |   |                                |___/                                         |_|      |   | \n |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n(_____)                                                                                     (_____)" << std::endl << std::endl;
                    std::cout << "Todays market: " << std::endl;
                    for (int ITEM = 0; ITEM < sizeof(Data.inventory) / sizeof(Data.inventory[0]); ITEM++) {
                        std::cout << "\t" << ITEM+1 << ") " << Data.inventory[ITEM].name << " (" << Data.inventory[ITEM].units << "x) : " << canAfford(Data.money, Data.inventory[ITEM].buyValue) << Data.inventory[ITEM].buyValue << "$\033[m" << std::endl;
                    }
                    std::cout << "\nBuy an item by selecting a product ID, or enter L to leave." << std::endl;
                    std::cout << "Your wallet: \033[33m" << Data.money << "$\033[m" << std::endl;
                    std::cout << ":";
                    int wantedItem;
                    std::cin >> action;
                    if (action == "L" || action == "l") {
                        wannaBeHere = false;
                    } else {
                        try {
                            wantedItem = std::stoi(action) - 1; //oohhh NOW you throw an error if its a char >:(
                        } catch (...) {
                            wantedItem = -9;
                            clear();
                            std::cout << "The clerk behind the counter screams in your face\n\"DO WE LOOK LIKE WE SELL FOOZ BALLS!? WE'RE SKETCHY VANS SHOP™ NOT FOOZ BALLS INC.!!!\"" << std::endl;
                            std::cout << "He storms off fuming and another clerk comes to your service.\n...";
                            std::cin.get();
                        }
                        bool wantedItemInItems = 0 <= wantedItem && wantedItem < sizeof(Data.inventory) / sizeof(Data.inventory[0]);
                        if (wantedItemInItems) {
                            std::string itemName = Data.inventory[wantedItem].name;
                            double itemCost = Data.inventory[wantedItem].buyValue;
                            if (Data.money >= itemCost) {
                                Data.money -= itemCost;
                                Data.inventory[wantedItem].units += 1;
                                //std::cin.get();
                                //std::cin.get();
                            } else {
                                std::cout << "The clerk behind the counter at Sketchy vanz shop™ shouts at you\n\"You don't have enough!\"\n...";
                                std::cin.get();
                                std::cin.get();
                            }
                        } else {
                            clear();
                            std::cout << "The clerk behind the counter screams in your face\n\"DO WE LOOK LIKE WE SELL FOOZ BALLS!? WE'RE SKETCHY VANS SHOP™ NOT FOOZ BALLS INC.!!!\"" << std::endl;
                            std::cout << "He storms off fuming and another clerk comes to your service.\n...";
                            std::cin.get();
                            std::cin.get();
                        }
                    }
                }
            } else if (action == "2") {
                bool wannaBeHere = true;
                std::cin.get(); //for some reason the first .get() just gets completely ignored so WHAAATever
                while (wannaBeHere) {
                    clear();
                    std::cout << " _____                                                                                       _____ \n( ___ )                                                                                     ( ___ )\n |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n |   |   ____  _        _       _                                        _                   |   | \n |   |  / ___|| | _____| |_ ___| |__  _   _  __   ____ _ _ __  ____  ___| |__   ___  _ __    |   | \n |   |  \\___ \\| |/ / _ \\ __/ __| '_ \\| | | | \\ \\ / / _` | '_ \\|_  / / __| '_ \\ / _ \\| '_ \\   |   | \n |   |   ___) |   <  __/ || (__| | | | |_| |  \\ V / (_| | | | |/ /  \\__ \\ | | | (_) | |_) |  |   | \n |   |  |____/|_|\\_\\___|\\__\\___|_| |_|\\__, |   \\_/ \\__,_|_| |_/___| |___/_| |_|\\___/| .__/   |   | \n |   |                                |___/                                         |_|      |   | \n |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n(_____)                                                                                     (_____)" << std::endl << std::endl;
                    std::cout << "Todays market: " << std::endl;
                    for (int ITEM = 0; ITEM < sizeof(Data.inventory) / sizeof(Data.inventory[0]); ITEM++) {
                        std::cout << "\t" << ITEM+1 << ") " << Data.inventory[ITEM].name << " (" << Data.inventory[ITEM].units << "x) : " << hasItem(Data.inventory[ITEM].units) << Data.inventory[ITEM].sellValue << "$\033[m" << std::endl;
                    }
                    std::cout << "\nSell an item by selecting a product ID, or enter L to leave." << std::endl;
                    std::cout << "\033[33mWelcome to Pawn Stars! My expert says your ancient flashdrive with \033[31m20 bitcoin\033[33m on it is worth a stick of gum, but i'll give you two for it!\033[m" << std::endl;
                    std::cout << "Your wallet: \033[33m" << Data.money << "$\033[m" << std::endl;
                    std::cout << ":";
                    int wantedItem;
                    std::cin >> action;
                    if (action == "L" || action == "l") {
                        wannaBeHere = false;
                    } else {
                        try {
                            wantedItem = std::stoi(action) - 1; //oohhh NOW you throw an error if its a char >:(
                        } catch (...) {
                            wantedItem = -9;
                            clear();
                            std::cout << "You shuffle your bag around and proudly present your empty fist, Rick Harrison does not look amused." << std::endl;
                            std::cin.get();
                        }
                        bool wantedItemInItems = 0 <= wantedItem && wantedItem < sizeof(Data.inventory) / sizeof(Data.inventory[0]);
                        if (wantedItemInItems) {
                            std::string itemName = Data.inventory[wantedItem].name;
                            double itemWorth = Data.inventory[wantedItem].sellValue;
                            if (Data.inventory[wantedItem].units != 0) {
                                Data.money += itemWorth;
                                Data.inventory[wantedItem].units -= 1;
                                //std::cin.get();
                                //std::cin.get();
                            } else {
                                std::cout << "You shuffle your bag around and proudly present your empty fist, Rick Harrison does not look amused.";
                                std::cin.get();
                                std::cin.get();
                            }
                        } else {
                            clear();
                            std::cout << "You shuffle your bag around and proudly present your empty fist, Rick Harrison does not look amused." << std::endl;
                            std::cin.get();
                            std::cin.get();
                        }
                    }
                }
            }
        } while (action != "3");
        clear();
        std::string troixlookPrompts[3] = {"You turn around and head back, the smell of fruits and whole sales meat eventually disappearing...", "You look both ways before crossing, which is odd because you're walking on the sidewalk.", "You got chased out of the market by a group of ducks. Congradulations."};
        std::string chosenPrompt = troixlookPrompts[rand() % (sizeof(troixlookPrompts) / sizeof(troixlookPrompts[0]))];
        std::cin.get();
    }

    void casino() {
        clear();
        std::cout << "You walk around for a bit when you find the enterance. A man comes barging out with a red face and clentched fists, he power walks away.\nYou are now at" << std::endl;
        std::cout << "                                 .----------------.  .----------------.  .----------------.                             \n                                | .--------------. || .--------------. || .--------------. |                            \n                                | |  _________   | || |  ____  ____  | || |  _________   | |                            \n                                | | |  _   _  |  | || | |_   ||   _| | || | |_   ___  |  | |                            \n                                | | |_/ | | \\_|  | || |   | |__| |   | || |   | |_  \\_|  | |                            \n                                | |     | |      | || |   |  __  |   | || |   |  _|  _   | |                            \n                                | |    _| |_     | || |  _| |  | |_  | || |  _| |___/ |  | |                            \n                                | |   |_____|    | || | |____||____| | || | |_________|  | |                            \n                                | |              | || |              | || |              | |                            \n                                | '--------------' || '--------------' || '--------------' |                            \n                                 '----------------'  '----------------'  '----------------'                             \n .----------------.  .----------------.  .----------------.  .----------------.  .-----------------. .----------------. \n| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n| |     ______   | || |      __      | || |    _______   | || |     _____    | || | ____  _____  | || |     ____     | |\n| |   .' ___  |  | || |     /  \\     | || |   /  ___  |  | || |    |_   _|   | || ||_   \\|_   _| | || |   .'    `.   | |\n| |  / .'   \\_|  | || |    / /\\ \\    | || |  |  (__ \\_|  | || |      | |     | || |  |   \\ | |   | || |  /  .--.  \\  | |\n| |  | |         | || |   / ____ \\   | || |   '.___`-.   | || |      | |     | || |  | |\\ \\| |   | || |  | |    | |  | |\n| |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  |`\\____) |  | || |     _| |_    | || | _| |_\\   |_  | || |  \\  `--'  /  | |\n| |   `._____.'  | || ||____|  |____|| || |  |_______.'  | || |    |_____|   | || ||_____|\\____| | || |   `.____.'   | |\n| |              | || |              | || |              | || |              | || |              | || |              | |\n| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << std::endl;
        std::cin.get();
        std::string action;
        do {
            clear();
            std::cout << " .----------------.  .----------------.  .----------------.  .----------------.  .-----------------. .----------------. \n| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n| |     ______   | || |      __      | || |    _______   | || |     _____    | || | ____  _____  | || |     ____     | |\n| |   .' ___  |  | || |     /  \\     | || |   /  ___  |  | || |    |_   _|   | || ||_   \\|_   _| | || |   .'    `.   | |\n| |  / .'   \\_|  | || |    / /\\ \\    | || |  |  (__ \\_|  | || |      | |     | || |  |   \\ | |   | || |  /  .--.  \\  | |\n| |  | |         | || |   / ____ \\   | || |   '.___`-.   | || |      | |     | || |  | |\\ \\| |   | || |  | |    | |  | |\n| |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  |`\\____) |  | || |     _| |_    | || | _| |_\\   |_  | || |  \\  `--'  /  | |\n| |   `._____.'  | || ||____|  |____|| || |  |_______.'  | || |    |_____|   | || ||_____|\\____| | || |   `.____.'   | |\n| |              | || |              | || |              | || |              | || |              | || |              | |\n| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << std::endl;
            std::cout << "\nPick your vice:\n\t1) Blackjack\n\t2) Slot machine\n\t3) Leave";
            std::cin >> action;
            if (action == "1" || action == "2") {
                std::cout << "You walk over to play, but the place is a mess.\nYou decide to not play for now..." << std::endl;
                std::cin.get();
                std::cin.get();
            }
        } while (action != "3");
        
    }

    void main() {
        Data.username = username; // This one you can use :P
        Data.accountDataFile = accountDataFile; // used for data-saving purposes, disregard if your name isn't Samuel. If it is, get rekt lmao
        std::string action = "-1";

        std::string preActionSTR = "-1";
        int preActionInt = 0; //these two are used together to prevent softlocking/hardlocking

        Data.importData(accountDataFile);
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
            std::cin >> preActionSTR;
            bool worked = true;
            try {
                preActionInt = std::stoi(preActionSTR);
            } catch (...) {
                worked = false;
                bool appropriateInput = preActionSTR == "s" || preActionSTR == "S" || preActionSTR == "l" || preActionSTR == "L";
                if (appropriateInput) {
                    action = preActionSTR;
                } else {
                    clear();
                    std::cout << "Give a correct input." << std::endl;
                    std::cin.get();
                }
            }
            if (worked) {
                action = std::to_string(preActionInt);
            }
            //std::cout << action;
            std::cin.get();
            if (action == "1") {
                streets();
            } else if (action == "2") {
                market();
            } else if (action == "3") {
                casino();
                /*
                clear();
                std::cout << "Not implemented yet.\n:";
                std::cin.get();
                */
            } else if (action == "s") {
                Data.password = password;
                Data.exportData(accountDataFile);
            }
        } while (action != "l");
    }
};