#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <limits>
#include "Downloader.h"

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enableANSIColors() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void printAsciiLogo() {
    std::cout << "\033[1;36m" << R"(                                                                                            
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

)" << "\033[0m" << std::endl;
}

void logToConsole(const std::string& message) {
    std::cout << "\033[1;32m" << message << "\033[0m" << std::endl;
}

void progressToConsole(int percent) {
    std::cout << "\r\033[1;33mProgress: " << percent << "%    \033[0m" << std::flush;
    if (percent == 100) std::cout << std::endl;
}

int main() {
    enableANSIColors();
    printAsciiLogo();

    std::cout << "\033[1;34m*********************************************\033[0m" << std::endl;

    std::cout << "\033[1;36mEMERGENCY DOWNLOADER - LICENSE & USAGE\033[0m" << std::endl << std::endl;
    std::cout << "\033[0;37mThis software is licensed under the GNU GPL v3." << std::endl;
    std::cout << "It is provided 'as-is' without warranty of any kind.\033[0m" << std::endl << std::endl;

    std::cout << "\033[1;34m*********************************************\033[0m" << std::endl;

    std::cout << "\033[0;37mThis tool downloads the following security applications" << std::endl;
    std::cout << "directly from their official servers:\033[0m" << std::endl;
    std::cout << "\033[1;32m- Emsisoft Emergency Kit" << std::endl;
    std::cout << "- HitmanPro" << std::endl;
    std::cout << "- Kaspersky Virus Removal Tool (KVRT)" << std::endl;
    std::cout << "- ESET Online Scanner\033[0m" << std::endl << std::endl;

    std::cout << "\033[0;37mAll files are saved into the '\033[1;33mDownloadedFiles\033[0;37m' folder." << std::endl;
    std::cout << "Use responsibly. No warranty provided.\033[0m" << std::endl << std::endl;

    std::cout << "\033[0;90m# App icon by Flaticon.com\033[0m" << std::endl << std::endl;

    std::cout << "\033[1;35mPress 'Y' to accept and continue, or 'N' to exit.\033[0m" << std::endl;
    std::cout << "\033[1;34m*********************************************\033[0m" << std::endl;

    char choice;
    std::cin >> choice;
    if (choice != 'Y' && choice != 'y') {
        std::cout << "\033[1;31mProgram terminated.\033[0m" << std::endl;
        return 0;
    }

    std::string targetFolder = "DownloadedFiles";

    if (!std::filesystem::exists(targetFolder)) {
        std::filesystem::create_directory(targetFolder);
        std::cout << "\033[1;32mCreated folder: " << targetFolder << "\033[0m" << std::endl;
    }

    std::vector<std::string> urls = {
        "https://dl.emsisoft.com/EmsisoftEmergencyKit.exe",
        "https://download.sophos.com/endpoint/clients/HitmanPro_x64.exe",
        "https://devbuilds.s.kaspersky-labs.com/devbuilds/KVRT/latest/full/KVRT.exe",
        "https://download.eset.com/com/eset/tools/online_scanner/latest/esetonlinescanner.exe"
    };

    Downloader downloader(targetFolder);
    downloader.downloadAll(urls, logToConsole, progressToConsole);

    std::cout << std::endl << "\033[1;32mAll files have been successfully saved to '\033[4m" << targetFolder << "\033[24m'.\033[0m" << std::endl;
    std::cout << "\033[1;36mPress ENTER to exit...\033[0m";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
