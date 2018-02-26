#include <iostream>
#include <string>
#include "Expression/SuffixExpression.h"
#include "Calculate.h"
using namespace std;
int main(){
    string a= "2^(10-6)*4.125*(7-8)+ 7/5";
    cout<<"Expression: "<<a<<endl<<endl;
    string s = toSuffix(a);
    cout<<"Suffix: "<<s<<endl<<endl;
    cout<<"Run calculate: "<<endl;
    BigFraction f= solveSuffix(s);
    cout<<endl;
    cout<<"Result: "<<f<<endl<<endl;
    cout<<"Mixed Number: ";
    f.getMixedNumber().printf();
    cout<<endl;
    return 0;
}
