#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> one;
    vector<int> two;
    function<bool(int)> pd = [&](int index)->bool{
        int sum1 = 0,sum2 = 0,ssum1 = 0,ssum2 = 0,sssum1 = 0,sssum2 = 0;
        for(int i=0;i<one.size();i++)
        {
            sum1+=one[i];
            ssum1+=one[i]*one[i];
            sssum1+=one[i]*one[i]*one[i];
        }

        for(int i=0;i<two.size();i++)
        {
            sum2 += two[i];
            ssum2 += two[i] * two[i];
            sssum2 += two[i]*two[i]*two[i];
        }

        if(sum1 == sum2 && ssum1 == ssum2 && sssum1 == sssum2) {
            cout<<"ASD "<<sum1<<" "<<sum2<<" "<<ssum1<<" "<<ssum2<<" "<<sssum1<<" "<<sssum2<<endl;
            return true;
            }

        return false;
    };
    function<void(int)> dfs = [&](int index){
        if(index == 17){
            if(pd(index))
            {
                for(int i=0;i<one.size();i++)
                {
                    cout<<one[i]<<" ";
                }
                cout<<endl;
            }
            return;
        }

        one.push_back(index);
        dfs(index+1);
        one.pop_back();

        two.push_back(index);
        dfs(index+1);
        two.pop_back();

    };

    one.push_back(1);
    dfs(2);
    return 0;
}