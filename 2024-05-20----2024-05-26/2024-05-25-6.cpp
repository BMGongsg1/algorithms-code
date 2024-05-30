#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> board(2,vector<pair<int,int>>(9));
    vector<int> cntt(2,0);
    int player = 0;
    vector<int> playerHP(2,30);
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        if(str == "summon")
        {
            int index,at,hp;
            cin>>index>>at>>hp;
            cntt[player%2]++;
            for(int j=cntt[player%2]-1;j>=index;j--)
            {
                board[player%2][j+1] = board[player%2][j];
            }
            board[player%2][index] = {at,hp};
        }
        else if(str == "attack")
        {
            int from,to;
            cin>>from>>to;
            if(to == 0) playerHP[(player+1)%2] -= board[player%2][from].first;
            else{
                board[(player+1)%2][to].second -= board[player%2][from].first;
                board[player%2][from].second -= board[(player+1)%2][to].first;
                if(board[(player+1)%2][to].second<=0)
                {
                    for(int j=to;j<7;j++)
                    {
                        board[(player+1)%2][j] = board[(player+1)%2][j+1];
                    }
                    board[(player+1)%2][cntt[(player+1)%2]] = {0,0};
                    cntt[(player+1)%2]--;
                    // 
                }
                
                if(board[player%2][from].second<=0)
                {
                    for(int j=from;j<7;j++)
                    {
                        board[player%2][j] = board[player%2][j+1];
                    }
                    board[(player)%2][cntt[(player)%2]] = {0,0};
                    cntt[(player)%2]--;
                    // 
                }
            }
        }
        else
        {
            player++;
        }
        if(playerHP[(player+1)%2]<=0||playerHP[player%2]<=0) break;

        // cout<<0<<" ";
        // for(int j=1;j<=7;j++)
        // {
        //     cout<<board[0][j].second<<" ";
        // }
        // cout<<endl<<1<<" ";
        // for(int j=1;j<=7;j++)
        // {
        //     cout<<board[1][j].second<<" ";
        // }
        // cout<<endl;
    }
    if(playerHP[0]<=0) cout<<-1<<endl;
    else if(playerHP[1]<=0) cout<<1<<endl;
    else cout<<0<<endl;

    cout<<playerHP[player%2]<<endl;
    int cnt = 0;
    for(int i=1;i<=7;i++)
    {
        if(board[player%2][i].second > 0)cnt++;
    }
    cout<<cnt<<" ";
    for(int i=1;i<=7;i++)
    {
        if(board[player%2][i].second>0)
        {
            cout<<board[player%2][i].second<<" ";
        }
    }
    cout<<endl;

    player++;
    cout<<playerHP[player%2]<<endl;
    cnt = 0;
    for(int i=1;i<=7;i++)
    {
        if(board[player%2][i].second > 0)cnt++;
    }
    cout<<cnt<<" ";
    for(int i=1;i<=7;i++)
    {
        if(board[player%2][i].second>0)
        {
            cout<<board[player%2][i].second<<" ";
        }
    }
    cout<<endl;

    return 0;
}