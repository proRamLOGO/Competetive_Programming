import java.io.*;
import java.util.*;

public class B5 {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in) ;	
		int x = in.nextInt(), y = in.nextInt() ;
		int m = Math.min(x,y) ;
		int tt = m+m ;
		if ( m < x+y-m  )
			tt++ ;
		int ans = (int)Math.sqrt(tt) ;
		// ans *= ans ;
		System.out.println(ans) ;
	}

}
