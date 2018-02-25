#pragma once
#include "AddBigInt.h"
string mulChar(string a, char c);
/** < Phụ > Hàm nhân 1 số lớn (string) với  1 số có 1 chữ số (char)
* Trả về kiểu string là kết quả của phép tính
* Ý tưởng nhân như nhân tay
* O(n)
* Nơi gọi hàm: mul
**/
//===================================//
string mul(string a, string b);
/** < Chính > Hàm nhân 2 số lớn
* Ý tưởng dùng đệ quy để đưa phép nhân 2 số lớn thành nhân số lớn với số có 1 kí tự (mulChar)
* Công thức đệ quy : a * b = a * int(b/10) + a*(b%10)
* Sử dụng hàm : mulChar , add , divideBy10
* O(n.m)
**/
//===================================//

string mulChar(string a, char c){ // nhân 1 big number với số có 1 chữ số
    // O(n)
    if(c=='0') return "0";
    if(c=='1') return a;
    int flag= 0;
    for(int i=a.size()-1;i>=0;i--){
        a[i]= (a[i]-'0') * (c - '0') + flag;
        flag =0;
        if(a[i]>= 10){
            flag= a[i]/10;
            a[i]= a[i]%10 + '0';
        }else a[i]+= '0';
    }
    if( flag !=0) a= char(flag + '0') + a;
    return a;
}
string mul(string a, string b){ // thuật toán nhân
    // O(n*m)
    string kq;
    if(b.size()== 1 ) return mulChar(a,b[0]);
    kq= mul(a, divideBy10(b));
    kq= mulBy10(kq); // nhân 10
    kq= add(kq,mulChar(a,b[b.size()-1]));
    //cout<<"mul "<<a<<" "<<b<<" "<<kq<<endl;
    return kq;
}
