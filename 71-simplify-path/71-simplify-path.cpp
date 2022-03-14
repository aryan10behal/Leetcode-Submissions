class Solution {
public:
    bool check(string tokens)
    {
        int j = 1; 
        while(j<tokens.size() && tokens[j] == '.')
            j++;
        return j == tokens.size() && tokens.size()-1 <= 2;
    }
    string simplifyPath(string path) {
        int i = 0;
        int n = path.size();
        vector<string> tokens;
        while(i<n)
        {
            if(path[i]=='/')
            {
                i++;
                string k = "/";
                while(i<n && path[i]!='/')
                    k.push_back(path[i++]);
                if(k != "/")
                    tokens.push_back(k);
            }
        }
        string ans = "";
        int val = 0;
        for(int i = tokens.size()-1;i>=0;i--)
        {
            if(tokens[i][1] == '.')
            {
               if(check(tokens[i]))
                  {
                      int iter = i;
                      val += tokens[i].size() - 2;
                      for(int j = i-1;j>=0;j--)
                      {
                          if(tokens[j][1]=='.' && check(tokens[j]))
                          {
                              iter = j;
                              val += (tokens[j].size()-2);
                          }
                          else
                              break;
                      }
                      cout<<iter<<" "<<val<<endl;
                      i  = iter;
                  }
                else
                {
                    if(val>0)
                    {
                        val--;
                        continue;
                    }
                    ans = tokens[i] + ans;
                }
            }
            else
            {
                 if(val>0)
                    {
                        val--;
                        continue;
                    }
                ans = tokens[i] + ans;
            }
        }
        if(ans == "")
            ans.push_back('/');
        //cout<<"$$$";
        return ans;
    }
};