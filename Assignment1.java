import java.util.Scanner;
import java.lang.Math;

public class Assignment1 {

    public static final Scanner input = new Scanner(System.in);

    public static void main(String[] args) {

       long startTimeODD = System.nanoTime();
       OddNums();
       long endTimeODD = System.nanoTime();
       long totalTimeODD = endTimeODD - startTimeODD;
       System.out.println("OddNums method took: " + totalTimeODD + " nanoseconds");

       long startTimeCAL = System.nanoTime();
       CalenderOps();
       long endTimeCAL = System.nanoTime();
       long totalTimeCAL = endTimeCAL - startTimeCAL;
       System.out.println("CalenderOps took: " + totalTimeCAL + " nanoseconds");

       long startTimeMAX = System.nanoTime();
       FindMax();
       long endTimeMAX = System.nanoTime();
       long totalTimeMAX = endTimeMAX - startTimeMAX;
       System.out.println("FindMax took: " + totalTimeMAX + " nanoseconds");

       long startTimeTEMP = System.nanoTime();
       ConvertTemp();
       long endtimeTEMP = System.nanoTime();
       long totalTimeTEMP = endtimeTEMP - startTimeTEMP;
       System.out.println("ConverTemp took: " + totalTimeTEMP + " nanoseconds");
        

    }

    public static void OddNums(){
        System.out.println("__________________________");
        System.out.println("Print Odd Nums:");
        System.out.println("The Odd Numbers are:");
		for (int i = 1; i <= 1001; i++) {
			if (i % 2 != 0) {
				System.out.print(i+ ((i%20==9) ? "\n" : " "));
			}
        }
        System.out.println();
    }

    public static void CalenderOps(){
        System.out.println("__________________________");
        System.out.println("Calender Conversions:");
        System.out.println("Enter number of days");
        double days = input.nextInt();

        double years = days/365;
        double months = days/12;

        System.out.println("Days: " + days);
        System.out.println("Years: " + years);
        System.out.println("Months: " + months);

        System.out.println();
    }

    public static void FindMax(){
        System.out.println("__________________________");
        System.out.println("Find Max:");
        System.out.println("Enter 3 integers: ");
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int num3 = input.nextInt();
        
        int max = Math.max(num1,num2);
        if(max>num2){
            max = Math.max(num1,num3);    
       }
        else { 
            max = Math.max(num2,num3);    
     }
        System.out.println("The max integer is: " + max);
        System.out.println();
    }

    public static void ConvertTemp(){
        System.out.println("__________________________");
        System.out.println("Temperature Conversion:");
        System.out.println("Enter your degrees in Fahrenheit");
        double tempF = input.nextDouble();

        double tempC = (tempF-32.0)*(5.0/9.0);

        System.out.println("Temp (F) to Temp (C): ");
        System.out.printf("%.2f", tempC);
        //System.out.printf("Temp (F) to Temp (C): " + temp);
        System.out.println();

    }
}

