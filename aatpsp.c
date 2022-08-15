#include <stdio.h>
#define pi 3.1415

// mech efficiency = (bp/ip)*100;

float IP(int i, float pm, float n, float l, float a, float k)
{

    return ((i * pm * l * a * n * k * 10.0) / 6.0);
}

int main(int argc, char const *argv[])
{
    // Indicated Power

    int i;
    float pm, l, a, k, n, st,d,b,dd;
    float eff, bp, t;

    printf("Enter Number of Cylinders in the Engine: ");
    scanf("%d", &i);

    printf("Enter Mean Effective Pressure (in bar): ");
    scanf("%f", &pm);

    printf("Enter Length of the Stroke (in meter): ");
    scanf("%f", &l);

    printf("Enter bore diameter of the Engine Cylinder (in meter): ");
    scanf("%f", &d);

    a = (pi * d * d)/4;

    printf("Enter the break drum diameter (in meter):");
    scanf("%f", &dd);

    printf("Enter Crank Shaft Speed (in RPM): ");
    scanf("%f", &n);

    printf("Enter 2 for a 2-Stroke Engine and 4 for a 4-Stroke Engine: ");
    scanf("%f", &st);

    if (st == 4)
        k = 0.5;

    else if (st == 2)
        k = 1;

    printf("Enter The brake load (in kg):");
    scanf("%f", &b);

    t = (b * dd * 9.8 ) / 2;

    float ip = IP(i, pm, n, l, a, k);

    printf("The Indicated Power of the Engine is %f kW\n", ip);

    // Brake Power

    bp = (2 * pi * n * t) / 60000;

    eff = bp * 100 / ip;

    printf("Brake Power of the Engine is %f kW\n", bp);

    printf("Factional Power of the Engine is %f kW\n", (ip - bp));

    printf("The Efficiency of Engine is %f\n", eff);

    return 0;
}
