#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int val,add;
};
class solve{
public:
    int N = 500011;
    Node* root = new Node();
    
    void update(Node* node,int start,int end,int l,int r,int val)
    {
        if(l<=start&&end<=r){
            node->val += val;
            node->add += val;
            return;
        }

        int mid = start+(end-start>>1);
        pushDown(node);
        if(l<=mid) update(node->left,start,mid,l,r,val);
        if(r>mid) update(node->right,mid+1,end,l,r,val);
        pushUp(node);
    }

    int query(Node* node,int start,int end,int l,int r)
    {
        if(l<=start&&end<=r) return node->val;
        int mid = start+(end-start>>1),ans = 0;
        pushDown(node);
        if(l<=mid) ans+=query(node->left,start,mid,l,r);
        if(r>mid) ans+=query(node->right,mid+1,end,l,r);
        return ans;
    }

    void pushUp(Node* node)
    {
        node->val = node->left->val+node->right->val;
    }

    void pushDown(Node* node)
    {
        if(node->left == nullptr) node->left = new Node();
        if(node->right == nullptr) node->right = new Node();
        if(node->add == 0) return;
        node->left->val += node->add;
        node->right->val += node->add;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0; 
    }

    void _start()
    {
        long long k;
        cin>>k;
        string str;
        cin>>str;
        char word1,word2;
        cin>>word1>>word2;

        for(int i=0;i<str.size();i++)
        {
            if(str[i] == word2)
            {
                update(root,0,N,i,i,1);
            }
        }

        long long ans = 0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == word1)
            {
                if(i+k-1<str.size())ans +=query(root,0,N,i+k-1,str.size());
            }
        }
        cout<<ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    solve* a = new solve();

    a->_start();



    return 0;
}