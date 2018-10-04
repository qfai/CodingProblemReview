#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<functional>
#include<limits>
#include<set>
#include<unordered_map>
#include<stack>
#include<bitset>
using namespace std;
#define nill -1
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}


	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (index.find(val) == index.end())
		{
			value.push_back(val);
			index[val].insert(value.size() - 1);
			return true;
		}
		else
		{
			value.push_back(val);
			index[val].insert(value.size() - 1);
			return false;

		}
	}
	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (index.find(val) != index.end())
		{
			int tmp = *(index[val].begin());
			index[val].erase(tmp);
			if (value.size() > 1) {
				index[value.back()].erase(value.size() - 1);
				index[value.back()].insert(tmp);
				value[tmp] = value.back();
			}



			value.pop_back();
			if (index[val].size() == 0)
				index.erase(val);
			return true;
		}
		else
			return false;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return value[rand() % value.size()];
	}
private:
	vector<int> value;
	map<int, set<int>> index;
};
//class RangeModule {
//public:
//	RangeModule() {
//
//	}
//
//	void addRange(int left, int right) {
//		map<int, int>::iterator it1 = res.lower_bound(right);
//		map<int, int>::iterator it2 = res.lower_bound(left);
//		if (it1 != res.end() && it1 == it2) {
//			if (it1->second >= right) {
//				res.insert(pair<int, int>(right, left));
//				return;
//			}else if (it1->second < right) {
//				it1->second =min(it1->second,left);
//				return;
//			}
//			return;
//		}
//		else if (it1 == res.end()) {
//			if (it2 == res.end()) {
//				res.insert(pair<int, int>(right, left));
//				return;
//			}
//			/*if (it2->second - left > 0) {
//				res.insert(pair<int, int>(right, it2->second));
//				
//			}
//			else {*/
//				map<int, int>::iterator tmp = it2;
//				tmp++;
//				map<int, int>::iterator tmp1 = tmp;
//				while (tmp != res.end()) {
//					tmp1++;
//					res.erase(tmp);
//					tmp = tmp1;
//				}
//
//				res.insert(pair<int, int>(right, min(left,it2->second)));
//			//}
//			res.erase(it2);
//		}
//		else {
//			map<int, int>::iterator tmp = it2;
//			tmp++;
//			map<int, int>::iterator tmp1 = tmp;
//			while (tmp != it1&&tmp != res.end()) {
//				tmp1++;
//				res.erase(tmp);
//				tmp = tmp1;
//			}
//			res[it1->first]=min(it2->second,left);
//			res.erase(it2);
//			//res.erase(it2);
//		}
//	}
//
//	bool queryRange(int left, int right) {
//		map<int, int>::iterator it=res.lower_bound(right);
//		if (it != res.end()) {
//			return it->second <= left;
//		}
//		return false;
//	}
//
//	void removeRange(int left, int right) {
//		map<int, int>::iterator it1 = res.lower_bound(right);
//		map<int, int>::iterator it2 = res.lower_bound(left);
//		if (it1 != res.end()&&it1==it2) {
//			if (it1->second >= right)
//				return;
//			//left = it1->second - left;
//			//right = it1->first - right;
//			if (left-it1->second > 0)
//				res.insert(pair<int, int>(left, it1->second));
//			if (it1->first > right)
//				res[it1->first] = right;
//			else
//				res.erase(it1);
//		}
//		else if(it1==res.end()){
//			if (it2 == res.end())
//				return;
//			
//				map<int, int>::iterator tmp = it2;
//				tmp++;
//				map<int, int>::iterator tmp1 = tmp;
//				while (tmp != res.end()) {
//					tmp1++;
//					res.erase(tmp);
//					tmp = tmp1;
//				}
//				if (it2->second - left < 0)
//					res.insert(pair<int, int>(left, it2->second));
//				if (it2->first != left)
//					res.erase(it2);
//
//		}
//		else {
//			map<int, int>::iterator tmp = it2;
//			tmp++;
//			map<int, int>::iterator tmp1 = tmp;
//			while (tmp != it1&&tmp != res.end()) {
//				tmp1++;
//				res.erase(tmp);
//				tmp = tmp1;
//			}
//			
//			if (it2->second - left < 0)
//				res.insert(pair<int, int>(left, it2->second));
//			res[it1->first] = right;
//			if (it2->first !=left)
//				res.erase(it2);
//			//res.erase(it2);
//		}
//
//	}
//private: 
//
//
//	map<int,int> res;//map<right,left>
//};
class RangeModule {
public:
	void addRange(int left, int right) {
		auto l = invals.upper_bound(left), r = invals.upper_bound(right);
		if (l != invals.begin()) {
			l--;
			if (l->second < left) l++;
		}
		if (l != r) {
			left = min(left, l->first);
			right = max(right, (--r)->second);
			invals.erase(l, ++r);
		}
		invals[left] = right;
	}

