#include <stdio.h>
#include <math.h>

int main()
{
    double n;

    printf("Enter a large value of n: ");
    scanf("%lf", &n);

    printf("\nFunction Values for n = %.0lf\n\n", n);

    printf("1. 1/n              = %e\n", 1.0 / n);
    printf("2. log2(n)          = %.4lf\n", log2(n));
    printf("3. 12*sqrt(n)       = %.4lf\n", 12 * sqrt(n));
    printf("4. 50*n^0.5         = %.4lf\n", 50 * pow(n, 0.5));
    printf("5. n^0.51           = %.4lf\n", pow(n, 0.51));
    printf("6. n*log2(n)        = %.4lf\n", n * log2(n));
    printf("7. n^2 - 324        = %.4lf\n", n * n - 324);
    printf("8. 100*n^2 + 6*n    = %.4lf\n", 100 * n * n + 6 * n);
    printf("9. 2*n^3            = %.4lf\n", 2 * n * n * n);
    printf("10. n^(log2 n)      = %.4lf\n", pow(n, log2(n)));
    printf("11. 3^n             = %.4e\n", pow(3, n));
    printf("12. 2^(32n)         = %.4e\n", pow(2, 32 * n));

    printf("\nIncreasing Order of Growth (Asymptotically):\n\n");

    printf("1/n\n");
    printf("< log2(n)\n");
    printf("< 12*sqrt(n) = 50*n^0.5\n");
    printf("< n^0.51\n");
    printf("< n*log2(n)\n");
    printf("< n^2 - 324\n");
    printf("< 100*n^2 + 6*n\n");
    printf("< 2*n^3\n");
    printf("< n^(log2 n)\n");
    printf("< 3^n\n");
    printf("< 2^(32n)\n");

    return 0;
}