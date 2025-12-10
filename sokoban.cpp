#include <iostream>
#include <cstdlib>
//apparently rand isnt apart of <random>, but <cstdlib>. MAKE IT MAKE SENSE

/*

This file was made entirely by Samuel Campbell

*/

struct sokobanBoardPiece { //could also add in brittle ground, only lets player move on it, or maybe just box.
    bool isPlayer;
    bool isBox;
    bool isHole;
    bool isWall;
    bool isGem;
    
    bool isMovableThrough() { //use when moving player
        bool sumCheck = isHole || isWall || isHole;
        return !sumCheck;
    }
    
    bool isClear() { //use when pushing box
        bool sumCheck = isBox || isWall || isGem;
        return !sumCheck;
    }
    
    void tryFill() { //use after isClear check
        if (isHole) {
            isHole = false;
        } else {
            isBox = true;
        }
    }
    
    std::string getLayer(int layer) {
        
        if (isPlayer) {
            if (layer == 0) {
                return "              ";
            } else if (layer == 1) {
                return "      o       ";
            } else if (layer == 2) {
                return "    --|--     ";
            } else if (layer == 3) {
                return "      |       ";
            } else if (layer == 4) {
                return "     / \\      ";
            } else if (layer == 5) {
                return "    /   \\     ";
            }
            return "ERR"; //gave wrong layer
        } else if (isBox) {
            if (layer == 0) {
                return "     ####     ";
            } else if (layer == 1) {
                return "  ####--####  ";
            } else if (layer == 2) {
                return " ##--------## ";
            } else if (layer == 3) {
                return " ##--------## ";
            } else if (layer == 4) {
                return "  ####--####  ";
            } else if (layer == 5) {
                return "     ####     ";
            }
            return "ERR"; //gave wrong layer
        } else if (isHole) {
            if (layer == 0) {
                return "     =  =     ";
            } else if (layer == 1) {
                return "  =        =  ";
            } else if (layer == 2) {
                return " =          = "; //Why does the emoji work but not the cool... whatever alt-178 thing not work??
            } else if (layer == 3) {
                return " =          = ";
            } else if (layer == 4) {
                return "  =        =  ";
            } else if (layer == 5) {
                return "     =  =     ";
            }
            /*
            it was so perfect too... :(
            if (layer == 0) {
                return "   ░░▒▒▒▒░░   ";
            } else if (layer == 1) {
                return " ░░▒▒▓▓▓▓▒▒░░ ";
            } else if (layer == 2) {
                return "░░▒▒▓▓▓▓▓▓▒▒░░";
            } else if (layer == 3) {
                return "░░▒▒▓▓▓▓▓▓▒▒░░";
            } else if (layer == 4) {
                return " ░░▒▒▓▓▓▓▒▒░░ ";
            } else if (layer == 5) {
                return "   ░░▒▒▒▒░░ ";
            }
            */
            return "ERR"; //gave wrong layer
        } else if (isWall) {
            return "##############";
        } else if (isGem) {
            if (layer == 0) {
                return "    ______    ";
            } else if (layer == 1) {
                return "   / *  $ \\   ";
            } else if (layer == 2) {
                return "   \\ $  * /   ";
            } else if (layer == 3) {
                return "    \\ *  /    ";
            } else if (layer == 4) {
                return "     \\ */     ";
            } else if (layer == 5) {
                return "      \\/      ";
            }
            return "ERR";
        }
        return "              "; //Whitespace, walk tile
    }
};

sokobanBoardPiece board[4][6] = {};

sokobanBoardPiece piece(char box) { // box options are w for wall, p for player, b for box, g for gem, h for hole, o (or any other char) for open area / empty space
    sokobanBoardPiece sBP;
    sBP.isPlayer = box == 'p';
    sBP.isBox = box == 'b';
    sBP.isHole = box == 'h';
    sBP.isWall = box == 'w';
    sBP.isGem = box == 'g';
    return sBP;
}

