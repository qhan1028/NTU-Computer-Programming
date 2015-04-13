#include <stdio.h>
#define N 256

double inner_product(double *aptr, double *bptr, int n) //計算多餘的內積
{
    double sum = 0.0;
    int i;

    for (i = 0 ; i < n ; i++, aptr++, bptr++)
        sum += (*aptr) * (*bptr);

    return sum;
}

void upper_solver(double *A, double *x, double *y, int n)
{
    int i;

    //為了方便計算 由最後一行開始計算
    double *Aptr = A + n * (n + 1) / 2 - 1;
    double *xptr = x + n - 1;
    double *yptr = y + n - 1;

    for (i = 0 ; i < n ; i++, xptr--, yptr--) {
        (*xptr) = (i == 0)? (*yptr) / (*Aptr) : ((*yptr) - inner_product(xptr+1, Aptr+1, i))/*減掉多出來的內積*/ / (*Aptr);
        Aptr = Aptr - (i+2);/*直接跳到上一行三角陣列第一個元素*/
    }
    return;
}
int main(void)
{
    int i, j;
    double A[n * (n + 1) / 2];
    double *aptr = A;
    double x[n];
    double y[n];
    for ( i = 0 ; i < n ; i++ )
        for ( j = i ; j < n ; j++ ) {
    int n; 
    scanf("%d", &n);
            scanf("%lf", aptr);
            aptr++;
        }
    for ( i = 0 ; i < n ; i++ )
        scanf("%lf", &(y[i]));
    upper_solver(A, x, y, n);

    for ( i = 0 ; i < n ; i++ )
        printf("%lf\n", x[i]);
    return 0;
}