#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Quy ước n,m lần lượt là đô dài chuỗi a,b
//===================================//
typedef pair< string , string > QR;
/** Kiểu dữ liệu QR
* Được định nghĩa bằng kiểu dữ liệu pair
* Lưu 1 cặp string
* Tác dụng lưu thương và số dư của phép chia
**/
//===================================//
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
//===================================//
string add (string a, string b);
/** < Chính > Hàm tính tổng 2 số dạng chuỗi
* Trả về tổng 2 số a và b
* Ý tưởng: cộng 2 số tiểu học
* O(n)
**/
//===================================//
string sub (string a, string b);
/** < Chính > Hàm tính hiệu 2 số dạng chuỗi
* Trả về hiệu 2 số a và b (mặc định lấy trị tuyệt đối)
* Ý tưởng: trừ 2 số tiểu học
* O(n)
**/
//===================================//
string mulChar(string a, char c);
/** < Phụ > Hàm nhân 1 số lớn (string) với  1 số có 1 chữ số (char)
* Trả về kiểu string là kết quả của phép tính
* Ý tưởng nhân như nhân tay
* O(n)
* Nơi gọi hàm: mul
**/
//===================================//
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
string mul(string a, string b);
/** < Chính > Hàm nhân 2 số lớn
* Ý tưởng dùng đệ quy để đưa phép nhân 2 số lớn thành nhân số lớn với số có 1 kí tự (mulChar)
* Công thức đệ quy : a * b = a * int(b/10) + a*(b%10)
* Sử dụng hàm : mulChar , add , divideBy10
* O(n.m)
**/
//===================================//
QR preDivide(string a, string b);
/** < Phụ > Hàm chia đơn 2 số lớn đơn giản
* Ý tưởng : a = q*b + r, bớt a đi q lần b cho tới khi đc a < b , lúc này a là số dư, q là thương
* Dùng hàm để tính các phép chia mà thương ko quá 10 vì thế rủi ro nhất là 9 phép trừ => O(n)
**/
//===================================//
void addChar(string &a, char c);
/** < Phụ > Hàm thêm 1 số vào cuối chuỗi sử dụng tham chiếu
* Sử dụng như phép toán a= (a * 10 + c)
* Trả về cặp số thương và dư
**/
//===================================//
QR divide(string a, string b);
/** < Chính > Phép chia 2 số lớn
* a = q.b + r , a' = q'.b + r' với a' = int(a/10)
* => với R = 10.r' + a%10 thì q = 10.q' + int(R/b) và r = R%b
* O(n*m)
**/
//===================================//
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
string randomChar( int length);
// Hàm lấy số lớn ngẫu nhiên có length chữ sô
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//Tổng
string add (string a, string b){ // tổng 2 số
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
string sub(string a, string b){ // trừ , mặc định trả về kết quả dương
    // O(n)
    balance(a,b);
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

string divideBy10 (string a){
    if(a.size() == 1) return string("0");
    return string(a.begin(), a.end()-1);
}
string mulBy10(string a){
    a+='0';
    return a;
}
/// Phép nhân
string mul(string a, string b){ // thuật toán nhân
    // O(n*m)
    string kq;
    if(a.size()< b.size()) swap(a,b);
    if(b.size()== 1 ) return mulChar(a,b[0]);
    kq= mul(a, divideBy10(b));
    kq= mulBy10(kq); // nhân 10
    kq= add(kq,mulChar(a,b[b.size()-1]));
    //cout<<"mul "<<a<<" "<<b<<" "<<kq<<endl;
    return kq;
}
/// Phép chia
QR preDivide(string a, string b) // phép chia nhanh 2 số gần bằng nhau ( a > b và a.size == b.size hoặc a.size == b.size + 1)
{
    // O(n)
    char c='0';
    while ( cmp(a,b) != -1 ){ // chạy ko quá 9 vòng lặp
        c++;
        a= sub(a,b);
    }
    if(a == string()) a+= '0';
    return QR(string()+c,a);
}
void addChar(string &a, char c){
    if(a != "0") a.push_back(c);
    else a= string() + c;
}
QR divide(string a, string b){
    // n phép trừ
    if(b=="1") return QR(a,"0");
    if(cmp(a,b)== -1) return QR("0",a);
    QR qr= divide(divideBy10(a),b);
    string q = qr.first, r= qr.second;
    addChar(r,a[a.size() -1]);
    qr = preDivide(r,b);
    r= qr.second;
    addChar(q, qr.first[0]);
    return QR(q,r);
}
/// Phép lũy thừa
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

