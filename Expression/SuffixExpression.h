#pragma once
#include "LibExpression.h"
#include "CheckExpression.h"
using namespace std;
void addNumber(stack< string > &sSuffix, string &number){
    sSuffix.push(number);
    number= string();
}
void addSuffix (stack< char > &sOperator, stack< string > &sSuffix){ // lấy dấu và 2 số trong stack để tại thành 1 biểu thức hậu tố
    char t = sOperator.top(); sOperator.pop();
    string b1, b2, suffix;
    b2= sSuffix.top(); sSuffix.pop();
    b1= sSuffix.top(); sSuffix.pop();
    suffix = b1 + ' ' + b2 + ' ' + t;
    sSuffix.Push(suffix);
}
string toSuffix (string &a){
    stack< char > sOperator;
    stack< string > sSuffix; // stack hậu tố
    string number;
    for(int i= 0; i<a.size() ; i++){
        if(isDigit(a[i])){ // nếu là chữ số
            number+= a[i];
            continue;
        }
        if(isOperator(a[i])){ // nếu là toán tử
            if(number!= string()) addNumber(sSuffix, number);
            while(!sOperator.empty() && getPriority(sOperator.top()) >= getPriority(a[i]))
                addSuffix(sOperator, sSuffix);
            sOperator.push(a[i]);
            continue;
        }
        if(isBracket(a[i])){
            if(number!= string()) addNumber(sSuffix, number);
            if(a[i]=='(') sOperator.push(a[i]);
            else{ // là ngoặc đóng
                while(sOperator.top() != '(')
                        addSuffix(sOperator, sSuffix);
                sOperator.pop(); // xóa ngoặc mở
            }
        }
    }
    if(number!= string())// xử lú số cuối cùng
        addNumber(sSuffix, number);
    while(!sOperator.empty())// xử lý phần còn lại strong stack
        addSuffix(sOperator, sSuffix);
    return sSuffix.top();
}


