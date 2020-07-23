import java.io.* ;
import java.util.* ;
// import javafx.util.Pair; 

public class KnightsBFS {
 
    static class cell {  
        int x, y, dist;  
      
        public cell(int x, int y, int dist) { 
            this.x = x; 
            this.y = y; 
            this.dist = dist; 
        } 
    } 

    public static int solve(int S, int D) {

        cell s = new cell(S/8,S%8,0) ;
        cell d = new cell(D/8,D%8,Integer.MAX_VALUE) ;

        int[] x = {-2, -1, 1, 2, -2, -1, 1, 2}; 
        int[] y = {-1, -2, -2, -1, 1, 2, 2, 1};  

        Queue< cell > q = new LinkedList<>() ;
        boolean[][] vis = new boolean[8][8] ;
        vis[s.x][s.y] = true ;

        q.add(s) ;

        while ( q.size()>0 ) {

            cell c = q.poll() ;

            if ( c.x == d.x && c.y == d.y )
                return c.dist ;

            // Try all 8 moves;
            for ( int i = 0 ; i < 8 ; ++i ) {
                int nx = c.x + x[i];
                int ny = c.y + y[i];
                if ( 0<=nx && nx<8 && 0<=ny && ny<8 ) {
                    if ( vis[nx][ny] ) continue ;
                    vis[nx][ny] = true ;
                    q.add( new cell(nx,ny,c.dist+1) ) ;
                }
            }

        }

        // no possible move which cant happen but for safety reasons.
        return -1 ;

    }

    public static void main( String args[] ) throws IOException {

        System.setIn( new FileInputStream( new File("input.txt") ) ) ;
        System.setOut( new PrintStream( new File("output.txt") ) ) ;

        Scanner in = new Scanner(System.in) ;

        int s = in.nextInt() , d = in.nextInt() ;
        
        System.out.println(solve(s,d)) ;

    }

}