import java.util.* ;
import java.io.* ;
import java.lang.* ;

class BINADD_NEW {

    public static Integer addNaive( Integer a, Integer b ) {

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

    public static Integer add( String a, String b ) {

        String buffer, z = "0" ; ;
        if ( a.length() < b.length() ) {
            int diff_in_len = b.length() - a.length() ;
            buffer = z.repeat(diff_in_len) ;
            a = buffer + a ;
        } else if ( a.length() > b.length() ) {
            int diff_in_len = a.length() - b.length() ;
            buffer = z.repeat(diff_in_len) ;
            b = buffer + b ;
        }

        int cnt = 1, cc = 0;
        int carry = 0, d1=0, d2=0 ;
        for ( int i = a.length()-1 ; i > -1 ; --i ) {

            // d1 = (int)(a.charAt(i)) ;
            // d2 = (int)(b.charAt(i)) ;
            d1 = a.charAt(i) - '0' ;
            d2 = b.charAt(i) - '0' ;
            
            if( d1+d2+carry == 2 ) { //( d1&d2&c == 1 || ( d1|d2|d3!=0 and d1^d2^c = 0 ) )
                carry = 1 ;
                cnt = Math.max(cnt,cc) ;
                ++cc ;
                // System.out.print("At i = ") ;
                // System.out.println(i) ;
            } else if ( d1+d2+carry == 3 ) {
                carry = 1 ;
                ++cc ;
                cnt = Math.max(cnt,cc) ;
                cc = 1 ;
            } else if ( d1+d2+carry == 1 ){
                cnt = Math.max(cnt,cc) ;
                cc = 1 ;
                carry = 0 ;
                // if ( d1+d2+carry == 0 )
                //     return cnt ;
            }
        }
        // if ( carry == 1 ) {
            ++cc ;
            cnt = Math.max(cnt,cc) ;
        

        return cnt ;

    }

    public static void main( String args[] ) throws java.lang.Exception, IOException {

        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "add.txt" ) ) ) ;
        Scanner in = new Scanner( System.in ) ;


        int n = 300, cnt = 0 ;
        // n = in.nextInt() ;

        //     String a = in.next() ;
        //     String b = in.next() ;
        for ( int i = 1 ; i <= n ; ++i ) {
            for ( int j = i ; j <= n ; ++j ) { 
                String a = Integer.toBinaryString(i), b = Integer.toBinaryString(j) ;
                System.out.print(i) ;
                System.out.print("  :  ") ;
                System.out.println(j) ;
                System.out.println(Integer.toBinaryString(i)) ;
                System.out.println(Integer.toBinaryString(j)) ;
                int nr = addNaive(Integer.parseInt(a,2),Integer.parseInt(b,2)) ;
                int cr = add(a,b) ;
                System.out.println( nr ) ;
                System.out.println( cr );
                System.out.print( "i&j =  " );
                System.out.println( Integer.parseInt(a,2)&Integer.parseInt(b,2) );
                // if ( (i&j)==i || (i&j)==j )
                //     System.out.println( "---SAME---" );
                if ( nr != cr ) {
                    System.out.println("----------DISCONTINUITY !!----------") ;
                }
                System.out.println( );
            }
        }
        

        // int t = in.nextInt() ;

        // while( t != 0 ) {
        //     --t ;

        //     String a = in.next() ;
        //     String b = in.next() ;
        //     if ( b.equals("0") )
        //         System.out.println( 0 );
        //     else 
        //         System.out.println( add(a,b) );

        // }

    }

}