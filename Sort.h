//
//  Sort.h
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 03/04/2022.
//

#ifndef Sort_h
#define Sort_h

#include <iostream>
#include <algorithm>

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Tool.h"

// SelectionSort
template <class T>
void SelectionSort(T *m, int n, bool kieusapxep = true) // kieusapxep là true: tăng - false: giảm
{
    for(int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Min bắt đầu từ i
    {
        int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i

        for(int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
        {
            if(m[j] < m[vitriMin] == kieusapxep) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
            {
                vitriMin = j; // cập nhật lại vị trí Min
            }
        }
        swap(m[i], m[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
    }
}

// SelectionSort_DeQuy_vs_Lap
template <class T>
void SelectionSort_DeQuy_vs_Lap(T *m, int n, bool kieusapxep = true) // kieusapxep là true: tăng - false: giảm
{
    if (n == 1) {
        return;
    }
    int vitriMax = 0;
    for(int j = 1; j < n; ++j)
    {
        if(m[j] > m[vitriMax] == kieusapxep)
        {
            vitriMax = j;
        }
    }
    swap(m[vitriMax], m[n - 1]);
    
    SelectionSort_DeQuy_vs_Lap(m, n - 1, kieusapxep);
}

// SelectionSort_2DeQuy
template <class T>
void TimViTriLonNhat(T *m, int n, int &vitriMax, bool kieusapxep)
{
    if (n == 1) {
        return;
    }
    if (m[n-1] > m[vitriMax] == kieusapxep) {
        vitriMax = n - 1;
    }
    TimViTriLonNhat(m, n - 1, vitriMax, kieusapxep);
}

template <class T>
void SelectionSort_2DeQuy(T *m, int n, bool kieusapxep = true) // kieusapxep là true: tăng - false: giảm
{
    if (n == 1) {
        return;
    }
    int vitriMax = 0;
    TimViTriLonNhat(m, n, vitriMax, kieusapxep);
    swap(m[vitriMax], m[n - 1]);
    
    SelectionSort_2DeQuy(m, n - 1, kieusapxep);
}

// SelectionSort_1DeQuy
template <class T>
void SelectionSort_1DeQuy(T *m, int n1, int n2, bool kieusapxep = true, int vitriMax = 0) // kieusapxep là true: tăng - false: giảm
{
    if (n1 == 1) {
        n1 = n2;
        swap(m[vitriMax], m[n1 - 1]);
        n1 = n2 = --n2;
        vitriMax = 0;
    }
    if (n2 == 1) {
        return;
    }
    if (m[n1-1] > m[vitriMax] == kieusapxep) {
        vitriMax = n1 - 1;
    }
    SelectionSort_1DeQuy(m, n1 - 1, n2, kieusapxep, vitriMax);
}

// InterchangeSort
template <class T>
void InterchangeSort(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    for (int i = 0; i < n -1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i] < m[j] == kieusapxep) {
                swap(m[i], m[j]);
            }
        }
    }
}

// InterchangeSort_DeQuy
template <class T>
void InterchangeSort_DeQuy(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    if (n == 1) {
        return;
    }
    for (int j = n - 2; j >= 0; j--) {
        if (m[n - 1] < m[j] == kieusapxep) {
            swap(m[n - 1], m[j]);
        }
    }
    InterchangeSort_DeQuy(m, n - 1, kieusapxep);
}

// BubbleSort
    //Thuong
template <class T>
void BubbleSort(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    for (int j = 0; j < n - 1; j++) {
        for (int i = n - 1; i > j; i--) {
            if (m[i - 1] > m[i] == kieusapxep) {
                swap(m[i - 1], m[i]);
            }
        }
    }
}
    //Cai tien
template <class T>
void BubbleSort_CaiTien(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    for (int j = 0; j < n - 1; j++) {
        bool check = true;
        for (int i = n - 1; i > j; i--) {
            if (m[i - 1] > m[i] == kieusapxep) {
                check = false;
                swap(m[i - 1], m[i]);
            }
        }
        if (check == true) {
            break;
        }
    }
}

// BubbleSort_DeQuy
template <class T>
void BubbleSort_DeQuy(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    if (n == 1) {
        return;
    }
    bool check = true;
    for (int i = 0; i < n - 1; i++) {
        if (m[i] > m[i + 1] == kieusapxep) {
            check = false;
            swap(m[i], m[i + 1]);
        }
    }
    if (check == true) {
        return;
    }
    BubbleSort_DeQuy(m, n - 1, kieusapxep);
}

// ShakerSort
template <class T>
void ShakerSort(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    int left = 0;
    int right = n - 1;
    int k = 0;
    while (left < right) {
        int temp_k = k;
        for (int i = right; i > left; i--) {
            if (m[i - 1] > m[i] == kieusapxep) {
                swap(m[i - 1], m[i]);
                k = i;
            }
        }
        if (temp_k == k) {
            break;
        }
        left = k;
        
        for (int i = left; i < right; i++) {
            if (m[i] > m[i + 1] == kieusapxep) {
                swap(m[i], m[i + 1]);
                k = i;
            }
        }
        right = k;
    }
}

// ShakerSort_CaiTien
template <class T>
void ShakerSort_CaiTien(T *m, int n, bool kieusapxep = true) { // kieusapxep là true: tăng - false: giảm
    int a = 0;
    int b = n - 1;
    bool check = true;
    while (true) {
        for (int i = a; i < b; i++) {
            if (m[i] > m[i + 1] == kieusapxep) {
                swap(m[i], m[i + 1]);
            }
        }
        if (check == true) {
            b--;
            check = false;
        } else {
            a++;
            check = true;
        }
        if (a == b) {
            break;
        }
    }
}

// InsertSort
template <class T>
void InsertionSort(T *m, int n) //Sap xep tang //Vs mang 1 chieu
{
    for (int i = 1; i < n; i++) {
        bool check = true;
        if (m[i] > m[i - 1]) {
            continue;
        }
        for (int j = i - 2; j >= 0; j--) {
            if (m[i] > m[j]) {
                Insert(m, j + 1, i);
                check = false;
                break;
            }
        }
        if (check == true) {
            Insert(m, 0, i);
        }
    }
}

#endif /* Sort_h */
