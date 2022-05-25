//
//  Linked_sample.h
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 22/05/2022.
//

#ifndef Linked_sample_h
#define Linked_sample_h

#include <iostream>
using namespace std;

//Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết
struct node_double
{
    int data;
    node_double *pNext;
    node_double *pRev;
};

struct node_single
{
    int data;
    node_single *pNext;
};

struct LIST_double
{
    node_double *pHead, *pTail;
};

struct LIST_single
{
    node_single *pHead, *pTail;
};

// Bước 2: Khởi tạo danh sách liên kết
void init_double(LIST_double &l)
{
    l.pHead = l.pTail = NULL;
}

void init_single(LIST_single &l)
{
    l.pHead = l.pTail = NULL;
}


// Bước 3: Tạo Node
node_double* getNode_double(int data)
{
    node_double *p = new node_double;
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

node_single* getNode_single(int data)
{
    node_single *p = new node_single;
    if (p == NULL) {
        cout << "\nBo Nho Day!!!";
        system("pause");
        return NULL;
    }
    p->data = data;
    p->pNext = NULL;
    
    return p;
}

// Bước 4: Thêm Node p vào đầu/Thêm Node p vào cuối trong danh sách liên kết
void addHead_double(LIST_double &l, node_double *p)
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

void addTail_double(LIST_double &l, node_double *p)
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

void addHead_single(LIST_single &l, node_single *p)
{
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail_single(LIST_single &l, node_single *p)
{
    if (l.pTail == NULL) {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Bước 5: Viết hàm InPut/OutPut
void inPut_double(LIST_double &l)
{
    init_double(l);
    
    int n;
    cout << "\nNhap vao so luong phan tu: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int data;
        cout << "\nNhap gia tri tai node " << i << ": ";
        cin >> data;
        
        node_double *p;
        p = getNode_double(data);
        addTail_double(l, p);
    }
}

void outPut_double(LIST_double l)
{
    cout << "\n";
    for (node_double *p = l.pHead; p != NULL; p = p ->pNext) {
        cout << p->data << "   ";
    }
}

void inPut_single(LIST_single &l)
{
    init_single(l);
    
    int n;
    cout << "\nNhap vao so luong phan tu: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int data;
        cout << "\nNhap gia tri tai node " << i << ": ";
        cin >> data;
        
        node_single *p;
        p = getNode_single(data);
        addTail_single(l, p);
    }
}

void outPut_single(LIST_single l)
{
    cout << "\n";
    for (node_single *p = l.pHead; p != NULL; p = p ->pNext) {
        cout << p->data << "   ";
    }
}

// Bước 6: Các thao tác

// Bước 7: Giải phóng danh sách liên kết
void GiaiPhong_double(LIST_double &l)
{
    node_double *p;
    while(l.pHead != NULL)
    {
        p = l.pHead; // Cho con trỏ p trỏ vào pHead
        l.pHead = l.pHead ->pNext; // pHead được trỏ sang Node bên cạnh
        delete p; // giải phóng con trỏ
    }
}

void GiaiPhong_single(LIST_single &l)
{
    node_single *p;
    while(l.pHead != NULL)
    {
        p = l.pHead; // Cho con trỏ p trỏ vào pHead
        l.pHead = l.pHead ->pNext; // pHead được trỏ sang Node bên cạnh
        delete p; // giải phóng con trỏ
    }
}

#endif /* Linked_sample_h */
