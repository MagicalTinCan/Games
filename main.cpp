#include <iostream>
#include <cstdlib>
#include <filesystem>
#include "data.cpp"
#include "files.h"
/*
#include "export.h"
depreciated and non-functional
*/

int main() {
    data Data;
    files Files;
    Data.initalizeData();
    int action = 0;
    bool loggedIn = false;
    std::string username;
    std::string password;
    do {
        bool successfulInput = true;
        std::cout << "Hello, welcome to Project Nat\n\t1) New game\n\t2) Continue\n\t3) Leave\n: ";
        try {
            std::cin >> action;
        } catch (...) {
            std::cout << "Give a correct input." << std::endl;
            successfulInput = false;
        }
        if (successfulInput) {
            if (action == 1) {
                bool accountAlreadyExists = true;
                do {
                    std::cout << "Alright, give your character a name" << std::endl;
                    std::cout << "(this will be used as your login credential and will be used to broadcast your username to other players)" << std::endl;
                    std::cout << ": ";
                    std::cin >> username;
                    accountAlreadyExists = std::filesystem::exists(Files.localDirectory + Files.gitRemoteName + "\\" + username + ".txt");
                    if (accountAlreadyExists) {
                        std::cout << "Account already taken!" << std::endl;
                    }
                } while (accountAlreadyExists);
                std::cout << "Alright, now give your account a password to secure it: ";
                std::cin >> password;
                Data.username = username;
                Data.accountDataFile = username + ".txt";
                std::string makeAccountCommand = "echo " + password + " > " + Files.localDirectory + Files.gitRemoteName + "\\" + Data.accountDataFile;
                system(makeAccountCommand.c_str());
                makeAccountCommand = "echo 0 >> " + Files.localDirectory + Files.gitRemoteName + "\\" + Data.accountDataFile;
                for (int x = 0; x < 5; x++) {
                    system(makeAccountCommand.c_str());
                }
                Data.exportData(Data.accountDataFile);
            }
        }
    } while (!loggedIn);
    return 0;
}