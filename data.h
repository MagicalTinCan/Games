#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include "files.h"
#include "item.h"

/*

This file was made entirely by Samuel Campbell

*/

#ifndef data_h
#define data_h

struct data {

    files Files;

    std::string username = "AAAHHHH";
    std::string password = "WHYYY";
    std::string accountDataFile = "LEAVE ME ALONE";

    double money = 0.0; //float gets hella weird with 99.1, it becomes like 99.099998

    item inventory[3] = {
        {"Apple", 3, 4, 0},
        {"Pear", 4, 5, 0},
        {"Pineapple", 5, 8}
    };
    // name, buyValue, sellValue

    void initalizeData() { //Run this first or im stealing your knees
        std::string initalizeCommand = "python \"" + Files.pythonInitalizer + "\" \"" + Files.localDirectory + "\"525292925252929252529292\"" + Files.gitRepository + "\"525292925252929252529292\"" + Files.gitRemoteName + "\"525292925252929252529292\"" + Files.projectDirectory + "\"";
        system(initalizeCommand.c_str());                                                            //Seperator
        //std::cout << initalizeCommand;
    }

    void importData(std::string dataFile, bool offlineMode = false) {

        std::string fileOfInterest = Files.localDirectory + Files.gitRemoteName + "\\" + dataFile;

        if (offlineMode)
            fileOfInterest = Files.offlineAccount;

        std::fstream DATA(fileOfInterest);
        std::string textData;
        int dataLine = 0;
        int inventoryOffset = 0;
        while (getline(DATA, textData)) { //dataLine 0 = password
            if (dataLine == 0) {
                //password
            } else if (dataLine == 1) {
                money = std::stod(textData);
            } else if (dataLine - 2 <= sizeof(inventory) / sizeof(inventory[0])) {
                inventory[inventoryOffset].units = std::stoi(textData);
                inventoryOffset++;
            }
            dataLine++;
        }
    }

    void exportData(std::string dataFile, bool offlineMode = false) {
        std::string saveCommand;
        std::string tempDataHolder;
        std::string dataFileAbsLocation = Files.localDirectory + Files.gitRemoteName + "\\" + dataFile;
        if (offlineMode)
            dataFileAbsLocation = Files.offlineAccount;

        saveCommand = "echo " + password + "> " + dataFileAbsLocation;
        system(saveCommand.c_str());
        tempDataHolder = std::to_string(money);
        saveCommand = "echo " + tempDataHolder.substr(0,tempDataHolder.find("."+2)) + ">> " + dataFileAbsLocation; //Gets rid of the ugly zeros after first decimal point. Only necessary for non-integar number values.
        system(saveCommand.c_str());                                                                               //Doesnt even do it anyway. WHAT EVERRRR -_-
        for (int ITEM = 0; ITEM < sizeof(inventory) / sizeof(inventory[0]); ITEM++) {
            tempDataHolder = std::to_string(inventory[ITEM].units);
            saveCommand = "echo " + tempDataHolder + " >> " + dataFileAbsLocation;
            system(saveCommand.c_str());
        }
        if (!offlineMode) {
            saveCommand = Files.batchUploader + " " + Files.localDirectory + Files.gitRemoteName + " " + dataFile;
            system(saveCommand.c_str()); // runs a batch file which uploads it, c++ doesn't have permission to upload.
        }
    }

};

#endif