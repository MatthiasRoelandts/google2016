#include <string>
#include <iostream>
#include <fstream>

#include "ParseInput.h"
#include "World.h"

void ParseInput::parseFile(std::string new_file) {
    std::ifstream theFile(new_file);
    if(theFile.is_open()) {
        std::string line;
        getline(theFile, line, ' ');
        std::cout << line << "\n"; 
        getline(theFile, line, ' ');
        std::cout << line << "\n"; 
        getline(theFile, line, ' ');
        std::cout << line << "\n"; 
        
        theFile.close();
    } else {
        std::cout << "could not open file \n";
    }
}

