#include<bits/stdc++.h>
using namespace std;
class Tree{
class Node{
    Node* left,right;
    int val,add;
}
private:
    int N = (int)1e9;
    Node root = new Node();
public:
    void update(Node* node,int start,int end,int l,int r,int val){
        if(l<=start&&end<=r)
        {
            node->val += (end - start + 1) * val;
            node->add += val;
            return;
        }
        int mid = (start+end)>>1;
        pushDown(node,mid-start+1,end-mid);
        if(l<=mid) update(node->left,start,mid,l,r,val);
        if(r>mid) update(node->right,mid+1,end,l,r,val);
        pushUp(node);
    }

    int query(Node* node,int start,int end,int l,int r)
    {
        if(l<=start&&end<=r) return node->val;
        int mid = (start+end)>>1,ans = 0;
        pushDown(node,mid-start+1,end-mid);
        if(l<=mid) ans += query(node->left,start,mid,l,r);
        if(r>mid) ans += query(node->right,mid+1,end,l,r);
        return ans;
    }
    void pushUp(Node* node){
        node->val = node->left->val+node->right->val;
    }
    void pushDown(Node* node,int leftNum,int rightNum){
        if(node->left == nullptr) node->left = new Node();
        if(node->right == nullptr) node->right = new Node();
        if(node->add == 0) return;
        node->left->val += node->add * leftNum;
        node->right->val += node->add * rightNum;
        node->left->add += node->add;
        node->right->add += node->add;
        node->add = 0;
    }
}
int main(){
    int na;
    na
    
    return 0;
}