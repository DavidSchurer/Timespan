//Name: David Schurer
//Class: CSS 342
//Assignment 2: TimeSpan
#include <iostream>
#include <sstream>
#include <cassert>
#include "TimeSpan.h"
using namespace std;

void myTest()
{

    cout << "########## TIMESPAN TEST CASES ##########" << endl;
    cout << endl;

    // Testing displaying TimeSpan objects
    cout << "Testing displaying TimeSpan objects (Positive Values)" << endl;

    stringstream stream;

    TimeSpan ts(2, 15, 40);
    TimeSpan ts2(9,44,22);

    stream.str("");
    stream << ts;
    assert(stream.str() == "2:15:40");
    cout << ts << endl;

    stream.str("");
    stream << ts2;
    assert(stream.str() == "9:44:22");
    cout << ts2 << endl;

    cout << endl;
    cout << "Testing displaying TimeSpan objects (Overflow and Negative Values)" << endl;

    TimeSpan ts3(6.8248, 7.223, 4.1123);
    TimeSpan ts4(3, -50, -2);

    stream.str("");
    stream << ts3;
    assert(stream.str() == "6:56:47");
    cout << ts3 << endl;

    stream.str("");
    stream << ts4;
    assert(stream.str() == "2:09:58");
    cout << ts4 << endl;

    cout << endl;

    // Testing adding TimeSpan objects
    cout << "Testing adding TimeSpan objects" << endl;

    stream.str("");
    stream << ts + ts2;
    assert(stream.str() == "12:00:02");
    cout << ts + ts2 << endl;

    stream.str("");
    stream << ts + ts3;
    assert(stream.str() == "9:12:27");
    cout << ts + ts3 << endl;

    stream.str("");
    stream << ts + ts4;
    assert(stream.str() == "4:25:38");
    cout << ts + ts4 << endl;

    cout << endl;

    // Testing subtracting TimeSpan objects
    cout << "Testing subtracting TimeSpan objects" << endl;

    TimeSpan ts5(30, 88, 65);
    TimeSpan ts6(4, -20, -90);
    TimeSpan ts7(1.5, 30.5, -90);
    TimeSpan ts8(29, 22, 11);

    stream.str("");
    stream << ts5 - ts6;
    assert(stream.str() == "27:50:35");
    cout << ts5 - ts6 << endl;

    stream.str("");
    stream << ts5 - ts7;
    assert(stream.str() == "29:30:05");
    cout << ts5 - ts7 << endl;

    stream.str("");
    stream << ts5 - ts8;
    assert(stream.str() == "2:06:54");
    cout << ts5 - ts8 << endl;

    cout << endl;

    // Testing += operator on TimeSpan objects
    cout << "Testing += operator on TimeSpan objects" << endl;

    stream.str("");
    ts5 += ts8;
    stream << ts5;
    assert(stream.str() == "0:51:16");
    cout << ts5 << endl;

    cout << endl;

    // Testing -= operator on TimeSpan objects
    cout << "Testing -= operator on TimeSpan objects" << endl;

    stream.str("");
    ts8 -= ts5;
    stream << ts8;
    assert(stream.str() == "28:30:55");
    cout << ts8 << endl;

    cout << endl;

    // Testing * operator on TimeSpan objects
    cout << "Testing * operator on TimeSpan objects" << endl;

    stream.str("");
    ts = ts * 2;
    stream << ts;
    assert(stream.str() == "4:31:20");
    cout << ts << endl;

    cout << endl;

    // Testing == operator on TimeSpan objects
    cout << "Testing == operator on TimeSpan objects" << endl;

    TimeSpan ts9(2, 25, 25);
    TimeSpan ts10(2, 25, 25);

    assert(ts9 == ts10);
    cout << "ts9 and ts10 are equal" << endl;

    cout << endl;

    // Testing != operator on TimeSpan objects
    cout << "Testing != operator on TimeSpan objects" << endl;

    TimeSpan ts11(3, 30, 40);
    TimeSpan ts12(4, 50, 2);

    assert(ts11 != ts12);
    cout << "ts11 and ts12 are not equal" << endl;

    cout << endl;

    // Testing < operator on TimeSpan objects
    cout << "Testing < operator on TimeSpan objects" << endl;
    TimeSpan ts13(1, 2, 3);
    TimeSpan ts14(14, 16, 28);

    assert(ts13 < ts14);
    cout << "ts13 is less than ts14" << endl;
    

    cout << endl;

    // Testing > operator on TimeSpan objects
    cout << "Testing > operator on TimeSpan objects" << endl;
    TimeSpan ts15(10, 20, 30);
    TimeSpan ts16(11, 55, 33);

    assert(ts16 > ts15);
    cout << "ts16 is greater than ts15" << endl;
    
    cout << endl;

    // Testing >= operator on TimeSpan objects
    cout << "Testing >= operator on TimeSpan objects" << endl;
    TimeSpan ts17(10, 10, 10);
    TimeSpan ts18(20, 20, 20);

    assert(ts18 >= ts17);
    cout << "ts18 is greater than or equal to ts17" << endl;

    cout << endl;

    // Testing <= operator on TimeSpan objects
    cout << "Testing <= operator on TimeSpan objects" << endl;
    TimeSpan ts19(35, 62, 8);
    TimeSpan ts20(11, 1, 5);

    assert(ts20 <= ts19);
    cout << "ts20 is less than or equal to ts19" << endl;
}

// testing constructor
void test1()
{
    TimeSpan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
    assert(ss.str() == "1:20:30");

    TimeSpan ts2(4, -20, -90);
    ss.str("");
    ss << ts2;
    assert(ss.str() == "3:38:30");

    TimeSpan ts3(1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    assert(ss.str() == "1:59:00");

    TimeSpan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    assert(ss.str() == "0:00:04");
}

// testing equality, addition, subtraction, multiplication
void test2()
{
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);
    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
}

void testAll()
{
    test1();
    test2();
    myTest();
}

int main()
{
    testAll();
    cout << endl;
    cout << "########## TEST CASES SUCCESSFULLY COMPLETED ##########" << std::endl;

    return 0;
}
