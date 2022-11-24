#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    time_t now = time(0); // get current date and time

    cout << "Number of seconds since January 1,2021 is:: " << now << endl;

    tm* ltm = localtime(&now);

    // print various components of tm structure.
    cout << "Year:" << 1900 + ltm->tm_year << endl; // print the year
    cout << "Month: " << 1 + ltm->tm_mon << endl; // print month number
    cout << "Day: " << ltm->tm_mday << endl; // print the day
    // Print time in hour:minute:second
    cout << "Time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
}
