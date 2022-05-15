//
//  Test_Sort_Array.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 15/05/2022.
//

#include <iostream>
#include <string>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"

int main()
{
    int *m;
    int n;
    string ThuatToan = "Sort";
    
    cout << "\t\t\t\t\t\t" << ThuatToan;
    cout << "\nNhap so luong phan tu: ";
    cin >> n;
    
    m = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "phan tu vi tri " << i << ":";
        cin >> m[i];
    }
    
    cout << "\n\tTruoc khi sap xep: ";
    cout << "\n\t";
    for (int i = 0; i < n; i++) {
        cout << m[i] << "  ";
    }
    
    //ShakerSort(m, n);
    //ShakerSort(m, n);
    //Insert(m, 9, 2);
    InsertionSort(m, n);
    cout << "\n\tSau khi sap xep: ";
    cout << "\n\t";
    for (int i = 0; i < n; i++) {
        cout << m[i] << "  ";
    }
    
    delete [] m;
    
    cout << "\n+++++DONE+++++" << endl;
    
    return 0;
}

