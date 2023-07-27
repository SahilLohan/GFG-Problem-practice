// Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1 


// Code :
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    vector<int> ans;
  public:

    vector<int> topView(Node *root)
    {
        if(!root) return ans;
        
        
        
        queue<pair<Node*,int>> q;
        vector<pair<int,int>> vec;
        // pair of node and its distance from centre line
        
        q.push(make_pair(root,0));
        int hd;
        Node* cur;
        int limit;
        int l=0,h=0;
        while(!q.empty())
        {
            limit=q.size();
            
            
            while(limit--)
            {
                cur=q.front().first;
                hd = q.front().second;
                
                if(cur == root)
                {
                    // cout << cur->data << " is pushed \n";
                    vec.push_back(make_pair(cur->data,hd));
                }
                else if(hd<l)
                {
                    // cout << cur->data << " is pushed .. l :"<< l<< " hd : " << hd << endl;
                    l=hd;
                    vec.push_back(make_pair(cur->data,hd));
                }
                else if(hd>h)
                {
                    // cout << cur->data << " is pushed .. h :"<< h<< " hd : " << hd << endl;
                    h=hd;
                    vec.push_back(make_pair(cur->data,hd));
                }
                
                q.pop();
                
                if(cur->left) q.push(make_pair(cur->left,hd-1));
                if(cur->right) q.push(make_pair(cur->right,hd+1));
            }
        }
        
        sort(vec.begin(),vec.end(),[](auto a,auto b){
            return a.second<b.second;
        });
        
        for(auto e:vec)
        {
            ans.push_back(e.first);
        }
        
        return ans;
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
