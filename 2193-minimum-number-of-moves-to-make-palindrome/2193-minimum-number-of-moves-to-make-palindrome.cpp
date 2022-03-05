class Solution {
public:
int swapCount(string str){
    int n = str.length();
    int count=0, pos = -1;
    for(int i=0;i<n/2;i++){
        int left=i,right=n-i-1;
        while(left<right){
            if(str[left]==str[right])
                break;
            else
                right--;
        }
        if(left == right)
        {
            pos = left;
            break;
        }
        for(int j=right;j<n-i-1;j++){
            swap(str[j],str[j+1]);
            count++;
        }
    }
    if(pos!=-1)
    {
        string x = str.substr(pos +1, 2*(n/2 - pos));
        return count + swapCount(x) + n/2-pos;
    }
    return count;
}
    int minMovesToMakePalindrome(string s) {
       int ans1 = swapCount(s);
        reverse(s.begin(), s.end());
        int ans2 = swapCount(s);
        sort(s.begin(), s.end());
        cout<<ans1<<" "<<ans2<<endl;
        return  max(ans1, ans2);
    }
};