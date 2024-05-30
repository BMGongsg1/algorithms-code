#include<bits/stcdc++.h>
using namespace std;
class Node{
    Node* pre;
    Node* nxt;
    int val;
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int maxx = 0;
    vector<Node*> nodes(n);
    for(int i=0;i<nums.size();i++)
    {
        cin>>nums[i];
        nodes[i]->val = nums[i];
    }

    Node* lst = nodes[n-1],ne;
    for(int i=0;i<n;i++)
    {
        if(i == n-1){
            ne = nodes[0];
            nodes[i]->nxt = ne;
            nodes[i]->pre = lst;
            break;
        }
        ne = nodes[i+1];
        nodes[i]->nxt = ne;
        nodes[i]->pre = lst;
        lst = node[i];
    }

    

    return 0;
}