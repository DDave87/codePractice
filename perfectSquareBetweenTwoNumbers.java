/* package whatever; // don't place package name! */
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static boolean isPerfect(double x){
		double tempsqrt = Math.floor(Math.sqrt(x*1.0));
		if(tempsqrt*tempsqrt == x){
			return true;
		}
		else {
			return false;
		}
	}//isPerfectSqare
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for(int i=0;i<t;i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			//System.out.println("A="+a+"B="+b);
			double x = Math.floor(Math.sqrt(a*1.0));
			double y = Math.floor(Math.sqrt(b*1.0));
			
			if(a==b & isPerfect(a*1.0)){
				System.out.println(1);
			}
			else if(isPerfect(a*1.0)){
				System.out.println((int)(y-x+1));
			}
			else{
				System.out.println((int)(y-x));
			}
			
			
			
		}

	}
}