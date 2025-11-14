#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>

/*

This program is used to do some networking using githubs servers.
Touch the code, and you'll probably break it.

Prereqestests... english is hard.
Programs you need to run this:
    git
    python
    Windows operating system (i'll figure out how to include macOS later... probably. Actually macOS might work, who knows.)

*/

#ifndef data_h
#define data_h

std::string gitRepository = "https://github.com/MagicalTinCan/battleshipServer.git";
std::string gitRemoteName = "noTouchie";
std::string localDirectory = "C:\\Users\\EGR126.03.CSCMERCER\\dataShtuff\\";
std::string dataFile = localDirectory + gitRemoteName + "\\data.txt";
std::string projectDirectory = std::filesystem::current_path().string() + "\\";
std::string pythonInitalizer = projectDirectory + "initalizeData.py";
std::string batchUploader = projectDirectory + "upload.bat";

struct data {

    int turn = 0;
    int strikePos[2] = {0,0};

    void initalizeData() { //Run this first or im stealing your knees
        std::string initalizeCommand = "python \"" + pythonInitalizer + "\" \"" + localDirectory + "\"525292925252929252529292\"" + gitRepository + "\"525292925252929252529292\"" + gitRemoteName + "\"";
        system(initalizeCommand.c_str());                                                            //Seperator
        //std::cout << initalizeCommand;
    }

    void importData() {
        std::fstream DATA(dataFile);
        std::string textData;
        int dataLine = 0;
        while (getline(DATA, textData)) {
            if (dataLine == 0) {
                turn = std::stoi(textData);
            } else if (dataLine == 1) {
                strikePos[0] = std::stoi(textData);
            } else if (dataLine == 2) {
                strikePos[1] = std::stoi(textData);
            }
            dataLine++;
        }
    }

    void exportData() { //Yes its ugly, yes it can probably be automated, yes I am probably an idiot for writing it this way. But c++ is fighting with me, and this works.
        std::string saveCommand;
        saveCommand = "echo " + std::to_string(turn) + " > " + dataFile;
        //std::cout << saveCommand << std::endl;
        system(saveCommand.c_str());
        saveCommand = "echo " + std::to_string(strikePos[0]) + " >> " + dataFile;
        //std::cout << saveCommand << std::endl;
        system(saveCommand.c_str());
        saveCommand = "echo " + std::to_string(strikePos[1]) + " >> " + dataFile;
        //std::cout << saveCommand << std::endl;
        system(saveCommand.c_str());
        saveCommand = batchUploader + " " + localDirectory + gitRemoteName;
        system(saveCommand.c_str()); // runs a batch file which uploads it

        /*
        saveCommand = "git add " + dataFile;
        std::cout << saveCommand << std::endl;
        std::cout << saveCommand << std::endl;
        system(saveCommand.c_str());
        saveCommand = "git commit -m \"Action\" " + localDirectory + gitRemoteName;
        std::cout << saveCommand << std::endl;
        system(saveCommand.c_str());
        saveCommand = "git push " + localDirectory + gitRemoteName;
        std::cout << saveCommand << std::endl;
        system(saveCommand.c_str());
        */
    }
};

#endif