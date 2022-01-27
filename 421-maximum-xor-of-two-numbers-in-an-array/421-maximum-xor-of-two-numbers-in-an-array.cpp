struct node
{
    node* left;
    node* right;
};
class trie
{
    node* root;
    public:
        trie()
        {
            root = new node();
        }
        void insert(int n)
        {
            node* temp = root;
            for(int i = 30;i>=0;i--)
            {
                int bit = (n>>i & 1);
                if(bit == 0)
                {
                    if(temp->left==NULL)
                        temp->left = new node();
                    temp = temp->left;
                }
                else
                {
                    if(temp->right==NULL)
                        temp->right = new node();
                    temp = temp->right;
                }
            }
        }
        int find_max(int n)
        {
            node* temp = root;
            int val = 0;
            for(int i = 30;i>=0;i--)
            {
                int bit = (n>>i & 1);
                if(bit == 0)
                {
                    if(temp->right)
                        {
                            val+= (1<<i);
                            temp = temp->right;
                        }
                    else
                        temp = temp->left;
                }
                else
                {
                     if(temp->left)
                        {
                            val+= (1<<i);
                            temp = temp->left;
                        }
                    else
                        temp = temp->right;
                }
            }
            return val;
        }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie* root = new trie();
        for(int x: nums)
            root->insert(x);
        int m = 0;
        for(int x: nums)
        {
            m = max(root->find_max(x), m);
        }
        return m;
    }
};