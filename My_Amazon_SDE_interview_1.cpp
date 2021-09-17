#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'connectedSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY edges
 */

/*
    test input:
    10
    5
    1 2
    1 3
    2 4
    3 5
    7 8
*/

const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;

bool visited[MAXN];
vector<int> adj[MAXM];

void dfs(int node, int& len) {
    visited[node] = true;
    len++;
    for(auto &it: adj[node]) {
        if (!visited[it]) {
            dfs(it, len);
        }
    }
}

// void bfs(int node){}

int connectedSum(int n, vector<string> edges) {
    
    // bool* visited = new bool[n];
    
    // mark inital visited array with false 
    /* note: we can comment this loop 
     *       since visited array declared outside functions
     *       thus its values already false.
     */
    for(int i=0; i<n; i++) {
        visited[i] = false;
    }
    
    // struct graph using adjacency matrix
    int m = (int)edges.size();
    for(int i=0; i<m; i++) {
        
        // parse the geline() string to ints using stringstream
        int a,b;
        string line = edges[i];
        stringstream ss;
        ss << line;
        ss >> a;
        ss >> b;
        
        // normalize to 0-based indexing
        a--,b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    long long ret = 0;
    
    for(int i=0; i<n; i++) {
        int len = 0;
        
        // make connected components and count each component length
        if (!visited[i]) {
            
            // note: we can acheive that using bfs too
            dfs(i, len);
            
            // cout << len << endl;
            ret += ceil(pow(len, 0.5));
        }
        
    }
    
    return ret;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string edges_count_temp;
    getline(cin, edges_count_temp);

    int edges_count = stoi(ltrim(rtrim(edges_count_temp)));

    vector<string> edges(edges_count);

    for (int i = 0; i < edges_count; i++) {
        string edges_item;
        getline(cin, edges_item);

        edges[i] = edges_item;
    }

    int result = connectedSum(n, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
