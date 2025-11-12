#include <iostream>
#include <cstdlib>
#include "export.h"

int main() {
    Export exportdat;
    //exportdat.importData();
    //system("help");
    //std::cout << "test" << std::endl;
    exportdat.turn = 1;
    std::cout << 1;
    //exportdat.importData();
    std::cout << 2;
    exportdat.exportData();
    return 0;
}