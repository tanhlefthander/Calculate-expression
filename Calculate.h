#pragma once
#include "BigInt/BigFraction.h"
#include "Expression/SuffixExpression.h"
using namespace std;
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
void pushStack( stack< BigFraction > &sSuffix, string &number){
    sSuffix.Push(BigFraction(number));
    number= string();
}
void solve(stack< BigFraction > &sSuffix, char c){
    BigFraction a,b;
    a= sSuffix.Top(); sSuffix.Pop();
    b= sSuffix.Top(); sSuffix.Pop();
    cout<<"   "<< b <<" "<<c<<" "<<a<<" = ";
    a= cal(b,a,c);
    sSuffix.Push(a);
    cout<<a<<endl;
}
BigFraction solveSuffix(string suffix){
    string number;
    stack< BigFraction > sSuffix;
    for(int i=0 ;i<suffix.size(); i++){
        if(isDigit(suffix[i])) number+= suffix[i];
        if(suffix[i]==' ' && number.size() != 0) pushStack(sSuffix, number);
        if(isOperator(suffix[i])) solve(sSuffix,suffix[i]);
    }
    return sSuffix.top();
}
