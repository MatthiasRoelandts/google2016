

#include "World.h"

World::World(std::size_t max_turns) : m_max_turns(max_turns), m_current_turn(0) {}

void World::createDrones(std::size_t amount, std::size_t capacity) {
        Point startingLocation = m_warehouses.front().getLocation(); // If m_warehouses is empty, undefined.

        m_drones.reserve(amount);

        for(int i = 0; i < amount; i++) {
                m_drones.push_back(Drone(i,startingLocation,capacity));
        }
}

void World::addWarehouse(Warehouse warehouse) {
        m_warehouses.push_back(warehouse);
}

void World::createProducts(std::vector<std::size_t> weights) {
        m_products.reserve(weights.size());
        for(int i = 0; i < weights.size(); i++) {
                m_products.push_back(Product(i, weights[i]));
        }
}

void World::addOrder(Order order) {
        m_orders.push_back(order);
}

std::size_t World::getMaxTurns() const { return m_max_turns; }

// TODO getters


        
