class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mp{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> val;
        for(string x: words)
        {
            string str = "";
            for(char a: x)
            {
                str+= mp[a-97];
            }
            val.insert(str);
        }
        return val.size();
    }
};