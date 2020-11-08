/*

@Autor : Yuri Domingos
Orientador : Msc.Eng : Solander Agostinho 
Disciplina : Sistemas Inteligentes 1 
Data   : 19 -10 -2020

Objectivo : Implementar as funcoes necessárias para realizar o percurso exaustivo de um grafo
            relativamente ao transversal search com TAD(tipo abstrato de dados)
*/

//  Escrever a interface do functions.c  

struct tree;
void great_users();
struct tree* Element(int information, bool Goal_Element);
struct tree** Create_Stack(int *first_stack_element);
void stack_push_operattion(struct tree **stack, int *first_stack_element, struct tree *new_element );
struct tree* stack_pop_operations(struct tree **stack, int *first_stack_element);
struct tree** Create_Queue(int *front , int *last);
void Insere_element_in_queue(struct tree **queue, int *last,  struct tree *new_element);
struct tree *take_queue_element(struct tree **queue, int *front);
