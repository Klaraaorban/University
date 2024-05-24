#include "FruitRepo.h"
#include <vector>
using namespace Repository;
//void FruitRepo::add(const Fruit& fruit) {
//    this->list.push_back(fruit);
//}
FruitRepo::FruitRepo() {}

void FruitRepo::add(const Fruit &new_fruit) {
    bool exist = false;
    for(Fruit& fruit : list){
        if(new_fruit.getFName() == fruit.getFName() && new_fruit.getFOrigin() == fruit.getFOrigin()){
            fruit.setFPrice(new_fruit.getFPrice() + fruit.getFPrice());
            fruit.setFAmmount(new_fruit.getFAmmount() + fruit.getFAmmount());
            if(fruit.getFExpdate().year < new_fruit.getFExpdate().year ){
                fruit.setFExpdate(new_fruit.getFExpdate().year, new_fruit.getFExpdate().month, new_fruit.getFExpdate().day);
            }
            if(fruit.getFExpdate().year == new_fruit.getFExpdate().year && fruit.getFExpdate().month < new_fruit.getFExpdate().month){
                fruit.setFExpdate(new_fruit.getFExpdate().year, new_fruit.getFExpdate().month, new_fruit.getFExpdate().day);
            }
            if(fruit.getFExpdate().year == new_fruit.getFExpdate().year && fruit.getFExpdate().month == new_fruit.getFExpdate().month && fruit.getFExpdate().day < new_fruit.getFExpdate().day){
                fruit.setFExpdate(new_fruit.getFExpdate().year, new_fruit.getFExpdate().month, new_fruit.getFExpdate().day);
            }
            exist = true;
            break;
        }
    }
    if(!exist){
        list.push_back(new_fruit);
    }
}

void FruitRepo::remove(const std::string &f_name, const std::string &f_origin) {
    for(auto i = list.begin(); i < list.end(); i++){
        if(i->getFName() == f_name && i->getFOrigin() == f_origin){
            list.erase(i);
        }
    }
}

vector<Fruit> FruitRepo::get_all() {
    return list;
}
