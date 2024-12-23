#include <iostream>
#include "duration.h"
#include <string>
using namespace std;

Duration::Duration(string unit, double value) {
    m_unit = unit;
    m_value = value;
}

Duration Duration::convert(Duration other) const {
    if(m_unit != other.get_unit()){
        if(m_unit == "sec") {
            int mins = m_value / 60;
            double rest_seconds = m_value - (mins * 60);
            double final_min;
            final_min = mins + rest_seconds / 100;
            return Duration("min", final_min);
        }
        if(m_unit == "h") {
            int hour = m_value * 60;
            return Duration("min", hour);
        }
    }
    return Duration(m_unit, m_value);
}

Duration Duration::add(Duration other) const {
    if (m_unit == other.get_unit()) {
        double new_value = m_value + other.get_value();
        return Duration(m_unit, new_value);
    }

    return Duration("",0);
}

Duration Duration::operator+(Duration other) const {
    if (m_unit == other.get_unit()) {
        double new_value = m_value + other.get_value();
        return Duration(m_unit, new_value);
    }

    return Duration("",0);
}


Duration Duration::substract(Duration other) const {
    if (m_unit == other.get_unit()) {
        double new_value = m_value - other.get_value();
        return Duration(m_unit, new_value);
    }
    return Duration("",0);
}

Duration Duration::operator-(Duration other) const {
    if (m_unit == other.get_unit()) {
        double new_value = m_value - other.get_value();
        return Duration(m_unit, new_value);
    }
    return Duration("",0);
}


void Duration::scale(double number) {
    m_value *= number;
}

void Duration::operator*(double number){
    m_value *= number;
    cout << m_value;
}

void Duration::divide(double number ) {
    m_value /= number;
}

void Duration::operator/(double number) {
    m_value /= number;
    cout << m_value;
}

string Duration::text() {
    string str = to_string(m_value);
    int size=str.size();
    while(str[size-1]=='0')
    {
        size--;
    }
    str.resize(size);
    str = str + " " + m_unit;
    return str;
}

int Duration::compare(Duration other) const {
    if (m_unit == other.get_unit()){
        if(m_value < other.get_value())     return -1;
        if(m_value > other.get_value())     return 1;
        else return 0;
    }
    return 444;
}

void Duration::read()
{
    cout<<"UNIT: ";
    cin>>m_unit;
    cout << "VALUE: ";
    cin>> m_value;

}

