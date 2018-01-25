#include <iostream>
#include <string>
#include <cstdio>
#include "Expression.h"
using namespace std;
int main(){
    string a= "(2^(16-6))*4.125*(7-8)+ 7/5";
    calculate(a);
    return 0;
}