void loadBoard() {

    int board_height = sizeof(board) / sizeof(board[0]);
    int board_width = sizeof(board[0]) / sizeof(board[0][0]);

    int numOfMaps = 4;
    int chosenMap = std::rand() % numOfMaps;
    std::string mapLayout[4] = {};
    if (chosenMap == 0) {
        mapLayout[0] = "pwhoog";
        mapLayout[1] = "obgwww";
        mapLayout[2] = "owowww";
        mapLayout[3] = "ogoooo";
    } else if (chosenMap == 1) {
        mapLayout[0] = "pboooh";
        mapLayout[1] = "wwwwwg";
        mapLayout[2] = "ghoobo";
        mapLayout[3] = "wwwwww";
    } else if (chosenMap == 2) {
        mapLayout[0] = "phhboh";
        mapLayout[1] = "obohbh";
        mapLayout[2] = "ohohoh";
        mapLayout[3] = "ooohhg";
    } else if (chosenMap == 3) {
        mapLayout[0] = "bbooph";
        mapLayout[1] = "gwbwhh";
        mapLayout[2] = "hohbgh";
        mapLayout[3] = "bobhob";
    } else if (chosenMap == 4) {
        mapLayout[0] = "wogwgo";
        mapLayout[1] = "ohhbob";
        mapLayout[2] = "wwobhh";
        mapLayout[3] = "ghpobo";
    }

    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            board[y][x] = piece(mapLayout[y][x]);
        }
    }
}

void clearDeux() { //C++ gets pissy if two functions in TWO DANG SERPERATE FILES have the same name. renamed it to include deux
    std::cout << std::endl; //clear removes all lines except for the very last one, dunno why.
    files Files;
    std::string clearCommand = Files.batchClear;
    system(clearCommand.c_str());
}

