#pragma once
#include <iostream>
#include <string>
#include "AlgorithmBigInt.h" // thư viện chứa các hàm tính
#include <sstream>
using namespace std;
class BigInt{
private: //Thuộc tính
    string bigInt;
    char pon; // dấu âmm hay dương
    string toString(int x){ //chuyển từ số nguyên sang kiểu string
        stringstream ss;
        ss<<x;
        string res;
        ss>>res;
        return res;
    }
public:
    // Cấu tử
    BigInt(){
        bigInt="0";
        pon='+';
    };
    BigInt(string big){
        if(big[0] != '-' && big[0] != '+'){
            bigInt= big;
            pon= '+';
        }
        else{
            bigInt=string(big.begin()+1, big.end());
            pon= big[0];
        }
    }
    BigInt(int x){
        string big= toString(x);
        if(big[0] != '-' && big[0] != '+'){
            bigInt= big;
            pon= '+';
        }
        else{
            bigInt=string(big.begin()+1, big.end());
            pon= big[0];
        }
    }
    BigInt (char p, string big){
        pon= p;
        bigInt= big;
    }
    void change(){ // đổi dấu
        if(pon=='+') pon= '-';
        else pon = '+';
    }
    // kích thước
    long size(){
        return bigInt.size();
    }
    bool isMinus(){ // âm
        if(pon=='-') return true;
        return false;
    }
    // phép gán
    void operator = (string big){
        BigInt tem(big);
        bigInt= tem.bigInt;
        pon= tem.pon;
    }

    // các phép logic
    bool operator < (BigInt b){
        if(pon != b.pon) return pon> b.pon; // '+' < '-'
        int i = cmp(bigInt, b.bigInt);
        if(pon == '+' && i<0) return true;
        if(pon=='-' && i>0) return true;
        return false;
    }
    bool operator > (BigInt b){
        if(pon != b.pon) return pon< b.pon;
        int i = cmp(bigInt, b.bigInt);
        if(pon == '+' && i>0) return true;
        if(pon=='-' && i<0) return true;
        return false;
    }
    bool operator == (BigInt b){
        if(pon != b.pon) return false;
        if(bigInt != b.bigInt) return false;
        return true;
    }
    bool operator != (BigInt b){
        if(pon != b.pon) return true;
        if(bigInt != b.bigInt) return true;
        return false;
    }
    bool operator <= (BigInt b){
        if(pon != b.pon) return pon> b.pon;
        int i = cmp(bigInt, b.bigInt);
        if(i==0) return true;
        if(pon == '+' && i<0) return true;
        if(pon=='-' && i>0) return true;
        return false;
    }
    bool operator >= (BigInt b){
        if(pon != b.pon) return pon< b.pon;
        int i = cmp(bigInt, b.bigInt);
        if(i==0) return true;
        if(pon == '+' && i>0) return true;
        if(pon=='-' && i<0) return true;
        return false;
    }

    // phép toán 2 ngôi
    BigInt operator + (BigInt b){
        if(bigInt[0] == '0') return b;
        if(b.bigInt[0]== '0') return BigInt(pon,bigInt);
        if(pon == b.pon) return BigInt(pon,add(bigInt, b.bigInt));
        int i= cmp(bigInt,b.bigInt);
        if(i == 0) return BigInt();
        //cout<<i<<endl;
        string s= sub(bigInt, b.bigInt);
        if(pon=='-'){
            if(i == 1) return BigInt('-', s);
            else return ('+',s);
        }
        if(i == 1) return BigInt('+', s);
        return BigInt('-',s);
    }
    BigInt operator + (string  x){
        BigInt b(x);
        if(bigInt[0] == '0') return b;
        if(b.bigInt[0]== '0') return BigInt(pon,bigInt);
        if(pon == b.pon) return BigInt(pon,add(bigInt, b.bigInt));
        int i= cmp(bigInt,b.bigInt);
        if(i == 0) return BigInt();
        //cout<<i<<endl;
        string s= sub(bigInt, b.bigInt);
        if(pon=='-'){
            if(i == 1) return BigInt('-', s);
            else return ('+',s);
        }
        if(i == 1) return BigInt('+', s);
        return BigInt('-',s);
    }
    BigInt operator - (BigInt b){
        // a - b = a + (-b)
        // đổi dấu
        b.change();
        BigInt res= BigInt(pon, bigInt) + b;
        //cout<<res<<endl;
        return res;
    }
    BigInt operator * (BigInt b){
        string s= mul(bigInt,b.bigInt);
        if(pon == b.pon) return BigInt('+', s);
        return BigInt('-',s);
    }
    BigInt operator / (BigInt b){
        QR qr = divide(bigInt, b.bigInt);
        if(pon == b.pon) return BigInt('+', qr.first);
        return BigInt('-',qr.first);
    }
    BigInt operator % (BigInt b){
        QR qr = divide(bigInt, b.bigInt);
        return qr.second;
    }
    BigInt operator ^ (BigInt b){ // tính toán với b dương
        if(b.pon=='-'){
            cout<<"Erro!";
            return BigInt();
        }
        string x= pow(bigInt,b.bigInt);
        char p='+';
        if(pon=='-' && !isEven(b.bigInt)) p='-';
        return BigInt(p,x);
    }
    void operator += (BigInt b){
        BigInt temp = BigInt(pon,bigInt) + b;
        pon= temp.pon;
        bigInt= temp.bigInt;
    }
    void operator -= (BigInt b){
        BigInt temp = BigInt(pon,bigInt) - b;
        pon= temp.pon;
        bigInt= temp.bigInt;
    }
    void operator *= (BigInt b){
        BigInt temp = BigInt(pon,bigInt) * b;
        pon= temp.pon;
        bigInt= temp.bigInt;
    }
    void operator /= (BigInt b){
        BigInt temp = BigInt(pon,bigInt) / b;
        pon= temp.pon;
        bigInt= temp.bigInt;
    }
    // nhập xuất
    friend ostream & operator << (ostream & out, BigInt b) {
        if(b.pon =='-' && b.bigInt[0]!= '0') out<<'-';
        //out<<b.pon;
        out<<b.bigInt;
        return out;
    }
    BigInt abs(){
        return bigInt;
    }
    friend istream & operator >> (istream &in, BigInt &b){
        string s;
        in>>s;
        b= BigInt(s);
        return in;
    }
    //
    string toString(){
        if(pon == '-') return pon + bigInt;
        return bigInt;
    }
    char& operator [] (int i){ // & cho phép gán b[3]= '9'
        return bigInt[i];
    }
    void random(int length){
        bigInt =randomChar(length);
        pon='+';
    }

};

