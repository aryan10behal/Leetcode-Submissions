struct node{
    node* left;
    node* right;
};
class trie{
    node* root;
    public:
    trie()
    {
        root = new node();
    }
    void insert(int number)
    {
        node* x = root;
        for(int i = 30;i>=0;i--)
        {
            int bit = (number >> i)&1;
            if(bit == 1)
            {
                if(x->right == NULL)
                    x->right = new node();
                x = x->right;
            }
            else
            {
                if(x->left == NULL)
                    x->left = new node();
                x = x->left;
            }
        }
    }
    int mx(int number)
    {
        node* x = root;
        int val = 0;
        for(int i = 30;i>=0;i--)
        {
            int bit = (number >> i)&1;
            if(bit == 1)
            {
                if(x->left)
                {
                    val += 1<<i;
                    x = x->left;
                }
                else
                    x = x->right;           
            }
            else
            {
                if(x->right)
                {
                    val += 1<<i;
                    x = x->right;
                }
                else
                    x = x->left;
            }
        }
        return val;
    }
    
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie* z = new trie();
        for(int x: nums)
        {
            z->insert(x);
        }
        int ans = 0;
        for(int x: nums)
        {
            ans = max(ans, z->mx(x));
        }
        return ans;
    }
};