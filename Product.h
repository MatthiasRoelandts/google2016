#pragma once


class Product {
        public:
                Product(int id, size_t weight);

                int getId() const;
                size_t getWeight() const;

        private:
                int m_id;
                size_t m_weight;

};
