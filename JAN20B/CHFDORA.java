import java.util.*;
import java.lang.*;
import java.io.*;

class CHFDORA {
    
    public static boolean isPalRow( int[][] matrix, int l, int r, int bar ) {
    
        for ( int i = l ; i < (l+r)/2 ; ++i )
            if ( matrix[i][bar] != matrix[r+l-i][bar] )
                return false;

        return true ;
        
    }
    
    public static boolean isPalCol( int[][] matrix, int l, int r, int bar ) {
    
        for ( int i = l ; i < (l+r)/2 ; ++i )
            if ( matrix[bar][i] != matrix[bar][r+l-i] )
                return false;

        return true ;
        
    }

    public static int palindromeswithcentre( int x, int y, int[][] matrix, int n, int m ) {

        int pal_count = 0 ;

        for ( int i = 1   ;   x-i > -1  &&  y-i > -1  &&  x+i < n  &&  y+i < m   ;   ++i ) {
            if ( isPalRow(matrix,x-i,x+i,y) && isPalCol(matrix,y-i,y+i,x) )
                ++pal_count ;
        }

        return pal_count ;

    }

    public static int solve( int[][] matrix, int n, int m ) {

        int ans = n*m ;

        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < m ; ++j ) {
                ans += palindromeswithcentre(i,j, matrix,n,m) ;
            }
        }

        return ans ;

    }

    public static void main (String[] args) throws IOException {
    
        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner(System.in) ;

        int t = in.nextInt() ; 

        while ( t-- != 0 ) {

            int n = in.nextInt() , 
            m = in.nextInt() ;
            
            int[][] matrix = new int[n][m] ;

            for ( int i = 0 ; i < n ; ++i )
                for ( int j = 0 ; j < m ; ++j )
                    matrix[i][j] = in.nextInt() ;
            
            System.out.println(solve(matrix, n, m)) ;

        }
        
    }
}
