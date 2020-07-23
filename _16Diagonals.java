import java.util.* ;
import java.io.* ;

class _16Diagonals {

    public static void print( int grid[][], int n ) {
        for ( int i = 0 ; i < n ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                char c = '-' ;
                if (grid[i][j]==1) c = '/';
                if (grid[i][j]==-1) c = '\\' ;
                System.out.print(c) ;
            }
            System.out.println() ;
        }
    }

    public static boolean solve( int grid[][],int x, int y, int d ) {
        int n = grid.length ;
        
        if ( d==0 )
            return true ;
        if ( x==n )
            return false ;
        if ( y==n ) 
            return solve(grid,x+1,0,d) ;
        
        // System.out.println(x+" "+y) ;
        // print(grid,n) ;

        boolean res = false ;

        // try to place \
        if ( !( ( x>0 && y>0 && ( grid[x-1][y-1] == -1 ) )
          || ( y>0 && grid[x][y-1] == 1 ) 
          || ( y<n-1 && grid[x][y+1] == 1 )
          || ( x<n-1 && y<n-1 && grid[x+1][y+1] == -1 ) 
          || ( x<n-1 && grid[x+1][y] == 1 )
          || ( x>0 && grid[x-1][y] == 1 ) ) ) {
            grid[x][y] = -1 ;
            res = solve(grid,x,y+1,d-1) ;
        }
        if ( res ) return true ;
        grid[x][y] = 0 ;
        // try to place /
        if ( !( ( x>0 && y<n-1 && grid[x-1][y+1] == 1 ) 
          || ( y<n-1 && grid[x][y+1] == -1 )
          || ( y>0 && grid[x][y-1] == -1 )
          || ( x>n-1 && y>0 && grid[x+1][y-1] == 1 )
          || ( x>0 && grid[x-1][y] == -1 )
          || ( x<n-1 && grid[x+1][y] == -1 ) ) ) {
            grid[x][y] = 1 ;
            res = solve(grid,x,y+1,d-1) ;
        }
        if ( res ) return true ;
        grid[x][y] = 0 ;
        return solve(grid,x,y+1,d) ;

    }

    public static void main( String args[] ) throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        System.setOut( new PrintStream( new File("output.txt") ) ) ;

        Scanner in = new Scanner(System.in) ;
 
        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            // -1 -> \
            // 0 -> empty
            // 1 -> /

            int n = in.nextInt(), d = in.nextInt(); 
            int[][] grid = new int[n][n];
            // for ( int i = 0 ; i < n ; ++i )
            //     for ( int j = 0 ; j < n ; ++j )
            //         grid[i][j] = 0 ;
            boolean res = solve(grid,0,0,d) ;
            if (res)
                print(grid,n) ;
            else
                System.out.println(-1) ;
            System.out.println() ;
                    

        }

    }

}