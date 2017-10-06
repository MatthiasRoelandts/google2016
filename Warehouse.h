#pragma once

#include <map>

#include "Product.h"

class OutOfStockException : public exception {
        public: 
                OutOfStockException(int item_id, int warehouse_id) : m_item_id(item_id), m_warehouse_id(warehouse_id) {}
        virtual const char* what() const throw() {
                return "Not enough stock of item " + m_item_id + " at warehouse " + m_warehouse_id;
        }

        private:
                int m_item_id, m_warehouse_id;
}

class Warehouse {
        public:
                Warehouse(int id, Point location, std::map<Product,int> stock);

                int getId() const;

                Point getLocation() const;

                void addProduct(Product product);

                void reserveProduct(Product product);

        private:
                int m_id;
                Point m_location;
                std::map<Product,int> m_stock;
};

