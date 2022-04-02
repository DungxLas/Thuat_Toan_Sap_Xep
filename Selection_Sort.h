//
//  Selection_Sort.h
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 02/04/2022.
//

#ifndef Selection_Sort_h
#define Selection_Sort_h

#include <iostream>
#include <algorithm>

// kieusapxep là true: tăng - false: giảm
template <class T>
void SelectionSort(T *m, int n, bool kieusapxep = true)
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

#endif /* Selection_Sort_h */
