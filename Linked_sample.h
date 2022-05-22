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


#endif /* Linked_sample_h */
