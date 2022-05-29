class Solution {
public:
    string discountPrices(string s, int discount) {
        string ans = "";
        double div = (double)(discount)/100;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '$' and (i==0 or s[i-1] == ' '))
            {
                string val = "";
                int x = i;
                i++;
                while(i<s.size() and s[i] >= '0' and s[i] <= '9')
                {
                    val += s[i++];
                }
                if(val.size() == 0)
                    ans += '$', i--;
                else if(i == s.size())
                {
                    cout<<val<<endl;
                    double num = std::stod(val);
                    num= num - (double)((long long)discount*num)/100;
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2) << num;
                    std::string str = ss.str();
                    ans += "$" + str;
                }
                else
                {
                    if(s[i] == '.')
                    {
                        val+= s[i];
                        while(i<s.size() and s[i] >= '0' and s[i] <= '9')
                        {
                            val += s[i++];
                        }
                        if(i == s.size() or s[i] == ' ')
                        {
                            double num = std::stod(val);
                            num= num - (double)((long long)discount*num)/100;
                            std::stringstream ss;
                            ss << std::fixed << std::setprecision(2) << num;
                            std::string str = ss.str();
                            ans += "$" + str;
                            i--;
                        }
                        else
                        {
                            ans += '$';
                            ans += val;
                            i--;
                        }
                    }
                    else if(s[i] == ' ')
                    {
                        double num = std::stod(val);
                        num = num - (double)((long long)discount*num)/100;
                        std::stringstream ss;
                    ss << std::fixed << std::setprecision(2) << num;
                    std::string str = ss.str();
                    ans += "$" + str;
                        i--;

                    }
                    else
                    {
                        ans += '$';
                        ans+=val;
                        i--;
                    }
                    
                 }
            }
            else
            {
                ans+= s[i];
            }
        }
        return ans;
    }
};