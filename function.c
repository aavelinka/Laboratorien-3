#include"function.h"


char getValidCharInteger(int min, int max) {
    char num;
    int valid = 0;

    while (!valid) {
        printf("Enter a number between %d and %d: ", min, max);
        if (scanf("%hhd", &num) == 1) {
            if (num >= min && num <= max) {
                valid = 1;
            } else {
                printf("The number must be between %d and %d.\n", min, max);
            }
        } else {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');
        }
    }
    return num;
}

void printHigherBits(char num) {
    BitField bitField;
    bitField.high_bits = (num >> 4) & 0x0F;
    printf("Upper 4 bits: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (bitField.high_bits >> i) & 1); 
    }
    printf("\n");
}

void findFourBits() {
    char num = getValidCharInteger(-128, 127); 
    printHigherBits(num); 
}

void input_Number(int* number) {
    rewind(stdin);
    *number = 0;
    int digit;
    int sign = 1;
    while ((digit = getchar()) != '\n' && digit != ' ') {
        if (digit == '-') {
            sign = -1;
        } else if (digit < '0' || digit > '9') {
            printf("Incorrect number\n");
            while ((digit = getchar()) != '\n' && digit != ' ');
            *number = 0;
            return;
        } else {
            *number = *number * 10 + (digit - '0');
        }
    }
    *number *= sign;
}

char* input_String(int* len_str) {
    *len_str = 0;
    int capacity = 1;
    char* s = (char*)malloc(capacity * sizeof(char));

    char c;
    while ((c = getchar()) != '\n') {
        if (*len_str + 1 >= capacity) {
            capacity *= 2;
            s = (char*)realloc(s, capacity * sizeof(char));
        }
        s[(*len_str)++] = c;
    }
    s[*len_str] = '\0';
    return s;
}

void input_Workinfo(struct workinfo** job, int number) {
    *job = (struct workinfo*)malloc(number * sizeof(struct workinfo));
    if (*job == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < number; ++i) {
        int len_title;
        printf("%d Job:\n", i + 1);
        printf("Enter the job title: ");
        (*job)[i].title = input_String(&len_title);
        printf("Enter salary: ");
        scanf("%lf", &(*job)[i].salary);
        printf("Enter experience: ");
        input_Number(&(*job)[i].experience);
        printf("Do you want to fill out additional requirements? (1 - YES, 0 - NO): ");
        char option;
        scanf(" %c", &option);
        if (option == '1') {
            printf("Enter requirements: ");
            scanf(" %s", (*job)[i].additions.requirements);
        } else {
            strcpy((*job)[i].additions.requirements, "No additions");
        }
    }
}

void output_Workinfo(struct workinfo* job, int i) {
    printf("%d Job:\n", i + 1);
    printf("Title: %s\n", job[i].title);
    printf("Salary: %.2lf\n", job[i].salary);
    printf("Experience: %d\n", job[i].experience);
    printf("Requirements: %s\n", job[i].additions.requirements);
}

int find_Job(struct workinfo* job, float desired_Salary, int number) {
    int flag = 0;
    for (int i = 0; i < number; ++i) {
        if (job[i].salary == desired_Salary) {
            output_Workinfo(job, i);
            flag++;
        }
    }
    return flag;
}

void delete_Job(struct workinfo** job, int min_title, int* number) {
    for (int i = 0; i < *number; ) {
        if (strlen((*job)[i].title) < min_title) {
            free((*job)[i].title);
            for (int j = i; j < *number - 1; ++j) {
                (*job)[j] = (*job)[j + 1];
            }
            (*number)--;
        } else {
            i++;
        }
    }
}
