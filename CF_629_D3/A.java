import java.util.* ;
import java.io.* ;

public class A {
 
    public static void main( String args[] ) {// throws IOException {

        // System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        // System.setOut( new PrintStream( new File("output.txt") ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            int n=in.nextInt(), m=in.nextInt() ;
            int div = (n/m) ;
            int ans ;
            if ( div*m < n ) {
                ans = (n - ((n/m)+1)*m) ;
            } else {
                ans = (n - (n/m)*m) ;
            }
            if ( ans < 0 )
                ans *= -1 ;
            System.out.println( ans ) ;


        }

    }

}