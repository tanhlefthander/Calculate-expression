#pragma once
#include "LibExpression.h"
#include "MyStack.h"
#define stack MyStack
#define push Push
#define pop Pop
#define empty IsEmpty
#define top Top
using namespace std;
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
