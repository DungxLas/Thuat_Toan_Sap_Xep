//
//  Su_Dung_DeQuy.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 14/04/2022.
//

#include <iostream>
using namespace std;

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
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a)/sizeof(a[0]);
    traiQuaPhai(a, n);
    cout << endl;
    phaiQuaTrai(a, n);
    return 0;
}
