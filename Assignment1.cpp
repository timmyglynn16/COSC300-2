#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <chrono>

using namespace std;


void OddNums(){

    cout << "Print Odd Numbers from 1 to 10001";
    cout << "\n\n";
    for (int a=1; a<=10001; a+=2) {
     
        cout << " " << a << " ";\
        if ((a % 20) == 9) // print 10 lines per line
        cout << endl;
    }

    cout << endl;

}

void CalenderOps(){

    cout << "__________________________" << endl;
    cout << "Calender Conversions:";
    cout << endl;

    cout << "Enter how many days:" << endl;
    double day;
    cin >> day; 
    cout << endl;

    double year = day/365.0;
    double month = day * 0.032855; 

    cout << "Days: " << day << endl;
    cout << "Years: " << year << endl;
    cout << "Months: " << month << endl;

}

void FindMax() {
    cout << "__________________________" << endl;
    cout << "Find Max:";
    cout << endl;

    cout << "Enter 3 integers: " << endl;
    double num1;
    double num2;
    double num3;

    cin >> num1 >> num2 >> num3;
    cout << endl;

	int max = num1; /* assume x is the largest */

	if (num2 > max) { /* if y is larger than max, assign y to max */
		max = num2;
	} /* end if */

	if (num3 > max) { /* if z is larger than max, assign z to max */
		max = num3;
	} /* end if */

	cout << "The max integer is: " << max << endl;

}

void ConvertTemp(){
    cout << "__________________________" << endl;
    cout << "Temperature Conversion: ";
    cout << endl;

    cout << "Enter your temperature in Fahrenheit" << endl;
    
    double tempF;
    cin >> tempF;
    cout << endl;

    double tempC = (tempF-32.0)*(5.0/9.0);

    cout << "Temp (F) to Temp (C): ";
    cout << fixed << setprecision(2) << tempC << endl; 

}

//main has to be called last??
int main() {
    //std::cout << "Main was reached";

    auto startODD = chrono::steady_clock::now();
    OddNums();
    auto endODD = chrono::steady_clock::now();
    auto totalODD = endODD - startODD;
    cout << "OddNums function took: " << chrono::duration <double, nano> (totalODD).count() << " nanoseconds" << endl;

    auto startCAL = chrono::steady_clock::now();
    CalenderOps();
    auto endCAL = chrono::steady_clock::now();
    auto totalCAL = endCAL - startCAL;
    cout << "CalenderOps function took: " << chrono::duration <double, nano> (totalCAL).count() << " nanoseconds" << endl;

    auto startMAX = chrono::steady_clock::now();
    FindMax();
    auto endMAX = chrono::steady_clock::now();
    auto totalMAX = endMAX - startMAX;
    cout << "FindMax function took: " << chrono::duration <double, nano> (totalMAX).count() << " nanoseconds" << endl;

    auto startTEMP = chrono::steady_clock::now();
    ConvertTemp();
    auto endTEMP = chrono::steady_clock::now();
    auto totalTEMP = endTEMP - startTEMP;
    cout << "CalenderTemp function took: " << chrono::duration <double, nano> (totalTEMP).count() << " nanoseconds" << endl;
}
