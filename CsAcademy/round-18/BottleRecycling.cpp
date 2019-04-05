
#include <bits/stdc++.h>
using namespace std;


int main() {
int n,m;
cin>>n>>m;
long long res = n;
while(n){
    if (n<m)break;
    res+= n/m;
    n = (n/m) + n%m;
    
}
cout<<res;
}
