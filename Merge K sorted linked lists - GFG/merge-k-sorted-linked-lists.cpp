// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node* x, Node* y)
    {
        if(x == NULL)
            return y;
        if(y == NULL)
            return x;
        Node *a;
        if(x->data < y->data)
        {
            a = x;
            x = x->next;
        }
        else
        {
            a = y;
            y = y->next;
        }
        Node* b = a;
        while(x && y)
        {
            if(x->data < y->data)
            {
                a->next = x;
                x = x->next;
            }
            else
            {
                a->next = y;
                y = y->next;
            }
            a = a->next;
        }
        while(x)
        {
            a->next = x;
            x = x->next;
            a = a->next;
        }
        while(y)
        {
            a->next = y;
            y = y->next;
            a = a->next;
        }
        a->next = NULL;
        return b;
    }
    Node* sort(Node *arr[], int l, int h)
    {
        if(l>h)
            return NULL;
        if(l == h)
            return arr[l];
        Node* x = sort(arr, l, (l+h)/2);
        Node *y = sort(arr, (l+h)/2 + 1, h);
        return merge(x, y);
    }
    Node * mergeKLists(Node *arr[], int k)
    {
           return sort(arr, 0, k-1);
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends