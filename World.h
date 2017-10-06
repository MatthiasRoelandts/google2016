#pragma once

#include <vector>

#include "Drone.h"
#include "Warehouse.h"
#include "Product.h"
#include "Order.h"

class World {
        public:
                World(int max_turns);

                // Creation
                /**
                 * Creates "amount" default initialised drones with carry capacity "capacity".
                 * These drones spawn at the location of the first warehouse. This warehouse should have been added before creating the drones!
                 *
                 * @pre addWarehouse(..) is called at least once.
                 * @post amount of drones are created
                 * @param amount The total amount of drones to create.
                 * @param capacity The carry capacity of the drones.
                 */
                void createDrones(int amount, int capacity);

                /**
                 * Add a warehouse to the world.
                 * @param warehouse The warehouse to add.
                 */
                void addWarehouse(int id, int x, int y, std::vector<int> stock);

                /**
                 * Creates weights.size() products. The weights vector should be ordered by product id. Each product of id "id" will have weight equal to weights[id].
                 * @param weights The ordered (by product id) of the different products.
                 */
                void createProducts(std::vector<int> weights);

                /**
                 * Adds an order to the world.
                 * @param order The order to add.
                 */
                void addOrder(int id, int x, int y, std::vector<int> products);

                // Getters
                int getMaxTurns() const;

                // TODO return iterators instead of vector ref
                std::vector<Drone> & getDrones() const;

                std::vector<Warehouse> & getWarehouses() const;

                std::vector<Product> & getProducts() const;

                std::vector<Order> & getOrders() const; 

                //print testing
                void printDrones();
                void printWarehouses();
                void printProducts();
                void printOrders();

                // Simulation
                void tick();

        private:
                int m_current_turn;
                int m_max_turns;
                std::vector<Drone> m_drones;
                std::vector<Warehouse> m_warehouses;
                std::vector<Product> m_products;
                std::vector<Order> m_orders;
};

