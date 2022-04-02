//
//  main.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 02/04/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Selection_Sort.h"
#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/InterChange_Sort.h"

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
    cout << "Tap tin khong ton tai!!!";
    return false;
}

int main()
{
    int n[5] = {100, 1000, 10000, 100000, 1000000} ;
    
    fstream f;
    f.open("/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/KetQua.txt", ios::out);
    f << "----------------------------   Selection Sort   ----------------------------" << endl;
    f << setw(20) << left << " " << setw(20) << "Lan 1" << setw(20) << "Lan 2" << setw(20) << "Lan 3" <<endl;
    
    for (int i = 0; i < 5; i++) {
        int *a;
        if (DocFile(a, n[i])) {
            f << setw(20) << left << "tap" + to_string(n[i]);
            for (int i = 1; i <= 3; i ++) {
                clock_t start = clock();
                SelectionSort(a, n[i]);
                //InterChangedSort(a, n);
                clock_t end = clock();
                double thoigian = (double)(end - start)/CLOCKS_PER_SEC;
                f << setw(20) << left << to_string(thoigian) + "s";
            }
            f << endl;
        }
        delete [] a;
    }
    cout << "+++++DONE+++++" << endl;
        
    f.close();
    
    
    
    return 0;
}
