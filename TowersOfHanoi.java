import java.util.* ;
import java.io.* ;

class TowersOfHanoi {

    public static void solve( int n, int s, int d, int h ) {

        if ( n==0 )
            return ;
        
        solve(n-1,s,h,d) ;
        System.out.println(n+"th disk to "+d) ;
        solve(n-1,h,d,s) ;

    }

    public static void main( String args[] ) throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        System.setOut( new PrintStream( new File("output.txt") ) ) ;

        Scanner in = new Scanner(System.in) ;
 
        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            int n = in.nextInt() ;
            solve(n,1,3,2) ;
                    

        }

    }

}