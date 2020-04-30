# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x: int, y: int) -> int:
#    def dimensions(self) -> list[]:

class Solution:
    def leftMostColumnWithOne(self, bm: 'BinaryMatrix') -> int:
        n,m = bm.dimensions()
        if ( n==0 or m==0 ) :
            return -1 ;
        
        x,y = 0,m-1
        ans = m
        while ( x < n and y > -1 ) :
            if ( bm.get(x,y) == 1 ) :
                ans = min(ans,y)
            if ( y>0 and bm.get(x,y-1) == 1 ) :
                y -= 1
                continue
            x += 1
        if (ans==m) :
            ans = -1
        return ans
            
        