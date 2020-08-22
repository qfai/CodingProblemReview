# Overview
[link](https://leetcode-cn.com/problems/24-game/), 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
```
示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24

示例 2:

输入: [1, 2, 1, 2]
输出: False

示例 3:

输入: [3, 3, 8, 8]
输出: True
解释: 8 * (3-8/3) = 24

```

## Quick think

数字只有4个，运算符也只有4个，暴力搜索是很简单的做法。

需要注意的点在于
1. 括号，先算后算的问题
2. 精度： float不够， 浮点数之间的比较不能直接用 ==，要用fabs()<eps 

最简单的想法是全排列，比较简单实现的方式是4个数变成3个数依次减少。

代码如下：
```
class Solution {
public:
   	const int target = 24;
	const double eps = 1e-6;
	bool judgePoint24(vector<int>& nums) {
		vector<double> input;
		for (int i = 0; i < nums.size(); i++)
			input.push_back(nums[i]);
		return solve(input);
	}

	bool solve(vector<double> input) {
		if (input.size() == 1 && abs(input[0] - target) < eps)
			return true;
		else if (input.size() <= 1)
			return false;

		vector<double> next;
		for(int i=0;i<input.size();i++)
			for (int j = 0; j < input.size(); j++)
			{
				if (i == j)
					continue;
				next.clear();
				for(int k=0;k<input.size();k++)
					if (k != i && k != j) {
						next.push_back(input[k]);
					}
				for (int k = 0; k < 4; k++) {
					switch (k) {
						case 0:
							next.push_back(input[i] + input[j]);
							break;
						case 1:
							next.push_back(input[i] - input[j]);
							break;
						case 2:
							next.push_back(input[i] * input[j]);
							break;
						case 3:
							if (abs(input[j] - 0) < eps)
								continue;
							next.push_back(input[i] / input[j]);
							break;
					}
					if (solve(next))
						return true;
					next.pop_back();
				}
			}
		return false;
	}
};
```


### 题解上看到的dfs方法

可以学习的是state来表示数已经选择的方式

另一个点在于后面的if是为了模拟括号的产生让后面的先算。

```
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for (auto n : nums) arr.push_back(n);
        return dfs(arr, 0, 0, 24);
    }

    bool dfs(vector<double>& arr, double point, int state, double tar) {
        if (state == 15) return point == tar;
        // 当前已计算点数直接加减乘除下一个数。
        for (int i = 0; i < 4; i ++ ) {
            if ((state >> i & 1) != 0) continue;
            int newstate = state | (1 << i);
            if (dfs(arr, point + arr[i], newstate, tar)) return true;
            if (dfs(arr, point - arr[i], newstate, tar)) return true;
            if (point && dfs(arr, point * arr[i], newstate, tar)) return true;
            if (point && dfs(arr, point / arr[i], newstate, tar)) return true;
        }
        // 当前已计算点数加减乘除一个组合数，那么已计算点数清0，并且继续要算的不是24点了。
        if (point) {
            if (dfs(arr, 0, state, tar - point) || dfs(arr, 0, state, point - tar) || dfs(arr, 0, state, tar / point) || dfs(arr, 0, state, point / tar)) return true;
        }
        return false;
    }
};
```