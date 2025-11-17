#include <stdio.h>
#include <stdlib.h>


typedef struct Polynomial {
    unsigned short degree;
    float tolerance;
    float *terms;
}Polynomial;

Polynomial *create_equation(unsigned short degree);
void display(Polynomial *func);

unsigned int input_degree() {
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
    Polynomial *function1 = create_equation(degree);

    display(function1);
    return 0;
}


Polynomial *create_equation(unsigned short degree) {
    Polynomial *func = (Polynomial*) malloc(sizeof(Polynomial));
    func->terms = (float *) malloc (degree * sizeof(float));
    func->degree = degree;
    
    for(int i=0; i<=degree;i++) {
        printf("Enter Coefficient (x^%d): ", i);
        scanf("%f", &func->terms[i]);
    }
    printf("Enter Tolerance: ");
    scanf("%f", &func->tolerance);

    return func;
}

void display(Polynomial *func) {


    for(int i = func->degree; i >= 0; i--) {
        if(i == 0)
            printf("%.2fx^%d", func->terms[i], i);
        else 
            printf("%.2fx^%d + ", func->terms[i], i);
    }

}