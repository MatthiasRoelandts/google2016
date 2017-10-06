#include <iostream>

#include "Warehouse.h"

Warehouse::Warehouse(Point location, std::map<Product,int> stock) : m_location(location), m_stock(stock) {}

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
                m_stock.at(product) -= 1;
        } catch(std::out_of_range & e) {
                std::cerr << "Cannot Reserve item " << product.getId() << " in Warehouse " << m_id << '\n';
                throw;
        }
}
