#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
void balance (string &a, string &b);
/** < Phụ > Hàm cân bằng độ dài [void]
* Sử dụng tham chiếu để lưu sự thay đổi sau cân bằng
* Cân bằng 2 số dạng chuỗi bằng cách thêm các chữ số 0 vào trc chuỗi ngắn hơn
* Nơi gọi hàm: add , sub
**/
//===================================//
int cmp (string a, string b);
/** < Chính > Hàm so sánh [int]
* So sánh 2 số dạng chuỗi
* Trả về:
     0: a == b
     1: a > b
    -1: a < b
* O(n)
**/
//====================================//
string divideBy10 (string a);
/** < Phụ > Hàm chia 1 số lớn cho 10 lấy phần nguyên
* Trả về string là kết quả phép tính
* Ý tường bỏ đi chữ số cuối cùng
* O(1);
* Hàm sử dụng: mul, divide...
**/
//===================================//
string mulBy10(string a);
/** < Phụ > Hàm nhân 1 số lớn với 10
* Trả về string là kết quả phép tính
* Ý tường thêm chữ số 0 vào cuối cùng
* O(1);
* Hàm sử dụng : mul
**/
//===================================//
string randomChar( int length);
// Hàm lấy số lớn ngẫu nhiên có length chữ sô
//
//
//
//
void balance (string &a, string &b){ // làm cho 2 số thành cùng size bằng cách thêm những số 0 đàng trc số bé hơn
    int sz_a = a.size(), sz_b= b.size();
    if(sz_a > sz_b) b= string(sz_a- sz_b,'0') +b;
    else a= string(sz_b- sz_a,'0') +a;
}
//So sánh
int cmp (string a, string b){ // so sánh 2 số
    // O(n)
    int szA= a.size(), szB= b.size();
    if(szA> szB) return 1;
    if(szA< szB) return -1;
    for( int i=0;i< szA;i++){
        if(a[i]> b[i]) return 1;
        if(a[i]< b[i]) return -1;
    }
    return 0;
}
string divideBy10 (string a){
    if(a.size() == 1) return string("0");
    return string(a.begin(), a.end()-1);
}
string mulBy10(string a){
    a+='0';
    return a;
}
string randomChar( int length){
    /* initialize random seed: */
    srand (time(NULL));
    string s;
    while(s.size() != length){
        int x= rand() % 10;
        s+= char(x+ 48);
    }
    if(s[0]=='0'){
        while(s[0] == '0'){
            int x= rand() % 10;
            s[0]= x+ 48;
        }
    }
    return s;
}
