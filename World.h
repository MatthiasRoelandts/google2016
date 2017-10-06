#pragma once



class World {
        public:
                World(size_t max_turns);

                // Creation
                void createDrones(size_t amount);

                void addWarehouse(Warehouse warehouse);

                void createProducts(std::vector<size_t> weights);

                void addOrder(Order order);

                // Getters
                size_t getMaxTurns() const;

                std::vector<Drone> & getDrones() const;

                std::vector<Warehouse> & getWarehouses() const;

                std::vector<Product> & getProducts() const;

                std::vector<Order> & getOrders() const; 

        private:
                size_t m_max_turns;
                std::vector<Drone> m_drones;
                std::vector<Warehouse> m_warehouses;
                std::vector<Product> m_products;
                std::vector<Order> m_orders;
};
