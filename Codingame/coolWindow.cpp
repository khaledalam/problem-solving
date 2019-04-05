#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n;
    cin >> n; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

   for(int i=0; i < 3 + 2* n; i++)cout<<'-';cout<<endl;
   
   
   for(int i=0; i<n; i++){
       cout<<'|'; 
       for(int j=0; j <n; j++)cout<<'.';
       cout<<'|'; 
       for(int j=0; j <n; j++)cout<<'.';
       cout<<'|'; 
       cout<<endl;
    }
   cout<<'|';for(int i=0; i < n; i++)cout<<'-';cout<<'+';for(int i=0; i < n; i++)cout<<'-';cout<<'|';cout<<endl;
  
   for(int i=0; i<n; i++){
       cout<<'|'; 
       for(int j=0; j <n; j++)cout<<'.';
       cout<<'|'; 
       for(int j=0; j <n; j++)cout<<'.';
       cout<<'|'; 
       cout<<endl;
    }
    
  
   for(int i=0; i < 3 + 2* n; i++)cout<<'-';
}
