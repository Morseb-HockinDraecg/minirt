#include "mini_rt.h"

static void code_error(int i)
{
    printf("error %d", i);
}

int     error_minirt(int i)
{
    code_error(i);
    return (-1);
}
