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
    vector<string> ThuatToan;
    ThuatToan.push_back("Selection Sort");
    ThuatToan.push_back("Interchange Sort");
    int size_ThuatToan = ThuatToan.size();
    
    vector<int> TapDuLieu;
    TapDuLieu.push_back(100);
    TapDuLieu.push_back(1000);
    TapDuLieu.push_back(10000);
    TapDuLieu.push_back(50000);
    TapDuLieu.push_back(100000);
    int size_TapDuLieu = TapDuLieu.size();
    
    int SolanKiemTra = 3;

    double KetQuaTB[size_TapDuLieu][size_ThuatToan];
    
    fstream f;
    f.open("/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/KetQua.txt", ios::out);
    
    for (int i = 0; i < size_ThuatToan; i++) {
        
        f << "\t\t\t\t\t\t" << ThuatToan[i] << endl;
        
        f << setw(20) << left << "Tap du lieu";
        for (int m = 0; m < SolanKiemTra; m++) {
            f << setw(20) << "Lan " + to_string(m + 1);
        }
        f << setw(20) << "Trung binh" <<endl;
        
        for (int j = 0; j < size_TapDuLieu; j++) {
            double tong = 0;
            f << setw(20) << left << "tap" + to_string(TapDuLieu[j]);
            for (int k = 0; k < SolanKiemTra; k++) {
                int *a;
                if (DocFile(a, TapDuLieu[j])) {
                    clock_t start = clock();
                    switch (i) {
                        case 0:
                            SelectionSort(a, TapDuLieu[j]);
                            break;
                        case 1:
                            InterchangeSort(a, TapDuLieu[j]);
                            break;
                    }
                    clock_t end = clock();
                    double thoigian = (double)(end - start)/CLOCKS_PER_SEC;
                    tong += thoigian;
                    f << setw(20) << left << to_string(thoigian) + "s";
                }
                delete [] a;
            }
            KetQuaTB[j][i] = tong/SolanKiemTra;
            f << setw(20) << left << to_string(KetQuaTB[j][i]) + "s";
            f << endl;
        }
        f << endl;
    }
    
    f << "\t\t\t\t\t\tKet Qua Trung Binh" << endl;
    f << setw(20) << left << " ";
    for (int i = 0; i < size_ThuatToan; i++) {
        f << setw(30) << left << ThuatToan[i];
    }
    f << endl;
    for (int i = 0; i < size_TapDuLieu; i++) {
        f << setw(20) << left << "tap" + to_string(TapDuLieu[i]);
        for (int j = 0; j < size_ThuatToan; j++) {
            f << setw(30) << left << to_string(KetQuaTB[i][j]) + "s";
        }
        f << endl;
    }
    
    f.close();
    
    cout << "\n+++++DONE+++++" << endl;
    
    return 0;
}
