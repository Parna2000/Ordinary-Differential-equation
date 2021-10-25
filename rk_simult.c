#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// this is dz/dx
double d2f(double x, double y, double z)
{
    double f2;
    f2 = y+(x*x);
    return f2;
}

// this is dy/dx
double df(double x, double y, double z)
{
    double f1;
    f1 =z+(x*x);
    return f1;
}
void rk4o2(double x0, double y0, double z0, double h, double x1)
{
    int i, n;
    double k1, k2, k3, k4, k, *x, *y, *z, l1, l2, l3, l4, l;
    n = (x1 - x0) / h;
    x = (double *)calloc(n + 1, sizeof(double));
    y = (double *)calloc(n + 1, sizeof(double));
    z = (double *)calloc(n + 1, sizeof(double));
    x[0] = x0;
    y[0] = y0;
    z[0] = z0;
    for (i = 0; i < n + 1; i++)
    {
        k1 = df(x[i], y[i], z[i]);
        l1 = d2f(x[i], y[i], z[i]);
        k2 = df(x[i] + h / 2, y[i] + h * k1 * 0.5, z[i] + h * l1 * 0.5);
        l2 = d2f(x[i] + h / 2, y[i] + h * k1 * 0.5, z[i] + h * l1 * 0.5);
        k3 = df(x[i] + h / 2, y[i] + h * k2 * 0.5, z[i] + h * l2 * 0.5);
        l3 = d2f(x[i] + h / 2, y[i] + h * k2 * 0.5, z[i] + h * l2 * 0.5);
        k4 = df(x[i] + h, y[i] + h * k3, z[i] + h * l3);
        l4 = d2f(x[i] + h, y[i] + h * k3, z[i] + h * l3);
        k = (k1 + (2 * k2) + (2 * k3) + k4)/6;
        l = (l1 + (2 * l2) + (2 * l3) + l4)/6;
        x[i + 1] = x[i] + h;
        y[i + 1] = y[i] + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        z[i + 1] = z[i] + h * (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        printf("k1=%f, k2=%f, k3=%f, k4=%f, k_avg=%f\n", h*k1, h*k2, h*k3, h*k4, h*k);
        printf("l1=%f, l2=%f, l3=%f, l4=%f, l_avg=%f\n", h*l1, h*l2, h*l3, h*l4, h*l);
        printf("y(%0.2lf)=%lf\tz(%0.2lf)=%lf\n", x[i + 1], y[i + 1], x[i + 1], z[i + 1]);
    }
}
int main()
{
    void rk2(double, double, double, double, double);
    double x, y, h, x1, z;
    printf("Enter the value of x[0] and y[0] and z[0]:\n");
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("Enter the value of h:\n");
    scanf("%lf", &h);
    printf("Enter x1 for which you want to find y(x1) and z(x1):\n");
    scanf("%lf", &x1);
    rk4o2(x, y, z, h, x1);
    return 0;
}