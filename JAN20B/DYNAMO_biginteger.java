/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger; 

/* Name of the class has to be "Main" only if the class is public. */
class DYNAMO_biginteger
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in) ;
        
	    int t = in.nextInt() ;
	    
	    while ( t--!=0 ) {
	        
	        BigInteger s, a, b, c, d, e, TWO, TEN ;
	        TWO = new BigInteger("2") ;
	        TEN = new BigInteger("10") ;
	        int n, res ;
            
	        n = in.nextInt() ;
            
			a = new BigInteger(in.next()) ;
	        s = ( TWO.multiply(TEN.pow(n)) ) .add(a);
	        System.out.println(s) ;
	        s.subtract(a) ;
            
	        b = new BigInteger(in.next()) ;
	        s.subtract(b) ;
	        
	        c = TEN.pow(n).subtract(b) ;
	        System.out.println(c) ;
	        s.subtract(c) ;
        
	        d = new BigInteger(in.next()) ;
	        s.subtract(d) ;
	        
	        e = TEN.pow(n).subtract(d) ;
	        System.out.println(e) ;
	        s.subtract(s) ;
            
	        res = in.nextInt() ;
	        
	        if ( res == -1 ) break ;
	        
	    }
	    
	    System.out.println() ;
	    
	}
}
