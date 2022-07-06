class Solution {
public:
    int j=-1;
    int convert(string& s,int i){
        if(i>=s.size()) return 0;
        int u=1;
        u=pow(10,s.size()-i-1);
        return (s[i]-48)*u+convert(s,i+1);
    }
    int calculate(string& s,int i){
        if(i>=s.size()) return 0;
        int ans=0;
        if(s[i]==')'){
            j=i+1;
            return 0;
        }
        if(s[i]>=48 && s[i]<=57){
            int k=i;
            while(s[k]>=48 && s[k]<=57) k++;
            string s1=s.substr(i,k-i);
            ans+=convert(s1,0);
            return ans+calculate(s,k);
        }
        if(s[i]=='-'){
            i++;
            while(s[i]==' ') i++;
            if(s[i]=='('){
                ans-=calculate(s,i+1);
                return ans+calculate(s,j);
            }
            else{
                int k=i;
            while(s[k]>=48 && s[k]<=57) k++;
                string s1=s.substr(i,k-i);
            ans-=convert(s1,0);
            return ans+calculate(s,k);
            }
        }
        if(s[i]=='+'){
            if(s[i+1]=='('){
                ans+=calculate(s,i+2);
                return ans+calculate(s,j);
            }
            else{
                return ans+calculate(s,i+1);
            }
        }
        if(s[i]=='('){
            ans+=calculate(s,i+1);
            return ans+calculate(s,j);
        }
        if(s[i]==' '){
            return calculate(s,i+1);
        }
        return ans;
    }
    int calculate(string s) {
        return calculate(s,0);
    }
};