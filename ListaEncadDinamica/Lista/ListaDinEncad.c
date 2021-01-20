#include <stdio.h>                                                                                   
#include <stdlib.h>  

#include "ListaDinEncad.h"

struct elemento
{
    struct aluno dados;

    // Ponteiro para o próximo elemento da Lista
    struct elemento *prox;
};

// Renomei para facilitar em algumas operações
typedef struct elemento Elem;


Lista* cria_lista()
{
    Lista* li = (Lista*)malloc(sizeof(Lista)); // Guarda o primeiro nome da Lista
    if(li != NULL)
        *li = NULL;
    return li;
}


void libera_lista(Lista* li)
{
    if(li != NULL)
    {
        Elem* no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li)
{
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li; // "Elem* no"  nó auxliar da lista, serve para não perder nó principal
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li)
{
    if(li == NULL) // Lista vazia
        return 1;
    
    if(*li == NULL) // Contéudo da lista vazia
        return 1;

   return 0;     
}

int insere_lista_inicio(Lista* li, struct aluno al)
{
    if(li == NULL) return 0; // Verifica se a Lista é valida

    Elem* no = (Elem*) malloc(sizeof(Elem)); // Crio novo elemento para lista
    if(no == NULL) return 0;
    
    no->dados = al; // copio os dados para o nó(al)
    no->prox = (*li);  // o próximo dele é a própria lista, evista casos de lista vazia 
    *li = no;  // inicio da Lista muda de lugar, passa a ser o NOVO nó
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al)
{
    if(li == NULL) return 0; 
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0; 

    no->dados = al;
    no->prox = NULL;

    if((*li) == NULL) // Lista vazia inseri no inicio
    {
        *li = no;
    }
    else
    {
        Elem *aux = *li;    //  "aux" aponta para o incio da lista, ponteiro auxiliar(se ñ perde a referência)
        while (aux->prox != NULL)  // vou percorrer toda Lista, até chegar no último elemento
        {
            aux = aux->prox;
        }
        aux->prox = no;  // inserir aqui o novo nó
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al)
{
    if(li == NULL) return 0; 
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;

    no->dados = al; // copio os dados para o nó(al)

    if(lista_vazia(li)) // Lista vazia inseri no inicio
    {
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else // Procura onde inserir
    {
        Elem *ant, *atual = *li;

        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ant = atual;
            atual = atual->prox;
        }

        if(atual == *li) // insere inicio
        {
            no->prox = (*li);
            *li = no;
        }
        else
        {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

int remove_lista_inicio(Lista* li)
{
    if(li == NULL)  // Lista existe
        return 0;

    if((*li) == NULL)  // Lista vazia
        return 0;

    Elem *no = *li;  // "no" elemento auxiliar que recebe o valor do inicio da Lista
    *li = no->prox;  // inicio da Lista começa apontar para o Elemento seguinte ao NÓ
    free(no); //libera nó
    return 1;
}

int remove_lista_final(Lista* li)
{
    if(li == NULL)  // Lista existe
        return 0;

    if((*li) == NULL)  // Lista vazia
        return 0;
                            // recebe inicio da Lista
    Elem *ant, *no = *li;   // é necessário dois Nó auxiliares para percorrer uma Lista

    while (no->prox != NULL) // Percorrer a Lista até o final dela
    {
        ant = no;
        no = no->prox;
    }

    if(no == (*li)) // o Nó igual ao inico da Lista ? remove o primeiro elemento, só tinha um.
        *li = no->prox;
    else
        ant->prox = no->prox;
    
    free(no);
    return 1;
}

int remove_lista(Lista* li, int mat)
{
    if(li == NULL)
        return 0;
    
    Elem *ant, *no = *li; // "*no" começa no inicio da Lista

    while (no != NULL && no->dados.matricula != mat)  // Percorrer a Lista
    {
        ant = no;
        no = no->prox; // aponta para o elemento seguinte
    }

    if(no == NULL)  // Não encontrado, lista vazia ou matricula ñ ncontrada
        return 0;
    
    if(no == *li)  // remover o primeiro elemento
        *li = no->prox;
    
    else  // Elemento intermediário, remove quem está no meio ou final
        ant->prox = no->prox;
    
    free(no);
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al)
{
    if(li == NULL || pos <= 0)
        return 0;
    
    Elem *no = *li;
    int i = 1;

    while (no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }

    if(no == NULL)
        return 0;
    else
    {
        *al = no->dados; // deu certo, retorna onde o ponteiro parou
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al)
{
    if(li == NULL)
    return 0;
    
    Elem *no = *li;

    while (no != NULL && no->dados.matricula != mat) // Só tem diferença na busca, comparando com consulta por posição
    {
        no = no->prox;
    }

    if(no == NULL)
        return 0;
    else
    {
        *al = no->dados; // deu certo, retorna onde o ponteiro parou
        return 1;
    }
}
