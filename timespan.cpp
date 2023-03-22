//Name: David Schurer
//Class: CSS 342
//Assignment 2: TimeSpan
#include <iostream>
#include <cmath>
#include <iomanip>
#include "timespan.h"
using namespace std;

// Implementation for default constructor, initializes hours_, minutes_, and seconds_ to 0
TimeSpan::TimeSpan() {

    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;
}

// Implementation for constructor that takes in just 1 parameter: seconds
TimeSpan::TimeSpan(float seconds) {

    hours_ = 0;
    minutes_ = 0;
    seconds_ = seconds;
    
}

// Implementation for constructor that takes in 2 parameters: minutes, and seconds
TimeSpan::TimeSpan(float minutes, float seconds) {

    float temporary = round(minutes * 60 + seconds);
    hours_ = 0;
    minutes_ = (int) (temporary / 60) % 60;
    seconds_ = (int) temporary % 60;

}

// Implementation for constructor that takes in hours, minutes, seconds (3 parameters)
TimeSpan::TimeSpan(float hours, float minutes, float seconds) {

    float temporary = round(hours * 3600 + minutes * 60 + seconds); // temporary converts hours, minutes, and seconds into seconds
    hours_ = (int) (temporary / 3600) % 60; // This calculates the correct hours from all of the stored seconds
    minutes_ = (int) (temporary / 60) % 60; // This calculates the correct minutes from all of the stored seconds
    seconds_ = (int) temporary % 60; // This calculates the correct seconds from all of the stored seconds

}

// setFormat converts the given hours, minutes and seconds into seconds and
// stores it into float temporary, then hours_, minutes_, and seconds_
// obtain the correct calculated hours, minutes, seconds and stores that value
// back into each appropriate TimeSpan variable. These values are converted to int
// to ensure no decimal values are displayed.
void TimeSpan::setFormat() {

    float temporary = round(hours_ * 3600 + minutes_ * 60 + seconds_);
    hours_ = (int) (temporary / 3600) % 60;
    minutes_ = (int) (temporary / 60) % 60;
    seconds_ = (int) temporary % 60;

}


// Implementation for the overloaded << operator,
// displays the correctly formatted TimeSpan.
ostream& operator<<(ostream& out, const TimeSpan &ts) {

    out << ts.hours_ << ":" << setw(2) << setfill('0') << ts.minutes_ << ":" << setw(2) << setfill('0') << ts.seconds_;
    return out;

}

// Implementation for the overloaded > operator
bool TimeSpan::operator>(TimeSpan const &ts) const {

    float temporary = round(hours_ * 3600 + minutes_ * 60 + seconds_);

    float temporary2 = round(ts.hours_ * 3600 + ts.minutes_ * 60 + ts.seconds_);

    return temporary > temporary2;
}

// Implementation for the overloaded >= operator
bool TimeSpan::operator>=(TimeSpan const &ts) const {

    float temporary = round(hours_ * 3600 + minutes_ * 60 + seconds_);

    float temporary2 = round(ts.hours_ * 3600 + ts.minutes_ * 60 + ts.seconds_);

    return temporary >= temporary2;
}

// Implementation for the overloaded < operator
bool TimeSpan::operator<(TimeSpan const &ts) const {

    float temporary = round(hours_ * 3600 + minutes_ * 60 + seconds_);

    float temporary2 = round(ts.hours_ * 3600 + ts.minutes_ * 60 + ts.seconds_);

    return temporary < temporary2;
}

// Implementation for the overloaded <= operator
bool TimeSpan::operator<=(TimeSpan const &ts) const {

    float temporary = round(hours_ * 3600 + minutes_ * 60 + seconds_);

    float temporary2 = round(ts.hours_ * 3600 + ts.minutes_ * 60 + ts.seconds_);

    return temporary <= temporary2;
}

// Implementation for the overloaded == operator
bool TimeSpan::operator==(TimeSpan const &ts) const {
    
    return hours_ == ts.hours_ && minutes_ == ts.minutes_ && seconds_ == ts.seconds_;
}

// Implementation for the overloaded != operator
bool TimeSpan::operator!=(TimeSpan const &ts) const {

    return hours_ != ts.hours_ || minutes_ != ts.minutes_ || seconds_ != ts.seconds_;
}

// Implementation for the overloaded + operator
TimeSpan TimeSpan::operator+(TimeSpan const &ts) {

    TimeSpan sum;

    sum.hours_ = ts.hours_ + hours_;
    sum.minutes_ = ts.minutes_ + minutes_;
    sum.seconds_ = ts.seconds_ + seconds_;

    sum.setFormat();
    return sum;
}

// Implementation for the overloaded += operator
TimeSpan TimeSpan::operator+=(TimeSpan const &ts) {

   hours_ += ts.hours_;
   minutes_ += ts.minutes_;
   seconds_ += ts.seconds_;

   setFormat();
   return *this;
}

// Implementation for the overloaded - operator
TimeSpan TimeSpan::operator-(TimeSpan const &ts) {

    TimeSpan subtract;
    
    subtract.hours_ = hours_ - ts.hours_;
    subtract.minutes_ = minutes_ - ts.minutes_;
    subtract.seconds_ = seconds_ - ts.seconds_;

    subtract.setFormat();
    return subtract;

}

// Implementation for the overloaded -= operator
TimeSpan TimeSpan::operator-=(TimeSpan const &ts) {
 
    hours_ -= ts.hours_;
    minutes_ -= ts.minutes_;
    seconds_ -= ts.seconds_;

    setFormat();
    return *this;

}

// Implementation for the overloaded * operator
TimeSpan TimeSpan::operator*(float value) const {

    TimeSpan multiply;

    multiply.hours_ = hours_ * value;
    multiply.minutes_ = minutes_ * value;
    multiply.seconds_ = seconds_ * value;

    multiply.setFormat();
    return multiply;

}
