/*
@Autor : Yuri Domingos
Orientador : Msc.Eng : Solander Agostinho 
Disciplina : Sistemas Inteligentes 1 
Data   : 19 -10 -2020

Objectivo : Implementar as funcoes necessárias para realizar o percurso exaustivo de um grafo
            relativamente ao transversal search com TAD(tipo abstrato de dados)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#include  "Transversal_operations.h"
#include <stddef.h>

/*
  Macro Pre-definitions processers

*/
#ifndef FUNCTIONS
#define FUNCTIONS

struct tree
{
   struct tree* right;
   struct tree* left;
   bool   Goal_Element;
   int    information;  
};

#endif



int main(void)
{
      
 compress();

 return 0;

}