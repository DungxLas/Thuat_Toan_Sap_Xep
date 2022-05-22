//
//  Tool_Test_Sort.h
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 22/05/2022.
//

#ifndef Tool_Test_Sort_h
#define Tool_Test_Sort_h

#include <iostream>
#include <ctime>
#include <algorithm>

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Linked_sample.h"

using namespace std;

template <class T>
void xuatMang(T *arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "    ";
    }
}

//Array
//Chi kiem tra sap xep tang
//Khoang radom so luong phan tu n ||nMin -> nMax||
template <class T>
void toolTestSort_array(void (*thuatToanSapxep)(T*, int, bool), int soTestCase, int nMin, int nMax, T resMin, T resMax)
{
    srand(time(NULL));
    for (int k = 0; k < soTestCase; ++k) {
        //Tao day so ngau nhien voi so luong n ngau nhien trong khoang nMin->nMax
         int n = rand() % (nMax - nMin + 1) + nMin;
         cout << "\nTest case[" << k <<"] (n = " << n << ")";
         
         //int n = 10;
         T *res = new T[n];
         //cout << "\nMang ban dau: ";
         for (int i = 0; i < n; i++) {
             res[i] = rand() % (resMax - resMin + 1) + resMin;
             //cout << res[i] << "    ";
         }
         
         T *ketquachinhxac = new T[n];
         for (int i = 0; i < n; i++) {
             ketquachinhxac[i] = res[i];
         }
         
         thuatToanSapxep(res, n, true);
         sort(ketquachinhxac, ketquachinhxac + n);
         
         //So Sanh Ket Qua
         bool check = true;
         for (int i = 0; i < n; ++i) {
             if (res[i] != ketquachinhxac[i]) {
                 check = false;
                 cout << "\nTest case sai o index: " << i << endl;
                 break;
             }
         }
         if (check == false) {
             cout << "\nMang ban dau: ";
             xuatMang(res, n);
             cout << "\nKet qua chinh xac sap tang: ";
             xuatMang(ketquachinhxac, n);
             cout << "\nTest case[" << k << "] khong pass" << endl;
             break;
         } else {
             cout << " => Pass test case" << endl;
         }
         
         delete [] res;
         delete [] ketquachinhxac;
    }
}

//Linked
//Chi kiem tra sap xep tang
//Khoang radom so luong phan tu n ||nMin -> nMax||
void toolTestSort_linked(void (*thuatToanSapxep)(list), int soTestCase, int nMin, int nMax, T resMin, T resMax)
{
    srand(time(NULL));
    for (int k = 0; k < soTestCase; ++k) {
        //Tao day so ngau nhien voi so luong n ngau nhien trong khoang nMin->nMax
         int n = rand() % (nMax - nMin + 1) + nMin;
         cout << "\nTest case[" << k <<"] (n = " << n << ")";
         
        list l;
         
         T *ketquachinhxac = new T[n];
         for (int i = 0; i < n; i++) {
             ketquachinhxac[i] = res[i];
         }
         
         thuatToanSapxep(res, n, true);
         sort(ketquachinhxac, ketquachinhxac + n);
         
         //So Sanh Ket Qua
         bool check = true;
         for (int i = 0; i < n; ++i) {
             if (res[i] != ketquachinhxac[i]) {
                 check = false;
                 cout << "\nTest case sai o index: " << i << endl;
                 break;
             }
         }
         if (check == false) {
             cout << "\nMang ban dau: ";
             xuatMang(res, n);
             cout << "\nKet qua chinh xac sap tang: ";
             xuatMang(ketquachinhxac, n);
             cout << "\nTest case[" << k << "] khong pass" << endl;
             break;
         } else {
             cout << " => Pass test case" << endl;
         }
         
         delete [] res;
         delete [] ketquachinhxac;
    }
}

#endif /* Tool_Test_Sort_h */
