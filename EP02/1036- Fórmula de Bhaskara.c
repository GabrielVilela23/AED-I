#include <stdio.h>
#include <math.h>

int main() {
 
    double a, b, c, r1, r2, alpha, t;
    scanf ("%lf %lf %lf", &a, &b, &c);
    
    alpha=(b*b)-(4*a*c);
    
    if (alpha<0 || a==0){
        printf ("Impossivel calcular\n");
    }
    else{
        t= sqrt(alpha);
        r1=(-b+t)/(2*a);
        r2=(-b-t)/(2*a);
        printf ("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
    }
    
    return 0;
}