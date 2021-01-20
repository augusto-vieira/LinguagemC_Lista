#include <stdio.h>                                                                                   
#include <stdlib.h> 
#include <stdbool.h>

#include "ListaDinEncad.h"

int main(int argc, char **argv)
{			
	/*
        " *li " é um ponteito para "struct elemento* Lista"
        Logo "*li " é um ponteiro para ponteiro **
        **p consegue guardar outros ponteiro(como uma lista de ponteiro)
    */
   
    Lista *li;  // Ponteiro para ponteiro 
    
    struct aluno read;
    struct aluno registros[] ={ {99, "Joao"   , 7,8,9},
                                {29, "Marcio" , 2,1,4},
                                {1 , "Marcela", 4,5,4},
                                {2 , "Amanda" , 5,5,6},
                                {3 , "Jessica", 6,4,7},
                                {55 , "Claudia", 7,3,8},
                                {5 , "Thais"  , 8,2,9},
                                {4 , "Ronaldo", 9,1,5}};


    size_t  size_campos = sizeof(registros) / sizeof(registros[0]);
    // printf("\t%d\n", size_registros);

    li = cria_lista();
    if(li != NULL)
        printf("Lista Criada\n");
 
    for(int i = 0; i < 4; i++)
    {
        insere_lista_final(li, registros[i]);
    }
    printf("Tamanho da Lista : %d\n",tamanho_lista(li)) ; 

    printf("%s\n", false < lista_vazia(li) ? "Lista Vazia" : "Lista NAO Vazia");

    printf("\n");
    for(int i = 1; i <= 4; i++)
    {
        consulta_lista_pos(li, i, &read);
        printf("id: %d %s notas: %f, %f, %f\n", read.matricula, read.nome, read.n1, read.n2, read.n3);
    }
    
    printf("\nInserindo no INICIO da Lista\n"); 
    insere_lista_inicio(li,registros[4]);
    consulta_lista_mat(li, 3, &read);
    printf("id: %d %s notas: %f, %f, %f\n", read.matricula, read.nome, read.n1, read.n2, read.n3);


    insere_lista_ordenada(li,registros[7]);
    printf("\n");
    for(int i = 1; i <= 6; i++)
    {
        consulta_lista_pos(li, i, &read);
        printf("id: %d %s notas: %f, %f, %f\n", read.matricula, read.nome, read.n1, read.n2, read.n3);
    }





	return 0; 
}

