#include "FruitUI.h"
#include <iostream>
#include <string>
using namespace UI;
using namespace std;

//FruitUI::FruitUI() {}
FruitUI::FruitUI(std::unique_ptr<FruitController> obj_ptr) {
    this->object = move(obj_ptr);
}

void FruitUI::title() {
    cout << "~~~~~~~FRUIT PROJECT~~~~~~~";
}

void FruitUI::menu() {
    cout << endl << "-----------------------------" << endl;
    cout << "1. Add a fruit" << endl;
    cout << "2. Remove a fruit" << endl;
    cout << "3. Print fruits" << endl;
    cout << "4. Find fruit by partial name or origin" << endl;
    cout << "5. Find low stock items" << endl;
    cout << "6. Sort fruit by expiration date" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------" << endl;

}

void FruitUI::initialize() {
//    Fruit fruit1("Mango", "Brazil", {2024, 6, 12}, 3, 5);
//    Fruit fruit2("Pear", "Hungary", {2024, 11, 24}, 5, 2);

    object->add("Mango", "Brazil", {2024, 6, 12}, 3, 5);
    object->add("Pear", "Hungary", {2024, 11, 24}, 5, 2);
    object->add("Apple", "Hungary", {2024, 12, 9}, 100, 1);
    object->add("Lime", "Egypt", {2025, 11, 13}, 14, 7);
    object->add("Lemon", "Egypt", {2025, 6, 2}, 11, 7);
    object->add("Banana", "Spain", {2024, 05, 26}, 4, 3);
}

void FruitUI::interface() {
    int number;

    do{
        menu();
        cout << endl << "Pick an option:  ";
        cin >> number;

        switch(number) {
            case 1:{
                string name, origin, input;
                int ammount, price, year, month, day;
                cout << "\nName of the fruit: ";
                cin >> name;
                cout << "\nOrigin of the fruit: ";
                cin >> origin;
                cout << "\nAmmount of the fruit: ";
                cin >> input;
                ammount = stoi(input);
                cout << "\nPrice of the fruit: ";
                cin >> input;
                price = stoi(input);
                cout << "\nDate of the fruit(year, month, day): ";
                cin >> input;   year = stoi(input);
                cin >> input;   month = stoi(input);
                cin >> input;   day = stoi(input);
                object->add(name, origin, {year, month, day}, ammount, price);

                cout << "Added fruit!" << endl;

                break;
            }
            case 2:{
                string name, origin;
                cout << endl << "Name of the fruit: ";
                cin >> name;
                cout << "\nOrigin of the fruit: ";
                cin >> origin;
                object->delete_func(name, origin);

                cout << "\nRemoved fruit!" << endl;

                break;
            }
            case 3:{
                vector<Fruit> final_list = object->print_all();
                if(final_list.empty()){
                    cout << "\nNo fruits added yet";
                }
                else{
                    cout << "\nAll fruits saved: ";
                    for(const Fruit& i : final_list) {
                        cout << "\n[ name: " << i.getFName();
                        cout << ", origin: " << i.getFOrigin();
                        cout << ", date: " << i.getFExpdate().year << "/" << i.getFExpdate().month << "/" << i.getFExpdate().day;
                        cout << ", ammount: " << i.getFAmmount();
                        cout << ", price: " << i.getFPrice() << " lei ]\n";
                    }
                }
                break;
            }
            case 4:{
                string substring;
                cout << endl << "Give a string to search by: ";
                cin >> substring;
                vector<Fruit> result = object->find_by_name(substring);
                if(result.empty()){
                    cout <<"\nNo results";
                }
                else{
                    cout << "\nAll results: ";
                    for(const Fruit& i : result){
                        cout << "\n[ name: " << i.getFName();
                        cout << ", origin: " << i.getFOrigin();
                        cout << ", date: " << i.getFExpdate().year << "/" << i.getFExpdate().month << "/" << i.getFExpdate().day;
                        cout << ", ammount: " << i.getFAmmount();
                        cout << ", price: " << i.getFPrice() << " lei ]\n";
                    }
                }
                break;
            }
            case 5:{
                int stock;
                cout << endl << "Give an ammount: ";
                cin >> stock;
                vector<Fruit> result = object->find_by_stock(stock);
                if(result.empty()){
                    cout << "\nNo results";
                }
                else{
                    cout << "\nAll results: ";
                    for(const Fruit& i : result){
                        cout << "\n[ name: " << i.getFName();
                        cout << ", origin: " << i.getFOrigin();
                        cout << ", date: " << i.getFExpdate().year << "/" << i.getFExpdate().month << "/" << i.getFExpdate().day;
                        cout << ", ammount: " << i.getFAmmount();
                        cout << ", price: " << i.getFPrice() << " lei ]\n";
                    }
                }
                break;
            }
            case 6: {
                vector<Fruit> result = object->sort_by_expdate();
                if (result.empty()) {
                    cout << "\nThere aren't any fruits yet!";
                }
                else {
                    cout << "\nSorting by expiration date: ";
                    for (const Fruit &i: result) {
                        cout << "\n[ name: " << i.getFName();
                        cout << ", origin: " << i.getFOrigin();
                        cout << ", date: " << i.getFExpdate().year << "/" << i.getFExpdate().month << "/"
                             << i.getFExpdate().day;
                        cout << ", ammount: " << i.getFAmmount();
                        cout << ", price: " << i.getFPrice() << " lei ]\n";
                    }
                    cout << endl << "DONE";
                }
                break;
            }
        }
    } while(number != 0);
}