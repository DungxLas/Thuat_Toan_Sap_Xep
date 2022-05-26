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
#include <list>

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
             cout << "\nMang thuat toan sap xep: ";
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
template <class T>
void toolTestSort_Double_Linked(void (*thuatToanSapxep)(LIST_double&, bool), int soTestCase, int nMin, int nMax, T resMin, T resMax)
{
    srand(time(NULL));
    for (int k = 0; k < soTestCase; ++k) {
        //Tao day so ngau nhien voi so luong n ngau nhien trong khoang nMin->nMax
        int n = rand() % (nMax - nMin + 1) + nMin;
        cout << "\nTest case[" << k <<"] (n = " << n << ")";
         
        LIST_double l;
        init_double(l);
        
        for (int i = 0; i < n; ++i) {
            T res = rand() % (resMax - resMin + 1) + resMin;
            node_double *p = getNode_double(res);
            addTail_double(l, p);
        }
        //cout << "\nDanh sach tu tao: ";
        //outPut(l);
        
        list<T> ketquachinhxac;
        for (node_double *p = l.pHead; p != NULL; p = p->pNext) {
            ketquachinhxac.push_back(p->data);
        }
        //cout << "\nDanh sanh may tao: ";
        //for (list<int>::iterator it = ketquachinhxac.begin(); it != ketquachinhxac.end(); ++it) {
        //    cout << *it << "    ";
        //}
        
        thuatToanSapxep(l, true);
        ketquachinhxac.sort();
        
        //So Sanh Ket Qua
        bool check = true;
        list<int>::iterator it = ketquachinhxac.begin();
        for (node_double *p = l.pHead; p != NULL; p = p->pNext) {
            if (p->data != *it) {
                check = false;
                cout << "\nTest case sai o node: " << p->data << endl;
                break;
            }
            ++it;
        }
        if (check == false) {
            cout << "\nDanh sach thuat toan sap xep: ";
            outPut_double(l);
            cout << "\nKet qua chinh xac sap tang: ";
            for (list<int>::iterator it = ketquachinhxac.begin(); it != ketquachinhxac.end(); ++it) {
                cout << *it << "    ";
            }
            cout << "\nTest case[" << k << "] khong pass" << endl;
            break;
        } else {
            cout << " => Pass test case" << endl;
        }
        
        GiaiPhong_double(l);
        ketquachinhxac.clear();
    }
}

template <class T>
void toolTestSort_Single_Linked(void (*thuatToanSapxep)(LIST_single&, bool), int soTestCase, int nMin, int nMax, T resMin, T resMax)
{
    srand(time(NULL));
    for (int k = 0; k < soTestCase; ++k) {
        //Tao day so ngau nhien voi so luong n ngau nhien trong khoang nMin->nMax
        int n = rand() % (nMax - nMin + 1) + nMin;
        cout << "\nTest case[" << k <<"] (n = " << n << ")";
         
        LIST_single l;
        init_single(l);
        
        for (int i = 0; i < n; ++i) {
            T res = rand() % (resMax - resMin + 1) + resMin;
            node_single *p = getNode_single(res);
            addTail_single(l, p);
        }
        //cout << "\nDanh sach tu tao: ";
        //outPut(l);
        
        list<T> ketquachinhxac;
        for (node_single *p = l.pHead; p != NULL; p = p->pNext) {
            ketquachinhxac.push_back(p->data);
        }
        //cout << "\nDanh sanh may tao: ";
        //for (list<int>::iterator it = ketquachinhxac.begin(); it != ketquachinhxac.end(); ++it) {
        //    cout << *it << "    ";
        //}
        
        thuatToanSapxep(l, true);
        ketquachinhxac.sort();
        
        //So Sanh Ket Qua
        bool check = true;
        list<int>::iterator it = ketquachinhxac.begin();
        for (node_single *p = l.pHead; p != NULL; p = p->pNext) {
            if (p->data != *it) {
                check = false;
                cout << "\nTest case sai o node: " << p->data << endl;
                break;
            }
            ++it;
        }
        if (check == false) {
            cout << "\nDanh sach thuat toan sap xep: ";
            outPut_single(l);
            cout << "\nKet qua chinh xac sap tang: ";
            for (list<int>::iterator it = ketquachinhxac.begin(); it != ketquachinhxac.end(); ++it) {
                cout << *it << "    ";
            }
            cout << "\nTest case[" << k << "] khong pass" << endl;
            break;
        } else {
            cout << " => Pass test case" << endl;
        }
        
        GiaiPhong_single(l);
        ketquachinhxac.clear();
    }
}

#endif /* Tool_Test_Sort_h */
