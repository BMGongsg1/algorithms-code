//2071: [蓝桥杯2023初赛] 颜色平衡树 %%未完成
#include<bits/stdc++.h>
using namespace std;
// class tree{
//     vector<tree*> son;
//     int color;
//     tree(int son)
//     {

//     }
// };
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> tree(n);
    vector<int> color(n);
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>color[i]>>temp;
        tree[temp].push_back(i);
    }
    
    function([])

    return 0;
}