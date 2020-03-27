import java.util.* ;
import java.io.* ;

public class B {
 
    public static Integer bs( int n ) {

        Integer lo = 1, hi = 100000 ;
        Integer ans = -1 ;
        while ( hi >= lo ) {
            Integer mid = (lo+hi)/ 2 ;
            Integer sum = (mid*(mid+1)) / 2 ;
            System.out.println(mid+"  "+sum);
            if ( sum == n ) {
                return mid ;
            }
            else if ( sum > n ) {
                ans = mid ;
                hi = mid-1 ;
            } else {
                lo = mid+1 ;
            }
        }

        return ans ;

    }
    public static void main( String args[] )  throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        System.setOut( new PrintStream( new File("output.txt") ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            int n=in.nextInt(), k=in.nextInt() ;
            // System.out.println(n+"  "+k);
            int p1 = bs(k)+1 ;
            int p2 = k- (((p1-2)*(p1-1))/2) ;

            System.out.println(p1+"  "+p2);

            for ( int i = n ; i > 0 ; --i )
                if ( i == p1 || i == p2 ) 
                    System.out.print('b') ;
                else 
                    System.out.print('a') ;
            
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();
            System.out.println();


        }

    }

}