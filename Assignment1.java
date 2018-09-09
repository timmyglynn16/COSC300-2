import java.util.Scanner;

public class Assignment1 {

    public static void main(String[] args) {

       //OddNums();
       CalenderOps();
        

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
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of days");
        double days = sc.nextInt();

        //convert to years
        double years = days/365;
        System.out.println("Days converted to years: " + years);

    }
}

