#include <stdio.h>
#include <stdlib.h>
const int n=3;

int main()
{
    float a[n][n+1],  c;
    int i, j, k, p;
    printf("enter extended system matrix\n");
    for (i=0; i<n; i++)
        for (j=0; j<n+1; j++) scanf("%f", &a[i][j]);
    for (k=0; k<1; k++)
    {
        if (a[k][k]==0)
        {
            p=k+1;
            while (a[p][k]==0) p++;
            for (j=k; j<n+1; j++)
            {
                c=a[p][j];
                a[p][j]=a[k][j];
                a[k][j]=c;
            }
        }
        for (i=k+1; i<n; i++)
            for (j=n; j>=k; j--) a[i][j]=a[i][j]-a[i][k]*a[k][j]/a[k][k];

    }
for (j=n-1; j>0; j--)
    {
    for (i=j-1; i>=0; i--)
    {
        a[i][n]=a[i][n]-a[i][j]*a[j][n]/a[j][j];
        a[i][j]=0;
    }
    }
for (i=0; i<n; i++) printf("%4.1f ", a[i][n]/a[i][i]);

    return 0;
}
