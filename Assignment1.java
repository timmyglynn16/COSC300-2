import java.util.Scanner;
import java.lang.Math;

public class Assignment1 {

    public static final Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

       //OddNums();
       //CalenderOps();
       FindMax();
        

    }

    public static void OddNums(){
        System.out.println("The Odd Numbers are:");
		for (int i = 1; i <= 1001; i++) {
			if (i % 2 != 0) {
				System.out.print(i+ ((i%20==9) ? "\n" : " "));
			}
		}
    }

    public static void CalenderOps(){
        
        System.out.println("Enter number of days");
        double days = input.nextInt();

        //convert to years
        double years = days/365;
        System.out.println("Days converted to years: " + years);

        //conert to months
        double months = days/12;
        System.out.println("Days converted to months: " + months);

        //conver to WHAT??

    }

    public static void FindMax(){
        System.out.println("Enter 3 integers: ");
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int num3 = input.nextInt();
        
        int max = Math.max(num1,num2);
        if(max>num2){ //suppose x is max then compare x with z to find max number
            max = Math.max(num1,num3);    
        }
        else{ //if y is max then compare y with z to find max number
            max = Math.max(num2,num3);    
        }
        System.out.println("The max integer is: " + max);

    }
}

