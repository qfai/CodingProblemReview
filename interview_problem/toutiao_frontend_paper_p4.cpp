#include <iostream>
#include <map>
#include <string>
#include <algorithm>  
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n,m;
	cin >> n>>m;
	vector<int> t1, t2;
	int tmp, num1 = n, num2 = m;
	float aver1 = 0, aver2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		t1.push_back(tmp);
		aver1 += tmp;
	}for (int i = 0; i < m; i++) {
		cin >> tmp;
		t2.push_back(tmp);
		aver2 += tmp;
	}
	aver1 /= num1;
	aver2 /= num2;
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	int count = 0;
	if (aver1 > aver2) {
		auto it = upper_bound(t1.begin(), t1.end(), aver2);
		while (true) {
			for (; it != t1.end() && *it < aver1; it++)
				if (find(t2.begin(), t2.end(), *it) == t2.end())
					break;
			if (it != t1.end() && *it < aver1) {

				num1--;
				aver1 = (aver1*(num1 + 1) - *it) / num1;
				aver2 = (aver2*num2 + *it) / (num2 + 1);
				num2++;
				count++;
				it++;
			}
			else
				break;
		}
	}
	else {
		auto it = upper_bound(t2.begin(), t2.end(), aver1);
		while (true) {
			for (; it != t2.end() && *it < aver2; it++)
				if (find(t1.begin(), t1.end(), *it) == t1.end())
					break;
			if (it != t2.end() && *it < aver2) {

				num2--;
				aver2 = (aver2*(num2 + 1) - *it) / num2;
				aver1 = (aver1*num1 + *it) / (num1 + 1);
				num1++;
				count++;
				it++;
			}
			else
				break;
		}
	}
	
	cout << count << endl;
	system("pause");
	return 0;
}