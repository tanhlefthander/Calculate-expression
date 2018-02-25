#pragma once
#include "LibBigInt.h"
string add (string a, string b);
/** < Chính > Hàm tính tổng 2 số dạng chuỗi
* Trả về tổng 2 số a và b
* Ý tưởng: cộng 2 số tiểu học
* O(n)
**/
string add (string a, string b){
    // O(n)
    balance(a,b);
    int sz= a.size(), flag=0;
    for(int i=sz-1; i>=0;i--){
        a[i]= a[i] + b[i] + flag - '0';
        flag =0;
        if(a[i]>'9'){
            flag= 1;
            a[i]-= 10;
        }
    }
    if(flag==1) a = "1" + a;
    return a;
}
