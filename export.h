#include <fstream>
#include <iostream>


/*

WARNING

File is depreciated and no longer is being updated. Do not use. Use data.h instead!

*/

#ifndef export
#define export

std::string gitDirectory = "https://github.com/MagicalTinCan/battleshipServer.git";
std::string localDirectory = "C:\\Users\\Public\\dataShtuff"; //RIP your stuff if you have something called dataShtuff
std::string dataPath = localDirectory + "\\data.txt";
bool initalDataImport = std::filesystem; //intended for the moment

struct Export {
    int turn = 0;
    int strikePos[2] = {0,0};
    
    void importData() {
        if (initalDataImport) { // downloads git folder w/ data
            initalDataImport = false;
            
            
            std::string downloadCommand = "git clone \"" + gitDirectory + "\" \"" + localDirectory + "\"";
            //std::cout << downloadCommand;
            system(downloadCommand.c_str());
            
            //remember to rmdir /q /s localDirectory when game ends
            
        } else { // pulls data from remote repository
            std::string pullCommand = "git pull -q \"" + localDirectory + "\"";
            system(pullCommand.c_str());
        }
        std::string textData;
        std::fstream DATA(dataPath);
        //std::fstream DATA("data.txt"); // substitute this line with line above when using VSCode
        int dataLine = 0;
        while (getline(DATA, textData)) {
            //std::cout << textData << std::endl;
            if (dataLine == 0) {
                turn = std::stoi(textData);
            } else if (dataLine == 1) {
                strikePos[0] = std::stoi(textData);
            } else if (dataLine == 2) {
                strikePos[1] = std::stoi(textData);
            }
            dataLine++;
        }
        //std::cout << turn;
        DATA.close(); //git will 'probably' have a stroke without this, don't remove.
    }
    
    void exportData() {
        std::cout << 3;
        std::string textFile = "data.txt";
        std::cout << 4;
        //std::string saveCommands[3] = {"echo " + std::to_string(turn) + " > " + textFile, "echo " + std::to_string(strikePos[0]) + " >> " + textFile, "echo " + std::to_string(strikePos[1]) + " >> " + textFile};
        
        /*
        std::string saveCommands[3] = {"echo " + std::to_string(turn) + " > " + dataPath, "echo " + std::to_string(strikePos[0]) + " >> " + dataPath, "echo " + std::to_string(strikePos[1]) + " >> " + dataPath};
        std::cout << 5;
        for (int x = 0; x < sizeof(saveCommands) / sizeof(saveCommands[0]); x++) {
            std::string saveCommand = saveCommands[x];
            system(saveCommand.c_str()); //only time I had to use chatGPT throughout the year was for this stupid turd. Apparently you need to use .c_str() >:[
        }
        */

        std::ofstream DATA(dataPath);
        DATA << turn << "\n" << strikePos[0] << "\n" << strikePos[1];
        DATA.close();
        std::string addCommand = "git add \"" + dataPath + "\"";
        std::string commitCommand = "git commit -q -m \"Action\" \"" + localDirectory + "\"";
        std::string pushCommand = "git push -q \"" + localDirectory + "\"";
        /*
        system(addCommand.c_str());
        system(commitCommand.c_str());
        system(pushCommand.c_str());
        */
        std::cout << addCommand.c_str() << std::endl;
        std::cout << commitCommand.c_str() << std::endl;
        std::cout << pushCommand.c_str() << std::endl;
    }
};

#endif