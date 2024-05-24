#include <algorithm>
#include "FruitController.h"
using namespace Controller;

FruitController::FruitController(std::unique_ptr<FruitRepo> repo_ptr) {
    this->repo = std::move(repo_ptr);
}

void FruitController::add(std::string name, std::string origin, const Fruit::Date& exp_date, int ammount, int price) {
    Fruit fruit(name, origin, exp_date, ammount, price);
    repo->add(fruit);
}

void FruitController::delete_func(std::string name, std::string origin) {
    return repo->remove(name, origin);
}

std::vector<Fruit> FruitController::print_all() {
    return repo->get_all();
}

std::vector<Fruit> FruitController::find_by_name(const string &substr) {
    std::vector <Fruit> result;
    for(auto f: repo->get_all()){
        if(f.getFName().find(substr) != -1 || f.getFOrigin().find(substr) != -1){
            result.push_back(f);
        }
    }
    return result;
}

std::vector<Fruit> FruitController::find_by_stock(const int &stock) {
    std::vector<Fruit> result;
    for(auto f : repo->get_all()){
        if(f.getFAmmount() <= stock){
            result.push_back(f);
        }
    }
    return result;
}

std::vector<Fruit> FruitController::sort_by_expdate() {
    std::vector<Fruit> fruits = repo->get_all();
    std::sort(fruits.begin(), fruits.end(), [](const Fruit& f1, const Fruit& f2){
        if(f1.getFExpdate().year != f2.getFExpdate().year){
            return f1.getFExpdate().year < f2.getFExpdate().year;
        }
        else if(f1.getFExpdate().month != f2.getFExpdate().month){
            return f1.getFExpdate().month < f2.getFExpdate().month;
        }
        else {
            return f1.getFExpdate().day < f2.getFExpdate().day;
        }
    });
    return fruits;
}
