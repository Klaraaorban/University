#include "Fruit.h"
using namespace Domain;
using namespace std;

Fruit::Fruit(const string &fName, const string &fOrigin, const Fruit::Date &exp_date, int fAmmount, int fPrice) {
    this->f_name = fName;
    this->f_origin = fOrigin;
    this->f_ammount = fAmmount;
    this->f_price = fPrice;
    this->exp_date = exp_date;

}
const string &Fruit::getFName() const {
    return f_name;
}

void Fruit::setFName(const string &fName) {
    f_name = fName;
}

const string &Fruit::getFOrigin() const {
    return f_origin;
}

void Fruit::setFOrigin(const string &fOrigin) {
    f_origin = fOrigin;
}

Fruit::Date Fruit::getFExpdate() const {
    return exp_date;
}

void Fruit::setFExpdate(int year, int month, int day) {
    exp_date.year = year;
    exp_date.month = month;
    exp_date.day = day;
}

int Fruit::getFAmmount() const {
    return f_ammount;
}

void Fruit::setFAmmount(int fAmmount) {
    f_ammount = fAmmount;
}

int Fruit::getFPrice() const {
    return f_price;
}

void Fruit::setFPrice(int fPrice) {
    f_price = fPrice;
}


