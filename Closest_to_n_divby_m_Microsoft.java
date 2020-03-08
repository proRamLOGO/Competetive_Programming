import java.io.*;
import java.util.Scanner;

// MICROSOFT
/*Given n, m no. closest to n divisble by m*/

public class Closest_to_n_divby_m_Microsoft {

    public static int nearest( int n, int m ) {
        int d1 = n/m ;
        int d2 = d1 + 1 ;
        if ( n - d1*m > d2*m - n ) 
            return d2*m ;
        else
            return d1*m ;
    }
    public static void main( String args[] ) throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) );
        System.setOut( new PrintStream( new File("output.txt") ) );
        Scanner input = new Scanner( System.in ) ;

        int n = input.nextInt(), m = input.nextInt() ;
        System.out.println(nearest(n,m)) ;

    }

}
