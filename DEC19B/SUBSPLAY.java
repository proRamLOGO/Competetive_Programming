import java.util.* ;
import java.io.* ;
import java.lang.* ;

class SUBSPLAY {

    public static void main( String args[] ) throws java.lang.Exception, IOException {

        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int t = in.nextInt() ;

        while( t != 0 ) {
            --t ;

            int n = in.nextInt() ; 
            String s = in.next() ;
            HashMap< Character, ArrayList< Integer > > map = new HashMap< Character , ArrayList < Integer > >() ;

            for ( int i = 0 ; i < n ; ++i ) {

                Character ch = s.charAt(i) ;
                if ( map.get(ch) == null ) {
                    ArrayList< Integer > arr = new ArrayList<>() ;
                    arr.add(i) ;
                    map.put(ch,arr) ;
                } else {
                    ArrayList< Integer > arr = map.get(ch) ;
                    if ( arr.size() == 1 ) {
                        arr.add(i) ;
                        map.put(ch,arr) ;
                    }
                }

            }

            int k = 0 ;

            for ( Map.Entry<Character, ArrayList< Integer > > itr : map.entrySet() ) 
                if( itr.getValue().size() == 2 ) 
                    k = Math.max( k, n - itr.getValue().get(1) ) ;

            System.out.println( k );

        }

    }

}