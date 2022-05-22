//
//  Test_Sort_Array.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 22/05/2022.
//

#include <iostream>

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"
#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Tool_Test_Sort.h"

using namespace std;

int main()
{
    toolTestSort_array<int>(ShakerSort, 500, 1, 20, 0, 100);//Chi kiem tra sap xep tang
    return 0;
}
