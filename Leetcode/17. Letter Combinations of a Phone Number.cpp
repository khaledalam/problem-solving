class Solution {
public:
    
    vector<string> res;
    string tmp = "";
    map<char,string> mp;
    map<pair<int,int>, bool>was;
    
    void run(int idx, string dig){
        
        // cout<<tmp<<endl;
        if(idx == dig.size())
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i=0; i<mp[dig[idx]].size(); i++){
            
            if(!was[{idx,i}])
            {
                was[{idx,i}] = true;
                tmp += mp[dig[idx]][i];
                
                run(idx+1, dig);
                
                tmp.pop_back();
                was[{idx,i}] = false;
            }
        }
        
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(!digits.size())return {};
        
        mp ['2'] = "abc";
        mp ['3'] = "def";
        mp ['4'] = "ghi";
        mp ['5'] = "jkl";
        mp ['6'] = "mno";
        mp ['7'] = "pqrs";
        mp ['8'] = "tuv";
        mp ['9'] = "wxyz";
        
        
        run(0, digits);
        
        return res;
        
        
    }
};
