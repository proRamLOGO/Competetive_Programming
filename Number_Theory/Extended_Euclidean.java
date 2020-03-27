import java.util.* ;
import java.io.* ;
import java.lang.* ;

class Extended_Euclidean {

    public static ArrayList<Integer> ext_Euclidean( int a, int b ) {

        if ( a == 0 ) {
            ArrayList< Integer > res = new ArrayList<>() ;
            res.add(0);
            res.add(1);
            res.add(b);
            return res ;
        }

        ArrayList<Integer> ans = ext_Euclidean(b%a, a) ;
        int y = ans.get(0) ;
        int x = ans.get(1) - ((b/a)*y) ;
        
        ArrayList<Integer> res = new ArrayList<>() ;
        res.add(x) ;
        res.add(y) ;
        res.add(ans.get(2)) ;

        return res ;

    }

    public static void main( String agrs[] ) throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) );
        System.setOut( new PrintStream( new File("output.txt") ) ) ;
        Scanner in = new Scanner( System.in ) ;

        int a = in.nextInt(), b = in.nextInt() ;
        ArrayList<Integer> ans = ext_Euclidean( a, b ) ;
        
        System.out.println(ans);
        System.out.println( a+" . "+ans.get(0) + " + " + b+" . "+ans.get(1)+"  =  "+ans.get(2) ) ;

    }

}