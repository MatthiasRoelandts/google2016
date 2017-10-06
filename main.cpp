#include <fstream>

#include "ParseInput.h"

int main() {
    ParseInput parseInput;
    std::string theFile("inputfiles/simple.in");
    parseInput.parseFile(theFile);
}

