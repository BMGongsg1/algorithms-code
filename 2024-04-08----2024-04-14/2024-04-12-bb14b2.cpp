#include <bits/stdc++.h>
using namespace std;
int main()
{

  double num = 23333333;
  for(int i=0;i<=23333333/2;i++)
  {
    double zero = i;
    double one = 23333333-zero;
    double s = -one*(one/num)*(log(one/num)/log(2))-zero*(zero/num)*(log(zero/num)/log(2));
    if(abs(s-11625907.5798)<=1)
    {
      cout<<s-11625907.5798<<"  "<<(int)zero<<endl;
    }
  }
  return 0;
}