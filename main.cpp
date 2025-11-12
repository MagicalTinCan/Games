#include <iostream>
#include <cstdlib>
#include "export.h"


int main() {
    Export exportdat;
    exportdat.importData();
    //system("help");
    //std::cout << "test" << std::endl;
    exportdat.exportData();
    return 0;
}