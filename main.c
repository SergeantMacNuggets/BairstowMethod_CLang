#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
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
    unsigned short degree;
    float tolerance;
    Polynomial *func;
    Table **table;
}Sheet;



Polynomial *create_equation(unsigned short degree);
Sheet *create_sheet(unsigned short degree);
void display(Sheet *sheet);

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

    display(sheet1);

    
    return 0;
}

Sheet *create_sheet(unsigned short degree) {
    Sheet *paper = (Sheet*) malloc(sizeof(Sheet));
    paper->degree = degree;
    paper->func = create_equation(degree);
    printf("Enter Tolerance: ");
    scanf("%f", &paper->tolerance);
    
    return paper;
}


Polynomial *create_equation(unsigned short degree) {
    Polynomial *func = (Polynomial*) malloc(sizeof(Polynomial));
    func->terms = (float *) malloc (degree * sizeof(float));
    
    for(int i=0; i<=degree;i++) {
        printf("Enter Coefficient (x^%d): ", i);
        scanf("%f", &func->terms[i]);
    }


    return func;
}

void display(Sheet *sheet) {

    for(int i = sheet->degree; i >= 0; i--) {
        if(i == 0)
            printf("%.2fx^%d", sheet->func->terms[i], i);
        else 
            printf("%.2fx^%d + ", sheet->func->terms[i], i);
    }

}