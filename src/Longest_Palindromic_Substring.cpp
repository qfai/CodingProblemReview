#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthLongestPath(string input) {
		int a = 0, b = 0;
		b = input.find("\n", a);
		int current_level = 0;
		vector<int> current;
		current.push_back(b - a + 1);
		int current_val = (b - a + 1);
		a = b + 1;
		int maxmun = 0;
		do {
			current_level = 0;
			while (input[a] == '\t') {
				current_level++;
				a += 1;
			}
			b = input.find("\n", a);
			if (current_level >= current.size()) {
				current.push_back(b - a + 1);
				current_val += (b - a + 1);
				if (input.substr(a, b - a).find('.') != string::npos)
					maxmun = max(maxmun, current_val - 1);
			}
			else if (current_level == current.size() - 1) {
				current_val = current_val - current[current_level] + b - a + 1;
				current[current_level] = b - a + 1;
				if (input.substr(a, b - a).find('.') != string::npos)
					maxmun = max(maxmun, current_val - 1);
			}
			else {
				while (current_level < current.size()) {
					current_val = current_val - current.back();
					current.pop_back();
				}
				current_val += (b - a + 1);
				current.push_back(b - a + 1);
				if (input.substr(a, b - a).find('.') != string::npos)
					maxmun = max(maxmun, current_val - 1);
			}
			a = b + 1;
		} while (b != string::npos);
		if (input.substr(a).find('.') != string::npos)
			maxmun = max(maxmun, current_val + int(input.size()) - a);
		return maxmun;
	}
	int longest_substr(string s) {
		string newstr("#");
		for (int i = 0; i < s.size(); i++) {
			newstr.push_back(s[i]);
			newstr.push_back('#');
		}
		vector<int> dl(newstr.size(), 0);
		int maxright = 0, pos = 0;
		for (int i = 0; i < newstr.size(); i++)
		{
			int startsearch = i-min(maxright - i, 2 * pos - i >= 0 ? dl[2 * pos - i] : 0);
			while (startsearch >= 0&&2*i-startsearch<newstr.size()&&newstr[2*i-startsearch]==newstr[startsearch]) {
				startsearch--;
			}
			dl[i] = i - startsearch;
			startsearch++;

			if (maxright < 2 * i - startsearch) {
				maxright = 2 * i - startsearch;
				pos = i;
			}
		}
		int maxresult = 0;
		for (int i : dl)
			maxresult = max(maxresult, i - 1);
		return maxresult;
	}
};
int main() {
	Solution s;
	int n = 0;
	//s.longest_substr("abba");
	cin >> n;
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cout << s.longest_substr(tmp)<< endl;
	}
	return 0;
}
