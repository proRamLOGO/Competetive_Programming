var main = function() {
    var start = parseInt(prompt()) ;
    var target = parseInt(prompt()) ;
    console.log(start,target) ;
    var dp = new Array() ;
    var str = "" ;
    for ( var i = start ; i <= target ; ++i ) {
        var temp = [0,""] ;
        dp.push(temp) ;  
    }
    for ( var i = start+1 ; i <= target ; ++i ) {
        var x,y,z ; 
        x = Number.MAX_SAFE_INTEGER ;
        y = Number.MAX_SAFE_INTEGER ;
        z = Number.MAX_SAFE_INTEGER ;
        if ( i-1 >= start ) {
            x = dp[i-1-start][0] ;}
        if ( i-3 >= start ) {
            y = dp[i-3-start][0] ;}
        if ( Math.floor(i/2) >= start && i&1^1 ) {
            z = dp[Math.floor(i/2)-start][0] ;}

        dp[i-start][0] = 1+Math.min(Math.min(x,y),z) ;
        
        if ( (dp[i-start][0]-1)==x ) 
            dp[i-start][1] = dp[i-1-start][1]+"C" ;
        else if ( (dp[i-start][0]-1)==y ) 
            dp[i-start][1] = dp[i-3-start][1]+"A" ;
        else if ( (dp[i-start][0]-1)==z && i&1^1 ) 
            dp[i-start][1] = dp[Math.floor(i/2)-start][1]+"B" ;
    }
    for ( i in dp ) {
        console.log(start+parseInt(i),dp[i]) ;
    }
    return dp[target-start] ;
}
