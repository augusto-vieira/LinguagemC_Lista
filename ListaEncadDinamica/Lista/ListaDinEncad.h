#ifndef LISTA_DINAMICA_H_INCLUDE
#define LISTA_DINAMICA_H_INCLUDE


struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

//Ponteiro para uma struct(do tipo elemento)
typedef struct elemento* Lista;

Lista* cria_lista(void);

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_vazia(Lista* li);

int insere_lista_inicio(Lista* li, struct aluno al);

int insere_lista_final(Lista* li, struct aluno al);

// inserir o dado de forma ordenada na lista
int insere_lista_ordenada(Lista* li, struct aluno al);

int remove_lista_inicio(Lista* li);

int remove_lista_final(Lista* li);

// remover um aluno especifico da Lista
int remove_lista(Lista* li, int mat);

// consulta pela posicão
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

// consulta pela matricula
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);



#endif // LISTA_DINAMICA_H_INCLUDE