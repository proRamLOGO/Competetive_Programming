// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;

// Please name your class Main
class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[]=new int[2*n];
		int j=1;
		
		for(int i=0;i<2*n;i++)
		{
		    j=i++;
		    System.out.println((j+1)+" "+(i+1));
		    System.out.println("MATCH");
		}
	    System.out.println(-1);
	
	}
}