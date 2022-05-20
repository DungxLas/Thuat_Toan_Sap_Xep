//
//  Test_Sort.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 17/05/2022.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"

using namespace std;

int main()
{
    toolTestSort<int>(ShakerSort, 500, 1, 20, 0, 100);//Chi kiem tra sap xep tang
    return 0;
}
