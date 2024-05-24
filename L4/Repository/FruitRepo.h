#ifndef L4_ORBAN_KLARA_FRUITREPO_H
#define L4_ORBAN_KLARA_FRUITREPO_H
#include <vector>
#include <string>
#include "../Domain/Fruit.h"
using namespace Domain;

namespace Repository {
    class FruitRepo {
    private:
        std::vector<Fruit> list;

    public:
        FruitRepo();

        void add(const Fruit &new_fruit);

        void remove(const string &f_name, const string &f_origin);

        vector<Fruit> get_all();

    };
}

#endif //L4_ORBAN_KLARA_FRUITREPO_H
