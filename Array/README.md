## Container With Max Water
	S(i,j) = Min(ai,aj) * (j-i)  
	initial i = 0,j = len-1  
	if S(i',j') >= S(i,j) i'>=i,j'<=j,then Min(ai',aj') >= Min(ai,aj),    
	if ai <= aj
		then i++
   	else
   		j--

## 3Sum Closest
	sort the array in increasing order,  
	three label:first,second,third
	first: 0 to size - 3,first+1 <= second < third <= nums-1  
	curSum = nums[first] + nums[second] + nums[third]  
	if curSum < target
		second++
	else
		third--
	
	when second & third cross, increase first by 1
	
## 4Sum
	the same idea as 3Sum Closest, just 3 to 4  

## Jump Game
	search from the last index
	if any index in [curIndex,Min(curIndex+nums[curIndex],lastIndex] can jump to last index  
	then curIndex can jump to last index
	
## Jump Game2
	search from index 0 to len-1,
	from index i, we can arrive at (i,i+nums[i]) 
	then we record the max index we can arrive in (i,i+nums[i])
	each time i == current best index, we update the steps info and best index
	
## Spiral Matrix II
	follow the sequence:right->down->left->up
	be careful of the index  border
	
## Set Matrix Zeroes
	the biggest challenge of the problem is how to solve it in place.  
	the following algorithm give an O(1) solution for reference.  
	first we search throgh the first row and first column, record whether zero exists.  
	then we search other elements:
		if matrix[i][j] == 0
			set all matrix[k][j] = 0, k < i
			set all matrix[i][m] = 0, m < j
		else if matrix[0][j] == 0 or matrix[i][0] == 0
			set matrix[i][j] = 0
	finally, according to the initial flag, deciding whether set the first row and column to zero or not
	
## Search a 2D Matrix
	use binary search in row and column, easy to achieve
	the time complexity is O(lg(m) + lg(n))
	
## Subsets
	using recursive method:
		select one num from nums
		find subsets in the rest nums
		add num to the subsets of the rest nums
	
## Word Search
	using backtracking algorithm, search from current pos, then it's adjacent cell

## Remove Duplicates from Sorted Array II
	record the pos info, initially pos = 2
	search from 2 to size-1:
		if nums[i] != nums[pos-2]
			nums[pos++] = nums[i]