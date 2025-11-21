#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include "files.h"

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

    //int inventory[] 

    void initalizeData() { //Run this first or im stealing your knees
        std::string initalizeCommand = "python \"" + Files.pythonInitalizer + "\" \"" + Files.localDirectory + "\"525292925252929252529292\"" + Files.gitRepository + "\"525292925252929252529292\"" + Files.gitRemoteName + "\"525292925252929252529292\"" + Files.projectDirectory + "\"";
        system(initalizeCommand.c_str());                                                            //Seperator
        //std::cout << initalizeCommand;
    }

    void importData(std::string dataFile) {
        std::fstream DATA(dataFile);
        std::string textData;
        int dataLine = 0;
        while (getline(DATA, textData)) {
            if (dataLine == 0) {
                std::cout << textData;
            }
            dataLine++;
        }
    }

    void exportData(std::string dataFile) {
        std::string saveCommand;
        std::string tempDataHolder;
        std::string dataFileAbsLocation = Files.localDirectory + Files.gitRemoteName + "\\" + dataFile;
        saveCommand = "echo " + password + "> " + dataFileAbsLocation;
        system(saveCommand.c_str());
        tempDataHolder = std::to_string(money);
        saveCommand = "echo " + tempDataHolder.substr(0,tempDataHolder.find("."+2)) + ">> " + dataFileAbsLocation; //Gets rid of the ugly zeros after first decimal point. Only necessary for non-integar number values.
        system(saveCommand.c_str());
        saveCommand = Files.batchUploader + " " + Files.localDirectory + Files.gitRemoteName + " " + dataFile;
        system(saveCommand.c_str()); // runs a batch file which uploads it, c++ doesn't have permission to upload.
    }

};

#endif