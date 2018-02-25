#pragma once
#include "SubtractBigInt.h"
typedef pair< string , string > QR;
/** Kiểu dữ liệu QR
* Được định nghĩa bằng kiểu dữ liệu pair
* Lưu 1 cặp string
* Tác dụng lưu thương và số dư của phép chia
**/
//===================================//
ostream & operator << (ostream &out, QR qr){
    out<<qr.first<<" "<<qr.second;
    return out;
}
QR preDivide(string a, string b);
/** < Phụ > Hàm chia đơn 2 số lớn đơn giản
* Ý tưởng : a = q*b + r, bớt a đi q lần b cho tới khi đc a < b , lúc này a là số dư, q là thương
* Dùng hàm để tính các phép chia mà thương ko quá 10 vì thế rủi ro nhất là 9 phép trừ => O(n)
**/
//===================================//
QR divide(string a, string b);
/** < Chính > Phép chia 2 số lớn
* Ý tưởng chia bằng tay
* O(n*m)
**/
//===================================//

QR preDivide(string a, string b) // phép chia nhanh 2 số gần bằng nhau ( a > b và a.size == b.size hoặc a.size == b.size + 1)
{
    // O(n)
    char c='0';
    if(b == "1") return QR(a,"0");
    while ( cmp(a,b) != -1 ){ // chạy ko quá 9 vòng lặp
        c++;
        a= sub(a,b);
    }
    return QR(string()+c,a);
}
QR divide(string a, string b){
    string c, res;
    QR qr;
    for(int i=0;i<a.size();i++){
        if(c == "0") c= string();
        c+=a[i];
        qr= preDivide(c,b);
        res+= qr.first[0];
        c= qr.second;
    }
    int i;
    for(i=0;i< res.size()-1;i++)
        if(res[i]!= '0') break;
    if(i != 0) res= string(res.begin()+i,res.end());
    return QR(res,c);
}
