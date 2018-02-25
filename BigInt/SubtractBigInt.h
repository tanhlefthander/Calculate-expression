#pragma once
#include "LibBigInt.h"
string sub (string a, string b);
/** < Chính > Hàm tính hiệu 2 số dạng chuỗi
* Trả về hiệu 2 số a và b (mặc định lấy trị tuyệt đối)
* Ý tưởng: trừ 2 số tiểu học
* O(n)
**/
string sub(string a, string b){ // trừ , mặc định trả về kết quả dương
    // O(n)
    balance(a,b);
    if(a<b) swap(a,b);
    int sz= a.size(), flag=0;
    for(int i=sz-1; i>=0;i--){
        a[i]= a[i] - b[i] - flag + '0';
        flag =0;
        if(a[i]<'0'){
            flag= 1;
            a[i]+= 10;
        }
    }
    int i=0;
    for(; i< sz; i++) if(a[i]!= '0') break;
    if(i == sz) return "0";
    if(i != 0) return string(a.begin()+i, a.end());
    return a;
}
