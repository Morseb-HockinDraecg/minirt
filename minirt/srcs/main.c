#include "mini_rt.h"

int main(int argc, char **argv)
{
    if (argc < 3 && argc)
    {
       ft_parse(&argv[1]);
       if (argc == 3)
       {
        if (!(ft_strncmp("-save", argv[2], 6)))
            printf("Module sauvegarde a faire !");
        else
            printf("Afficher a l'ecran : sauvegarde non prise en charge");
       }
    }
    else
        return (error_minirt(1));
}
