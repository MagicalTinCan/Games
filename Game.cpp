#include <iostream>
#include "data.h"
#include "files.h"
#include "item.h"

void clear() { //C++ throws a hissy fit if this is put in data.h, but doesn't if its here. Barbaric.
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
    std::string accountDataFile;
    // used for data-saving purposes, disregard if your name isn't Samuel.

    void test() {
        std::cout << Data.username << std::endl;
        std::cout << Files.localDirectory << Files.gitRemoteName << "\\" << Data.accountDataFile << std::endl;
    }

    void main() {
        Data.username = username; // This one you can use :P
        Data.accountDataFile = accountDataFile; // used for data-saving purposes, disregard if your name isn't Samuel. If it is, get rekt lmao
        clear();
        test();
        std::cin.get();
    }
};