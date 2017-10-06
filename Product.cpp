#include "Product.h"

Product::Product(int id, int weight) : m_id(id), m_weight(weight) {
}

int Product::getId() const {
        return m_id;
}

std::string Product::toString() {
        return "id: " + std::to_string(m_id) + " weight: " + std::to_string(m_weight);
}

bool Product::operator<(const Product& product2) const{
        return m_id < product2.getId();
}

