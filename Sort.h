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
using namespace std;


#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Linked_sample.h"

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
void InsertionSort1(T *m, int n, bool kieusapxep = true) //Sap xep tang //Vs mang 1 chieu
{
    for (int i = 1; i < n; i++) {
        T x = m[i];
        bool check = false;
        
        for (int j = i - 1; j >= 0; j--) {
            if (x < m[j] == kieusapxep) {
                m[j + 1] = m[j]; //m[j] nhich qua ben phai 1 o
            }
            else {
                m[j + 1] = x;
                check = true;
                break;
            }
        }
        if (check == false) {
            m[0] = x;
        }
    }
}

template <class T>
void InsertionSort2(T *m, int n, bool kieusapxep = true) //Sap xep tang //Vs mang 1 chieu
{
    for (int i = 1; i < n; i++) {
        T x = m[i];
        
        int j = i - 1;
        while (j >= 0 && (x < m[j] == kieusapxep)) {
            m[j + 1] = m[j];
            j--;
        }
        m[j + 1] = x;
    }
}

void InsertionSort_Double_Linked1(LIST_double &l, bool saptang = true) //true la tang //Vs danh sach lien ket doi
{
    for (node_double *i = l.pHead->pNext; i != NULL; i = i->pNext) { //Duyet tu vi tri ngay sau pHead den ngay truoc pTail
        int x = i->data;
        
        node_double *j = i->pPrev;
        while (j != NULL && (saptang == true ? x <= j->data : x >= j->data)) {
            j->pNext->data = j->data;
            j = j->pPrev;
        }
        if (j != NULL) {
            j->pNext->data = x;
        } else {
            l.pHead->data = x;
        }
    }
}

void InsertionSort_Double_Linked2(LIST_double &l, bool saptang = true) //true la tang //Vs danh sach lien ket doi
{
    for (node_double *i = l.pHead->pNext; i != NULL; i = i->pNext) { //Duyet tu vi tri ngay sau pHead den ngay truoc pTail
        node_double *k = i->pPrev;
        if (i->data > k->data) {
            continue;
        }
        node_double *j = i->pPrev->pPrev;
        while (j != NULL && (saptang == true ? i->data <= j->data : i->data >= j->data)) {
            j = j->pPrev;
        }
        tachNode_double(l, i);
        if (j == NULL) {
            addHead_double(l, i);
        } else {
            themNode_double(l, i, j);
        }
        i = k;
    }
}

void InsertionSort_Single_Linked1(LIST_single &l, bool saptang = true) //Sap xep tang //Vs danh sach lien ket don
{
    for (node_single *i = l.pHead->pNext; i != NULL; i = i->pNext) { //Duyet tu vi tri ngay sau pHead den ngay truoc pTail
        int x = i->data;
        
        for (node_single *j = l.pHead; j != i; j = j->pNext) {
            if (saptang == true ? x <= j->data : x >= j->data) {
                int y = j->data;
                int z;
                for (node_single *k = j->pNext; k != i->pNext; k = k->pNext) {
                    z = k->data;
                    k->data = y;
                    y = z;
                }
                j->data = x;
                break;
            }
        }
    }
}

void InsertionSort_Single_Linked2(LIST_single &l, bool saptang = true) //Sap xep tang //Vs danh sach lien ket don
{
    for (node_single *i = l.pHead->pNext; i != NULL; i = i->pNext) { //Duyet tu vi tri ngay sau pHead den ngay truoc pTail
        node_single *next_i = i->pNext;
        
        node_single *pre_j = NULL;
        node_single *j = l.pHead;
        while (j != i && (saptang == true ? i->data >= j->data : i->data <= j->data)) {
            pre_j = j;
            j =j->pNext;
        }
        if (j == l.pHead) {
            tachNode_single(l, i);
            addHead_single(l, i);
        } else if (j == i) {
            continue;
        } else {
            tachNode_single(l, i);
            themNode_single(l, i, pre_j);
        }
        
        node_single *pre_i = NULL;
        node_single *k = l.pHead;
        while (k != next_i) {
            pre_i = k;
            k = k->pNext;
        }
        i = pre_i;
    }
}

#endif /* Sort_h */
