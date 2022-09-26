class Solution {
public:
    static bool comp(const string &a, const string &b)
    {
        if(a[1] == '!' or b[1] == '=')
            return false;
        return true;
    }
    int find_parent(int a, vector<int> &par)
    {
        int x = a;
        while(par[a] != a)
        {
            a = par[a];
        }
        par[x] = a;
        return a;
    }
    bool equationsPossible(vector<string>& eq) {
        sort(eq.begin(), eq.end(), comp);
        vector<int> parents(26);
        for(int i = 0;i<26;i++)
        {
            parents[i] = i;
        }
        int i = 0;
        for(;i<eq.size();i++)
        {
            string x = eq[i];
            if(x[1] == '=')
            {
                int y = find_parent(x[0]-'a', parents);
                int z = find_parent(x[3]-'a', parents);
                if(y != z)
                {
                    if(y < z)
                        parents[z] = y;
                    else
                        parents[y] = z;
                }
            }
            else
                break;
        }
        for(;i<eq.size();i++)
        {
            string x = eq[i];
            if(x[1] == '!')
            {
                int y = find_parent(x[0]-'a', parents);
                int z = find_parent(x[3]-'a', parents);
                if(y == z)
                    return false;
            }
        }
        return true;
    }
};