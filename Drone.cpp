
#include <climits>

#include "Drone.h"
#include "Warehouse.h"
#include "Order.h"

Drone::Drone(int id, Point starting_location, int capacity) : m_id(id), m_location(starting_location), m_capacity(capacity) {}

int Drone::getId() const { return m_id; }

Point Drone::getLocation() const { return m_location; }

int Drone::getCapacity() const { return m_capacity; }

/*
// Simulation
void tick() {
        //TODO
}

// Order Processing
void Drone::announce(std::vector<Order> &orders) {
        // Only Free Drones offer
        if(m_state != FREE) {
                return;
        }

        m_costs.clear();
        int min_cost = INT_MAX;
        int optimal_order_id = -1;
        OrderPlan optimal_plan;
        // Loop over each order
        // If the order is not CLAIMED, keep track of personal cost to complete that order
        for(auto it : orders) {
                if(it.isClaimed()) {
                        continue;
                }
                int cost;
                OrderPlan plan;
                std::tie(cost,plan) = determineCost(it);
                if(cost < min_cost) {
                        min_cost = cost;
                        optimal_order_id = it.getId();
                        optimal_plan = plan;
                }
                m_costs.insert({it,cost});
        }

        // Make the offer to the best order
        for(auto it : orders) {
                if(it.getId() == optimal_order_id) {
                        it.makeOffer(*this, m_costs.at(it));
                        m_order_plan = optimal_plan;
                        // Remove from cost map
                        m_costs.erase(it);
                        break;
                }
        }

}

void Drone::reannounce() {
        // Only Free Drones reannounce
        if(m_state != FREE) {
                return;
        }

        // Remove next optimal order from map
        int min_cost = INT_MAX;
        int optimal_order_id = -1;
        for(auto e : m_costs) {
                if(e.second < min_cost) {
                        min_cost = e.second;
                        optimal_order_id = e.first.getId();
                }
        }
        // Make offer to that order
        for(auto e : m_costs) {
                if(e.first.getId() == optimal_order_id) {
                        m_order_plan = determineCost(e.first).second;
                        e.first.makeOffer(*this, min_cost);
                        
                        // Remove from cost map
                        m_costs.erase(e.first);
                        break;
                }
        }
}

void Drone::makeReservations() {
        //TODO take weight into account
        std::vector<std::pair<Warehouse*, Product>> history;
        // Loop over the plan
        for(auto e : m_order_plan) {
                for(auto it : e.second) {
                        try {
                                // At each warehouse, make reservations for its products
                                e.first->reserveProduct(it);
                                history.push_back(std::make_pair<Warehouse*,Product>(e.first,it));
                        } catch(OutOfStockException e) {
                        // If reservation fails, rollback previous reservations and cancel OFFER at order
                        for(auto it : history) {
                                it.first->addProduct(it.second);
                        }
                        m_accepted_order->reject();
                        m_accepted_order = nullptr;
                        m_order_plan.clear();
                        m_state = FREE;
                }
        }
}

void Drone::accept(Order *order) {
       // Only FREE drones can ACCEPT
       if(m_state == FREE) {
              m_state = ACCEPTED;
              m_accepted_order = order;
       } 
}

void Drone::cancel() {
        // Only an ACCEPTED drone can be cancelled
        if(m_state == ACCEPTED) {
                m_state = FREE;
        }
}

bool Drone::hasUnaccepted(std::vector<Drone> &drones) {
        for(auto it : drones) {
                if(it.m_state != ACCEPTED) {
                        return true;
                }
        }
        return false;
}

bool Drone::hasFree(std::vector<Drone> &drones) {
        for(auto it : drones) {
                if(it.m_state == FREE) {
                        return true;
                }
        }
        return false;
}

std::pair<int,OrderPlan> determineCost(Order &order) {
        // TODO
}
*/
