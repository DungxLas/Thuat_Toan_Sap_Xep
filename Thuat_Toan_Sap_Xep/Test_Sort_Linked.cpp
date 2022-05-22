//
//  Test_Sort_Linked.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 15/05/2022.
//

#include <iostream>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Linked_sample.h"

//Sap xep tang
void InsertionSort_Linked(list &l) //Sap xep tang //Vs danh sach lien ket
{
    for (node *p = l.pHead->pNext; p != NULL; p = p->pNext) { //Duyet tu vi tri ngay sau pHead den ngay truoc pTail
        node *i = p->pRev; //i la node truoc node p
        node *j = p == l.pTail ? NULL : p->pNext; //j la node sau node p
        if (p->data > i->data) { //So sanh node p voi node truoc no la node i
            continue;
        }
        if (p->data < l.pHead->data) { //So sanh node p voi node pHead
            //Lay node p ra khoi danh sach khi dang o giua node i va j
            i->pNext = p == l.pTail ? NULL : j;
            if (p != l.pTail) {
                j->pRev = i;
            }
            l.pTail = p == l.pTail ? i : l.pTail;
            p->pNext = NULL;
            p->pRev = NULL;
            //Dat node p vao dau danh sach
            addHead(l, p);
            //Gan p lai vi tri cu (tuc la i) de tiep tuc duyet
            p = i;
            continue;
        }
        for (node *q = i->pRev; q != NULL; q = q->pRev) { //So sanh node p vs node truoc no, tinh tu node truoc p 2 vi tri den node sau pHead 1 vi tri
            if (p->data > q->data) {
                //Lay node p ra khoi danh sach khi dang o giua node i va j
                i->pNext = p == l.pTail ? NULL : j;
                if (p != l.pTail) {
                    j->pRev = i;
                }
                l.pTail = p == l.pTail ? i : l.pTail;
                p->pNext = NULL;
                p->pRev = NULL;
                //Dat node p vao sau sau q
                node *k = q->pNext;
                q->pNext = p;
                p->pRev = q;
                p->pNext = k;
                k->pRev = p;
                //Gan p lai vi tri cu (tuc la i) de tiep tuc duyet
                p = i;
                break;
            }
        }
    }
}

    
int main()
{
    string ThuatToan = "Sort";
    cout << "\t\t\t\t\t\t" << ThuatToan;
    list l;
    inPut(l);

    cout << "\n\tTruoc khi sap xep: ";
    outPut(l);
    
    InsertionSort_Linked(l);
    cout << "\n\tSau khi sap xep: ";
    outPut(l);
    
    cout << "\n+++++DONE+++++" << endl;
    
    return 0;
}

