#include<stdio.h>
//#include<conio.h>
#define MAX 50

int main ()
{
int a[MAX][MAX], b[MAX][MAX],product[MAX][MAX];
int arows, acolumns, brows, bcolumns;
int i, j, k;
int sum = 0;

printf("enter the rows and columns of matrix a: ");
scanf("%d %d",&arows, &acolumns);

printf("enter the element of the matrix a:\n");
for(i=0; i<arows; i++)
{
for(j=0; j<acolumns; j++)

{
scanf("%d", &a[i][j]);
}
}
printf("enter the rows and columns of matrix b : ");
scanf("%d %d",&brows, &bcolumns);
if(brows != acolumns)
{
printf("can't be multiplied");
}
else
{
printf("enter the elemnets of matrix b:\n");
for(i=0; i<brows; i++)
{
for(j=0; j<bcolumns; j++)
{
scanf("%d" , &b[i][j]);
}
}
}

printf("\n");
for(i=0; i<arows; i++)
{
for(j=0; j<bcolumns; j++)
{

for(k=0; k<brows; k++)
{
sum += a[i][k] * b[k][j];
}
product[i][j] = sum;
sum = 0;

}

}

printf("Resultant matrix\n");
for(i=0; i<arows; i++)
{

for(j=0; j<bcolumns; j++)
{
printf("%d ", product[i] [j]);
}
printf("\n");
}

//getch();
return 0;
}
