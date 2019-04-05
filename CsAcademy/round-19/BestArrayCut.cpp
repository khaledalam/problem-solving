
#include <bits/stdc++.h>
using namespace std;

int main() {
	//iFile(input.txt);
	//oFile(output.txt);
    
    int n;
    cin>>n;
    long long a[n];
    long long l=0,r=0,res = (long long)1e9;
    for(int i=0; i<n; i++){
        cin>>a[i];
        l+= a[i];
    }
    
    
    for(int i=n-1; i>=1; i--){
        r += a[i];
        l -= a[i];
        res = min(res, abs(l - r) );
        
    }
    
    cout<<res;
    
}
