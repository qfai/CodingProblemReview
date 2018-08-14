#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class node {
public:	
	int mem;
	string place = "";
	vector<node*> dict;
	node(int a) {
		mem = a;
		dict.assign(10, NULL);
	}
	void addword(string s,string l) {
		node* root = this;
		for (int i = 0; i < s.size()&&s[i]!='x'; i++) {
			
			if (!root->dict[s[i] - '0']) {
				root->dict[s[i] - '0'] = new node(s[i]-'0');
			}
			root = root->dict[s[i] - '0'];
		}
		root->place = l;
	}
	string find_prefix(string s) {
		node* root = this;
		for (int i = 0; i < s.size(); i++) {
			if (root->dict[s[i] - '0']) {
				root = root->dict[s[i] - '0'];
			}
			else
				return "unknown";
			if (root->place.size()>0)
				return root->place;
		}
		return root->place;
	}
	void destroy() {
		for (int i = 0; i < 10; i++)
			if (dict[i])
				dict[i]->destroy();
		delete this;
	}
};
class Trie {
public:
	int count = 0;
	char m_a;
	vector<Trie*> dict;
	Trie() {
		dict.assign(26, NULL);
		m_a = ' ';
		
	}
	Trie(char s){
		dict.assign(26, NULL);
		m_a = s;
	//	count = 1;
	}
	void addword(string s){
		Trie* root = this;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 'a')
				s[i] = s[i] - 'A' + 'a';
			if (!root->dict[s[i]-'a']) {
				root->dict[s[i] - 'a'] = new Trie(s[i]);
			}
			
			root->count++;
			root = root->dict[s[i] - 'a'];
		}
		root->count++;
	}
	int find_prefix(string s) {
		Trie* root = this;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 'a')
				s[i] = s[i] - 'A' + 'a';
			if (root->dict[s[i]-'a']) {
				root = root->dict[s[i] - 'a'];
			}
			else
				return 0;
		}
		return root->count;
	}
};
class Kmp {
public:
	string tmpl;
	vector<int> next;
	Kmp(string s ) {
		tmpl = s;
		next.assign(s.size(), -1);
		compute();
	}
	void changeword(string s) {
		tmpl = s;
		next.assign(s.size(), -1);
		compute();
	}
	void compute() {
		int index = -1;
		for (int i = 1; i < tmpl.size(); i++) {
			while (index >= 0 && tmpl[index + 1] != tmpl[i])
				index = next[index];
			if (tmpl[index + 1] == tmpl[i])
				index++;
			next[i] = index;
		  
		}
	}
	int compare(string s) {
		int count=0;
		int index = -1;
		for (int i = 0; i < s.size();i++) {

			while (index >= 0 && tmpl[index + 1] != s[i])
				index = next[index];
			if (tmpl[index + 1] == s[i])
				index++;
			if (index == tmpl.size() - 1)
			{
				index = next[index];
				count++;
			}
		}
		return count;
	}
	
};

int main() {

	int n;
	cin >> n;
	string s,l;
	Kmp str("");
	int num;
	string ss;
	for (int i = 0; i < n; i++) {
		cin >> ss;
		str.changeword(ss);
		cin >> ss;
		cout << str.compare(ss)<<endl;
	}

	return 0;
}
