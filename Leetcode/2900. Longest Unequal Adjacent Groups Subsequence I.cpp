class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        
        // Khaled Alam <khaledalam.net@gmail.com>

        if (words.size() < 2) return words;

        // longest , parent idx
        vector<pair<int,int>> len(words.size() + 1, {1, -1});
        int mx_res = -1, mx_idx = -1;
        for(int i=0; i<words.size(); i++) {
            for(int j=i+1; j<words.size(); j++) {
                if (groups[i] != groups[j]) {
                    len[j].first = max(len[i].first + 1 , len[j].first);
                    // cout<<len[j].first<<endl;
                    len[j].second = i;
                    if (mx_res < len[j].first) {
                        mx_res = len[j].first;
                        mx_idx = j;
                    }
                }
            }
        }

        vector<string> res;
        while(true && mx_res >= 0) {
            res.push_back(words[mx_idx]);
            if (len[mx_idx].second == -1) break;
            mx_idx = len[mx_idx].second;
        }

        reverse(res.begin(), res.end());

        if (res.empty()) return vector<string>{words[0]};

        return  res;
    }
};
