#include <string>
#include <sstream>
#include "BigInt.h"
#include "AlgorithmBigInt.h"
using namespace std;
struct MixedNumber { // hỗn số a b/c
    char ch; // dấu âm hay dương
    BigInt a;
    BigInt b;
    BigInt c;
    void init(char s, string x, string y, string z){
        ch= s;
        a= x;
        b= y;
        c= z;
    }
    void printf(){
        if(ch == '-') cout<<ch<<'(';
        cout<<a;
        if(b != BigInt() ) cout<<" + "<<b<<"/"<<c;
        if(ch == '-') cout<<')';
    }
};
class BigFraction {
private:
    BigInt numer; // tử số
    BigInt denomin; // mẫu số
    BigInt gcd( BigInt x, BigInt y){// lấy ước chung lớn nhất
        //cout<<x<<" "<<y<<endl;
        if(y == BigInt()) return x;
        return gcd(y, x%y);
    }
    void pre(){ // đổi dấu lên tử
        if(denomin < BigInt()){
            denomin.change();
            numer.change();
        }
    }
    void abridge(){//rút gọn
        if(numer == BigInt()) return;
        pre();
        BigInt ucln = gcd(numer,denomin);
        //cout<<ucln<<endl;
        numer/= ucln;
        denomin/= ucln;
    }
public:
    BigFraction(){
        numer="0";
    }
    BigFraction(string a){
        numer=a;
        denomin ="1";
    }
    BigFraction(string a, string b){
        numer= a;
        denomin = b;
        abridge();
    }
    BigFraction operator + (BigFraction b){
        b.numer = b.numer * denomin + numer * b.denomin;
        b.denomin *= denomin;
        b.abridge();
        return b;
    }
    BigFraction operator - (BigFraction b){
        b.numer = numer * b.denomin - b.numer * denomin;
        b.denomin *= denomin;
        //cout<<b<<endl;
        b.abridge();
        //cout<<b<<endl;
        return b;
    }
    BigFraction operator * (BigFraction b){
        b.numer *= numer;
        b.denomin *= denomin;
        b.abridge();
        return b;
    }
    BigFraction operator / (BigFraction b){
        b.numer *= denomin;
        b.denomin *= numer;
        b.abridge();
        return b.invert();
    }
    BigFraction operator ^ (BigFraction b){
        BigFraction t;
        BigInt p = b.getInt(); // chỉ tính đc mũ nguyên
        bool c = false;
        if(p < BigInt()){ // mũ âm
            p.change();
            c= true;
        }
        t.numer = (numer ^ p);
        t.denomin = (denomin ^ p);
        if(c) t = t.invert();
        //t.abridge();
        return t;
    }
    BigFraction invert (){ // đảo ngược
        return BigFraction(denomin.toString(),numer.toString());
    }
    MixedNumber getMixedNumber(){ // lấy hỗn so
        MixedNumber mn;
        BigInt a= numer.abs(), b= denomin.abs(); // lấy trị tuyệt đối
        QR qr = divide(a.toString(), b.toString());
        if(numer< BigInt()) mn.init('-',qr.first, qr.second, b.toString());
        else mn.init('+',qr.first, qr.second, b.toString());
        //mn.printf();
        return mn;
    }
    BigInt getInt(){
        return numer/denomin;
    }
    bool operator != (BigFraction b){
        if(numer != b.numer && denomin != b.denomin) return true;
        return false;

    }
    friend ostream & operator << (ostream & out, BigFraction b) {
        out<<b.numer;
        if(b.numer != BigInt() && b.denomin != BigInt("1")) out<<'/'<<b.denomin;
        return out;
    }
    string toString(){
        string res = numer.toString();
        if(numer != BigInt() && denomin != BigInt("1")){
            res+= '/';
            res+= denomin.toString();
        }
        return res;
    }
};
BigFraction getFromDouble(string a) // a chức xâu kiểu double : 35345.565
{
    int i;
    for( i=0 ;i< a.size(); i++) if(a[i]=='.') break; // trả về vị trí dấu '.'
    a.erase(a.begin()+ i);
    string b = "1";
    b+= string(a.size() -i,'0');
    return BigFraction(a,b);
};

