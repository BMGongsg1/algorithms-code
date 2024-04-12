 #include<bits/stdc++.h>(未完成)
 using namespace std;
 int main()
 {
    int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<nums.size();i++)
	{
		cin>>nums[i];
	}

	auto LCM = [&] (int a,int b){
		return a/__gcd(a,b)*b;
	}

    for(int i = 0;i<nums.size();i++)
    {

    }
    return 0;
 }