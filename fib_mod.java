import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class fib_mod {

    // Complete the fibonacciModified function below.
    static int fibonacciModified(int t1, int t2, int n) {

        int sum = 0 ;
        
        for ( int i = 3 ; i <= n ; ++i ) {
            sum = t1 + t2*t2 ;
            t1 = t2 ;
            t2 = sum ;
        }

        return sum ;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args)  {
        Scanner in = new Scanner( System.in ) ;
        int t1, t2, n ;
        t1 = in.nextInt() ;
        t2 = in.nextInt() ;
        n = in.nextInt() ;
        System.out.println(fibonacciModified(t1,t2,n)) ;
    }
}
