class Solution {
public:
    int find(vector<string>& words, vector<int> &a, int ind, vector<int>& score)
    {
        if(ind == words.size())
            return 0;
        int aa = find(words, a, ind+1, score);
        bool pssbl = true;
        int iscore = 0;
        for(char x: words[ind])
        {
            a[x-'a']--;
            iscore+=score[x-'a'];
            if(a[x-'a'] <0)
                pssbl = false;
        }
        int bb = -1;
        if(pssbl)
            bb = iscore + find(words, a, ind+1, score);
        for(char x: words[ind])
        {
            a[x-'a']++;
        }
        return max(aa, bb);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> a(26, 0);
        for(char x: letters)
        {
            a[x-'a']++;
        }
        int ans = find(words, a, 0, score);
        return ans;
    }
};