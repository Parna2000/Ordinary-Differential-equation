// Value of a function
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(float x,float y)
{
    float f = (x*x)+(y*y);
    return f;
}
int main()
{
    float x, h;
    printf("Enter the initial value of x:\n");
    scanf("%f", &x);
    printf("Enter the increment:\n");
    scanf("%f", &h);
    int n;
    printf("Enter the number of terms you want to get:\n");
    scanf("%d", &n);
    float y[n];
    printf("Enter the %d values of y:\n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&y[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("f(%f,%f) = %f\n", x,y[i], function(x,y[i]));
        x = x + h;
    }
    return 0;
}