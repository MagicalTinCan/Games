#include <iostream>
#include <cstdlib>
#include "data.h"

int main() {
    data Data;
    std::cout << "Before initalize" << std::endl;
    Data.initalizeData();
    std::cout << "After initalize, before export" << std::endl;
    Data.exportData();
    std::cout << "After export" << std::endl;
    return 0;
}