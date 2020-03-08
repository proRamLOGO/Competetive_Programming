import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {

    public static void main (String[] args) throws java.lang.Exception {
    
        Scanner in = new Scanner(System.in) ;

        Integer n = in.nextInt() , 
        q = in.nextInt() ;
        
        Integer[] arr = new Integer[n+1] ;

        for ( Integer i = 0 ; i < n ; ++i )
            arr[i] = in.nextInt() ;
       
        arr[n] = arr[n-2] ;

        Integer[][] increasing = new Integer[n][2], 
        decreasing = new Integer[n][2] ;

        boolean xf = true ;
        Integer x=0,y=0, ki = 0, kd = 0 ; ;
        for ( Integer i = 1 ; i < n ; ++i ) {
            if ( arr[i] == arr[i-1] || arr[i] == arr[i+1] ) {
                xf = false ;
                continue ;
            }
            if ( arr[i-1] < arr[i] && arr[i] > arr[i+1] ) {
                if ( !xf ) {
                    xf = true ;
                    x = i ; 
                } else {
                    increasing[ki][0] = x ;
                    increasing[ki][1] = i ;
                    ++ki ;
                    x = i ;
                }
            }
            else if ( arr[i-1] > arr[i] && arr[i] < arr[i+1] ) {
                if ( !xf ) {
                    xf = true ;
                    x = i ; 
                } else {
                    decreasing[kd][0] = x ;
                    decreasing[kd][1] = i ;
                    ++kd ;
                    x = i ;
                }
            }
        }

        while( q-- != 0 ) {

            Integer l = in.nextInt() ,
            r = in.nextInt() ;

            Integer inc_cnt = 0, dec_cnt = 0 ;

            // first count maximal inc subs 
            for ( Integer i = 0 ; i < ki && increasing[i][1] <= r ; ++i ) {
                x = increasing[i][0] ;
                y = increasing[i][1] ;
                if ( (x >= l-1 && y <= r-1) || ( x < l-1 && l-1 < y ) || ( x < r-1 && r-1 < y ) ) {
                    ++inc_cnt ;
                }
            }
            // second count maximal dec subs 
            for ( Integer i = 0 ; i < kd && decreasing[i][1] <= r ; ++i ) {
                x = decreasing[i][0] ;
                y = decreasing[i][1] ;
                if ( (x >= l-1 && y <= r-1) || ( x < l-1 && l-1 < y ) || ( x < r-1 && r-1 < y ) ) {
                    ++dec_cnt ;
                }
            }

            if ( inc_cnt == dec_cnt && inc_cnt != 0 )
                System.out.println("YES") ;
            else
                System.out.println("NO") ;
        }

    }

}
