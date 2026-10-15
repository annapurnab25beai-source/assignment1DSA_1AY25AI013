#include <stdio.h>

typedef struct { int row, col, value; } term;
int main() {
    term a[50], b[50];
    int row_terms[10], starting_pos[10];
    int r, c, i, j, x, n = 0;
    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
      for (j = 0; j < c; j++) {
        scanf("%d", &x);
          if (x != 0) {            
           n++;
           a[n].row = i;
           a[n].col = j;
           a[n].value = x;
        }
     }
    a[0].row = r; a[0].col = c; a[0].value = n;  
    printf("Original triples:\n");
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    for (i = 0; i < c; i++) row_terms[i] = 0;
    for (i = 1; i <= n; i++) row_terms[a[i].col]++;
    starting_pos[0] = 1;
    for (i = 1; i < c; i++)
       starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
    printf("\nrow_terms    : ");
    for (i = 0; i < c; i++) printf("%d ", row_terms[i]);
    printf("\nstarting_pos : ");
    for (i = 0; i < c; i++) printf("%d ", starting_pos[i]);
    b[0].row = c; b[0].col = r; b[0].value = n;
    for (i = 1; i <= n; i++) {
        j = starting_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
    printf("\n\nTransposed triples:\n");
    for (i = 0; i <= n; i++)
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    return 0;
}
