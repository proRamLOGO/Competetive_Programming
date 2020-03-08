import java.util.* ;
import java.io.* ;
import java.lang.* ;

class WATSCORE {

    public static Integer sumOfArray( Integer[] arr ) {
        
        Integer sum = 0;
        for ( Integer i : arr ) 
            sum += i ;
        return sum ;

    }

    public static void main( String args[] ) throws java.lang.Exception, IOException {

        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int t = in.nextInt() ;

        while( t != 0 ) {
            --t ;

            int n = in.nextInt() ;
            Integer[] arr = new Integer[8] ;
            Arrays.fill(arr, 0) ;

            for ( int i = 0 ; i < n ; ++i ) {
                int problem_no = in.nextInt() ;
                int score = in.nextInt() ; 
                if ( problem_no < 9 ) 
                    arr[problem_no-1] = Math.max( arr[problem_no-1], score ) ;
            }

            System.out.println( sumOfArray( arr ) );

        }

    }

}