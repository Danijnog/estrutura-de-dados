#ifndef MSGASSERT_H
#define MSGASSERT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Macros de erros e avisos do programa
 * 
 */
#define erroAssert(e,m) ((void) ((e)?0: __erroassert (#e,__FILE__,__LINE__,m)))
#define __erroassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Erro '%s' - %s\n",file,line,e,m), abort(),0)

#endif