//
//  main.cpp
//  Phat_Sinh_Day_So
//
//  Created by PHẠM HÙNG DŨNG on 02/04/2022.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

static void PhatSinhDaySo(int n, int a, int b) {
    string tentaptin = "tap" + to_string(n);
    fstream f;
    f.open("/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/" + tentaptin + ".txt", ios::out);
    
    int res;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        res = rand() % (b - a + 1) + a;
        //cout << res << "    ";
        f << res << endl;
    }
    cout << "\ndu lieu da duoc ghi vao " << tentaptin << endl;
    
    f.close();
}

int main()
{
    PhatSinhDaySo(10, -100, 100);
    PhatSinhDaySo(100, -100, 100);
    PhatSinhDaySo(1000, -100, 100);
    PhatSinhDaySo(10000, -100, 100);
    PhatSinhDaySo(50000, -100, 100);
    PhatSinhDaySo(100000, -100, 100);
    return 0;
}
