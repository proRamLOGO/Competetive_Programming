import java.util.* ;
import java.io.* ;
import java.lang.* ;

public class PLMU {

    public static Integer numOfPairs( int n ) {
        --n ;
        return ((n*(n+1)) / 2) ;
    }

    public static void main( String args[] ) throws java.lang.Exception {

        // System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        // System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int t = in.nextInt() ;

        while( t != 0 ) {
            --t ;

            int n = in.nextInt(), twos = 0, zeroes = 0 ;
            ArrayList< Integer > arr = new ArrayList<>() ;
            for ( int i = 0 ; i < n ; ++i ) {
                int val = in.nextInt() ;
                arr.add(val);
                if ( val == 0 ) 
                    ++zeroes ;
                else if ( val == 2 )
                    ++twos ; 
            }

            int pairsCountFor0 = numOfPairs( zeroes ) ;
            int pairsCountFor2 = numOfPairs(  twos  ) ;
            
            System.out.println( pairsCountFor0 + pairsCountFor2 );

        }

    }

}