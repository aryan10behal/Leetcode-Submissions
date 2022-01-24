class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps = 0, n = word.size();
        for(int i = 0;i<n;i++)
        {
            if(word[i] >='A' && word[i] <= 'Z')
                caps++;
        }
        if(caps == n || caps == 0 || (caps == 1 && word[0]>='A' && word[0]<='Z'))
            return  true;
        return false;
    }
};