//
//  Test_Sort_Linked.cpp
//  Thuat_Toan_Sap_Xep
//
//  Created by PHẠM HÙNG DŨNG on 15/05/2022.
//

#include <iostream>
using namespace std;

#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Sort.h"
#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Linked_sample.h"
#include "/Users/phamhungdung/CoDe/C:C++/Thuat_Toan_Sap_Xep/Tool_Test_Sort.h"
    
int main()
{
    //toolTestSort_Double_Linked(InsertionSort_Double_Linked1, 100, 100, 200, -500, 500);
    //toolTestSort_Single_Linked(InsertionSort_Single_Linked1, 1000, 100, 200, -500, 500);
    //toolTestSort_Double_Linked(InsertionSort_Double_Linked2, 100, 100, 200, -500, 500);
    //toolTestSort_Single_Linked(InsertionSort_Single_Linked2, 10000, 100, 500, -500, 500);
    toolTestSort_Single_Linked(InsertionSort_Single_Linked2_CaiTien, 10000, 100, 500, -500, 500);

    
    cout << "\n+++++DONE+++++" << endl;
    
    return 0;
}

