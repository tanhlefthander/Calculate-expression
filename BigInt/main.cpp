#include <iostream>
#include "BigInt.h"
using namespace std;
int main(){
    /*string a("2"), b("100");
    cout<<add(a,b)<<endl;
    cout<<sub(a,b)<<endl;
    cout<<mul(a,b)<<endl;
    cout<<divide(a,b)<<endl;
    cout<<pow(a,b)<<endl;*/
    BigInt a("-2343"),b("2123");
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<(a^b)<<endl;
    cout<<a%b<<endl;
    return 0;
}
