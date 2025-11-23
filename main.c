#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct Polynomial {
    unsigned short degree;
    float *terms;
}Polynomial;

typedef struct Table {
    Polynomial *first_func;
    Polynomial *middle_func;
    Polynomial *last_func;
    float neg_u0;
    float neg_v0;
    float delta_u;
    float delta_v;
    float u_k1;
    float v_k1;
}Table;

typedef struct Sheet {
    float tolerance;
    Polynomial *func;
    LinkedList *tables;
}Sheet;


Polynomial *create_equation(unsigned short degree);
Sheet *create_sheet(unsigned short degree);
Table *create_table(float u0, float v0, Polynomial *first_func);
void display(Polynomial *func);

unsigned short input_degree() {
    unsigned short degree;
    printf("Enter degree of the Polynomial: ");
    scanf("%d", &degree);
    if(degree < 2 || degree > 5) {
        return input_degree();
    }
    return degree;
}

int main() {
    unsigned short degree = input_degree();
    Sheet *sheet1 = create_sheet(degree);

    
    return 0;
}

Sheet *create_sheet(unsigned short degree) {
    Sheet *paper = (Sheet*) malloc(sizeof(Sheet));
    paper->func = create_equation(degree);
    paper->tables = create_list();
    printf("Enter Tolerance: ");
    scanf("%f", &paper->tolerance);
    add_table(paper->tables, create_table(1,1, paper->func));    
    return paper;
}


Polynomial *create_equation(unsigned short degree) {
    Polynomial *func = (Polynomial*) malloc(sizeof(Polynomial));
    func->terms = (float *) malloc (degree * sizeof(float));
    func->degree = degree;
    for(int i=0; i<degree;i++) {
        printf("Enter Coefficient (x^%d): ", degree-i-1);
        scanf("%f", &func->terms[i]);
    }


    return func;
}

float delta_u_formula(Polynomial *b_func, Polynomial *c_func) {
    unsigned short max = b_func->degree - 1;

    return ((b_func->terms[max] * c_func->terms[max-3]) - (b_func->terms[max-1] * c_func->terms[max-2])) /
            ((c_func->terms[max-1] * c_func->terms[max-3])-(c_func->terms[max-2] * c_func->terms[max-2]));
}

float delta_v_formula(Polynomial *b_func, Polynomial *c_func) {
    unsigned short max = b_func->degree - 1;

    return  ((c_func->terms[max-1] * b_func->terms[max-1])-(b_func->terms[max] * c_func->terms[max-2])) / 
            ((c_func->terms[max-1] * c_func->terms[max-3])-(c_func->terms[max-2] * c_func->terms[max-2]));

}

Polynomial *equate(float neg_u0, float neg_v0, Polynomial *func) {
    Polynomial *new_func = (Polynomial*)malloc(func->degree * sizeof(func));
    new_func->degree = func->degree;

    new_func->terms = (float*)malloc(func->degree * sizeof(float));

    for(int i=0;i<func->degree;i++) {
        if(i==0) {
            new_func->terms[i] = func->terms[i];
        } else if(i==1) {
            new_func->terms[i] = func->terms[i] + (neg_u0 * new_func->terms[i-1]);
        }
        else {
            new_func->terms[i] = func->terms[i] + (neg_u0 * new_func->terms[i-1]) + (neg_v0 * new_func->terms[i-2]);
        }
    }

    return new_func;
}

Table *create_table(float u0, float v0, Polynomial *first_func) {

    Table *new_table = (Table*) malloc(sizeof(Table));
    new_table->neg_u0 = u0 * (-1);
    new_table->neg_v0 = v0 * (-1);
    new_table->first_func = first_func;
    new_table->middle_func = equate(new_table->neg_u0, new_table->neg_v0, new_table->first_func);
    new_table->last_func = equate(new_table->neg_u0, new_table->neg_v0, new_table->middle_func);
    display(new_table->first_func);
    display(new_table->middle_func);
    display(new_table->last_func);

    new_table->delta_u = delta_u_formula(new_table->middle_func, new_table->last_func);
    new_table->delta_v = delta_v_formula(new_table->middle_func, new_table->last_func);
    new_table->u_k1 = u0 + new_table->delta_u;
    new_table->v_k1 = v0 + new_table->delta_v;
    printf("U0 = %.6f\tV0=%.6f\n", new_table->delta_u, new_table->delta_v);
    printf("Uk+1 = %.6f\tVk+1 = %.6f\n", new_table->u_k1, new_table->v_k1);
    return new_table;
}

void display(Polynomial *func) {

    for(int i = 0; i < func->degree; i++) {
        float terms = func->terms[i];
        char op = '+';
        if(func->terms[i] < 0) {
            terms = func->terms[i] * -1;
            op = '-';
        }
        if(i == 0)
            printf("%.2fx^%d", terms, func->degree - i-1);
        else {
            
            printf(" %c %.2fx^%d", op, terms, func->degree - i-1);
        }
            
    }
    printf("\n");

}