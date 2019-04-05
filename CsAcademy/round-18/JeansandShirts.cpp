
#include <bits/stdc++.h>
using namespace std;

int main() {
long long res = 0;
int n,m,k;
cin>>n>>m>>k;
int a[n],b[m];
for(int i=0; i<n; i++)cin>>a[i];
for(int i=0; i<m; i++)cin>>b[i];

    for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(abs(a[i]-b[j]) >= k)res++;
    }
}

cout<<res;

}
