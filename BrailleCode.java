import java.util.* ;
import java.io.* ;

class BrailleCode {

    static String[] braille = { "100000", "110000", "100100", "100110", "100010", "110100", "110110", "110010", "010100", "010110", "101000", "111000", "101100", "101110", "101010", "111100", "111110", "111010", "011100", "011110", "101001", "111001", "010111", "101101", "101111", "101011" } ;

    static String space = "000000", capital = "000001" ;

    public static String braille_encode( String code ) {

        int n = code.length() ;
        String bc = new String("") ;

        for ( int i = 0 ; i < n ; ++i ) {

            // if ' ' append 000000
            if ( code.charAt( i ) == ' ' ) {
                bc += space ;
            } else { // it is an aplhabet

                int ord = code.charAt(i) ;
                
                // if capital then add capitalization + lowercase the letter
                if ( 64<ord && ord<91 ) {
                    bc += capital ;
                    ord += 32 ;// to shift to lowercase letters. 
                }

                bc += braille[ord-'a'] ;

            }

        }

        return bc ;

    }

    public static void main( String args[] ) throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;

        Scanner in  = new Scanner(System.in);

        String code = in.nextLine();
        String bc = braille_encode(code) ;

        System.out.println(bc) ;

    }

}