/*

@Autor : Yuri Domingos
Data   : 19 -10 -2020

Objectivo : Implementar as funcoes necessárias para realizar o percurso exaustivo de um grafo
            relativamente ao transversal search com TAD(tipo abstrato de dados)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NO_MEMORY 1
#define NEGATIVE_VALUE -1
#define SIZE_MEMORY 500

//-------------------------------- Suplement Implementing functions



void great_users()
{  
    printf("\n\n     \n");

    printf("*---------------------------------------------------------------------------*\n");
    printf("|  YS                                                                       |\n");
    printf("|                    SEJA BEM VINDO AO  SEARCHING SYSTEM                    |\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|                                                                           |\n");
    printf("|   -> DIGITE UMA OPCAO :                                                   |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|     1 - CARREGAR DADOS NOVOS                                              |\n");
    printf("|     2 - IMPRIMIR OS DADOS EXISTENTE                                       |\n");
    printf("|     3 - SAIR                                                              |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("*---------------------------------------------------------------------------*\n");

}






// Estrutura fundamental de uma arvore (NO Intuito de um agente baseado em objectivo)


struct tree
{

   struct tree* right;
   struct tree* left;
   bool   Goal_Element;
   int    information;  


};



// EStrututura fundamental de um elemento da arvore 





struct tree* Element(char information, bool Goal_Element)
{
    // find a local memory

    struct tree* new_element = (struct tree*) malloc(sizeof(struct tree));

    if (new_element != NULL)
    {
        new_element ->right = NULL;
        new_element ->left  = NULL;
        new_element ->Goal_Element = Goal_Element;
        new_element->information = information;

        return (new_element);
    }
    
}


struct tree** Create_Stack(char first_stack_element)
{
    struct tree** stack = (struct tree **)malloc(sizeof(struct tree*)*(SIZE_MEMORY));
    first_stack_element = -1;
    return stack;
}

void stack_push_operattion(struct tree **stack, char first_stack_element, struct tree *new_element )
{

 (first_stack_element)++;
 stack[first_stack_element] = new_element;


}

struct tree* stack_pop_operations(struct tree **stack, char first_stack_element)
{
    return stack[first_stack_element];
}


//--- criaremos uma outra estrutura

struct tree** Create_Queue(char front , char last)
{
    struct tree **queue = (struct tree **) malloc(sizeof(struct tree *)*(SIZE_MEMORY));
    front = last = NULL;
    return (queue);
}

void Insere_element_in_queue(struct tree **queue, char *last,  struct tree *new_element)
{
    queue[*last] = new_element;
    (*last)++;
}

struct tree *take_queue_element(struct tree **queue, int *front)
{
    (*front)++;
    return queue[*front-1];
}


