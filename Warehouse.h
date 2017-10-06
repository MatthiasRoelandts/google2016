#pragma once

#include <map>
#include <string>

#include "Product.h"
#include "Point.h"

class OutOfStockException : public std::exception {
        public: 
                OutOfStockException(int item_id, int warehouse_id) : m_item_id(item_id), m_warehouse_id(warehouse_id) {}
        virtual const char* what() const throw() {
                //return "Not enough stock of item " + m_item_id + " at warehouse " + m_warehouse_id;
                return "not enough stock";
        }

        private:
                int m_item_id, m_warehouse_id;
};

class Warehouse {
        public:
                Warehouse(int id, Point location, std::map<Product,int> stock);

                int getId() const;

                Point getLocation() const;

                void addProduct(Product product);

                void reserveProduct(Product product);

                int getItemCount(Product product);
                std::string toString();

        private:
                int m_id;
                Point m_location;
                std::map<Product,int> m_stock;
};

