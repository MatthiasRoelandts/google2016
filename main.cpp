#include <fstream>

#include "ParseInput.h"

int main() {
    ParseInput parseInput;
    std::string theFile("inputfiles/simple.in");
    World * world = parseInput.parseFile(theFile);
    world->printWarehouses();
    //world->printProducts();
}

