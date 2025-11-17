#include <iostream>
#include <filesystem>

#ifndef files_h
#define files_h

struct files {
    std::string gitRepository = "https://github.com/MagicalTinCan/Server.git";
    std::string gitRemoteName = "noTouchie";
    std::string localDirectory = "C:\\Users\\EGR126.03.CSCMERCER\\dataShtuff\\";
    std::string projectDirectory = std::filesystem::current_path().string() + "\\";
    std::string pythonInitalizer = projectDirectory + "initalizeData.py";
    std::string batchUploader = projectDirectory + "upload.bat";
};


#endif