int lcs(string l, string r) {
	vector<vector<int>> dp(l.size(), vector<int>(r.size(), 0));

	for (int i = 0; i < l.size(); i++)
		for (int j = 0; j < r.size(); j++)
			if (l[i] == r[j])
				dp[i][j] = i > 0 && j > 0 ? dp[i - 1][j - 1] + 1 : 1;
			else
				dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
	return dp[l.size() - 1][r.size() - 1];

}