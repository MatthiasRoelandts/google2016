#include <iostream>

#include "World.h"
#include "Point.h"

World::World(int max_turns) : m_max_turns(max_turns), m_current_turn(0) {}
/*
void World::createDrones(int amount, int capacity) {
        Point startingLocation = m_warehouses.front().getLocation(); // If m_warehouses is empty, undefined.

        m_drones.reserve(amount);

        for(int i = 0; i < amount; i++) {
                m_drones.push_back(Drone(i,startingLocation,capacity));
        }
}*/

void World::addWarehouse(int id, int x, int y, std::vector<int> stock) {
        Point point(x, y);
        std::map<Product, int> productStock;
        for(int i = 0; i < stock.size(); i++) {
                productStock.insert(std::pair<Product, int> (m_products[i], stock[i]));
        }
        Warehouse wh(id, point, productStock);
        m_warehouses.push_back(wh);
}

void World::createProducts(std::vector<int> weights) {
        m_products.reserve(weights.size());
        for(int i = 0; i < weights.size(); i++) {
                m_products.push_back(Product(i, weights[i]));
        }
}
/*
void World::addOrder(Order order) {
        m_orders.push_back(order);
}*/

int World::getMaxTurns() const { return m_max_turns; }


void World::printWarehouses() {
        std::cout << "===Warehouses===\n";
        for(auto i : m_warehouses) {
                std::cout << i.toString() << "\n";
        }
}

void World::printProducts() {
        std::cout << "=== Products ===\n";
        for(auto i : m_products) {
                std::cout << i.toString() << "\n";
        }
}


// TODO getters

/*
// Simulation
void World::tick() {
        bool freeDrone = Drone::hasFree(getDrones());
        bool openOrder = Order::hasOpen(getOrders());

        // Continue while a drone is still free (not BUSY or ACCEPTED) and an order is still OPEN
        while(freeDrone && openOrder) {
                // Announce All open orders to all drones
                for(auto it : getDrones()) {
                        // Drones are either BUSY (and ignore announce) or OFFER to their best order
                        it.announce(getOrders());
                }

                for(auto it : getOrders()) {
                        // The order chooses which drone is the best (lowest cost) and ACCEPTS that drone
                        it.accept();
                }

                bool unacceptedDrone = Drone::hasUnaccepted(getDrones());
                // While a drone wasn't ACCEPTED and had other options, make more OFFERS
                while(unacceptedDrone) {
                        // If this OFFER is better for the order than current ACCEPT, RELEASE drone
                        for(auto it : getDrones()) {
                                it.reannounce();
                        }
                        for(auto it : getOrders()) {
                                it.accept();
                        }
                }

                // Each drone reserves his items at the chosen warehouses
                // TODO would be optimal if drones would be iterated over with the lowest achievable cost going first...
                // If a reserve fails (another drone beat them to it), then rollback previous reservations for that drone and cancel OFFER for its ORDER.
                for(auto it : getDrones()) {
                        it.makeReservations();
                }
        }
                                
        // All ACCEPTED orders are now CLAIMED and cannot be changed (static contract net protocol)
        // Tick Drones (reduce their BUSY counter) 
        for(auto it : getDrones()) {
                it.tick();
        }

        // End of turn
        ++m_current_turn;
}
*/
 
