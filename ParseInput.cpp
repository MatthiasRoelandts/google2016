#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <iterator>

#include "ParseInput.h"
#include "World.h"

World* ParseInput::parseFile(std::string new_file) {
    std::ifstream theFile(new_file);
    if(theFile.is_open()) {

        std::string line;
        getline(theFile, line);
        std::istringstream iss(line);
        std::vector<std::string> words((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
        std::string rows = words[0];
        std::string colums = words[1];
        int drones = atoi(words[2].c_str());
        int turns = atoi(words[3].c_str());
        int max_payload = atoi(words[4].c_str());
        m_world = new World(turns);
        getline(theFile, line);
        int amount_products = atoi(line.c_str());
        getline(theFile, line);
        parseProducts(amount_products, line);
        getline(theFile, line);
        int amount_warehouses = atoi(line.c_str());
        std::string firLineWH;
        std::string secLineWH;
        for (int i = 0; i < amount_warehouses; i++) {
            getline(theFile, line);
            firLineWH = line;
            getline(theFile, line);
            secLineWH = line;
            parseWarehouse(i, firLineWH, secLineWH);
        }
        //world->createDrones(drones, max_payload);
        getline(theFile, line);
        int amount_orders = atoi(line.c_str());
        std::string firstLineOrder;
        int secLineOrder;
        std::string thirdLineOrder;
        for (int i = 0; i< amount_orders; i++) {
            getline(theFile, line);
            firstLineOrder = line;
            getline(theFile, line);
            secLineOrder = atoi(line.c_str());
            getline(theFile, line);
            thirdLineOrder = line;
            parseOrder(i, firstLineOrder, secLineOrder, thirdLineOrder);
        }
        theFile.close();
    } else {
        std::cout << "could not open file \n";
    }
    return m_world;
}

void ParseInput::parseWarehouse(int& id, std::string& firstLine, std::string& secLine) {
    std::istringstream iss(firstLine);
    std::vector<std::string> location((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    int x = atoi(location[0].c_str()); 
    int y = atoi(location[1].c_str()); 
    std::istringstream iss2(secLine);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss2)), std::istream_iterator<std::string>());
    std::vector<int> stock;
    for(auto i : words) {
        stock.push_back(atoi(i.c_str()));
    }
    m_world->addWarehouse(id, x, y, stock);
}

void ParseInput::parseProducts(int& amount, std::string& line) {
    std::vector<int> weights;
    std::istringstream iss(line);
    std::vector<std::string> words((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());
    for(auto i : words) {
        weights.push_back(atoi(i.c_str()));
    }
    m_world->createProducts(weights);
}

void ParseInput::parseOrder(int& id, std::string& first,  int& sec, std::string& third) {
    std::istringstream iss1(first);
    std::vector<std::string> location((std::istream_iterator<std::string>(iss1)), std::istream_iterator<std::string>());
    std::istringstream iss2(third);
    std::vector<std::string> products((std::istream_iterator<std::string>(iss2)), std::istream_iterator<std::string>());
    int x = atoi(location[0].c_str()); 
    int y = atoi(location[1].c_str()); 
    std::vector<int> allProducts;
    for(auto i : products) {
        allProducts.push_back(atoi(i.c_str()));
    }
    //world->addOrder(id, x, y, allProducts);
}

