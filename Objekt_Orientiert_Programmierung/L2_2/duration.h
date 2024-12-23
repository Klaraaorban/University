#ifndef L2_ORBAN_KLARA_PROBLEM2_DURATION_H
#define L2_ORBAN_KLARA_PROBLEM2_DURATION_H
#include <string>
using namespace std;
class Duration {
private:
    string m_unit;
    double m_value;

public:
    Duration(string, double);
    double get_value() {return m_value;}
    const string& get_unit() {return m_unit;}

    Duration add(Duration other) const;
    Duration operator+(Duration other) const;       //usage of "+" instead of the function "add"
    Duration substract(Duration other) const;
    Duration operator-(Duration other) const;       //usage of "-" instead of the function "substract"
    void scale(double);
    void operator*(double);         //usage of "*" instead of the function "scale"
    void divide(double);
    void operator/(double);         //usage of "\" instead of the function "divide"
    string text();
    int compare(Duration other)const;
    void read();
    Duration convert(Duration other) const;     //convert every given unit into min --> this way all the functions work with minutes
};


#endif //L2_ORBAN_KLARA_PROBLEM2_DURATION_H
