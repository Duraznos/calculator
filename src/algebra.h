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
double eval_var_at(variable *var, double value);
double pow_value_to_var(variable *var, double value);

polynomial * create_polynomial();
void add_var_to_poly(polynomial * poly, variable * var);
double eval_poly_at(polynomial *poly, double value);

