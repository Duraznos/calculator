#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXELEMENTS 100

typedef struct variable{
    double scalar;
    double degree;
    double (*f)(struct variable *, double);
} variable;

typedef struct polynomial{
    variable *elements[MAXELEMENTS];
    int length;
} polynomial;

variable * create_variable(double init_scalar, double init_degree,double (*var_func)(variable *, double));
double eval_at_value(polynomial * poly, double value );
double var_to_nth_power(variable * var, double value);
polynomial * create_polynomial();
void add_var_to_poly(polynomial * poly, variable * var);

void test_main();

int main(int argc, char *argv[])
{

    test_main();
    return 0;
}

void test_main() {
    variable *variable1 = create_variable(1, 3, var_to_nth_power);
    for (int x = 0; x < 5; x++) {
        printf("%f %d^ %f = %f\n", variable1->scalar, x, variable1->degree, variable1->f(variable1,x));
    }

    variable *variable2 = create_variable(-3, 2, var_to_nth_power);
    polynomial *polynomial1 = create_polynomial();
    add_var_to_poly(polynomial1, variable1);
    add_var_to_poly(polynomial1, variable2);

    for (int x =0; x < 5; x++){
        printf("variable1: %f (%d )^ %f = %f\t", variable1->scalar, x, variable1->degree, variable1->f(variable1,x));
        printf("variable2: %f (%d )^ %f = %f\t", variable2->scalar, x, variable2->degree, variable2->f(variable2,x));
        printf("variable1 + variable2 = %f\n", variable1->f(variable1,x) + variable2->f(variable2,x));
        printf("P(x) = %f\n", eval_at_value(polynomial1,x));
    }
    free(variable1);
    free(variable2);
    free(polynomial1);

}

variable * create_variable(double init_scalar, double init_degree, double (*var_func)(variable *, double))
{
    variable *result = malloc(sizeof(variable));
    result->scalar =  init_scalar;
    result->degree = init_degree;
    result->f = var_func;
    return result;
}

double eval_at_value(polynomial * poly, double value )
{
    double accum = 0;
    int length = poly->length;
    while (length-- > 0){
        accum += poly->elements[length]->f(poly->elements[length], value);
    }
    return accum;
}


double var_to_nth_power(variable * var, double value)
{
    return (var->scalar * pow(value, var->degree));
}

polynomial *create_polynomial()
{
    polynomial *result = malloc(sizeof(polynomial));
    result->length = 0;
    return result;
}

void add_var_to_poly(polynomial *poly, variable *var)
{
    if (poly->length < MAXELEMENTS){
        poly->elements[poly->length] = var;
        (poly->length)++;
    }
}
