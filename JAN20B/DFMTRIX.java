import java.util.*;
import java.lang.*;
import java.io.*;

class DFMTRIX {

    public static void printarr( int [][] arr, int n ) {

        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                System.out.printf("%2d ",arr[i][j]) ;
            }
            System.out.println() ;
        }
        // System.out.println() ;

    }

    public static int[][] generate_matrix( int n ) {


        int[][] doof_matrix = new int[n][n] ;

        // L-R Diagonal
        for ( int i = 0 ; i < n ; ++i ) {
            doof_matrix[i][i] = 2*n-1 ;
        }

        // R-L Diagonal 
        for ( int i = 0 ; i < n/2 ; ++i ) {
            doof_matrix[n/2 + i ][n/2 - i - 1] = 2*n - 2 ; // Left Side
            doof_matrix[n/2 - i - 1][n/2 + i ] = n - 1 ; // Right Side
        }

        // Boundaries
        for ( int i = 1 ; i < n-1 ; ++i ) {
            doof_matrix[i][0] = n+i-1 ; // Left
            doof_matrix[0][i] = i ; // Top
        }

        for ( int i = 3 ; i < n-1 ; ++i ) {
            
            //West Block
            int target = doof_matrix[i][0] ;
            int x = i, y = 0 ;
            while ( x > y ) {
                doof_matrix[x][y] = target ;
                --x ; ++y ;
            }

            //North Block
            target = doof_matrix[0][i] ;
            x = 0 ; y = i ;
            while ( x < y ) {
                doof_matrix[x][y] = target ;
                ++x ; --y ;
            }

        }

        for ( int i = 1 ; i < n/2 - 1 ; ++i ) {
            
            // South Block
            for ( int j = 0 ; j < 2*i ; ++j ) {
                doof_matrix[n/2+i][n/2-i+j] = n + j ;
            }

            // East Block
            for ( int j = 0 ; j < 2*i ; ++j ) {
                doof_matrix[n/2-i+j][n/2+i] = 1 + j ;
            }

        }

        for ( int i = n/2 ; i < n-1 ; ++i ) {

            //Bottom Boundary
            doof_matrix[n-1][i] = n + 2*(i - n/2) ;
            doof_matrix[n-1][i-n/2+1] = n + 2*(i - n/2) + 1;
            
            //Right Boundary
            doof_matrix[i][n-1] = 1 + 2*(i - n/2) ;
            doof_matrix[i-n/2+1][n-1] = 1 + 2*(i - n/2) + 1;

        }


        return doof_matrix ;

    }

    public static void main (String[] args) throws IOException {
    
        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner(System.in) ;

        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            int n = in.nextInt() ;

            if ( (n&1) == 1 ) {
                System.out.println("Boo") ;
                continue ;
            }

            int[][] doof_matrix = generate_matrix( n ) ;

            System.out.println("Hooray") ;
            printarr(doof_matrix,n) ;
                
        }

    }

}
