import java.util.* ;
import java.io.* ;

public class A {
 
    public static void main( String args[] ) { //throws IOException {

        // System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        // System.setOut( new PrintStream( new File("output.txt") ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            String str = in.next() ;

            if ( str.length()==1 ) {
                System.out.println(0);
                continue ;
            }

            int l = 0, r = str.length()-1, ans = 0 ;
            while ( str.charAt(l)!='1' && l < str.length()-1 ) 
                ++l ;
            while ( str.charAt(r)!='1' && r > 0 ) 
                --r ;

            for ( int i = l ; i <= r ; ++i ) 
                if ( str.charAt(i)=='0' )
                    ans++ ;
            
            System.out.println(ans);

        }

    }

}