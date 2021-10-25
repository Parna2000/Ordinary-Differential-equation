#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float y0, h, f1, f2, f3;
    printf("Enter y0,h,f1,f2,f3:\n");
    scanf("%f %f %f %f %f", &y0, &h, &f1, &f2, &f3);
    float a=y0+(((4*h)/3)*((2*f3)-f2+(2*f1)));
    printf("the predictor value is: %f\n",a);
    return 0;
}