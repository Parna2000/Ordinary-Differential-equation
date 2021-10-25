// Value of a function
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(float x)
{
    float f = 1+x-(x*x)+(pow(x,4)/12);
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
    for (int i = 0; i < n; i++)
    {
        printf("y(%f) = %f\n", x, function(x));
        x = x + h;
    }
    return 0;
}