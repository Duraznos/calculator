
#include "algebra.h"



void test_main();

int main(int argc, char *argv[])
{

    test_main();
    return 0;
}

void test_main() {
    variable *variable1 = create_variable(1, 3, pow_value_to_var);
    for (int x = 0; x < 5; x++) {
        printf("%f %d^ %f = %f\n", variable1->scalar, x, variable1->degree, variable1->f(variable1,x));
    }

    variable *variable2 = create_variable(-3, 2, pow_value_to_var);
    polynomial *polynomial1 = create_polynomial();
    add_var_to_poly(polynomial1, variable1);
    add_var_to_poly(polynomial1, variable2);

    for (int x =0; x < 5; x++){
        printf("variable1: %f (%d )^ %f = %f\t", variable1->scalar, x, variable1->degree, variable1->f(variable1,x));
        printf("variable2: %f (%d )^ %f = %f\t", variable2->scalar, x, variable2->degree, variable2->f(variable2,x));
        printf("variable1 + variable2 = %f\n", variable1->f(variable1,x) + variable2->f(variable2,x));
        printf("P(x) = %f\n", eval_poly_at(polynomial1, x));
    }
    free(variable1);
    free(variable2);
    free(polynomial1);

}


