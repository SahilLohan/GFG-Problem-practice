// Link for problem :- https://practice.geeksforgeeks.org/problems/trie-insert-and-search0651/1


// code :- 

/********************************************************************************************************
*********************************************************************************************************
**********************************************Driver code starts*****************************************
*********************************************************************************************************
********************************************************************************************************/




//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends

/********************************************************************************************************
*********************************************************************************************************
**********************************************Driver code ends*******************************************
*********************************************************************************************************
********************************************************************************************************/




/********************************************************************************************************
*********************************************************************************************************
**********************************************Real code starts*******************************************
*********************************************************************************************************
********************************************************************************************************/

// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    for(int i=0;i<key.length();i++)
    {
        if(root->children[key[i]-'a']==nullptr)
        {
            root->children[key[i]-'a']=new TrieNode();
        }
        root=root->children[key[i]-'a'];
        if(i==key.length()-1)
        root->isLeaf=true;
        
    }
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    for(int i=0;i<key.length();i++)
    {
        if(root->children[key[i]-'a']==nullptr)
        return false;
        
        if(i==key.length()-1)
        {
            if(root->children[key[i]-'a']->isLeaf==false)
            return false;
            else
            return true;
        }
        root=root->children[key[i]-'a'];
    }
    return false;
}


/********************************************************************************************************
*********************************************************************************************************
**********************************************Real code ends*********************************************
*********************************************************************************************************
********************************************************************************************************/