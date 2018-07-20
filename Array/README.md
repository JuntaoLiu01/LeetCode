## Container With Max Water
1, S(i,j) = Min(ai,aj) * (j-i)
2, initial i = 0,j = len-1
3, if S(i',j') >= S(i,j) i'>=i,j'<=j, we must have Min(ai',aj') >= Min(ai,aj), so  
    if ai <= aj then i++
    else j--

