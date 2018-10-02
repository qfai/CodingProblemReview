#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;


class triemap {
public:
	char element;
	bool flag = false;
	vector<triemap*> nexts;
	triemap* parents;
	triemap(char c, triemap* p) {
		element = c;
		nexts.assign(26, NULL);
		parents = p;
	}
	triemap() {
		nexts.assign(26, NULL);
	}
	triemap(vector<string> strs) {
		parents = this;
		int l = 0;//length
		queue<triemap*> q;
		for (int i = 0; i<26; i++)
			nexts.push_back(this);
		for (int i = 0; i<strs.size(); i++) {
			if (nexts[strs[i][0] - 'a'] == this) {
				nexts[strs[i][0] - 'a'] = new triemap(strs[i][0], this);
			}
			q.push(nexts[strs[i][0] - 'a']);
		}

		l++;
		queue<triemap*> qtmp;
		while (!q.empty()) {
			for (int i = 0; i<strs.size(); i++)
			{
				if (l <= strs[i].size())
				{
					auto p = q.front();
					q.pop();

					qtmp.push(p);
					if (l == strs[i].size())
						continue;
					if (!p->nexts[strs[i][l] - 'a']) {
						p->nexts[strs[i][l] - 'a'] = new triemap(strs[i][l], p->parents->nexts[strs[i][l] - 'a']);
					}
					if (l == strs[i].size() - 1) {
						p->nexts[strs[i][l] - 'a']->flag = true;
						//qtmp.push(p->nexts[strs[i][l] - 'a']);
					}
					q.push(p->nexts[strs[i][l] - 'a']);
				}
			}
			while (!qtmp.empty()) {
				auto p = qtmp.front();
				qtmp.pop();
				for (int i = 0; i<26; i++)
					if (!p->nexts[i]) {
						p->nexts[i] = p->parents->nexts[i];
					}
			}
			l++;
		}

	}
	bool find(string str) {
		triemap* root = this;
		for (int i = 0; i<str.size(); i++) {
			root = root->nexts[str[i] - 'a'];
			if (root->flag)
				return true;
		}
		return false;
	}

};
int main() {
	int n;
	cin >> n;
	vector<string> inputs(n, "");
	for (int i = 0; i<n; i++)
		cin >> inputs[i];
	triemap root = triemap(inputs);
	string tmp;
	cin >> tmp;
	if (root.find(tmp))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
