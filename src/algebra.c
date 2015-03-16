#include "algebra.h"

variable * create_variable(double init_scalar, double init_degree, double (*var_func)(variable *, double))
{
    variable *result = malloc(sizeof(variable));
    result->scalar =  init_scalar;
    result->degree = init_degree;
    result->f = var_func;
    return result;
}

double eval_var_at(variable *var, double value)
{
    return ((var->scalar) * (var->f(var, value)));
}

double pow_value_to_var(variable *var, double value)
{
    return pow(value, var->degree);
}

double exp_to_value(variable *var, double value)
{
    return exp(value);
}

double exp_var_to_value(variable *var, double value)
{
    return exp((value - 1)*log(abs(var->scalar)));
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

double eval_poly_at(polynomial *poly, double value)
{
    double accum = 0;
    int length = poly->length;
    while (length-- > 0){
        accum += eval_var_at(poly->elements[length], value);
    }
    return accum;
}