	bool queryRange(int left, int right) {
		auto it = invals.upper_bound(left);
		if (it == invals.begin() || (--it)->second < right) return false;
		return true;
	}

	void removeRange(int left, int right) {
		auto l = invals.upper_bound(left), r = invals.upper_bound(right);
		if (l != invals.begin()) {
			l--;
			if (l->second < left) l++;
		}
		if (l == r) return;
		int l1 = min(left, l->first), r1 = max(right, (--r)->second);
		invals.erase(l, ++r);
		if (l1 < left) invals[l1] = left;
		if (r1 > right) invals[right] = r1;
	}
	map<int, int> invals;
};
class lowbittree {
public:

	const int maxn = 100010;
	int c[100010];
	int lowbit(int i) {
		return i&(-i);
	}
	void update(int x, int v) {
		for (int i = x; i < maxn; i += lowbit(i)) {
			c[i] += v;
		}
	}
	int getSum(int x) {
		int sum = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			sum += c[i];
		return sum;
	}

};
class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new Node();
	}
	void delword(string word) {
		if (!search(word))
			return;
		Node* s = root;
		int tmp;
		for (int i = 0; i < word.size(); i++)
		{
			tmp = word[i] - 'a';
			if (s->next[tmp]->count > 1) {
				s->count--;
				s = s->next[tmp];
			}
			else
			{
				Node* t = s;
				s = s->next[tmp];
				t->next[tmp] = NULL;
				while (s) {
					t = s;
					s = s->next[tmp];
					delete t;
				}
				return;
			}
		}
		s->exist = false;
		s->count--;
	}
	/** Inserts a word into the trie. */
	void insert(string word) {
		Node* s = root;
		int tmp;
		for (int i = 0; i < word.size(); i++)
		{
			tmp = word[i] - 'a';
			if (!s->next[tmp])
				s->next[tmp] = new Node();
			s->count++;
			s = s->next[tmp];

		}
		s->exist = true;
		s->count++;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node* s = root;
		int tmp;
		for (int i = 0; i < word.size(); i++)
		{
			tmp = word[i] - 'a';
			if (!s->next[tmp])
				return false;
			s = s->next[tmp];
		}
		return s->exist;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node* s = root;
		int tmp;
		for (int i = 0; i < prefix.size(); i++)
		{
			tmp = prefix[i] - 'a';
			if (!s->next[tmp])
				return false;
			s = s->next[tmp];
		}
		return true;
	}
