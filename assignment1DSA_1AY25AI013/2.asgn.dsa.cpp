#include <stdio.h> 

typedef struct {
  int degree;
  float coef[101];
} polynomial; 
polynomial add(polynomial a, polynomial b)
{
  polynomial c;
  int i, maxDegree;
  maxDegree = (a.degree > b.degree) ? a.degree : b.degree;
  c.degree = maxDegree;
    for (i = 0; i <= maxDegree; i++)
       c.coef[i] = 0;
    for (i = 0; i <= a.degree; i++)
       c.coef[maxDegree - a.degree + i] += a.coef[i];
    for (i = 0; i <= b.degree; i++)
       c.coef[maxDegree - b.degree + i] += b.coef[i];
    return c;
}
void display(polynomial p)
{
    int i, exp, first = 1;
    float c;
    for (i = 0; i <= p.degree; i++)
    {
      c = p.coef[i];
      exp = p.degree - i;
      if (c == 0)
       continue;
      if (!first)
      {
         if (c > 0)
            printf(" + ");
         else
            printf(" - ");
        }
        else if (c < 0)
        {
            printf("-");
        }
        if (c < 0)
            c = -c;
        if (exp == 0)
           printf("%g", c);
        else if (exp == 1)
           printf("%gx", c);
        else
           printf("%gx^%d", c, exp);

        first = 0;
    }
    if (first)
    printf("0");
    printf("\n");
}
int main()
{
    polynomial a, b, c;
    int i;
    printf("Enter degree of polynomial A: ");
    scanf("%d", &a.degree);
    printf("Enter coefficients of A from highest to lowest power:\n");
    for (i = 0; i <= a.degree; i++)
   {
	scanf("%f", &a.coef[i]); }
    printf("Enter degree of polynomial B: ");
     scanf("%d", &b.degree);
    printf("Enter coefficients of B from highest to lowest power:\n"); 
for (i = 0; i <= b.degree; i++)
    scanf("%f", &b.coef[i]);
    printf("\nPolynomial A: ");
    display(a);
    printf("Polynomial B: ");
    display(b); 
    c = add(a, b);
    printf("Sum: ");
    display(c);
    return 0;
}

