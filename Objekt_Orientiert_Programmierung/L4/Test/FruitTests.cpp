#include "FruitTests.h"
#include "../Controller/FruitController.h"
#include "../Domain/Fruit.h"
#include "../Repository/FruitRepo.h"
#include "../UI/FruitUI.h"
#include <cassert>
#include <iostream>

void FruitTests::test_domain() {
    Fruit f("Mango", "Brazil", {2024, 6, 12}, 3, 5);

    assert(f.getFName() == "Mango");
    assert(f.getFOrigin() == "Brazil");
    assert(f.getFExpdate().year == 2024);
    assert(f.getFExpdate().month == 6);
    assert(f.getFExpdate().day == 12);
    assert(f.getFAmmount() == 3);
    assert(f.getFPrice() == 5);

    f.setFName("mango");
    f.setFOrigin("brazil");
    f.setFExpdate(2024, 3, 22);
    f.setFAmmount(5);
    f.setFPrice(2);

    assert(f.getFName() == "mango");
    assert(f.getFOrigin() == "brazil");
    assert(f.getFExpdate().year == 2024);
    assert(f.getFExpdate().month == 3);
    assert(f.getFExpdate().day == 22);
    assert(f.getFAmmount() == 5);
    assert(f.getFPrice() == 2);

    std::cout << "Domain test passed";
}

void FruitTests::test_repo() {
    FruitRepo repo;
    Fruit f("Mango", "Brazil", {2024, 6, 12}, 3, 5);
    Fruit g("Pear", "Hungary", {2024, 11, 24}, 5, 2);

    repo.add(f);
    repo.add(g);

    std::vector<Fruit> results = repo.get_all();
    assert(results.size() == 2);
    assert(results[0].getFName() == f.getFName());
    assert(results[1].getFName() == g.getFName());

    repo.remove("Pear", "Hungray");
    results = repo.get_all();
    assert(results.size() == 1);

    cout << "Repo test passed";
}

//void FruitTests::test_controller() {
//    std::unique_ptr<FruitRepo> repo;
//    FruitController(std::unique_ptr<FruitRepo> repo);
//
//
//}