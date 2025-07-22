#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "Downloader.h"

void printAsciiLogo() {
    std::cout << R"(                                                                                            
     _____                                   ____                _           _         
    |   __|_____ ___ ___ ___ ___ ___ ___ _ _|    \ ___ _ _ _ ___| |___ ___ _| |___ ___ 
    |   __|     | -_|  _| . | -_|   |  _| | |  |  | . | | | |   | | . | .'| . | -_|  _|
    |_____|_|_|_|___|_| |_  |___|_|_|___|_  |____/|___|_____|_|_|_|___|__,|___|___|_|  
                        |___|           |___|                                          
                                                                                    
     _                      _     _       _                                            
    | |_ _ _    ___ ___ ___|_|___| |_ ___|_|___ ___ ___                                
    | . | | |  | -_| . | . | |_ -|  _| . | |- _|- _| .'|                               
    |___|_  |  |___|_  |___|_|___|_| |  _|_|___|___|__,|                               
        |___|      |___|             |_|                                               

)" << std::endl;
}

void logToConsole(const std::string& message) {
    std::cout << message << std::endl;
}

void progressToConsole(int percent) {
    std::cout << "\rProgress: " << percent << "%    " << std::flush;
}

int main() {
    printAsciiLogo();

    std::cout << "*********************************************" << std::endl;

    std::cout << "EMERGENCY DOWNLOADER - LICENSE & USAGE" << std::endl << std::endl;
    std::cout << "This software is licensed under the GNU GPL v3." << std::endl;
    std::cout << "It is provided 'as-is' without warranty of any kind." << std::endl << std::endl;

    std::cout << "*********************************************" << std::endl;

    std::cout << "This tool downloads the following security applications" << std::endl;
    std::cout << "directly from their official servers:" << std::endl;
    std::cout << "- RKill" << std::endl;
    std::cout << "- Emsisoft Emergency Kit" << std::endl;
    std::cout << "- HitmanPro" << std::endl;
    std::cout << "- Kaspersky Virus Removal Tool (KVRT)" << std::endl;
    std::cout << "- ESET Online Scanner" << std::endl << std::endl;

    std::cout << "All files are saved into the 'DownloadedFiles' folder." << std::endl;
    std::cout << "Use responsibly. No warranty provided." << std::endl << std::endl;

    std::cout << "# App icon by Flaticon.com" << std::endl << std::endl;

    std::cout << "Press 'Y' to accept and continue, or 'N' to exit." << std::endl;
    
    std::cout << "*********************************************" << std::endl;


    char choice;
    std::cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        std::cout << "Program terminated." << std::endl;
        return 0;
    }

    std::string targetFolder = "DownloadedFiles";

    if (!std::filesystem::exists(targetFolder)) {
        std::filesystem::create_directory(targetFolder);
        std::cout << "Created folder: " << targetFolder << std::endl;
    }

    std::vector<std::string> urls = {
        "https://download.bleepingcomputer.com/dl/7bef92650de84dc39c6a134d5363ec82666c9677ea9473eba50acd9bea739774/687edc57/windows/security/security-utilities/r/rkill/rkill.exe",
        "https://dl.emsisoft.com/EmsisoftEmergencyKit.exe",
        "https://download.sophos.com/endpoint/clients/HitmanPro_x64.exe",
        "https://devbuilds.s.kaspersky-labs.com/devbuilds/KVRT/latest/full/KVRT.exe",
        "https://download.eset.com/com/eset/tools/online_scanner/latest/esetonlinescanner.exe"
    };

    Downloader downloader(targetFolder);
    downloader.downloadAll(urls, logToConsole, progressToConsole);

    std::cout << std::endl << "All files have been successfully saved to '" << targetFolder << "'." << std::endl;
    std::cout << "Application is terminating." << std::endl;

    return 0;
}
