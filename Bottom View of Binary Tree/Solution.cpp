// Link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


// Code :

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        vector<int> ans;
        vector<pair<int,int>> temp;
        queue<pair<Node*,int>> q;
        if(!root) return ans;
        
        int hd=0;
        q.push(make_pair(root,0));
        
        int limit;
        Node* cur;
        while(!q.empty())
        {
            limit = q.size();
            while(limit--)
            {
                cur = q.front().first;
                hd = q.front().second;
                q.pop();
                
                mp[hd] = cur->data;
                
                if(cur->left) q.push(make_pair(cur->left,hd-1));
                if(cur->right) q.push(make_pair(cur->right,hd+1));
            }
        }
        
        for(auto e:mp)
        {
            temp.push_back(make_pair(e.second,e.first));
        }
        
        sort(temp.begin(),temp.end(),[](auto x,auto y){
            return x.second<y.second;
        });
        
        for(auto e:temp)
        {
            ans.push_back(e.first);
        }
        
        return ans;
    }
};