struct sokobanGame {
    bool playGame() { //change to bool playGame and stick in struct named sokobanGame when moving to main game
        loadBoard();
        int board_height = sizeof(board) / sizeof(board[0]);
        int board_width = sizeof(board[0]) / sizeof(board[0][0]);
        
        int playerPos[2] = {-9999, -9999};
        int gemCount = 0;
        
        for (int y = 0; y < board_height; y++) {
            for (int x = 0; x < board_width; x++) {
                if (board[y][x].isPlayer && (playerPos[0] == -9999 && playerPos[1] == -9999)) {
                    playerPos[0] = x; //im DEFINITELY gonna forget to put y as first bracket and not x
                    playerPos[1] = y;
                } else if (board[y][x].isPlayer) {
                    std::cout << "YOUR GAMES BROKE. THERE ARE 2 PLAYERS, FIX YOURSELF.";
                    return false; //exits game
                }
                if (board[y][x].isGem)
                    gemCount++;
            }
        }
        
        //std::cout << playerPos[0] << "," << playerPos[1] << std::endl;
        
        std::string beam = "-";
        
        for (int x = 0; x < board_width; x++)
            beam = beam + "---------------";
        
        while (gemCount != 0) {
        
            clearDeux();
        
            for (int y = 0; y < board_height; y++) {
                std::cout << beam << std::endl;
                for (int layer = 0; layer <= 5; layer++) { //probably works
                    for (int x = 0; x < board_width; x++) {
                        if (x == 0)
                            std::cout << "|";
                        std::cout << board[y][x].getLayer(layer) << "|";
                        //std::cout << layer;
                    }
                    std::cout << std::endl;
                }
            }
            
            std::cout << beam << std::endl << std::endl;
            
            std::cout << "Gems left: " << gemCount << std::endl;
            std::cout << "Enter L to leave." << std::endl;
            std::string action;
            while ((action != "W" && action != "A" && action != "S" && action != "D") && (action != "w" && action != "a" && action != "s" && action != "d")) {
                std::cout << "Move where (WASD): ";
                std::cin >> action;
                if (action == "L" || action == "l")
                    return 0; //Returns loss
            }
            
            bool moveTo[4] = {action == "W" || action == "w", action == "A" || action == "a", action == "S" || action == "s", action == "D" || action == "d"};
            if (moveTo[0] && playerPos[1] != 0) { //moving up
                if (board[playerPos[1] - 1][playerPos[0]].isMovableThrough()) { //this can probably be optimized
                    if (board[playerPos[1] - 1][playerPos[0]].isBox) {
                        if (playerPos[1] != 1) { //prevents out of bounds check
                            if (board[playerPos[1] - 2][playerPos[0]].isClear()) {
                                board[playerPos[1] - 2][playerPos[0]].tryFill();
                                board[playerPos[1]][playerPos[0]].isPlayer = false;
                                playerPos[1] -= 1;
                                board[playerPos[1]][playerPos[0]].isPlayer = true;
                                board[playerPos[1]][playerPos[0]].isBox = false;
                            }
                        }
                    } else {
                        board[playerPos[1]][playerPos[0]].isPlayer = false;
                        playerPos[1] = playerPos[1] - 1;
                        board[playerPos[1]][playerPos[0]].isPlayer = true;
                        if (board[playerPos[1]][playerPos[0]].isGem) {
                            board[playerPos[1]][playerPos[0]].isGem = false;
                            gemCount -= 1;
                        }
                    }
                }
            } else if (moveTo[2] && playerPos[1] != board_height - 1) { //moving down
                if (board[playerPos[1] + 1][playerPos[0]].isMovableThrough()) { //this can probably be optimized
                    if (board[playerPos[1] + 1][playerPos[0]].isBox) {
                        if (playerPos[1] != board_height - 2) { //prevents out of bounds check
                            if (board[playerPos[1] + 2][playerPos[0]].isClear()) {
                                board[playerPos[1] + 2][playerPos[0]].tryFill();
                                board[playerPos[1]][playerPos[0]].isPlayer = false;
                                playerPos[1] += 1;
                                board[playerPos[1]][playerPos[0]].isPlayer = true;
                                board[playerPos[1]][playerPos[0]].isBox = false;
                            }
                        }
                    } else {
                        board[playerPos[1]][playerPos[0]].isPlayer = false;
                        playerPos[1] = playerPos[1] + 1;
                        board[playerPos[1]][playerPos[0]].isPlayer = true;
                        if (board[playerPos[1]][playerPos[0]].isGem) {
                            board[playerPos[1]][playerPos[0]].isGem = false;
                            gemCount -= 1;
                        }
                    }
                }
            } else if (moveTo[1] && playerPos[0] != 0) { //moving left
                if (board[playerPos[1]][playerPos[0] - 1].isMovableThrough()) { //this can probably be optimized
                    if (board[playerPos[1]][playerPos[0] - 1].isBox) {
                        if (playerPos[0] != 1) { //prevents out of bounds check
                            if (board[playerPos[1]][playerPos[0] - 2].isClear()) {
                                board[playerPos[1]][playerPos[0] - 2].tryFill();
                                board[playerPos[1]][playerPos[0]].isPlayer = false;
                                playerPos[0] -= 1;
                                board[playerPos[1]][playerPos[0]].isPlayer = true;
                                board[playerPos[1]][playerPos[0]].isBox = false;
                            }
                        }
                    } else {
                        board[playerPos[1]][playerPos[0]].isPlayer = false;
                        playerPos[0] = playerPos[0] - 1;
                        board[playerPos[1]][playerPos[0]].isPlayer = true;
                        if (board[playerPos[1]][playerPos[0]].isGem) {
                            board[playerPos[1]][playerPos[0]].isGem = false;
                            gemCount -= 1;
                        }
                    }
                }
            } else if (moveTo[3] && playerPos[0] != board_width - 1) { //moving right
                if (board[playerPos[1]][playerPos[0] + 1].isMovableThrough()) { //this can probably be optimized
                    if (board[playerPos[1]][playerPos[0] + 1].isBox) {
                        if (playerPos[0] != board_width - 2) { //prevents out of bounds check
                            if (board[playerPos[1]][playerPos[0] + 2].isClear()) {
                                board[playerPos[1]][playerPos[0] + 2].tryFill();
                                board[playerPos[1]][playerPos[0]].isPlayer = false;
                                playerPos[0] += 1;
                                board[playerPos[1]][playerPos[0]].isPlayer = true;
                                board[playerPos[1]][playerPos[0]].isBox = false;
                            }
                        }
                    } else {
                        board[playerPos[1]][playerPos[0]].isPlayer = false;
                        playerPos[0] = playerPos[0] + 1;
                        board[playerPos[1]][playerPos[0]].isPlayer = true;
                        if (board[playerPos[1]][playerPos[0]].isGem) {
                            board[playerPos[1]][playerPos[0]].isGem = false;
                            gemCount -= 1;
                        }
                    }
                }
            }
        }
        
        std::cout << "You win!" << std::endl;
        std::cin.get();

        return true; //return success
    }

};


