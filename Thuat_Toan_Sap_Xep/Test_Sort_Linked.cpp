//
//  Test_Sort_Linked.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 15/05/2022.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"

//Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết
struct node
{
    int data;
    node *pNext;
    node *pRev;
};

struct list
{
    node *pHead, *pTail;
};

// Bước 2: Khởi tạo danh sách liên kết
void init(list &l)
{
    l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node
node* getNode(int data)
{
    node *p = new node;
    if (p == NULL) {
        cout << "\nBo Nho Day!!!";
        system("pause");
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    p->pRev = NULL;
    
    return p;
}

// Bước 4: Thêm Node p vào đầu/Thêm Node p vào cuối trong danh sách liên kết
void addHead(list &l, node *p)
{
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead->pRev = p;
        l.pHead = p;
    }
}

void addTail(list &l, node *p)
{
    if (l.pTail == NULL) {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        p->pRev = l.pTail;
        l.pTail = p;
    }
}

// Bước 5: Viết hàm InPut/OutPut
void inPut(list &l)
{
    init(l);
    
    int n;
    cout << "\nNhap vao so luong phan tu: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int data;
        cout << "\nNhap gia tri tai node " << i << ": ";
        cin >> data;
        
        node *p;
        p = getNode(data);
        addTail(l, p);
    }
}

void outPut(list l)
{
    cout << "\n";
    for (node *p = l.pHead; p != NULL; p = p ->pNext) {
        cout << p->data << "   ";
    }
}

// Bước 6: Các thao tác


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

