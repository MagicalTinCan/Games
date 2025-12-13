#include <iostream>
#include "files.h"
/*

Tutorial thrown together by Samuel at 3:41 AM

Fun fact: this is the only program I've made entirely in onlinegdb.com, the rest are made in VSCode.

*/

/*
void clear() { //C++ throws a hissy fit if this is put in data.h, but doesn't if its here. Barbaric.
    std::cout << "Test" << std::endl; //clear removes all lines except for the very last one, dunno why.
    files Files;
    std::string clearCommand = Files.batchClear;
    system(clearCommand.c_str());
}
*/

void clear();

struct tutorial
{
    void inquireYerKnowledge() {
        std::string action;
        files Files;
        do {
            clear();                    //Turns out ANSI doesnt end at 47, sick.
            std::cout << "Welcome to the \033[93;1mwiki.\033[m\nWhat do you want to learn about?\n\n\t1) Accounts\n\t2) Base game\n\t3) Offline mode\n\t4) Other\n\tl) Leave wiki\n\n:";
            std::cin >> action;
            if (action == "1") {
                do {
                    clear();
                    std::cout << "Very well, what do you want to know about accounts?\n\n\t1) Where is my account stored?\n\t2) What is saved to my account (what gets collected)\n\t3) How do I make an account?\n\t4) How do I delete my account?\n\tl) leave division\n\n:";
                    std::cin >> action;
                    if (action == "1") {
                        clear();
                        std::cout << "Your account is saved both on a local folder \033[4mand\033[m on a remote repository.";
                        std::cin.get();
                        std::cin.get();
                    } else if (action == "2") {
                        clear();
                        std::cout << "Your account (and probably many others) will be stored under " + Files.localDirectory << std::endl;
                        std::cout << "Your offline account will be stored under " << Files.projectDirectory << std::endl;
                        std::cout << "Please do \033[91mnot\033[m attempt to mess with other peoples accounts. I do keep logs and I \033[1;4mwill\033[0m find out if you do.\n";
                        std::cin.get();
                        std::cin.get();
                        std::cout << "Your \033[3mown\033[m account is fair game though, do it at your own risk.";
                        std::cin.get();
                    } else if (action == "3") {
                        clear();
                        std::cout << "To make an account, exit back to the main menu and enter 1 to start making a new account.\nAfter that, you want to give it a username\nAfter that, secure your account with a password.\n\tAt the time of this wiki, passwords are still unencrypted, but please do not log into other peoples accounts without permission.\n";
                        std::cin.get();
                        std::cin.get();
                    } else if (action == "4") {
                        clear();
                        std::cout << "Unfortunately, there is no native way to do this, as I am still quite to lazy to make the tool to do it.\nSo for now, fiddle around with git.exe and delete it from your local repository.\nIf you do delete your account, or some other poor persons account by accident, and you want to reverse it, just download the data from prior commits and push the file again.\n";
                        std::cin.get();
                        std::cin.get();
                    }
                } while (action != "l");
                action = "blah";
            } else if  (action == "2") {
                do {
                    clear();
                    std::cout << "Very well, so you want to learn more about the game. Surprising you came to a wiki to do that, its rather thrilling you came.\nFlat humor aside, what do you want to know?\n\n\t1) The streets\n\t2) The market\n\t3) The casino\n\t4) The story\n\tl) Leave division\n\n:";
                    std::cin >> action;
                    if (action == "1") {
                        do {
                            clear();
                            std::cout << "Certainly.\nThe streets in the game is where you go initally to beg for some money.\nEach time you go to beg, you must play 3 minigames in order to recieve some cash.\nEach 3 minigames award you with 3-10 dollars\n\n\t1) Learn about the minigames\n\t2) Secret\n\tl) Leave subsection\n\n:";
                            std::cin >> action;
                            if (action == "1") {
                                do {
                                    clear();
                                    std::cout << "So the current minigames that pop up are:\n\t • Sokoban\n\t • Hangman\n\nWhat do you want to do?\n\n\t1) Look at Sokoban\n\t2) Look at hangman\n\tl) leave subsection\n\n:";
                                    std::cin >> action;
                                    if (action == "1") {
                                        clear();
                                        std::cout << "Sokoban is just one of those games people never remember the name to but know how to play it.\nTo play Sokoban, your player will be dropped on a flat grid with boxes, walls, holes, and gems.\nYour objective is to collect all the gems\nBoxes can be pushed if there is not an object (box, wall, or gem) behind it.\nBoxes can not be pulled.\nIf a box is pushed and there is a hole behind it, the box fills the hole and the player can walk on it.\n\nThe controls to playing are:\n\tW - Move up\n\tS - Move down\n\tA - move left\n\tD - move right\n\tL - leave the game\n\n";
                                        std::cin.get();
                                        std::cin.get();
                                    } else if (action == "2") {
                                        clear();
                                        std::cout << "In hangman, you're given a mystery word and your job is to guess it without killing your stick figure.\nIn each guess, you have to give a single letter. If that letters in the word, it gets revealed, if not, your stick figure is one step closer to dying." << std::endl;
                                        std::cout << "As for the specifics and the controls.\nThere are 339 unique words that can be randomly selected.\nYou get 6 attempts to guess the word.\nAny incorrect guesses will be saved, so don't worry about keeping track of incorrect guesses.\n";
                                        std::cin.get();
                                        std::cin.get();
                                    }
                                } while (action != "l");
                                action = "blah"; //Newtons 2nd law, for every blah, there is an equal and opposite blah. You're welcome universe.
                            } else if (action == "2") {
                                clear();
                                std::cout << "Every time you open or give an input to the console while in the streets, there is a chance for a mystery 3rd option to be avaliable" << std::endl;
                                std::cout << "This option is to scream at a nearby passing car.\nWhy is this in the game?";
                                std::cin.get();
                                std::cin.get();
                                std::cout << "I don't know. But I like to imagine adding in a little popup UI that states you earned the \"Delusional\" ending achievement.";
                                std::cin.get();
                            }
                        } while (action != "l");
                        action = "blah";
                    }
                } while (action != "l");
                action = "blah";
            } else if (action == "3") {
                clear();
                std::cout << "This game is intended to be played both on a network and offline.\nWhen you save your data, if you are on online mode, it will save to a server where you can log into your account from any computer.\nIn offline mode, your data is saved to a local file instead of a server.\nThis is good if you don't want to log into your github account or don't have internet access.";
                std::cin.get();
                std::cin.get();
            } else if (action == "4") {
                do {
                    clear();
                    std::cout << "Welcome to the 'others' division, where random junk I couldnt shove in a major division.\n\n\t1) Contributers\n\t2) Cool neat features\n\tl) leave division\n\n:";
                    std::cin >> action;
                    if (action == "1") {
                        clear();
                        std::cout << "---------------------------------\n|         Contributers          |\n|                               |\n|   Samuel Campbell - Sokoban   |\n|   Cayden Hendrix - Hangman    |\n|                               |\n|                               |\n|                               |\n|                               |\n|                               |\n|                               |\n---------------------------------";
                        std::cin.get();
                        std::cin.get();
                    } else if (action == "2") {
                        clear();
                        std::cout << "Some of the \033[38;2;255;0;0mc\033[38;2;255;165;0mo\033[38;2;255;255;0ml\033[38;2;0;255;0mo\033[38;2;0;0;255mr\033[38;2;255;0;255ms\033[m, \033[1mBoldness\033[m, \033[3mItalics\033[m and other \033[4mcool stuff\033[m" << std::endl;
                        std::cout << "was made possible by ANSI escape codes. Similar to how ASCII turns bits into letters, numbers, and most things printable like ♥ ♦ ♣ ♠ • (ASCII codes 3 thru 7)" << std::endl;
                        std::cout << "ANSI uses specific codes to determine how the console displays its output.\n\n";
                        std::cout << "ANSI lets you change:\n\t• \033[91mThe foreground aka text color\033[m\n\t• \033[103;30mThe background aka highlight text\033[m\n\t• \033[1mBoldness\n\t• \033[3mItalics\033[m\n\t• \033[4mUnderscores\033[m";
                        
                        std::cout << "\n\n";
                        
                        std::cout << "Side note, ANSI escape codes don't just work on C++, it works in any programming language.\nC#, Python, even the 2nd worst language just behind esoteric languages, Javascript, can use ANSI escape codes.";
                        
                        std::cin.get();
                        std::cin.get();
                    }
                } while (action != "l");
                action = "blah";
            }
        } while (action != "l");
    }
};