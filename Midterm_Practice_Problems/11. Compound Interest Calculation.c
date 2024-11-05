#include <stdio.h>
#include <math.h>


double Calculate_Interest(int principle, double interest_rate, int years, int frequency){
    return principle * pow((1+interest_rate/frequency),(years*frequency));
}

int main(){
    // create Var
    int years,frequency;
    double principle,interest_rate;
    printf("Enter Principle(1000), Interest_Rate (0.05), Years(10), frequency(4): ");
    //Take Inputs
    scanf("%lf",&principle);
    scanf("%lf",&interest_rate);
    scanf("%d",&years);
    scanf("%d",&frequency);
    
    //print Calculations
    printf("%.2lf\n",Calculate_Interest(principle,interest_rate,years,frequency));

    return 0;
}
