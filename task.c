
#include "function.h"
#include "task.h"

void task1() {
void findFourBits() {
    char num = getValidCharInteger(-128, 127); 
    printHigherBits(num); 
}
}

void task2() {
    printf("Please, enter the desired number of jobs: ");
    int number;
    input_Number(&number);
    struct workinfo* job = NULL;
    input_Workinfo(&job, number);

    while (1) {
        puts("\nMenu:");
        printf("1. Find jobs by salary\n");
        printf("2. Delete jobs with a title shorter than the specified length\n");
        printf("3. Exit\n");
        char option;
        scanf(" %c", &option);

        switch (option) {
            case '1': {
                float desired_Salary;
                printf("Enter desired salary: ");
                scanf("%f", &desired_Salary);
                if (find_Job(job, desired_Salary, number) == 0) {
                    printf("No jobs found with the salary %.2f\n", desired_Salary);
                }
                break;
            }
            case '2': {
                int min_title;
                printf("Enter the minimum title length: ");
                input_Number(&min_title);
                delete_Job(&job, min_title, &number);
                printf("Jobs after deletion:\n");
                for (int i = 0; i < number; ++i) {
                    output_Workinfo(job, i);
                }
                break;
            }
            case '3': {
                for (int i = 0; i < number; ++i) {
                    free(job[i].title);
                }
                free(job);
                return;
            }
            default:
                printf("Invalid option\n");
                break;
        }
    }
}
