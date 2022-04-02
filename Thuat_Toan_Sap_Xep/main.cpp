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
    int n[4] = {100, 1000, 10000, 100000};
    double thoigiantb1[4];
    double thoigiantb2[4];
    int *a;
    
    fstream f;
    f.open("/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/KetQua.txt", ios::out);
    f << "-------------------------------------------Selection Sort------------------------------------------" << endl;
    f << setw(20) << left << " " << setw(20) << "Lan 1" << setw(20) << "Lan 2" << setw(20) << "Lan 3" << setw(20) << "Trung binh" <<endl;
    
    for (int i = 0; i < 4; i++) {
        if (DocFile(a, n[i])) {
            double tong = 0;
            f << setw(20) << left << "tap" + to_string(n[i]);
            for (int j = 1; j <= 3; j ++) {
                clock_t start = clock();
                SelectionSort(a, n[i]);
                //InterChangedSort(a, n);
                clock_t end = clock();
                double thoigian = (double)(end - start)/CLOCKS_PER_SEC;
                tong += thoigian;
                f << setw(20) << left << to_string(thoigian) + "s";
            }
            thoigiantb1[i] = tong/3;
            f << setw(20) << left << to_string(thoigiantb1[i]) + "s";
            f << endl;
        }
        delete [] a;
    }
    
    f << "------------------------------------------InterChanged Sort-----------------------------------------" << endl;
    f << setw(20) << left << " " << setw(20) << "Lan 1" << setw(20) << "Lan 2" << setw(20) << "Lan 3" << setw(20) << "Trung binh" <<endl;
    
    for (int i = 0; i < 4; i++) {
        if (DocFile(a, n[i])) {
            double tong = 0;
            f << setw(20) << left << "tap" + to_string(n[i]);
            for (int j = 1; j <= 3; j ++) {
                clock_t start = clock();
                InterChangedSort(a, n[i]);
                clock_t end = clock();
                double thoigian = (double)(end - start)/CLOCKS_PER_SEC;
                tong += thoigian;
                f << setw(20) << left << to_string(thoigian) + "s";
            }
            thoigiantb2[i] = tong/3;
            f << setw(20) << left << to_string(thoigiantb2[i]) + "s";
            f << endl;
        }
        delete [] a;
    }
    
    f << "-----------------------------------------Ket Qua Trung Binh----------------------------------------" << endl;
    f << setw(50) << right << "Selection Sort  " << "  InterChanged Sort" << endl;
    for (int i = 0; i < 4; i++) {
        f << setw(20) << left << "tap" + to_string(n[i]) << setw(30) << right << to_string(thoigiantb1[i]) + "s  " << "  " +to_string(thoigiantb2[i]) + "s" << endl;
    }
    
    cout << "+++++DONE+++++" << endl;
        
    f.close();
    
    
    
    return 0;
}
