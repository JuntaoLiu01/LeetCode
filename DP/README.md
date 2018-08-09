## [House Robber](HR.cpp)
	dynamic programming:
		dp[i] = max(dp[i-1], dp[i-2]+nums[i]) i > 2
		
## [House Robber II](HR2.cpp)
	for the nums in the array constructs a circle, the first and the last elements are linked.
	so, 
		we can use dp on nums[1..n-1] which results into dp1
		and use dp on nums[n-2..0] which results into dp2
		return the largger num of {dp1[n-1],dp2[0]}
## [Integer Break](IB.cpp)
	using dp method
	dp[1] = 1, dp[2] = 1
	dp[i] = max(max(dp[j],j) * max(dp[i-j],i-j)) j <= i/2,i >= 3
	