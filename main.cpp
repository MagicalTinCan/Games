#include <iostream>
#include <cstdlib>
#include "data.h"
/*
#include "export.h"
depreciated and non-functional
*/

int board[10][10][3] = {{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}};

char pieceState(int firedUpon, int hit, int localShip) {
    return '#';
}

void printBoard() {
    for (int y = -1; y < 11; y++) {
        for (int x = -1; x < 11; x++) {
            if (y == -1 || y == 10) {
                std::cout << "-";
                if (x == 10) {
                    std::cout << "\n";
                }
            } else {
                if (x == -1 || x == 10) {
                    std::cout << "|";
                    if (x == 10) {
                        std::cout << "\n";
                    }
                } else {
                    std::cout << pieceState(board[x][y][0],board[x][y][1],board[x][y][2]);
                }
            }
        }
    }
}

int main() {
    /*
    data Data;
    Data.initalizeData();
    Data.importData();
    std::cout << Data.turn << ":" << Data.strikePos[0] << ":" << Data.strikePos[1] << std::endl;
    Data.turn = 1;
    Data.strikePos[0] = 2;
    Data.strikePos[1] = 3;
    std::cout << Data.turn << ":" << Data.strikePos[0] << ":" << Data.strikePos[1] << std::endl;
    Data.exportData();
    */

    data Data;
    Data.initalizeData();
    std::string playerName;
    do {
    std::cout << "What player are you (1 or 2): ";
    std::cin >> playerName;
    } while (playerName != "1" && playerName != "2" && !(playerName == "moderator" || playerName == "mod"));

    if (playerName == "moderator" || playerName == "mod") {
        std::string userInput;
        do {
            std::cout << "Options:\n1) Begin game\n2) End game early\n3) Exit\n:";
            std::cin >> userInput;
            if (userInput == "1") {
                Data.turn = 1;
                Data.exportData();
            } else if (userInput == "2") { //soft reset, can be overwritten by players. implemented to allow if players disconnect.
                Data.turn = 0;
                Data.exportData();
            }
        } while (userInput != "3");
    } else {
        printBoard();
    }


    return 0;
}