#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY related as parameter.
 */

/* input:
    1 1 0
    1 1 0
    0 0 1
 */
 
const int MAXN = 300 + 5;

vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int node) {
    vis[node] = true;
    for(auto &it: adj[node]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}

int countGroups(vector<string> related) {
    
    const int n = (int)related.size();
    
    auto parseInputs = [&]() {
        for(int i=0; i<n; i++) {
            for(int j=0; j < n && i != j; j++){
                if (related[i][j] == '1') {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
    };
    
    parseInputs();
    
    int ret = 0;
    for(int i=0; i<n; i++) {
        if (!vis[i]) {
            dfs(i);
            ret++;
        }
    }
    
    return ret;
}

int main()
