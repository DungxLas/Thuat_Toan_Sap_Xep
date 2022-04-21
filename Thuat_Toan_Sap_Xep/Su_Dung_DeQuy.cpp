//
//  Su_Dung_DeQuy.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 14/04/2022.
//

#include <iostream>
#include <ctime>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"

void phaiQuaTrai(int a[], int n) {
    if (n == 0) {
        return;
    }
    cout << a[n - 1] << "   ";
    phaiQuaTrai(a, n - 1);
}

void traiQuaPhai(int a[], int n) {
    if (n > 1) {
        traiQuaPhai(a, n - 1);
    }
    cout << a[n - 1] << "   ";
}

int main() {
    int *m;
    
    int n;
    cout << "\nNhap so luong phan tu: ";
    cin >> n;
    //int a, b;
    //cout << "\nNhap khong muon random: ";
    //cin >> a;
    //cout << " -> ";
    //cin >> b;
    
    cout << "\nDay so phat sinh trong tu 0 toi 10 la: ";
    
    m = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) {
        m[i] = rand() % (10 - 0 + 1) + 0;
        cout << m[i] << "   ";
    }
    
    //SelectionSort_DeQuy(m, n);
    //InterchangeSort_DeQuy(m, n);
    //BubbleSort_DeQuy(m, n);
    SelectionSort_1DeQuy(m, n, n);
    cout << "\nDay sau khi sap xep tang: ";
    for (int i = 0; i < n; i++) {
        cout << m[i] << "   ";
    }
    
    //SelectionSort_DeQuy(m, n, false);
    //InterchangeSort_DeQuy(m, n, false);
    //BubbleSort_DeQuy(m, n, false);
    SelectionSort_1DeQuy(m, n, n, false);
    cout << "\nDay sau khi sap xep giam: ";
    for (int i = 0; i < n; i++) {
        cout << m[i] << "   ";
    }
    
    return 0;
}
