#include <iostream>
#include <ctime>

using namespace std;

class Clock
{
protected:
    int hr, min, sec, is_pm;
public:
    Clock ();
    virtual void setClock () = 0;
    void readClock (int& h, int& s,  int& m, bool& pm);
};

class Calendar
{
protected:
    int mo, day, yr;
public:
    Calendar ();
    virtual void setCalendar () = 0;
    void readCalendar (int& d, int& m,  int& y);
};

class ClockCalendar : public Clock, public Calendar
{
public:
    ClockCalendar ();
    void setClock();
    void setCalendar();
    void readClock(int& h, int& s,  int& m, bool& pm);
    void readCalendar (int& d, int& m,  int& y);
};
