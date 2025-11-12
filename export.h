#include <fstream>
#include <iostream>

#ifndef export
#define export

std::string gitDirectory = "https://www.github.com/doorKnobLicker.git";
std::string localDirectory = "C:\\Users\\Public\\dataShtuff\\"; //RIP your stuff if you have something called dataShtuff
std::string dataPath = localDirectory + "data.txt";
bool initalDataImport = true;

struct Export {
    int turn = 0;
    int strikePos[2] = {0,0};
    
    void importData() {
        if (initalDataImport) { // downloads git folder w/ data
            initalDataImport = false;
            
            /*
            std::string downloadCommand = "gitport clone \"" + gitDirectory + "\" \"" + localDirectory + "\"";
            system(downloadCommand);
            */
            
            //remember to rmdir /q /s localDirectory when game ends
            
        } else { // pulls data from remote repository
            //std::string pullCommand = "git pull -q \"" + localDirectory + "\"";
            //system(pullCommand);
        }
        std::string textData;
        //std::fstream DATA(dataPath);
        std::fstream DATA("data.txt"); // substitute this line with line above when using VSCode
        int dataLine = 0;
        while (getline(DATA, textData)) {
            //std::cout << textData << std::endl;
            if (dataLine == 0) {
                turn = std::stoi(textData);
            }
            dataLine++;
        }
        std::cout << turn;
        DATA.close(); //git will 'probably' have a stroke without this, don't remove.
    }
    
    void exportData() {
        std::string textFile = "data.txt";
        std::string saveCommands[3] = {"echo " + std::to_string(turn) + " > " + textFile, "echo " + std::to_string(strikePos[0]) + " >> " + textFile, "echo " + std::to_string(strikePos[1]) + " >> " + textFile};
        //std::string saveCommands[1] = {"echo " + std::to_string(turn) + " > " + dataPath, "echo " + std::to_string(strikePos[0]) + " >> " + dataPath, "echo " + std::to_string(strikePos[1]) + " >> " + dataPath};
        for (int x = 0; x < sizeof(saveCommands) / sizeof(saveCommands[0]); x++) {
            std::string saveCommand = saveCommands[x];
            system(saveCommand.c_str()); //only time I had to use chatGPT throughout the year was for this stupid turd. Apparently you need to use .c_str() >:[
        }
    }
};

#endif