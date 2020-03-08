/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class DYNAMO
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in) ;
        
		// System.out.print("      ") ;
	    int t = in.nextInt() ;
	    
	    while ( t--!=0 ) {
	        
	        int n, s, a, b, c, d, e, res ;
			
			// System.out.print("      ") ;
	        n = in.nextInt() ;
			
			// System.out.print("      ") ;
			a = in.nextInt() ;
	        s = 2*(int)Math.pow(10,n) + a;
	        System.out.println(s) ;
	        s -= a ;
			
			// System.out.print("      ") ;
	        b = in.nextInt() ;
	        s -= b ;
	        
	        c = (int)Math.pow(10,n) - b ;
	        System.out.println(c) ;
	        s -= c ;
			
			
			// System.out.print("      ") ;
	        d = in.nextInt() ;
	        s -= d ;
	        
	        e = (int)Math.pow(10,n) - d ;
	        System.out.println(e) ;
	        s -= s ;
			
			// System.out.println( "Sum of vars = " + (a+b+c+d+e) ) ;


			// System.out.print("      ") ;
	        res = in.nextInt() ;
	        
	        if ( res == -1 ) break ;
	      //  System.out.println() ;
	        
	    }
	    
	    System.out.println() ;
	    
	}
}