/*

Disregard, these are notes, shapes, and other stuff...


-------------------------------------------------------------------------------------------------------------------------
|              |              |       o      |              |    @@@@@     |    ______    |    ______    |              |
|              |              |     --|--    |      o       |  @@@@@@@@@   |   /      \   |   / *    \   |              |
|              |              |       |      |    --|--     | @@@@@@@@@@@  |   \      /   |   \    * /   |              |
|              |              |      / \     |      |       | @@@@@@@@@@@  |    \    /    |    \ *  /    |              |
|              |              |     /   \    |     / \      |  @@@@@@@@@   |     \  /     |     \ *\/     |              |
|              |              |              |    /   \     |    @@@@@     |      \/      |      \/      |              |
-------------------------------------------------------------------------------------------------------------------------


int layer = 0; layer <= 5; layer++
int x = 0; x < board_width; x++

    =  =    
 =        = 
=          =
=          =
 =        = 
    =  =    



    =..=    
 =..,,,,..= 
=..,####,..=
=..,####,..=
 =..,,,,..= 
    =..= 

    =  =    
 = ‼↓  ↓‼ = 
=↓ ‼↓  ↓‼ ↓=
=↓ ‼↓  ↓‼ ↓=
 = ‼↓  ↓‼ = 
    =  =    



   ░░▒▒▒▒░░   
 ░░▒▒▓▓▓▓▒▒░░ 
░░▒▒▓▓▓▓▓▓▒▒░░
░░▒▒▓▓▓▓▓▓▒▒░░
 ░░▒▒▓▓▓▓▒▒░░ 
   ░░▒▒▒▒░░ 


   ░░▒▒▒▒░░   
 ░░▒▒▓▓▓▓▒▒░░ 
░░▒▒▓▓▓▓▓▓▒▒░░
░░▒▒▓▓▓▓▓▓▒▒░░

   ░░▒▒▒▒░░ 


    ####    
 ####--#### 
##--------##
##--------##
 ####--#### 
    ####   

¶§▬↨↑↓→←∟↔▲▼ !"#$%%'()*+,♦-./012789:;<=>?@Ae⌂~}~⌂Çüéâäà*åçê¬ûáªº¿⌐á¬┤▒½¼¡«» ░▒▓
←→↓   
☺☻♥♦♣♠•◘○♂◙♂♀♪♫☼►◄↕‼

☺☻♥♫♦♣♠




    for (int y = 0; y <= 0; y++) {
        
        for (int x = 0; x <= 120; x++) {
            //std::cout << x << "," << y << std::endl;
            std::cout << "-";
        }
        
        std::cout << std::endl;
        
        for (int layer = 0; layer <= 5; layer++) {
            for (int x = 0; x <= 120; x++) {
                //std::cout << x << "," << y << std::endl;
                if (x % 15 == 0) {
                    std::cout << "|";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
        
        for (int x = 0; x <= 120; x++) {
            //std::cout << x << "," << y << std::endl;
            std::cout << "-";
        }
    }



Maps:

Test map:
{
{false, false, false, false, false},{false, false, true, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false}
},
{
{false, false, false, false, false},{false, false, false, false, false},{false, true, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, true}
},
{
{false, false, false, false, false},{false, false, false, false, true},{false, false, false, false, false},{false, false, false, false, false},{false, true, false, false, false},{false, false, false, false, false}
},
{
{false, false, false, false, false},{false, false, false, false, false},{true, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false}
}

Test map2:
{
{true, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false}
},
{
{false, false, false, false, false},{false, false, false, false, false},{false, true, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, true, false}
},
{
{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false}
},
{
{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false}
}


Zigzag:
{
{true, false, false, false, false},{false, true, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, true, false, false}
},
{
{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, false, true}
},
{
{false, false, false, false, true},{false, false, true, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, true, false, false, false},{false, false, false, false, false}
},
{
{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false}
}

Loop around:
{
{true, false, false, false, false},{false, false, false, true, false},{false, false, true, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, true}
},
{
{false, false, false, false, false},{false, true, false, false, false},{false, false, false, false, true},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false}
},
{
{false, false, false, false, false},{false, false, false, true, false},{false, false, false, false, false},{false, false, false, true, false},{false, false, false, true, false},{false, false, false, true, false}
},
{
{false, false, false, false, false},{false, false, false, false, true},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false},{false, false, false, false, false}
}


*/