private:
	typedef struct Trie_node
	{
		int count;                    // 统计单词前缀出现的次数  
		struct Trie_node* next[26];   // 指向各个子树的指针  
		bool exist;  // 标记该结点处是否构成单词    
					 //int index;
		Trie_node() {
			this->count = 0;
			this->exist = false;
			memset(this->next, 0, sizeof(this->next));

		}
	}TrieNode, Node;

	TrieNode* root;

};

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		if (matrix.size() <= 0)return;
		vals = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i<matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
			{
				vals[i][j] = getnum(i - 1, j) + getnum(i, j - 1) + matrix[i][j] - getnum(i - 1, j - 1);
			}
	}
	int getnum(int i, int j) {
		if (i < 0)return 0;
		if (j < 0)return 0;
		return vals[i][j];
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		return vals[row2][col2] - getnum(row2, col1 - 1) - getnum(row1 - 1, col2) + getnum(row1 - 1, col1 - 1);
	}
	vector<vector<int>> vals;
};
class NumArray {
public:
	NumArray(vector<int> nums) {
		vals = vector<int>(nums.size() + 1, 0);
		ranges = vector<int>(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			update(i, nums[i]);
	}

	void update(int i, int val) {
		int v = val - vals[i];
		vals[i] = val;
		for (int t = i; t < ranges.size();) {
			ranges[t] += v;
			t += lowbit(t);
		}
	}

	int sumRange(int i, int j) {
		return range(j) - range(i - 1);
	}
	int range(int i) {
		if (i < 0)
			return 0;
		else
		{
			int tmp = 0;
			for (int t = i; t >0;) {
				tmp += ranges[t];
				t -= lowbit(t);
			}
			return tmp;
		}
	}
private:
	int lowbit(int i) {
		i++;
		return i&(-i);
	}
	vector<int> vals;
	vector<int> ranges;
};

class Solution {
private:
	bool static LessSort(Interval a, Interval b) { return (a.start < b.start); }
	bool static MaxSort(int a, int b) { return abs(a) > abs(b); }
	vector<int> numbers;
	vector<int> mul;
public:
	TreeNode* contructTree(vector<int>& input) {

		queue<TreeNode*> q;
		TreeNode* l, *r, *root;
		if (input[0] == -1)return NULL;
		l = new TreeNode(input[0]);
		root = l;
		q.push(l);
		for (int i = 1; i < input.size(); ) {

			if (input[i] != -1)
				l = new TreeNode(input[i]);
			else
				l = NULL;
			if (i + 1<input.size() && input[i + 1] != -1)
				r = new TreeNode(input[i + 1]);
			else
				r = NULL;
			if (!q.empty())
			{
				q.front()->left = l;
				q.front()->right = r;
				q.pop();
				if (l)
					q.push(l);
				if (r)
					q.push(r);
			}
			i += 2;

		}
		return root;

	}

	void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
	{
		std::string::size_type pos1, pos2;
		pos2 = s.find(c);
		pos1 = 0;
		while (std::string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2 - pos1));

			pos1 = pos2 + c.size();
			pos2 = s.find(c, pos1);
		}
		if (pos1 != s.length())
			v.push_back(s.substr(pos1));
	}

	bool hasPathSum(TreeNode* root, int sum) {
		if (!root&&sum != 0)
			return false;
		else if (!root &&sum == 0)
			return true;
		return pathsum(root, 0, sum);
	}
	bool pathsum(TreeNode* root, int current, int sum) {
		if (!root)return false;
		if (!root->left && !root->right) {
			if (current + root->val == sum)return true;
			else
				return false;
		}
		else if (!root->left)
			return pathsum(root->right, current + root->val, sum);
		else if (!root->right)
			return pathsum(root->left, current + root->val, sum);
		else
			return pathsum(root->left, current + root->val, sum) || pathsum(root->right, current + root->val, sum);


	}
private:
	int preval = INT_MIN;
};
// Init an empty set.use own main with catch https://github.com/catchorg/Catch2/blob/master/docs/own-main.md#top

int main(int argc, char* argv[])
{
	Solution s;
	vector<vector<int>> re;
	int x = -1;
	unsigned int y = 2;
	vector<int> input;
	input.clear();
	input.push_back(5);
	input.push_back(4);
	input.push_back(8);
	input.push_back(11);
	input.push_back(-1);
	input.push_back(13);
	input.push_back(4);
	input.push_back(7);
	input.push_back(2);
	input.push_back(-1);
	input.push_back(-1);
	input.push_back(-1);
	input.push_back(1);

	cout << s.hasPathSum(s.contructTree(input), 22) << endl;

	system("pause");
	return 0;
}
