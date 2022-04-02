//
//  InterChange_Sort.h
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 02/04/2022.
//

#ifndef InterChange_Sort_h
#define InterChange_Sort_h

#include <iostream>
#include <algorithm>

// kieusapxep là true: tăng - false: giảm
template <class T>
void InterChangedSort(T *m, int n, bool kieusapxep = true) {
    for (int i = 0; i < n -1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i] < m[j] == kieusapxep) {
                swap(m[i], m[j]);
            }
        }
    }
}

#endif /* InterChange_Sort_h */
