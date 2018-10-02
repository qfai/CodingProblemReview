
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stdlib.h> 
#include <map>
#include <memory>
#include <set>
#include <functional>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<string, int> PAIR;

ostream& operator<<(ostream& out, const PAIR& p) {
	return out << p.first << "\t" << p.second;
}
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

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
}

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
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
	map<string, int, mycomp> m;
	m["11"] = 2;
	m["1"] = 1;
	m["2"] = 1;
	for (auto i : m)
		cout << i << endl;
	map<string, int, greater<string>> my;
	my["11"] = 2;
	my["1"] = 1;
	my["2"] = 1;
	for (auto i : my)
		cout << i << endl;

	//sort by value
	vector<PAIR> vec(m.begin(), m.end());
	//sort(vec.begin(), vec.end(), cmp_by_value);
	sort(vec.begin(), vec.end(), CmpByValue());
	// sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);  
	for (int i = 0; i != vec.size(); ++i) {
		cout << vec[i] << endl;
	}

	return 0;
}

