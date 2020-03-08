import java.io.* ;
import java.util.* ;
import java.lang.Math ;


public class NtoApowP_Microsoft {

    public double fastPow( double base, int power ) {

        if ( power == 1 )
            return base ;
        
        double res = fastPow(base, power/2) ;
        if ( power%2 )
            return res*res*base ;
        else
            return res*res ;

    }

    public double nthroot( int base, int n ) {
        //base^(1/n)

        double lo = 1, hi = n ;
        for ( int i = 0 ; i < 100 ; ++i ) {

            double mid = (lo+hi) / 2 ;
            double pow = fastPow(mid, n) ;
            double powi = fastPow((int)mid, n) ;
            if ( pow == (double)base )
                return mid ;
            else if ( powi < base )
                ++lo ;
            else
                ++hi ;

        }

    }

    public bool isExponential( int n ) {

        int sq = Math.sqrt(n) ;


    }

    public static void main( String args[] ) throws IOException {

        System.setIn(new FileInputStream( new File("input.txt") ) );
        System.setOut(new PrintStream( new File("output.txt") ) );
        Scanner input = new Scanner(System.in) ;

        int n = input.nextInt() ;
        System.out.println(isExponential(n)) ;

    }

}