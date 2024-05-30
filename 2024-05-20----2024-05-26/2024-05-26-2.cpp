#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int s=0;s<=6;s++){
        for(int f=0;f<=60;f++){
            for(int m=0;m<=60;m++)
            {
                double shi = (s*3600+f*60+m)*360/43200;
                double fen = (f*60+m)*360/3600;
                double miao = m*60;

                double a,b;
                if(shi>fen){
                    if(shi-fen>180)
                    {
                        a = 360 + fen - shi;
                    }
                    else
                    {
                        a = shi - fen;
                    }
                }
                else
                {
                    if(fen-shi>180) a = 360 + shi - fen;
                    else a = fen - shi;
                }

                if(fen>miao)
                {
                    if(fen-miao>180) b = 360 + miao - fen;
                    else b = fen - miao;
                }
                else
                {
                    if(miao - fen>180) b = 360 + fen - miao;
                    else b = miao - fen;
                }

                if(a == 2*b)
                {
                    cout<<s<<" "<<f<<" "<<m<<endl;
                }
            }
        }
    }
    return 0;
}