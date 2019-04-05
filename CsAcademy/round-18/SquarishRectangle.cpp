
#include <bits/stdc++.h>
using namespace std;

int main() {

long long n,m,a,b,d,c=1e9;
cin>>n>>m;

a = (n*m);
long long i = sqrt(a);
for(i; ; i++){
    if(a % i == 0){
        b = a/i;
        d = abs ( b - i);
        // cout<<b <<' '<<d<<endl;
        if( d <= c)c = d;
        else break;
    }
}

if(c == 1e9)return cout<<0,0;

cout<<c;


}
