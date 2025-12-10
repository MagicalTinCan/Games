/******************************************************************************
Name: Cayden Hendrix
Section: 003
Assignment


*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "files.h"

struct HangmanGame {
    std::string word;
    std::string display;
    std::string used;
    int tries;

    HangmanGame(std::string w) {
        word = w;
        display = std::string(w.length(), '_');
        used = "";
        tries = 6;
    }
};

void clearQuatre() { //C++ throws a hissy fit if this is put in data.h, but doesn't if its here. Barbaric.
    std::cout << std::endl; //clear removes all lines except for the very last one, dunno why.
    files Files;
    std::string clearCommand = Files.batchClear;
    system(clearCommand.c_str());
}

void drawHangman(int tries) {
    int stage = 6 - tries;

    std::cout << "\n";
    std::cout << " +----+\n";
    std::cout << " |    |\n";

    if (stage >= 1) std::cout << " O    |\n";
    else            std::cout << "      |\n";

    if (stage == 2) std::cout << " |    |\n";
    else if (stage == 3) std::cout << "/|    |\n";
    else if (stage >= 4) std::cout << "/|\\   |\n";
    else std::cout << "      |\n";

    if (stage == 5) std::cout << "/     |\n";
    else if (stage >= 6) std::cout << "/ \\   |\n";
    else std::cout << "      |\n";

    std::cout << "      |\n";
    std::cout << "=========\n\n";
}

struct hangmanGame {

    bool playGame() {
        std::vector<std::string> words = {
            "apple","computer","school","hangman","water","apple","banana","orange","grape","peach",
            "melon","pear","mango","strawberry","blueberry","raspberry","pineapple","watermelon",
            "kiwi","papaya","coconut","plum","cherry","lemon","lime","apricot","fig","date","almond",
            "walnut","peanut","cashew","pistachio","hazelnut","cat","dog","rabbit","mouse","horse",
            "cow","sheep","goat","chicken","duck","eagle","tiger","lion","bear","shark","whale",
            "dolphin","penguin","zebra","giraffe","monkey","panda","koala","camel","frog","snake",
            "lizard","turtle","spider","bee","car","truck","bus","train","plane","ship","boat",
            "bicycle","motorcycle","scooter","rocket","submarine","tractor","ambulance","taxi","van",
            "helicopter","school","teacher","student","pencil","pen","marker","notebook","paper",
            "binder","folder","desk","chair","computer","keyboard","mousepad","backpack","classroom",
            "locker","textbook","calculator","charger","house","kitchen","bedroom","bathroom","garage",
            "window","door","floor","ceiling","staircase","basement","attic","couch","sofa","table",
            "lamp","blanket","pillow","closet","curtain","dresser","water","fire","earth","air","light",
            "shadow","storm","rain","snow","wind","cloud","thunder","lightning","ocean","river",
            "mountain","forest","desert","island","volcano","canyon","valley","hill","meadow","garden",
            "pizza","burger","fries","taco","sandwich","pasta","noodles","sushi","steak","chicken",
            "salad","cheese","bread","cookie","brownie","donut","candy","chocolate","icecream","happy",
            "sad","angry","excited","bored","tired","scared","confused","proud","brave","shy","worried",
            "football","basketball","baseball","soccer","tennis","golf","volleyball","hockey","boxing",
            "running","cycling","phone","tablet","laptop","charger","battery","internet","network",
            "camera","speaker","monitor","remote","robot","engine","morning","night","evening",
            "yesterday","tomorrow","future","past","memory","dream","thought","family","mother",
            "father","brother","sister","uncle","aunt","cousin","baby","child","parents","music",
            "guitar","piano","drums","violin","flute","trumpet","singer","song","melody","rhythm",
            "planet","galaxy","star","asteroid","comet","orbit","gravity","rocket","spaceship",
            "universe","king","queen","prince","princess","castle","dragon","knight","wizard","magic",
            "sword","shield","treasure","pirate","color","red","blue","green","yellow","purple","pink",
            "orange","white","black","gray","silver","gold","city","town","village","street","bridge",
            "tower","park","plaza","market","harbor","winter","spring","summer","autumn","season",
            "holiday","festival","copper","iron","silver","gold","bronze","diamond","crystal","marble",
            "stone","brick","energy","power","machine","engine","metal","plastic","rubber","glass",
            "wood","paper","friend","enemy","people","crowd","group","team","winner","loser","flower",
            "rose","tulip","orchid","sunflower","daisy","lily","lotus","clock","watch","time","moment",
            "second","minute","hour","game","level","score","player","enemy","mission","challenge",
            "victory"
        };
    
        srand(time(0));
        HangmanGame game(words[rand() % words.size()]);
    
        std::cout << "=== Hangman ===\n";
    
        while (game.tries > 0 && game.display != game.word) {
            clearQuatre();
            drawHangman(game.tries);
    
            std::cout << "Word: " << game.display << std::endl;
            std::cout << "Tries: " << game.tries << std::endl;
            std::cout << "Used: " << game.used << std::endl;
    
            std::cout << "Guess a letter: ";
            char letter;
            std::cin >> letter;
    
            if (game.used.find(letter) != std::string::npos) {
                std::cout << "Already used.\n";
                continue;
            }
    
            game.used += letter;
            bool found = false;
    
            for (int i = 0; i < game.word.length(); i++) {
                if (game.word[i] == letter) {
                    game.display[i] = letter;
                    found = true;
                }
            }
    
            if (!found) {
                std::cout << "Wrong.\n";
                game.tries--;
            } else {
                std::cout << "Correct.\n";
            }
        }
    
        drawHangman(game.tries);
    
        if (game.display == game.word) {
            std::cout << "You win! The word was: " << game.word << "\n";
            return true;
        } else {
            std::cout << "You lost! The word was: " << game.word << "\n";
            return false;
        }
    } 
};