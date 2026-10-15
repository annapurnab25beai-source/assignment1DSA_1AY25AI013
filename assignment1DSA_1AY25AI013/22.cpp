#include <stdio.h>
#include <stdlib.h>

enum EmpType { FULL_TIME, CONTRACT };
typedef struct {
    char name[40];
    int  emp_id;
    enum EmpType type;
    union {
        float salary;                                                   
        struct { float hourly_rate; int hours_worked; } contract_info;  
    } pay;
} Employee;
int main() {
    int n, i, choice;
    float total, grand_total = 0;

    printf("How many employees? ");
    scanf("%d", &n);

    Employee *emp = (Employee *)malloc(n * sizeof(Employee));

    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("ID: ");
        scanf("%d", &emp[i].emp_id);

        printf("Type (0 = Full-time, 1 = Contract): ");
        scanf("%d", &choice);

        if (choice == 0) {
            emp[i].type = FULL_TIME;
            printf("Monthly salary: ");
            scanf("%f", &emp[i].pay.salary);
        } else {
            emp[i].type = CONTRACT;
            printf("Hourly rate: ");
            scanf("%f", &emp[i].pay.contract_info.hourly_rate);
            printf("Hours worked: ");
            scanf("%d", &emp[i].pay.contract_info.hours_worked);
        }
    }

    for (i = 0; i < n; i++) {
        printf("\n===== PAYSLIP =====\n");
        printf("Name: %s\n", emp[i].name);
        printf("ID  : %d\n", emp[i].emp_id);

        if (emp[i].type == FULL_TIME) {
            printf("Type: Full-time\n");
            total = emp[i].pay.salary;
        } else {
            printf("Type: Contract\n");
            total = emp[i].pay.contract_info.hourly_rate *
                    emp[i].pay.contract_info.hours_worked;
        }
        printf("Total Pay: %.2f\n", total);
        grand_total = grand_total + total;
    }
    printf("\nTotal salary bill of the company: %.2f\n", grand_total);

    free(emp);
    return 0;
}
