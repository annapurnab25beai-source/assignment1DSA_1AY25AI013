#include <stdio.h>
#include <stdlib.h>

struct Student {
    int   roll_no;
    char  name[50];
    float marks;
};
static int read_students(struct Student *start, int count)
{
    for (int i = 0; i < count; i++) {
        struct Student *p = start + i;
        printf("Enter roll, name, marks: ");
        if (scanf("%d %19s %f", &p->roll_no, p->name, &p->marks) != 3) {
            printf("Invalid input.\n");
            return 0;
        }
    }
    return 1;
}
static void report(const struct Student *base, int n, const char *avg_label)
{
    const struct Student *top = base;
    float sum = 0.0f;
 for (int i = 0; i < n; i++) {
    const struct Student *p = base + i;
    sum += p->marks;
    if (p->marks > top->marks)
            top = p;
    }

    printf("\n%s: %.2f\n", avg_label, sum / n);
    printf("Topper: %s (Roll %d, Marks %.2f)\n", top->name, top->roll_no, top->marks);
}
int main(void)
{
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }
    struct Student *students =(struct Student*) malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    if (!read_students(students, n)) {
        free(students);
        return 1;
    }
 report(students, n, "Average marks");
 char choice;
 printf("\nAdd 2 more students? (y/n): ");
 scanf(" %c", &choice);
  if (choice == 'y' || choice == 'Y') {
    int new_n = n + 2;
    struct Student *tmp =(struct Student*) realloc(students, new_n * sizeof(struct Student));
        if (tmp == NULL) 
           { printf("Reallocation failed; keeping existing data.\n");
        } else {
           students = tmp;  
            if (read_students(students + n, 2)) {
              n = new_n;
              report(students, n, "Updated average marks");
            }
        }
    }
    free(students);
    return 0;
}
