
/*
@Autor : Yuri Domingos
Data   : 19 -10 -2020

Objectivo : Implementar as funcoes necessárias para realizar o percurso exaustivo de um grafo
            relativamente ao transversal search com TAD(tipo abstrato de dados)
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"


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
  char   information;  
};

#endif



//--- Dados carregados por padrao



//----------------------------- bellow we will put transversal function


//---- DFS (Deapth first search )



void inOrder(struct tree* source)
{

    if (source != NULL)
    {
        inOrder(source->left);
        printf("  %s",source->information);
        inOrder(source->right);


    }
}

//---- Pos-Order


void PosOrder(struct tree* source)
{
    if (source != NULL)
    {
        PosOrder(source->left);
        PosOrder(source->right);
        printf(" %s ",source->information);
    }
}


//  - Ordem simétrica

void Pre_Order(struct tree* source)
{

    if ( source != NULL)
    {
        printf(" %s ", source->information);
        Pre_Order(source->left);
        Pre_Order(source->right);
    }
}

// function to show all element tree 

void show_leves_tree(struct tree* source)
{
    int last, front;
    struct tree **queue = Create_Queue(&front,&last);
    struct tree *data_temp = source;

    while(data_temp)
    {
        printf(" %s ", data_temp->information);
        if(data_temp->left)  Insere_element_in_queue(queue,&last,data_temp->left);
        if(data_temp->right) Insere_element_in_queue(queue,&last,data_temp->right);
        data_temp = take_queue_element(queue,&front);
    }
}





void CustINorder(struct tree* source, int *counter)
{
    int first_stack_element;
    struct tree **stack = Create_Stack(&first_stack_element);
    struct  tree *data_temporary = source;
    do {

        while(data_temporary != NULL)
        {
            stack_push_operattion(stack,&first_stack_element,data_temporary);
            data_temporary = data_temporary->left;
        }
        
        data_temporary = stack_pop_operations(stack,&first_stack_element);
        first_stack_element = first_stack_element -1;
        (*counter)++;
        if(data_temporary->Goal_Element == true)
        {
            printf("              | OBJECTIVO [%s] ", data_temporary->information);
            return;
        }
        data_temporary = data_temporary->right;
    }while( (data_temporary != NULL) ||(stack[first_stack_element-1]));
}


//---- calcular custos do BFS

void cust_path_BFS( struct tree* source, int *counter)
{
    int front, last;
    struct  tree **queue = Create_Queue(&front,&last);
    struct tree *data_temporary = source;

    while(data_temporary)
    {
        (*counter)++;

        if (data_temporary->Goal_Element == true)
        {
            printf("              | OBJECTIVO [%s] ",data_temporary->information);
            return;
        }

        if(data_temporary->left) Insere_element_in_queue(queue,&last,data_temporary->left);
        if(data_temporary->right) Insere_element_in_queue(queue,&last,data_temporary->right);
        data_temporary = take_queue_element(queue,&front);  
    } 
}

//----- calcular 



void calcular_preOrdem_cust(struct tree* source, int *counter)
{
    int first_stack_element;
    struct tree **stack = Create_Stack(&first_stack_element);
    struct tree *data_temporary = source;
    
    do {

        while(data_temporary!= NULL )
        {
            (*counter)++;
            if(data_temporary->Goal_Element == true)
            {
                printf("             | OBJECTIVO [%s] ", data_temporary->information);
                return;
            }
            stack_push_operattion(stack,&first_stack_element,data_temporary);
            data_temporary = data_temporary->left;
        }
        data_temporary = stack_pop_operations(stack,&first_stack_element);
        first_stack_element = first_stack_element -1;
        data_temporary = data_temporary->right;
    }while((data_temporary!= NULL) || (stack[first_stack_element-1]));
}






// calcular custos posOrdem

void cust_PosOrdem(struct tree* source, int *counter)
{
    if ( source != NULL)
    {
        cust_PosOrdem(source->left,counter);
        cust_PosOrdem(source->right,counter);

        if (source->Goal_Element == true)
        {
          printf("             [%s] ",source->information);
            return;
        }

        (*counter)++;
    }
}

void otherLine()
{
  printf("\n");
}

void otherLine_Horintal()
{
printf("------------------------------------------------------------------------------------------------------------");
}
void fist()
{
   printf("\n BFS [ BREAD FIRST SEARCH]  :            ");
}



void Carregando()
{
 
    int c1,c2,c3,c4;
    struct tree *source = Element('A',false);
    source->left = Element('B',false);
    source->right = Element('C',true);
    source->left->left = Element('D',false);
    source->left->right = Element('E',false);
    source->right->left = Element('F',false);
    source->right->right = Element('G',false);

    

    c1 = c2 = c3 = c4 = 0;




     printf("\n DFS [ DEPTH FIRST SEARCH] (PRE-ORDER):  ");
     Pre_Order(source);
     calcular_preOrdem_cust(source,&c1);
     printf("      CUSTO =  %d",c1);
     otherLine();
     otherLine_Horintal();
     printf("\n DFS [ DEPTH FIRST SEARCH] (IN-ORDER):  ");
     inOrder(source);
     CustINorder(source,&c2);
     printf("      CUSTO =  %d", c2);
     otherLine();
     otherLine_Horintal();
     printf("\n DFS [ DEPTH FIRST SEARCH] (POS-ORDER):  ");
     PosOrder(source);
     cust_PosOrdem(source,&c3);
     printf("      CUSTO =  %d", c3);
     otherLine();
     otherLine_Horintal();
     fist();
     show_leves_tree(source);
     cust_path_BFS(source,&c4);
     printf("      CUSTO =  %d", c4);
     otherLine();

}

int read_option()
{
    int n;
    scanf("%d",&n);
    return n;
}


void chosee(int option)
{
    switch(option)
    {
       case 1 :

             printf(" - Carregando novos dados");
             break;
             
       case 2 :

             printf("\n\n Imprimindo dados  \n\n");
             Carregando();
             


            break;

        case 3 :

             exit(0);
          

    }
}



void compress()
{

   great_users();
   int receive = read_option();
   chosee(receive);

}
