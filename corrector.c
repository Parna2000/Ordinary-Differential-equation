#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float y2, h, f2, f3,f4;
    printf("Enter y2,h,f2,f3,f4:\n");
    scanf("%f %f %f %f %f", &y2, &h, &f2, &f3,&f4);
    float a=y2+(((h)/3)*((f4)+(4*f3)+(f2)));
    printf("the corrector value is: %f\n",a);
    return 0;
}