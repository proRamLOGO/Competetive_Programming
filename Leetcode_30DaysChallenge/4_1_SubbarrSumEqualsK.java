class Solution {
    public int subarraySum(int[] nums, int k) {
        
        int n = nums.length ;
        if ( n==0 ) return 0 ;
        
        // HashMap< Integer, ArrayList< Integer > > indices = new HashMap<>() ;
//         for ( int i = 0 ; i < n ; ++i ) {
//             sum += nums[i] ;
//             int m = sum%k ;
//             if( indices.get(m) == null ) {
//                 ArrayList< Integer > a = new ArrayList<>() ;
//                 indices.put(m,a) ;
//             }
//             ArrayList< Integer > a = indices.get(m) ;
//             a.add(i) ;
//             indices.put(m,a) ;
//         }
        
//         int ans = 0 ;
        
//         for ( Map.Entry< Integer, ArrayList< Integer > > itr : indices.entrySet() ) {
//             ArrayList<Integer> a = itr.getValue() ;
//             if ( a.size() < 2 ) 
//                 continue ;
//             // ans++ ;
//             for ( int i = 0 ; i < a.size()-1 ; ++i ) {
//                 ans += a.get(i+1)-a.get(i) ;
//             }
//         }
        
        int sum=0, ans = 0 ;
        
        HashMap<Integer,Integer> freq = new HashMap<>() ;
        
        for ( int i = 0 ; i < n ; ++i ) {
            sum += nums[i] ;
            
            if ( sum==k ) ++ans ;
            
            if ( freq.get(sum-k)!=null ) 
                ans += freq.get(sum-k) ;
            
            if ( freq.get(sum)==null ) 
                freq.put(sum,0) ;
            freq.put(sum,freq.get(sum)+1) ;
        
        }
        return ans ;
        
    }
}