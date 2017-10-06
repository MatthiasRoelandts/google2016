#pragma once

#include <map>

#include "Product.h"

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

