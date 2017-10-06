#pragma once

#include <vector>

#include "Drone.h"
#include "Warehouse.h"
#include "Product.h"
#include "Order.h"

class World {
        public:
                World(std::size_t max_turns);

                // Creation
                void createDrones(std::size_t amount);

                void addWarehouse(Warehouse warehouse);

                void createProducts(std::vector<std::size_t> weights);

                void addOrder(Order order);

                // Getters
                std::size_t getMaxTurns() const;

                std::vector<Drone> & getDrones() const;

                std::vector<Warehouse> & getWarehouses() const;

                std::vector<Product> & getProducts() const;

                std::vector<Order> & getOrders() const; 

                // Simulation
                void tick();

        private:
                std::size_t m_current_turn;
                std::size_t m_max_turns;
                std::vector<Drone> m_drones;
                std::vector<Warehouse> m_warehouses;
                std::vector<Product> m_products;
                std::vector<Order> m_orders;
};
