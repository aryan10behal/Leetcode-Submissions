class WordDictionary {
    unordered_map<int, vector<string>> s;
public:
    WordDictionary() {    
    }
    bool KMPSearch(string &pat, string &txt)
    {
        int M = pat.size();
        int N = txt.size();
        if(M!=N)
            return false;
        int i = 0;
        while(i<M)
        {
            if(pat[i]==txt[i] || pat[i]=='.')
                i++;
            else 
                return false;
        }
        return true;
    }
    void addWord(string word) {
        s[word.size()].push_back(word);
    }
    
    bool search(string word) {
        int n = word.size();
       // cout<<x<<endl;
        //cout<<lps.size();
        for(string x: s[n])
        {
            if(KMPSearch(word, x))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */