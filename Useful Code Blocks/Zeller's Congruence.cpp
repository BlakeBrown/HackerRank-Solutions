// Zeller's congruence: Returns an int representing the day
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