//
//  Test_Sort.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 06/04/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"

template <class T>
bool DocFile(T *&a, int n) {
    string tentaptin = "tap" + to_string(n) + ".txt";
    
    fstream f;
    f.open("/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/" + tentaptin, ios::in);
    
    a = new int[n];
    if (f) {
        int i = 0;
        while (!f.eof()) {
            f >> a[i];
            i++;
        }
        f.close();
        return true;
    }
    cout << "\nTap tin khong ton tai!!!";
    return false;
}

int main()
{
    int *m;
    int n;
    string ThuatToan = "Bubble Sort";
    
    cout << "\t\t\t\t\t\t" << ThuatToan;
    cout << "\nNhap ten tap can sap xep: tap";
    cin >> n;
    
    DocFile(m, n);
    
    fstream f;
    f.open("/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/KetQuaTest.txt", ios::out);
    
    f << "\t\t\t\t\t\t" << ThuatToan << endl;
    
    f << "\n\tTruoc khi sap xep: ";
    f << "\n\t";
    for (int i = 0; i < n; i++) {
        f << m[i] << "  ";
    }
    
    BubbleSort_CaiTien(m, n);
    f << "\n\tSau khi sap xep: ";
    f << "\n\t";
    for (int i = 0; i < n; i++) {
        f << m[i] << "  ";
    }
    
    f.close();
    
    cout << "\n+++++DONE+++++" << endl;
    
    return 0;
}
