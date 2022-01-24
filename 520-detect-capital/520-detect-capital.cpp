class Solution {
public:
    bool detectCapitalUse(string word) {
        int caps = 0, n = word.size(), sml = 0;
        for(int i = 0;i<n;i++)
        {
            if(word[i] >='A' && word[i] <= 'Z')
                caps++;
            if(word[i] >='a' && word[i] <= 'z')
                sml++;
        }
        if(caps == n || sml == n || (caps == 1 && word[0]>='A' && word[0]<='Z'))
            return  true;
        return false;
    }
};