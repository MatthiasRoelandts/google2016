#pragma once

#include <vector>
#include <map>

#include "Product.h"

class Warehouse {
        public:
                Warehouse(Point location, std::map<Product,int> stock);

                void addProduct(Product product);

                void reserveProduct(Product product);

        private:
                Point m_location;
                std::map<Product,int> stock;
};

