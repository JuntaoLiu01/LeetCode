## [House Robber](HR.cpp)
	dynamic programming:
		dp[i] = max(dp[i-1], dp[i-2]+nums[i]) i > 2
		