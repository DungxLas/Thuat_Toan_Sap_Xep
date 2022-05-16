//
//  Tool.h
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 14/05/2022.
//

#ifndef Tool_h
#define Tool_h

template <class T>
void Insert(T *m, int vitrichen, int vitrilay) // Chen so trong mang tu vi tri nay sang vi tri khac
{
    T temp = m[vitrilay];
    if (vitrilay > vitrichen) { //Chen phia truoc
        for (int i = vitrilay; i > vitrichen; i--) {
            m[i] = m[i - 1];
        }
    }else if (vitrilay < vitrichen) { //Chen phia sau
        for (int i = vitrilay; i < vitrichen; i++) {
            m[i] = m[i + 1];
        }
    }else {
        return;
    }
    m[vitrichen] = temp;
}

#endif /* Tool_h */
