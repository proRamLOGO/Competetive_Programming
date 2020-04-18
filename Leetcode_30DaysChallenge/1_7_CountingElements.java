class Solution {
    public int countElements(int[] arr) {
        
        HashMap<Integer, Boolean> exist = new HashMap<>() ;
            
        for ( int i = 0 ; i < arr.length ; ++i ) {
            exist.put(arr[i],true) ;
        }
        
        int ans = 0 ;
        
        for ( int i = 0 ; i < arr.length ; ++i ) {
            if ( exist.get(arr[i]+1) != null ) 
                ++ans ;
        }
        
        return ans ;
        
    }
}