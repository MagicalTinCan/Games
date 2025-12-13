#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include "data.h" //changed back to .h instead of .cpp because of initalizing data and
#include "files.h"
#include "Game.cpp"
#include "tutorial.cpp"
/*
#include "export.h"
depreciated and non-functional
*/

/*

This file was made entirely by Samuel Campbell

*/

void clear() { //I take it back, past me didn't know what the hell he was doing. C++ maybe you are good.
    std::cout << std::endl; //clear removes all lines except for the very last one, dunno why.
    files Files;
    std::string clearCommand = Files.batchClear;
    system(clearCommand.c_str());
}

int main() {

    srand(time(0)); // turns out rand isnt so rand. If this isnt here its always gonna be the same. -9 iq language.

    data Data;
    files Files;
    std::string action = "0";
    bool loggedIn = false;
    std::string username;
    std::string password;
    std::string null;
    // Serves as a buffer for getline(cin) cause for some reason, getline takes whatever was put in for std::cin on a prior command
    do {
        bool successfulInput = true;
        std::cout << "Hello, welcome to Project Nat\n\t1) New game\n\t2) Continue\n\t3) Offline mode\n\t4) Tutorial\n\tl) Exit\n: ";
        std::cin >> action;
        successfulInput = action == "1" || action == "2" || action == "3" || action == "4" || action == "l";

        clear();

        getline(std::cin, null); //should stop auto input... probably.
        if (successfulInput) {
            if (action == "1") {
                Data.initalizeData();
                bool accountAlreadyExists = true;
                do {
                    std::cout << "Alright, give your character a name" << std::endl;
                    std::cout << "(this will be used as your login credential and will be used to broadcast your username to other players)" << std::endl;
                    std::cout << ": ";
                    getline(std::cin, username);
                    accountAlreadyExists = std::filesystem::exists(Files.localDirectory + Files.gitRemoteName + "\\" + username + ".txt");
                    if (accountAlreadyExists) {
                        std::cout << "Account already taken!" << std::endl;
                    }
                } while (accountAlreadyExists);
                std::cout << "Alright, now give your account a password to secure it: ";
                getline(std::cin, password);
                Data.username = username;
                Data.password = password;
                Data.accountDataFile = username + ".txt";
                std::string makeAccountCommand = "echo " + password + "> " + Files.localDirectory + Files.gitRemoteName + "\\" + Data.accountDataFile;
                system(makeAccountCommand.c_str());
                makeAccountCommand = "echo 0.0>> " + Files.localDirectory + Files.gitRemoteName + "\\" + Data.accountDataFile;
                for (int x = 0; x < 5; x++) {
                    system(makeAccountCommand.c_str());
                }
                Data.exportData(Data.accountDataFile);
                //loggedIn = true;
            } else if (action == "2") {
                Data.initalizeData();
                bool gaveUp = false;
                do {
                    clear();
                    std::cout << "Username: ";
                    getline(std::cin, username);
                    std::cout << "Password: ";
                    getline(std::cin, password);
                    bool accountExists = std::filesystem::exists(Files.localDirectory + Files.gitRemoteName + "\\" + username + ".txt");
                    if (accountExists) {
                        std::string accPassword = "undefinedUserPassword(0)(>)+=[]W";
                        std::string firstLineTest;
                        std::fstream plrData(Files.localDirectory + Files.gitRemoteName + "\\" + username + ".txt");
                        getline(plrData, accPassword);
                        plrData.close();
                        if (password == accPassword) {
                            std::cout << "Logged in." << std::endl;
                            loggedIn = true;
                            game Game;
                            Game.username = username;
                            Game.password = password;
                            Game.accountDataFile = username + ".txt";
                            Game.main();
                            clear();
                        } else {
                            std::cout << "Username/Password incorrect!" << std::endl;
                            //std::cout << "\"" << password << "\"" << std::endl; Testing purposes. DO NOT TOUCH.
                            //std::cout << "\"" << accPassword << "\"" << std::endl; SECURITY BREACH IF UNCOMMENTED
                        }
                    } else {
                        std::cout << "Username/Password incorrect!" << std::endl;
                    }
                    if (!loggedIn) {
                        bool improperResponse = true;
                        do {
                        std::cout << "Back to title?" << std::endl;
                        std::cout << "(Y/N): ";
                        char response;
                        std::cin >> response;
                        response = (char)std::tolower(response);
                        if (response == 'y') {
                            improperResponse = false;
                            gaveUp = true;
                        } else if (response == 'n') {
                            improperResponse = false;
                        } else {
                            std::cout << "Give a proper response, Y/y, N/n." << std::endl;
                        }
                        getline(std::cin, null); //stops auto input for next getline.
                        } while (improperResponse);
                    }
                } while (!loggedIn && !gaveUp);
                loggedIn = false; //Makes it so they return to title screen instead of getting boot'd out
            } else if  (action == "3") {
                game Game;
                Game.password = "Buffer";
                Game.main(true);
                clear();
            } else if (action == "4") {
                tutorial TUTORIAL;
                TUTORIAL.inquireYerKnowledge();
                clear();
            } else if (action == "l") {
                loggedIn = true;
                return 1; //Ends int main() {}
            }
        } else {
            std::cout << "Give a correct input." << std::endl; // std::cin wasnt throwing an err when a char was inputted, so now we're here.
            std::cin.get();
            clear();
        }
    } while (!loggedIn);
    return 0;
}