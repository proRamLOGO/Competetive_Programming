import java.util.*;
import java.lang.*;
import java.io.*;

class DFMTRIX_BF {

    public static void printarr( int [][] arr, int n ) {

        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                System.out.print(arr[i][j] + " ") ;
            }
            System.out.println() ;
        }
        // System.out.println() ;

    }

    public static boolean isDFMTRIX( int[][] matrix, int n ) {

        int[][] freq = new int[2*n-1][n] ;

        for ( int i = 0 ; i < n ; ++i ) 
            for ( int j = 0 ; j < n ; ++j ) {
                freq[matrix[i][j]-1][i]++ ;
                freq[matrix[i][j]-1][j]++ ;
            }

        for ( int[] i : freq )
            for ( int j : i ) 
                if ( j == 0 )
                    return false ;

        return true ;

    }

    public static boolean generator( int[][] matrix, int n, int i, int j ) {

        if ( i == n ) {
            boolean res = isDFMTRIX( matrix, n ) ;
            if (res) {
                System.out.println("Hooray") ;
                printarr(matrix,n) ;
            }
            return res ;
        }
        
        if ( j == n ) {
            return generator( matrix, n, i+1, 0 ) ;
        }
        if ( matrix[i][j] != 0 ){
            return generator( matrix, n, i, j+1 ) ;
        }

        for ( int x = 0 ; x < 2*n - 1 ; ++x ) {

            matrix[i][j] = x+1 ;
            boolean res = generator( matrix, n, i, j+1 ) ;
            if ( res == true ) {
                return true ;
            }

        }
        matrix[i][j] = 0 ;
        
        return false ;

    }

    public static boolean generate_matrix( int n ) {

        int[][] doof_matrix = new int[n][n] ;
        // for ( int i = 0 ; i < n-1 ; ++i ) {
        //     // doof_matrix[i][0] = i+1 ;
        //     for ( int j = i ; j < n ; ++j )
        //         doof_matrix[i][j] = 1 ;
        // }
        // for ( int i = 0 ; i < n ; ++i ) {
        //     doof_matrix[n-1][i] = n-i ;
        // }
        // printarr(doof_matrix,n) ;
        return generator(doof_matrix,n,0,0) ;

    }

    public static void main (String[] args) throws IOException {
    
        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner(System.in) ;

        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            int n = in.nextInt() ;

            int[][] doof_matrix = new int[n][n] ;

            for ( int i = 0 ; i < n-1 ; ++i ) {
                doof_matrix[i][0] = i+1 ;
                for ( int j = i ; j < n ; ++j )
                    doof_matrix[i][j] = 1 ;
            }
            for ( int i = 0 ; i < n ; ++i ) {
                doof_matrix[n-1][i] = n-i ;
            }

            if(!generate_matrix( n )) 
                System.out.println("Boo") ;

        }

    }

}
