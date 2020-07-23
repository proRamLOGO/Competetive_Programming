var main1 = function() {

    var n = parseInt(readLine()) ;
    var dp = Array.from(Array(n+1),()=>0) ;
    
    for ( var i = 1 ; i<= n ; ++i ) {
        var x,y,z ;
        x = y = z = Number.MAX_SAFE_INTEGER ;
        if ( i-1 > -1 )
            x = dp[i-1] ;
        if ( i-10 > -1 )
            y = dp[i-10] ;
        if ( i-100 > -1 )
            z = dp[i-100] ; 
        dp[i] = Math.min(Math.min(x,y),z) + 1 ;
    } 
    console.log(dp) ;
    return dp[n] ;

}

var main2 = function() {
	
	var n = parseInt(readLine()) ;
	var ans = Math.floor(n/100) ;
	n %= 100 ;
	ans += Math.floor(n/10) + Math.floor(n%10) ;
	return ans ;
}
