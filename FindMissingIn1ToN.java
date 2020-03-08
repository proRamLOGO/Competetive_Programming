import java.io.*;
import java.util.*;

public class FindMissingIn1ToN {

    public static void main( String args[] ) throws IOException {

        System.setIn(new FileInputStream(new File("input.txt")));
        System.setOut(new PrintStream(new File("output.txt")));
        Scanner input = new Scanner(System.in) ;

        int n = input.nextInt() ;
        int expXOR = n%4 ;
        if( expXOR==0 )
            expXOR = n ;
        else if( expXOR==2 )
            expXOR = n+1 ;
        else if( expXOR==3 )
            expXOR = 0 ;
        
        int[] arr = new int[n-1] ;
        int arrXOR = 0 ;

        for ( int i = 0 ; i < n-1 ; ++i ) {
            arr[i] = input.nextInt() ;
            arrXOR ^= arr[i] ;
        }    

        for ( int i = 1 ; i<= n ; ++i ) {
            if ( (arrXOR^i) == expXOR ) {
                System.out.println(i);
                break ;
            }
        }

        // pw.flush();

    }

}