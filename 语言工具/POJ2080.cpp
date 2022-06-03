/*
URL:http://poj.org/problem?id=2080
完成日期:2022.6.3
题目大意:日历
所用方法:...
*/
#include "iostream"
#include "iomanip"
#include "string"
using namespace std;
int day, w, nyear, nmonth, nday;
int monthofyear[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string dayofweek[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int main() {
    while (cin >> day, day != -1) {
        w = day % 7;
        nyear = 2000, nmonth = 1, nday = 1;
        while (day >= 365) {
            if ((nyear % 4 == 0 && nyear % 100 != 0) || nyear % 400 == 0) {
                if (day == 365)
                    break;
                day -= 366;
            } else day -= 365;
            nyear++;
        }
        if ((nyear % 4 == 0 && nyear % 100 != 0) || nyear % 400 == 0) monthofyear[2]++;
        while (day >= monthofyear[nmonth]) {
            day -= monthofyear[nmonth];
            nmonth++;
        }
        nday += day;
        if ((nyear % 4 == 0 && nyear % 100 != 0) || nyear % 400 == 0) monthofyear[2]--;
        cout << nyear << "-" << setw(2) << setfill('0') << right << nmonth << "-" << setw(2) << setfill('0') << right << nday << " " << dayofweek[w] << "\n";
    }
    return 0;
}