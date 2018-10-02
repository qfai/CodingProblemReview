
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stdlib.h> 
#include <map>
#include <memory>
#include <set>
using namespace std;
typedef long long ll;

class Solution {
public:    
	static bool cmp(int a, int b) // 注意comp函数必须为static bool，返回值为bool类型。a.start<b.start为升序    
	{        
		return a > b;
	}
};
bool comp(int a, int b) // 注意comp函数可以为static bool或者bool，返回值为bool类型。a<b为升序
{
	return a > b;
}
struct mycomp {
	bool operator()(const string &k1, const string &k2)const {
		if (atoi(k1.c_str()) < atoi(k2.c_str()))
			return true;
		else
			return false;
	}
};
int main() { 
	Solution s;
	vector<int> nums = { 1,1,1,3,3,2,2,2 };
	sort(nums.begin(), nums.end());
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
	//sort(nums.begin(), nums.end(),comp);
	sort(nums.begin(), nums.end(), Solution::cmp);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;
	map<string,int,mycomp> m;
	m["11"] = 2;
	m["1"] = 1;
	m["2"] = 1;
	for (auto i : m)
		cout << i.first << " " << i.second << endl;
	cout << endl;
	return 0; 
}

