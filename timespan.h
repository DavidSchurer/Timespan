//Name: David Schurer
//Class: CSS 342
//Assignment 2: TimeSpan
#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>
using namespace std;

class TimeSpan {

    public:
        // Constructors for initializing hours, minutes, seconds in TimeSpan class
        TimeSpan();
        TimeSpan(float seconds);
        TimeSpan(float minutes, float seconds);
        TimeSpan(float hours, float minutes, float seconds);

        // Overloading output stream operator
        friend ostream& operator<<(ostream& out, const TimeSpan &ts);

        // Overloading relational operators
        bool operator>(TimeSpan const &ts) const;
        bool operator>=(TimeSpan const &ts) const;
        bool operator<(TimeSpan const &ts) const;
        bool operator<=(TimeSpan const &ts) const;
        bool operator==(TimeSpan const &ts) const;
        bool operator!=(TimeSpan const &ts) const;

        // Overloading arithmetic operators
        TimeSpan operator+(TimeSpan const &ts);
        TimeSpan operator+=(TimeSpan const &ts);
        TimeSpan operator-(TimeSpan const &ts);
        TimeSpan operator-=(TimeSpan const &ts);
        TimeSpan operator*(float value) const;

        // Function to properly format the hours, minutes, seconds, accounting for
        // overflow and negative values
        void setFormat();

    private:
        // Private variables for hours, minutes, seconds, to be stored in the TimeSpan class
        float seconds_;
        float minutes_;
        float hours_;
        

};

#endif
