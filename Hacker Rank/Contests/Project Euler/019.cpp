#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Zeller's congruence    
// 0 = saturday, 1 = sunday, 2 = monday, 3 = tuesday, 4 = wednesday, 5 = thursday, 6 = friday
int dayOfTheWeek(long long year, long long month, long long day) {
    if(month == 1) {
       month = 13;
       year--;
     }
     if(month == 2) {
       month = 14;
       year--;
     }
     long long q = day;
     long long m = month;
     long long k = year % 100;
     long long j = year / 100;
     long long h = q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j;
     h = h % 7;
     return h;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        if(T < 0) {
            break;
        }
        long long sundays = 0, Y1, M1 , D1, Y2, M2 , D2;
        cin>>Y1>>M1>>D1>>Y2>>M2>>D2;
        // Add sundays from Y1 to Y2 including all months
        for(long long y = Y1; y <= Y2; y++) {
            for(long long m = 1; m <= 12; m++) {
                if(dayOfTheWeek(y, m, 1) == 1) {
                    sundays++;
                }
            }
        }
        // Remove sundays that occur in Y1 before M1 is reached
        for(long long m = 1; m <= M1; m++) {
            if(dayOfTheWeek(Y1, m, 1) == 1) {
                sundays--;
            }
        }
        // Remove sundays that occur in Y2 after M2 is reached
        for(long long m = M2+1; m <= 12; m++) {
            if(dayOfTheWeek(Y2, m, 1) == 1) {
                sundays--;
            }
        }
        // Add a sunday if Y1 M1 D1 is a sunday
        if(D1 == 1 && dayOfTheWeek(Y1, M1, 1) == 1) {
            sundays++;
        }
        cout<<sundays<<"\n";
    }
    return 0;
}