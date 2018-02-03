#include <iostream>
#include <string>
#include <cstdio>
#include "Expression.h"
#include "AlgorithmBigInt.h"
using namespace std;
int main(){
    string a= "(2^(16-6))*4.125*(7-8)+ 7/5";
    //string a="1234567/345"; //3578 + 157/345
    calculate(a);
    /*QR qr= divideChar("7",'6');
    cout<<divideBy2("12323")<<endl;
    cout<<qr.first<< "  "<< qr.second<<endl;*/
    return 0;
}
