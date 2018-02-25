#pragma once
#include <iostream>
#include <string>
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
