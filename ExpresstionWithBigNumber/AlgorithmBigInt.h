#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef pair< string , string > QR;
char changeD(char d){ // đổi dấu
    if(d=='+') return '-';
    return '+';
}
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
string add (string a, string b){ // tổng 2 số
    // O(n)
    int sz_a = a.size(), sz_b= b.size();
    if(sz_a > sz_b) b= string(sz_a- sz_b,'0') +b;
    else a= string(sz_b- sz_a,'0') +a;
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
string sub(string a, string b){ // trừ
    // O(n)
    int sz_a = a.size(), sz_b= b.size();
    if(sz_a > sz_b) b= string(sz_a- sz_b,'0') +b;
    else a= string(sz_b- sz_a,'0') +a;
    if(a < b) swap(a,b);
    int sz= a.size(), flag=0;
    for(int i=sz-1; i>=0;i--){
        a[i]= a[i] - b[i] - flag + '0';
        flag =0;
        if(a[i]<'0'){
            flag= 1;
            a[i]+= 10;
        }
    }
    int i;
    for(i=0; i< sz; i++) if(a[i]!= '0') break;
    if(i!= 0) return string(a.begin()+i, a.end());
    return a;
}
string divide2( string s){ // chia đôi
    // O(n)
    if(s.size()==1 && s[0]<='0') return "0";
    int c;
    int flag= 0;
    for(int i=0; i<s.size();i++){
        c= s[i] -48 + flag*10;
        flag = 0;
        if(c%2==1) flag= 1;
        c= c/2;
        s[i]= c+ 48;
    }
    int i=0;
    if(s[0]=='0'&& s.size()>1) i=1;
    return string (s.begin() +i, s.end());
}
bool isEven(string a){ // kiểm tra số chẵn
    char c= a[a.size()-1];
    if(c%2 == 0) return true;
    return false;
}
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
string divide10 (string a){
    if(cmp(a,"10")== -1) return "0";
    return string(a.begin(), a.end()-1);
}
string mul10(string a){
    a+='0';
    return a;
}
string mul(string a, string b){ // thuật toán nhân
    // O(n*m)
    string kq;
    if(a.size()< b.size())
        swap(a,b);
    if(b.size()== 1 ) return mulChar(a,b[0]);
    kq= mul(a, divide10(b));
    kq= mul10(kq); // nhân 10
    kq= add(kq,mulChar(a,b[b.size()-1]));
    //cout<<"mul "<<a<<" "<<b<<" "<<kq<<endl;
    return kq;
}
string mulLogb(string a, string b){ // thuật toán nhân băng cách giảm dần đi 2 l
    // O(nlogb)
    string kq;
    if(a.size()< b.size())
        swap(a,b);
    if(b=="1") return a;
    if(b=="0") return "0";
    kq= mulLogb(a, divide2(b));
    kq= add(kq,kq);
    if(!isEven(b)) kq= add(kq,a);
    return kq;
}
QR preDivide(string a, string b) // phép chia nhanh 2 số gần bằng nhau ( a > b và a.size == b.size hoặc a.size == b.size + 1)
{
    // tìm 1 số lớn nhất có 1 chữ số khi nhân với b đc kết quả gần a nhất
    // vì 2 số này gần bằng nhau nên ta sẽ thực hiện phép trừ để tìm kết quả (rủi ro cao nhất là 9 phép trừ)
    // O(n)
    char c='0';
    while ( cmp(a,b) >= 0 ){ // chạy ko quá 9 vòng lặp
        c++;
        a= sub(a,b);
    }
    return QR(string()+c,a);
}
QR divide(string a, string b){
    // O(n^2) ý tưởng dựa vào phép chia tay
    int i=b.size();
    if(b == "1") return QR(a,"0");
    if(cmp(a,b)== -1) return QR("0",a);
    string x(a.begin(),a.begin()+ i),res; // lấy trước x sao cho x.size = b.size
    //cout<<x<<endl;
    QR qr=preDivide(x,b);
    x= qr.second;
    res+= qr.first;
    while(i != a.size()){ // lấy x
        if(x=="0") x= string();
        x+= a[i++];
        qr= preDivide(x,b);
        x= qr.second;
        res+= qr.first;
        //cout<<x<<" "<<res<<endl;
    }

    if(x=="") x="0";
    for(i=0; i<res.size();i++)
        if(res[i]!= '0') break;
    if(i == 0) return QR(res,x);
    return QR(string(res.begin()+ i, res.end()),x);
}
string pow2(string a, string b){ // a^b ý tưởng giảm giần mũ đi 2 lần
    //O(n*m*log b)
    //cout<<a<<" "<<b<<endl;
    if(b=="0") return "1";
    if(b=="2") return mul(a,a);
    if(b=="1") return a;
    string x= pow2(a,divide2(b));
    x= mul(x,x);
    if(!isEven(b)) x= mul(x,a);
    //cout<<a<<" "<<b<<" "<<x<<endl;
    a.clear();
    b.clear();
    return x;
}
string pow10(string a, string b){ // a^b ý tưởng giảm dần mũ đi 10 lần
    //O(n*m*m*log10)
    if(cmp(b,"10")== 0 ||b.size()== 1 ) return pow2(a,b);
    string x= pow10(a,divide10(b));
    x= pow2(x,"10");
    char c = b[b.size()-1];
    if(c!='0') x= mul(x,pow2(a,string()+c));
    //cout<<a<<" "<<b<<" "<<x<<endl;
    a.clear();
    b.clear();
    return x;
}
string pow(string a,string b){
    return pow10(a,b);
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

