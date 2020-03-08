import java.util.*;
import java.lang.*;
import java.io.*;

class ISBIAS_2 {

    public static void main (String[] args) throws java.lang.Exception , IOException {
                    
        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner(System.in) ;
        
        Integer n = in.nextInt() , 
        q = in.nextInt() ;
        
        Integer[] arr = new Integer[n+1] ,
        increasing = new Integer[n] ,
        decreasing = new Integer[n] ;
        increasing[0] = decreasing[0] = 0 ;
        
        Integer x, y ;
        boolean increment, decrement ;
        x = y = 0 ;
        increment = decrement = false ;
        
        for ( Integer i = 0 ; i < n ; ++i )
            arr[i] = in.nextInt() ;
       
        for (int i = 1; i < n; i++) {
            
            if (arr[i] <= arr[i - 1]) {
                if (!decrement) {
                    y++;
                    decrement = true ;
                }
                increasing[i] = increasing[i - 1];
                decreasing[i] = y;
                increment = false;

            } else {

                if (!increment) {
                    x++;
                    increment = true;
                }
                increasing[i] = x;
                decreasing[i] = decreasing[i - 1];
                decrement = false;

            } 
        }

        while( q-- != 0 ) {

            int l = in.nextInt() ,
            r = in.nextInt() ;

            Integer inc_cnt, dec_cnt ;
            inc_cnt = dec_cnt = 0 ;

            if (l != 1) {
                if ( arr[l - 2] < arr[l - 1] && arr[l] > arr[l - 1] ) 
                    inc_cnt = 1;
                if ( arr[l - 2] > arr[l - 1] && arr[l] < arr[l - 1] )
                    dec_cnt = 1;
            }
            
            inc_cnt += increasing[r - 1] - increasing[l - 1] ;
            dec_cnt += decreasing[r - 1] - decreasing[l - 1] ;
            
            if ( inc_cnt == dec_cnt && inc_cnt != 0 )
                System.out.println("YES") ;
            else
                System.out.println("NO") ;
        }

    }

}