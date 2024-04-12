#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;

    int good = 0,perfect = 0;
    for(int i=0;i<n;i++)
    {
        double temp;
        cin>>temp;
        if(temp>=60) good++;
        if(temp>=85) perfect++;
    }

    double good1 = good,perfect1 = perfect;

    good1/=n;
    perfect1/=n;

    good1*=1000;
    perfect1*=1000;

    int gd = good1;
    int pf = perfect1;

    if(gd%10>=5)
    {
        gd+=10;
    }
    if(pf%10>=5)
    {
        pf+=10;
    }

    gd/=10;
    pf/=10;

    cout<<gd<<"%"<<endl<<pf<<"%";

    return 0;
}