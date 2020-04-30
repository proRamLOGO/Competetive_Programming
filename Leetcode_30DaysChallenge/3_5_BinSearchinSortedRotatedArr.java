import java.util.* ;
import java.lang.* ;
import java.Math.*;

class Solution {
    public int minPathSum(int[][] grid) {
     
        int lo = 0, hi = v.length; 
        if (hi==0) return -1 ;
        int l = v[hi-1] ;  
        
        while ( hi >= lo ) {
            
            int mid = (lo+hi)/2 ;
            // System.out.println(lo+" "+hi+" "+mid) ;
            if ( v[mid] == x ) return mid ;
            
            if ( x <= l && v[mid]>l ) 
                lo = mid+1 ;
            if ( x>l && v[mid]<=l )
                hi = mid-1 ;
            if ( ( x>l && v[mid]>l ) || ( x<=l && v[mid]<=l ) ) {
                if ( x>v[mid] ) lo = mid+1 ;
                else hi = mid-1 ;
            }
            
            // System.out.println(lo+" "+hi+" "+mid) ;
            // System.out.println() ;
        }
        
        return -1 ;
        
    }
}