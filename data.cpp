#include <iostream>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include "files.h"

struct data {

    files Files;

    std::string username = "AAAHHHH";
    std::string accountDataFile = "LEAVE ME ALONE";

    void initalizeData() { //Run this first or im stealing your knees
        std::string initalizeCommand = "python \"" + Files.pythonInitalizer + "\" \"" + Files.localDirectory + "\"525292925252929252529292\"" + Files.gitRepository + "\"525292925252929252529292\"" + Files.gitRemoteName + "\"";
        system(initalizeCommand.c_str());                                                            //Seperator
        //std::cout << initalizeCommand;
    }

    void importData(std::string dataFile) {
        std::fstream DATA(dataFile);
        std::string textData;
        int dataLine = 0;
        while (getline(DATA, textData)) {
            if (dataLine == 0) {
                std::cout << "Pass first saved var";
            }
            dataLine++;
        }
    }

    void exportData(std::string dataFile) {
        std::string saveCommand;
        
        system(saveCommand.c_str());
        saveCommand = Files.batchUploader + " " + Files.localDirectory + Files.gitRemoteName + " " + dataFile;
        system(saveCommand.c_str()); // runs a batch file which uploads it, c++ doesn't have permission to upload.
    }
};