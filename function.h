#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    unsigned int high_bits : 4;
} BitField;
char getValidCharInteger(int min, int max);
void printHigherBits(char num);
void findFourBits();

struct workinfo;
void input_Number(int*);
char* input_String(int*);
void input_Additions(struct workinfo*);
void input_Workinfo(struct workinfo**, int);
void output_Workinfo(struct workinfo*, int);
int find_Job(struct workinfo*, float, int);
void delete_Job(struct workinfo**, int, int*);

struct workinfo {
    char *title;
    double salary;
    int experience;
    struct {
        char requirements[50];
    } additions;
};

#endif
