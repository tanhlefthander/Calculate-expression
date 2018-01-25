#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include "MyStack.h"
#include "BigFraction.h"
#define stack MyStack
#define push Push
#define pop Pop
#define empty IsEmpty
#define top Top

using namespace std;
int getPriority(char c){ // lấy độ ưu tiên của toán tử
    if(c=='+' || c=='-' ) return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    if(c=='.') return 4;
    return 0;
}
bool isOperator( char c){
    if( getPriority(c) ) return true;
    return false;
}
bool isBracket(char c){
    if(c=='(' || c==')') return true;
    return false;
}
bool isDigit(char c){ // kiểm tra c có phải là chữ số hay ko
    if(c>='0' && c<='9') return true;
    return false;
}
bool isChar(char c){ // đúng cú pháp
   if( isOperator(c) || isDigit(c) || isBracket(c)) return true;
   return false;
}
string delSpace(string &a){
    string b;
    for(int i=0; i< a.size() ; i++){
            if(a[i]!= ' ') b+= a[i];
    }
    return b;
}
int checkOperator( string &a){
    for(int i=0; i< a.size() ; i++){
            if(isOperator(a[i])){
                if(i==0) return i; // đấu ở đầu
                if(isOperator(a[i-1])) return i; // có tồn tại toán tử trc nó
            }
            if(!isChar(a[i])) return i; // kí tự ko hợp lệ
    }
    return -1;
}
int checkBracket(string &a){ // kiểm tra ngoặc trả về vị trí ngoặc lỗi , nếu ko lỗi trả về -1
    stack< char > brackets;
    int j=0;
    for(int i=0; i< a.size() ; i++){
        if(a[i] == '('){
            if(i!=0 && isDigit(a[i-1])) return i; // 8+9(...
            if(isOperator(a[i+1])) return i; // (+
            if(brackets.empty()) j= i;
            brackets.push(a[i]);
        }
        if(a[i] == ')'){
            if(i!=0 && isDigit(a[i+1])) return i;// )8
            if(isOperator(a[i-1])) return i;// +)
            if(a[i-1] == '(') return i; // ()
            if(brackets.empty()) return i;
            brackets.pop();
        }
    }
    if(!brackets.empty()) return j;
    return -1;
}
BigFraction cal(BigFraction a,BigFraction b,char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/')
        if(b != BigFraction()) return a/b;
        else return BigFraction("Error");
    if(c == '^') return a^b;
    if(c == '.') return getFromDouble(a.toString()+ "." +b.toString());
    return BigFraction();
}
void addNumber(stack< BigFraction > &sNumber, string &number){
    sNumber.push(BigFraction(number));
    number= string();
}
void addSuffix (stack< char > &sOperator, stack< BigFraction > &sNumber){ // lấy dấu và 2 số trong stack để tại thành 1 biểu thức hậu tố
    char t = sOperator.top(); sOperator.pop();
    BigFraction b1, b2, res;
    b2= sNumber.top(); sNumber.pop();
    b1= sNumber.top(); sNumber.pop();
    res= cal(b1, b2, t);
    cout<<b1<<" "<<t<<" "<<b2<<" = "<<res<<endl;
    sNumber.push(res);
}
BigFraction toSuffix (string &a){
    stack< char > sOperator;
    stack< BigFraction > sNumber; // stack số
    string number;
    for(int i= 0; i<a.size() ; i++){
        if(isDigit(a[i])){ // nếu là chữ số
            number+= a[i];
            continue;
        }
        if(isOperator(a[i])){ // nếu là toán tử
            if(number!= string()) addNumber(sNumber, number);
            while(!sOperator.empty() && getPriority(sOperator.top()) >= getPriority(a[i])) addSuffix(sOperator, sNumber);
            sOperator.push(a[i]);
            continue;
        }
        if(isBracket(a[i])){
            if(number!= string()) addNumber(sNumber, number);
            if(a[i]=='(') sOperator.push(a[i]);
            else{ // là ngoặc đóng
                while(sOperator.top() != '(')
                        addSuffix(sOperator, sNumber);
                sOperator.pop(); // xóa ngoặc mở
            }
        }
    }
    if(number!= string())// xử lú số cuối cùng
        addNumber(sNumber, number);
    while(!sOperator.empty())// xử lý phần còn lại strong stack
        addSuffix(sOperator, sNumber);
    return sNumber.top();
}
bool checkError(string &a){
    int j= -1;
    j = checkBracket(a);
    if(j == -1) j= checkOperator(a);
    if(j != -1){
        cout<<"Error: "<<'\''<<a[j]<<'\''<<" ("<<j<<')'<<endl;
        return false;
    }
    return true;
}
int calculate(string a){
    a= delSpace(a);
    if(checkError(a)){
        BigFraction b= toSuffix(a);
        cout<<endl;
        cout<<a<<" = "<<b<<" = ";
        b.getMixedNumber().printf();
        cout<<endl;
    }
    return 0;
}


