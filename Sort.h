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

// SelectionSort_DeQuy
template <class T>
void SelectionSort_DeQuy(T *m, int n, bool kieusapxep = true) // kieusapxep là true: tăng - false: giảm
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
    
    SelectionSort_DeQuy(m, n - 1, kieusapxep);
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

#endif /* Sort_h */
