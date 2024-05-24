#include <iostream>
#include "UI/FruitUI.h"
#include "Controller/FruitController.h"
#include "Repository/FruitRepo.h"
#include "Domain/Fruit.h"
#include <memory>
#include <vector>
using namespace UI;

int main() {

    std::unique_ptr<FruitRepo> repo = std::make_unique<FruitRepo>();
    std::unique_ptr<FruitController> obj = std::make_unique<FruitController>(std::move(repo));
//    std::unique_ptr<FruitController> obj = std::make_unique<FruitController>(repo);
    FruitUI user(std::move(obj));
    user.title();
    user.initialize();
    user.interface();

    return 0;
}
