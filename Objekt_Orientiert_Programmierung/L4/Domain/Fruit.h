#ifndef L4_ORBAN_KLARA_FRUIT_H
#define L4_ORBAN_KLARA_FRUIT_H
#include <string>
using namespace std;
namespace Domain {
    class Fruit {
    private:
        string f_name;
        string f_origin;
        //    int f_expdate;
        int f_ammount;
        int f_price;

    public:
        struct Date {
            int year;
            int month;
            int day;
        } exp_date{};

        Fruit(const string &fName, const string &fOrigin, const Date &exp_date, int fAmmount, int fPrice);

        const string &getFName() const;

        void setFName(const string &fName);

        const string &getFOrigin() const;

        void setFOrigin(const string &fOrigin);

        Date getFExpdate() const;

        void setFExpdate(int year, int month, int day);

        int getFAmmount() const;

        void setFAmmount(int fAmmount);

        int getFPrice() const;

        void setFPrice(int fPrice);

        void set_price(int set_price);
    };
}

#endif //L4_ORBAN_KLARA_FRUIT_H
