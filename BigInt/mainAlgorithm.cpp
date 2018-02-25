#include <iostream>
#include "AlgorithmBigInt.h"
using namespace std;
int main(){
    string a("2"), b("1000");
    cout<<add(a,b)<<endl;
    cout<<sub(a,b)<<endl;
    cout<<mul(a,b)<<endl;
    cout<<divide(a,b)<<endl;
    cout<<pow(a,b)<<endl;
    return 0;
}
