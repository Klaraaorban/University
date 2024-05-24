#ifndef L4_ORBAN_KLARA_FRUITCONTROLLER_H
#define L4_ORBAN_KLARA_FRUITCONTROLLER_H
#include "../Domain/Fruit.h"
#include "../Repository/FruitRepo.h"
#include <memory>
using namespace Repository;
namespace Controller {
    class FruitController {

    private:
        std::unique_ptr<FruitRepo> repo;
    public:

//    FruitRepo repo;
//    FruitController();
        FruitController(std::unique_ptr<FruitRepo> repo_ptr);

        void add(string name, string origin, const Fruit::Date &exp_date, int ammount, int price);

        void delete_func(string name, string origin);

        std::vector<Fruit> print_all();

        std::vector<Fruit> find_by_name(const string &substr);

        std::vector<Fruit> find_by_stock(const int &stock);

        std::vector<Fruit> sort_by_expdate();
    };
}

#endif //L4_ORBAN_KLARA_FRUITCONTROLLER_H
