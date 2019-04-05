#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    string word;
    getline(cin, word);
    for(int i=0; i<word.size(); i++){
        if(toupper(word[i]) == toupper(word[i-1])){
            cout<<"true";
            return 0;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "false" << endl;
}
