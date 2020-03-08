import java.util.* ;
import java.io.* ;
import java.lang.* ;

class BINADD_PARTIAL_DEBUG {

    public static Integer add( Integer a, Integer b ) {

        int cnt = 0 ;
        while ( b > 0 ) {
            int u = (a^b) ;
            int v = (a&b) ;
            a = u ;
            b = v*2 ;
            ++cnt ;
        }
        return cnt ;

    }

    public static void main( String args[] ) throws java.lang.Exception, IOException {

        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int n = in.nextInt(); 
        String a = in.next(), b = in.next() ;
        System.out.println(add( Integer.parseInt(a), Integer.parseInt(b) )) ;


    }

}