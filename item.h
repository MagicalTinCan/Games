#include <iostream>

#ifndef item_h
#define item_h

struct item { //moved this out of item.h because its kinda pointless to have just this in a .h if its not used anywhere else.
    std::string name;
    double buyValue;
    double sellValue;
    int units;
};

#endif