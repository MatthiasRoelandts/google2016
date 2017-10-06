#pragma once

#include <string>

class Product {
        public:
                Product(int id, int weight);

                int getId() const;
                int getWeight() const;
                std::string toString();
                bool operator<(const Product&) const;
        private:
                int m_id;
                int m_weight;

};
