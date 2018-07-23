## Container With Max Water

	S(i,j) = Min(ai,aj) * (j-i)  
	initial i = 0,j = len-1  
	if S(i',j') >= S(i,j) i'>=i,j'<=j,then Min(ai',aj') >= Min(ai,aj),    
	if ai <= aj :
		then i++
   	else :
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