// #include <stdio.h>
// #include <string.h>

// #include "../include/identificaExp.h"
// #include "../include/lerExp.h"

// int main () {

//     char *exp = "2 + 3 + 5";
//     if(identificaExpInfixa(exp))
//         printf("É infixa: %s\n", exp);
//     else  
//         printf("Não é infixa: %s\n", exp);


//     // remove o caractere de nova linha do final da string
//     // exp2[strcspn(exp2, "\n")] = 0;

//     char exp2[1000] = "5 3 2 + * 4 / 6 -";
//     if (identificaExpPosFixa(exp2)) {
//         printf("A expressao eh pos-fixa.\n");
//     } else {
//         printf("A expressao nao eh pos-fixa.\n");
//     }
    
//     // if(identificaExpPosFixa(exp2))
//     //     printf("É posfixa: %s\n", exp2);
//     // else
//     //     printf("Não é posfixa: %s\n", exp2);

//     return 0;
// }