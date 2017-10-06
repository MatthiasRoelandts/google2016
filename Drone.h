#pragma once

//#include <size_t>
#include <vector>
#include <map>

#include "Point.h"

enum DroneState { FREE, BUSY, ACCEPTED };

typedef std::vector<std::pair<Warehouse*,std::vector<Product>>> OrderPlan;

class Warehouse;
class Order;

class Drone {
        public:
                Drone(int id, Point starting_location, int capacity);

                int getId() const;
                Point getLocation() const;
                int getCapacity() const;

                // Simulation
                void tick();

                // Order Processing
                void announce(std::vector<Order> &orders);
                void reannounce();
                void makeReservations();
                void accept(Order * order);
                void cancel();

                static bool hasUnaccepted(std::vector<Drone> &drones);
                static bool hasFree(std::vector<Drone> &drones);

        private:
                std::pair<int,OrderPlan> determineCost(Order &order);

                int m_id;
                Point m_location;
                int m_capacity;

                // State
                DroneState m_state;
                Order * m_accepted_order;
                OrderPlan m_order_plan;
                std::map<Order&,int> m_costs;
};
