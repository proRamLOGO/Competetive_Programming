import java.util.*;
import java.lang.*;
import java.io.*;

class CHFPSA_2 {

    public static void printarr( int [][] arr, int n ) {

        for ( int i = 0 ; i < n ; ++i ) {
            System.out.print(arr[i] + " ") ;
        }
        System.out.println() ;

    }

    public static int fact( int n ) { 
        if (n == 0) 
            return 1; 
        return n * fact(n-1); 
    }

    public static void main (String[] args) throws IOException {
    
        System.setIn( new FileInputStream( new File( "input.txt" ))) ;
        System.setOut( new PrintStream( new File( "output.txt" ) ) ) ;
        Scanner in = new Scanner(System.in) ;

        int t = in.nextInt() ;

        while ( t-- != 0 ) {

            int n = in.nextInt() ;
            int[] arr = new int[n+n] ;
            int sum_of_pre_and_suff_arr = 0 ;
            HashMap< Integer, Integer > freq = new HashMap<>() ;

            for ( int i = 0 ; i < 2*n ; ++i ) {
                arr[i] = in.nextInt() ;
                sum_of_pre_and_suff_arr += arr[i] ;

                if ( freq.get(arr[i])!=null )
                    freq.put(arr[i],freq.get(arr[i])+1) ;
                else
                    freq.put(arr[i],1) ;

            }

            // Arrays.sort(arr) ;

            int a_sum = sum_of_pre_and_suff_arr / (n+1) ;

            int aSum_freq = 0 ;

            for ( int i = 0 ; i < 2*n ; ++i ) {
                if (a_sum == arr[i])
                    ++aSum_freq ;
                if (aSum_freq == 2 )
                    break ;
            }

            if ( aSum_freq < 2 ) {
                System.out.println(0) ;
                continue ;
            }

            int no_of_pairs_of_a = 0, same_pairs = 0, rep_pairs = 1;


            for ( Map.Entry< Integer , Integer > i : freq.entrySet() ) {
                if ( freq.get(a_sum-i.getKey()) == null )  
                    continue ;

                int a = i.getKey() ;
                int b = a_sum-a ;

                if ( b < a )
                    break ;

                if ( a==b )
                    no_of_pairs_of_a  = ( freq.get(a) * (freq.get(b)-1) ) / 2  ;
                else 
                    no_of_pairs_of_a  = ( freq.get(a) * freq.get(b) ) ;

                if ( freq.get(a)==1 || freq.get(b)==1 )
                    rep_pairs *= fact((Math.max(freq.get(a), freq.get(b)))) ;

                if ( a == b )
                    same_pairs = freq.get(a) ;

            }

            // Here was OLD code
            
            int raiser = no_of_pairs_of_a - same_pairs ;
            int power = (int)(Math.pow(2 , raiser )) ;
            int ans =  ( (fact(no_of_pairs_of_a)) * (power) ) / rep_pairs ;
            System.out.println( ans%1000000007 ) ;

        }

    }

}

/* HashMap< ArrayList<Integer>, Integer > pair_freq = new HashMap<>() ;

            for ( int i = 0 ; i < 2*n ; ++i ) {
                for ( int j = i+1 ; j < 2*n ; ++j ) {
                    if ( arr[i]+arr[j] == a_sum ) {
                        
                        ArrayList newPair = new ArrayList();
                        newPair.add(arr[i]) ;
                        newPair.add(arr[j]) ;

                        if ( pair_freq.get(newPair) == null ) {
                            pair_freq.put(newPair,1) ;
                        } else {
                            pair_freq.put(newPair,1+pair_freq.get(newPair)) ;
                        }

                        ++no_of_pairs_of_a ;
                        if ( arr[i]==arr[j] )
                            ++same_pairs ;
                    }
                }
            }

            int rep_pairs = 0 ;

            for ( Map.Entry< ArrayList<Integer>, Integer > pairs_cnt : pair_freq.entrySet() ) {
                if ( pairs_cnt.getValue() > 1 )
                    ++rep_pairs ;
            }

            // System.out.println(rep_pairs)

            if ( no_of_pairs_of_a == 0 ) {
                System.out.println(0) ;
                continue ;
            } */
