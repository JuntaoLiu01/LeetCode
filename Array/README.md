## [Container With Max Water](CWMW.cpp)
	S(i,j) = Min(ai,aj) * (j-i)  
	initial i = 0,j = len-1  
	if S(i',j') >= S(i,j) i'>=i,j'<=j,then Min(ai',aj') >= Min(ai,aj),    
	if ai <= aj
		then i++
   	else
   		j--

## [3Sum Closest](3SC.cpp)
	sort the array in increasing order,  
	three label:first,second,third
	first: 0 to size - 3,first+1 <= second < third <= nums-1  
	curSum = nums[first] + nums[second] + nums[third]  
	if curSum < target
		second++
	else
		third--
	
	when second & third cross, increase first by 1
	
## [4Sum](4Sum.cpp)
	the same idea as 3Sum Closest, just 3 to 4  

## [Jump Game](JG.cpp)
	search from the last index
	if any index in [curIndex,Min(curIndex+nums[curIndex],lastIndex] can jump to last index  
	then curIndex can jump to last index
	
## [Jump Game2](JG2.cpp)
	search from index 0 to len-1,
	from index i, we can arrive at (i,i+nums[i]) 
	then we record the max index we can arrive in (i,i+nums[i])
	each time i == current best index, we update the steps info and best index
	
## [Spiral Matrix II](SM2.cpp)
	follow the sequence:right->down->left->up
	be careful of the index  border
	
## [Set Matrix Zeroes](SMZ.cpp)
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
	
## [Search a 2D Matrix](S2DM.cpp)
	use binary search in row and column, easy to achieve
	the time complexity is O(lg(m) + lg(n))
	
## [Subsets](SUBSET.cpp)
	using recursive method:
		select one num from nums
		find subsets in the rest nums
		add num to the subsets of the rest nums
	
## [Word Search](WS.cpp)
	using backtracking algorithm, search from current pos, then it's adjacent cell

## [Remove Duplicates from Sorted Array II](RDSA2.cpp)
	record the pos info, initially pos = 2
	search from 2 to size-1:
		if nums[i] != nums[pos-2]
			nums[pos++] = nums[i]
			
## [Search in Rotated Sorted Array](SRSA.cpp)
	using binary search:
		first, find the pivot using binary search 
		then, search the target using binary again
		
	solution2:  
	observe the following rotation of arryay [0,1,2,3,4,5,6,7]
	0 1 2 3 4 5 6 7
	7 0 1 2 3 4 5 6
	6 7 0 1 2 3 4 5
	5 6 7 0 1 2 3 4 
	4 5 6 7 0 1 2 3 
	3 4 5 6 7 0 1 2
	2 3 4 5 6 7 0 1
	1 2 3 4 5 6 7 0
	
	we can find if nums[mid] < nums[right] then the right half nums are sorted, otheriwse the left half nums are sorted. so we can compare the target with the nums[mid] to decide which part the target may be in.
	
## [Search in Rotated Sorted Array II](SRSA2.cpp)
	according to the method 2 on 'Search in Rotated Sorted Array', if nums[mid] == nums[right], then let right--;
	
## [Spiral Matrix](SM.cpp)
	according to the sequence:
		right->down->left->up
		right: keep x, y < n-x
		down : keep y, x < m-(n-y)+1
		left : keep x, y >= m-x+1
		up   : keep y, x >= y+1

## [Majority Element II](ME2.cpp)
	using the voting method to find the candidate
	no more than 2 elements appears over [n/3] times 
	
## [Maximize Distance to Closest Person](MDCP.cpp)
	set a flag:
		-1: left has number 1
		0 : left and right both have number 1
		1 : rigth has number 1
	if 0:
		update answer with length/2
	else:
		update answer with length
	Note: length means the most continuous zero num
		
## [Pascal's Triangle](PT.cpp)
	using recursive method
	ret[i][0] = 1,ret[i][i] = 1
	ret[i][j] = ret[i-1][j-1] + ret[i-1][j]  i > 1
	
## [Product of Array Except Self](PAES.cpp)
	if we can't use the division,we have to use multiplication method.
	search the second times, from 0 to n-1 and from n-1 to 0
		so we can record the result nums[0]**nums[i-1] and nums[i+1]**nums[n-1] 
		then it's esay to combine and get the final result

## [Construct Binary Tree from Preorder and Inorder Traversal](CBTPIT.cpp)  
	preorder: 3 9 20 15 7
	inorder : 9 3 15 20 7
	first we can know that the first num(3) in preorder is the root,  
	then find the position(1) of root in inorder,  
	the left nums(9) are left tree and right nums(15 20 7) are right nums.	  
	
## [Construct Binary Tree from Inorder and Postorder Traversal](CBTIPT.cpp)  
	the same thought as the last problem. Now, the last one in postorder is the root.
	
## [Find Minimum in Rotated Sorted Array](FMRSA.cpp)  
	observe the following rotation of arryay [0,1,2,3,4,5,6,7]
	0 1 2 3 4 5 6 7
	7 0 1 2 3 4 5 6
	6 7 0 1 2 3 4 5
	5 6 7 0 1 2 3 4 
	4 5 6 7 0 1 2 3 
	3 4 5 6 7 0 1 2
	2 3 4 5 6 7 0 1
	1 2 3 4 5 6 7 0
	we can find that: 
		1. nums[mid] < nums[right], the right half is in order  
		2. nums[mid] > nums[right], the left half is in order  
	according to the faeture, we can using binary search method to find the answer.  
	
## [Find Minimum in Rotated Sorted Array II](FMRSA2.cpp)  
	if the array contain duplicates, make some change on the above method: 
		3. nums[mid] == nums[right], let right--
## [Combination Sum III](CS3.cpp)  
	backtracking thought:  
		1. choose current num, push it into vector tmp
		2. if tmp.size() ==  k && n == 0, then push the tmp to res  
		3. if n < 0, just return  
		4. recursive   
		5. pop back current num  

	

		
	
	
		