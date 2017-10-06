#include <iostream>

#include "Warehouse.h"

Warehouse::Warehouse(int item_id, Point location, std::map<Product,int> stock) : m_id(item_id), m_location(location), m_stock(stock) {}

int Warehouse::getId() const {
        return m_id;
}

void Warehouse::addProduct(Product product) {
        try {
                m_stock.at(product) += 1;
        } catch(std::out_of_range & e) {
                m_stock.insert({product,1});
        }
}

void Warehouse::reserveProduct(Product product) {
        try {
                int & stock = m_stock.at(product);
                if(stock == 0) {
                        throw OutOfStockException(product.getId(), getId());
                } else {
                        m_stock.at(product) -= 1;
                }
        } catch(std::out_of_range & e) {
                std::cerr << "Cannot Reserve item " << product.getId() << " in Warehouse " << m_id << '\n';
                throw;
        }
}

Point Warehouse::getLocation() const {
        return m_location;
}

std::string Warehouse::toString() {
        std::string returnString =  "id: " + std::to_string(m_id) + " " +  m_location.toString() + "\n" + "== Products ==\n";
        for(auto i : m_stock) {
                returnString += "\tid: " + std::to_string(i.first.getId()) + " amount: " + std::to_string(i.second) + "\n"; 
        }
        return returnString;
}
