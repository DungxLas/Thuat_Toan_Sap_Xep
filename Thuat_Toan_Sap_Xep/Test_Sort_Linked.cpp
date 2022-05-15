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
    
int main()
{
    string ThuatToan = "Sort";
    cout << "\t\t\t\t\t\t" << ThuatToan;
    list l;
    init(l);
    inPut(l);

    cout << "\n\tTruoc khi sap xep: ";
    cout << "\n\t";
    for (node *p = l.pHead; p != NULL; p = p->pNext) {
        cout << p->data << "  ";
    }
    
    /*cout << "\n\tSau khi sap xep: ";
    cout << "\n\t";
    for (int i = 0; i < n; i++) {
        cout << m[i] << "  ";
    }*/
    
    cout << "\n+++++DONE+++++" << endl;
    
    return 0;
}

