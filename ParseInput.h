#pragma once

#include <string>

#include "World.h"

class ParseInput {
    public:
        ParseInput() { m_world = nullptr; }
        World* parseFile(std::string);

    private:
        void parseWarehouse(int&, std::string&, std::string&);
        void parseProducts(int&, std::string&);
        void parseOrder(int&, std::string&, int&, std::string&);
        
        World *m_world;   
};

