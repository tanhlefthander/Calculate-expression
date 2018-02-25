#pragma once
#include "MultiplyBigInt.h"
bool isEven(string a);
/** < Phụ > Hàm kiểm tra số chẵn
* Kiểm tra kí tự cuối cùng
* O(1)
**/
//===================================//
string divideBy2( string s);
/** < Phụ > Hàm chia đôi
* O(n)
**/
//===================================//
string pow(string a,string b);
/** < Chính > Hàm lũy thừa
* Ý tưởng a^b = a^(int(b/2)) * a^(b%2)
* O(m.n.logb)
**/
//===================================//
bool isEven(string a){ // kiểm tra số chẵn
    char c= a[a.size()-1];
    if(c%2 == 0) return true;
    return false;
}
string divideBy2( string s){ // chia đôi
    // O(n)
    if(s.size()==1 && s[0]<='1') return "0";
    int flag= 0,c,i=0;
    if(s[0] < '2'){
        i++;
        flag = s[0] - 48;
    }
    string res;
    for(i; i<s.size();i++){
        c= s[i] -48 + flag*10;
        flag= c%2;
        c= c/2;
        res += c+ 48;
    }
    if(res == string()) res= "0";
    return res;
}
string pow(string a,string b){
    // a^b ý tưởng giảm giần mũ đi 2 lần
    //O(n*m*log b) // log b phep nhan
    if(b=="2") return mul(a,a);
    if(b=="1") return a;
    string x= pow(a,divideBy2(b));
    x= mul(x,x);
    if(!isEven(b)) x= mul(x,a);
    return x;
}
