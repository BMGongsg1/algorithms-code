#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    vector<int> cnt(4);
    for(int i=0;i<str.size();i++){
        if(str[i] == 'A') {cnt[1]++;str[i] = '1';}
        else if(str[i] == 'B') {cnt[2]++;str[i] = '2';}
        else {cnt[3]++;str[i] = '3';}
    }
    vector<int> nums(6);
    vector<pair<int,int>> fenbu = {{1,2},{1,3},{2,1},{2,3},{3,1},{3,2}};
    int minn = INT_MAX;
    for(int i=0;i<6;i++){
        int step = 0,ft = fenbu[i].first,bk = fenbu[i].second;
        string temp = str;
        int left = 0,right = str.size()-1;
        cout<<"AwwSD"<<endl;
        while(left<cnt[ft])
        {
            int flag = -1;
            while(temp[right]!=ft+'0'&&right>left)
            {
                right--;
            }
            while(temp[left] == ft+'0'&&left<cnt[ft])
            {
                left++;
            }
            if(temp[right] == ft+'0'&&right>left)
            {
                swap(temp[right],temp[left]);
                step++;
                cout<<temp<<" "<<left<<" "<<right<<endl;
            }   
            
        }
        cout<<"ASD"<<endl;
        left = cnt[ft],right = str.size()-1;
        while(str.size()-right-1<cnt[bk])
        {
            int flag = -1;
            while(temp[right]==bk+'0'&&str.size()-right-1<cnt[bk])
            {
                right--;
            }
            while(temp[left] != bk+'0'&&right>left)
            {
                left++;
            }
            if(temp[left] == bk+'0'&&right>left)
            {
                swap(temp[right],temp[left]);
                step++;
                cout<<temp<<" "<<left<<" "<<right<<endl;
            }   
            
        }
        cout<<step<<endl;
        nums[i] = step;
        minn = min(minn,step);
    }
    cout<<minn;
    return 0;
}