#include <iostream>
using namespace std;

struct MyTime {
    int h, m, s;
};

void addTime(MyTime t1, MyTime t2, MyTime& t3) {
    int total_s = t1.s + t2.s;
    int total_m = t1.m + t2.m + (total_s / 60);

    t3.s = total_s % 60;
    t3.m = total_m % 60;
    t3.h = t1.h + t2.h + (total_m / 60);
    
}

int main() {
    MyTime t1 = {1, 40, 50}; 
    MyTime t2 = {2, 30, 20}; 
    MyTime result;
    
  
    addTime(t1, t2, result); 
    
    cout << "방법 2 결과: " << result.h << "시 " << result.m << "분 " << result.s << "초" << endl;
    
    return 0;
}