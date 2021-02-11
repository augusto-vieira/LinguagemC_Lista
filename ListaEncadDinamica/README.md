# •	Lista Dinâmica Encadeada 

Uma estrutura do tipo **“Lista”** é uma sequência de elementos do mesmo tipo.
Seus elementos possuem estrutura interna abstraída, ou seja, sua complexidade é arbitrária e não é afeta o seu funcionamento. 

Uma **“Lista”** pode posssuir N (N >= 0) elementos.
Se N = 0, dizemos que a  **“Lista”** está vazia


1. **Aplicações:**
    - Cadastro de funcionários
    - Itens em estoque
    - Cartas de trabalho
    - etc


2. **Em uma “Lista” podemos realizar as seguintes operações básicas::**
    - Criação da Lista
    - Inserção de um elemento
    - Exclusão de um elemento
    - Acesso a um elemento 
    - Destruição da Lista
    - etc


3. **Essas operações dependem do tipo de alocação de memória usa**
    - Estática
    - **Dinâmica**

Alocação dinâmica:  
>O espaço de memória é alocado em tempo de execução.
 >  A  “Lista” crece à medida que novos elementos são armazenados,e diminiu à medida que elementos são removidos
>Acesso encadeado: cada elemento pode estar em uma área distinta da memória.
Para acessar um elemento, é preciso percorrer todos os seus antecessores na “Lista”. 

![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/Lista.png)

## **Lista Dinâmica Encadeada**

Cada elemento da Lista é composto por dois campos **“dados”** e **“prox”**

- “dados”  =  informações que eu quero armazenar na Lista
- “prox” =  quem é o próximo elemento da Lista

    - Cada elemento é trato como um ponteiro que é alocado dinamicamente,a medida que os dados são inseridos.
    - Para guardar o primeiro elemento, utilizamos um **“ponteiro para ponteiro”**
    - Um “ponteiro para ponteiro” pode guardar o endereço de um “ponteiro”.
    - Assim, fica fácil mudar quem está no início da Lista mudando o “conteúdo” do “ ponteiro para ponteiro” 

**Vantagens:**
 - Melhor utilização dos recursos de memória 
 - Não precisa movimentar os elementos nas operações de inserção e remoção

# ![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/gif/InserindoNo.gif)

**Desvantagens:**
 - Acesso indireto aos elementos 
 - Necessidade de percorrer a lista para acessar um elemento 
 
 ![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/gif/PercorrerElementos.gif)

**Quando utilizar essa “Lista” ?** 
 - Não há necessidade de garantir um espaço mínimo para a execução do aplicativo.
 - Inserção/remoção em Lista ordenada são as operações mais frequente

 ![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/Lista_2.png)


### Implementando uma “Lista Dinâmica Encadeada”

<span style="color: purple"> **“ListaDinEncd.h”: definir** </span> 
 - os protótipos das funções
 - o tipo de dado armazenado na Lista
 - o ponteiro “Lista” 

<span style="color: blue"> **“ListaDinEncd.c”: definir:** </span> 

 - o tipo de dados “Lista”
 - implementar as suas funções.


``` C
/* ListaDinEncad.h */
Lista* cria_lista(void);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
Lista* cria_lista()
{
    Lista* li = (Lista*)malloc(sizeof(Lista)); 
    if(li != NULL)
        *li = NULL;
    return li;
}
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    Lista *li;
    li = cria_lista();
}

```
![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/createList.png)

``` C
/* ListaDinEncad.h */
void libera_lista(Lista* li);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
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
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    Lista *li;
    li = cria_lista();
    libera_lista(li);
}

```
![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/gif/LiberaLista.gif)

``` C
/* ListaDinEncad.h */
int tamanho_lista(Lista* li);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
int tamanho_lista(Lista* li)
{
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    Lista *li;
    li = cria_lista();
    printf("Tamanho da Lista : %d\n",tamanho_lista(li)) ; 
}
```

![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/gif/TamanhoLista.gif)

``` c
/* ListaDinEncad.h */
int lista_vazia(Lista* li);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
int lista_vazia(Lista* li)
{
    if(li == NULL) // Lista vazia
        return 1;
    
    if(*li == NULL) // Contéudo da lista vazia
        return 1;

   return 0;     
}
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    Lista *li;
    li = cria_lista();
    printf("%d\n",lista_vazia(li)) ; 
}
```
![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/ListaVazia.png) Foto ListaVazia

**Existem 3 tipos de inserção:**
- início
- meio
- final

Inserção no início da Lista:
``` c
/* ListaDinEncad.h */
int insere_lista_inicio(Lista* li, struct aluno al);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
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
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    struct aluno inserir = { 99, "Joao", 7, 8, 9};

    Lista *li;
    li = cria_lista();
    insere_lista_inicio(li, inserir);
    return 0;  
}
```
![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/gif/InserirInicioLista.gif)


Inserção no final da Lista:
``` c
/* ListaDinEncad.h */
int insere_lista_final(Lista* li, struct aluno al);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
int insere_lista_final(Lista* li, struct aluno al)
{
    if(li == NULL) return 0; 
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0; 

    no->dados = al;
    no->prox = NULL;

    if((*li) == NULL) 
    {
        *li = no;
    }
    else
    {
        Elem *aux = *li;    
        while (aux->prox != NULL)  
        {
            aux = aux->prox;
        }
        aux->prox = no;  
    }
    return 1;
}
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    struct aluno inserir = { 99, "Joao", 7, 8, 9};

    Lista *li;
    li = cria_lista();
    insere_lista_final(li, inserir);
    return 0;  
}
```
![Lista](https://github.com/augusto-vieira/LinguagemC_Lista/blob/master/ListaEncadDinamica/img/gif/InserirFinalLista.gif)
Inserção de um elemento de forma Ordenada:
``` c
/* ListaDinEncad.h */
int insere_lista_ordenada(Lista* li, struct aluno al);
```

``` c
/* ListaDinEncad.c */
#include "ListaDinEncad.h"
int insere_lista_ordenada(Lista* li, struct aluno al)
{
    if(li == NULL) return 0; 
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;

    no->dados = al; 

    if(lista_vazia(li)) 
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
``` 

``` C
/* main.c */
#include "ListaDinEncad.h"

int main(int argc, char **argv)
{
    struct aluno inserir = { 99, "Joao", 7, 8, 9};

    Lista *li;
    li = cria_lista();
    insere_lista_ordenada(li, inserir);
    return 0;  
}
```

### Referência:
- https://programacaodescomplicada.wordpress.com/
- https://www.youtube.com/user/progdescomplicada
- https://www.youtube.com/playlist?list=PL1EkVGo1AQ0HgYpSwWwt_7JnavxRmCwt0

