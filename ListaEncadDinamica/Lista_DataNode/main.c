#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct dataNode
{
   int id;   //Aqui poderia ter uma pessoa, uma outra estrutura
} DataNode;




typedef struct node
{
   DataNode data;
   struct node *next;
} Node;


typedef struct list
{
   int size;
   Node *head;
} List;

List *createList();
void push(List *list, DataNode data);
void printList(List *list);
void pop(List *list);
bool isEmpty(List *list); // Lista vazio ou não
Node *atPos(List *list, int index); // Passamos um INDICE e recebemos um NÓ
int indexOf(List *list, Node *node); // Passamos um NÓ e recebemos um INDICE
void erase(List *list, int index);    //Passamos a Lista, exluir o Nó do INDICE

void insert(List *list, DataNode data, int index); // Inserir na Lista tal, um Dado Tal, no INDICE tal
                                                   // Vai inserir um NÓ em um posição especificada da LISTA

void xchgNodes(List *list, Node *nodeA, Node *nodeB);// Troca dois NÓ da Lista, util para ordenar a LISTA

Node *min(List *list, int index); // Buscar o MENOR id 
Node *max(List *list, int index); // Buscar o MAIOR id 

void incSort(List *list); // Ordenar em ordem crecente 

void decSort(List *list); // Ordenar em ordem decrecente 

// Ordenar crescente

List *createList()
{
    List *list = (List*)malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;

    return list;
}

void push(List *list, DataNode data)
{
    Node *node = (Node*)malloc(sizeof(Node));
    
    node->data = data;
    node->next = list->head;  //Liga o nó na Lista, o próximo nó aponta para cabeça da Lista
    list->head = node;  // cabeça da Lista é igual ao nó que criamos
    list->size++;  // sempre incrementar a lista
}

void printList(List *list)
{
    if(isEmpty(list))
    {
        printf("Lista vazia\n");
        return;
    }
    
    // Nó apontador, quando tiver em NULL chegou no fim da Lista
    Node *pointer = list->head;

    while (pointer != NULL)
    {
        printf(" %d",pointer->data.id);

        //vai para o proixmo nó da Lista
        pointer = pointer->next;
    }
    printf("\n");
}

bool isEmpty(List *list)
{
    return(list->size == 0); // Se for verdadeira retorna 1, falsa 0.
}

void pop(List *list)
{
    // Verifica se o nó não é NULO
    if(!isEmpty(list))  
    {
        // Ponteiro auxiliar da Lista 
        Node *pointer = list->head;

        // Muda a cabeça da lista para o próximo elemento
        list->head = pointer->next;

        // Libera memória
        free(pointer);
        list->size--;
    }
}

Node *atPos(List *list, int index)
{
    // Verifica se o indice é valido, menor que o tamanho da lista
    if (index  >= 0 && index < list->size)
    {
        // Ponteiro auxiliar, aponta para o começo da Lista.
        Node *node = list->head;

        int i;
        for (i = 0; i < index; i++)
        {
            // recebe o próximo elemento da Lista
            node = node->next;
        }

        return node;
    }
    printf("Indice invalido\n");
    return NULL;
}


int indexOf(List *list, Node *node)
{
    if( node != NULL)
    {
        Node *pointer = list->head;

        int index = 0;

        while (pointer != node && pointer != NULL)
        {
            pointer = pointer->next;
            index++;
        }
        if(pointer != NULL)
        return index;
    }

    printf("NO nao pertence a lista\n");
    return -1;
}

void erase(List *list, int index)
{
    if (index == 0)
        pop(list);
    
    else
    {
        Node *current = atPos(list, index);
        if(current != NULL)
        {
            Node *previus =  atPos(list, index - 1);
            previus->next = current->next;

            free(current);
            list->size--;

        }
    }
}

void insert(List *list, DataNode data, int index)
{
    if(index == 0)
    {
        push(list,data);
    }
    else
    {
        // Ponteiro para Receber a Referencia 
        Node *current = atPos(list, index);
        
        // Verifica se o NÓ existi 
        if(current != NULL)
        {
        // Ponteiro para Receber o Nó anterior
        Node *previous = atPos(list, index - 1);

        // previous tem que apontar parao novo NÓ
        Node *newNode = (Node*)malloc(sizeof(Node)); // Aloca um Nó novo
        newNode->data = data; // Passamos o dado para ela 

        previous->next = newNode;  //O Próximo do anterior vai ser o Novo NÓ
        newNode->next = current;  // Novo nó vai ser o do (index) indice especificado

        list->size++; // Incrementando a Lista
        }

    }
    
}

void xchgNodes(List *list, Node *nodeA, Node *nodeB)
{
    
    if(nodeA == nodeB)
      return;
    
    int indexA = indexOf(list, nodeA);
    int indexB = indexOf(list, nodeB);

    // Verifica se o Nó pertence a Lista
    if(indexA == -1 || indexB == -1)
    return;

    if(indexA > indexB)
    {
        nodeA = nodeB;
        nodeB = atPos(list, indexA);

        indexA = indexB;
        indexB = indexOf(list, nodeB);
    }
    
    Node *pb = atPos(list, indexB - 1);

    if (nodeA == list->head)
    {
        list->head = nodeB;
    }
    else
    {
        Node *pa = atPos(list, indexA -1);
        pa->next = nodeB;
    }

    pb->next = nodeA;

    Node *pointer = nodeA->next;
    nodeA->next = nodeB->next;
    nodeB->next = pointer;
    
    

}

Node *min(List *list, int index)
{
    // Nó auxiliar 
    Node *pointer = atPos(list, index);

    if(pointer != NULL)
    {
        //NÓ auxiliar para segurar o menor valor
        Node *minNode = pointer;

        while (pointer != NULL)
        {
            if(pointer->data.id < minNode->data.id )
                minNode = pointer;

           pointer = pointer->next;     
        }
      
      return minNode;
    }
   return NULL;
}

Node *max(List *list, int index)
{
    // Nó auxiliar, refrencia para indice especificado
    Node *pointer = atPos(list, index);

    if(pointer != NULL)
    {
        //NÓ auxiliar para segurar o menor valor
        Node *maxNode = pointer;

        while (pointer != NULL)
        {
            if(pointer->data.id > maxNode->data.id )
                maxNode = pointer; //se for maior atribui

           pointer = pointer->next;     
        }
      
      return maxNode;
    }
   return NULL;
}

void incSort(List *list)
{
    int i = 0;

    for (i = 0; i < list->size - 1 ; i++)
    {
        xchgNodes(list, atPos(list, i), min(list, i));
    }
    
}

void decSort(List *list)
{
    int i;
                  // Menor que a última posição
    for (i = 0; i < list->size -1 ; i++)
    {
        xchgNodes(list, atPos(list, i), max(list, i));
    }
    
}




int main(void)
{

    List *l = createList();
   

    // Inserir um elemento no começo da lista;
    DataNode data;  // vamos passar uma cópia dela para push()

    data.id = 5 ;
    push(l, data);  //Primeira posição da Lista, tem um nó igual a 5

    data.id = 9 ;
    push(l, data);

   /*
   // Imprimir o valor da cabeça da nossa Lista
   printf("%d", l->head->data.id);

   // Imprimir o outro nó
   printf(" %d", l->head->next->data.id);
   */


    data.id = 8 ;
    push(l, data);
    data.id = 9 ;
    push(l, data);
    data.id = 7 ;
    push(l, data);
    data.id = 10 ;
    push(l, data);

    printList(l);

    pop(l);
    printList(l);

    //Buscando o elemento da posição '2' -----> [0] = 7| [1] = 9| [2] = 8|  [3] = 9| 
    printf("%d\n",atPos(l, 2)->data.id);

    // Tentar imprimir o indice da cabeça da Lista(0)
    printf("%d\n", indexOf(l, l->head));

    // Imprimir o próximo nó 
    printf("%d\n", indexOf(l, l->head->next));

    // Imprimir o próximo do próximo NÓ
    printf("%d\n", indexOf(l, l->head->next->next));


    Node *node = (Node*)malloc(sizeof(Node)); //Cria outro Nó, 
    printf("%d\n", indexOf(l, node));  // Nó não pertence a Lista

    // Apaga um Nó, para exluir a cabeça da Lista é só usar o pop.
    printf("\n");
    erase(l,11);
    printList(l);


    // Inserir um novo em uma posição especificada da Lista  
    printf("\n");
    data.id = 11; 
    insert(l, data, 2); // inserindo na posição 2   [0] = ...| [1] = ...| [2] = 11|  [3] = ...| 
    printList(l);

    // l->head->next = Posição de indice 1     ||   l->head->next->next = Posição de indice 2
    printf("\n");
    xchgNodes(l, l->head->next, l->head->next->next);
    printList(l);

    // min retorna um Node, logo, para visualizar precisamos usar "min(l,0)->data.id)"   
    // min((l,0)) ERRADO
    // 0 -> começar pelo indice 0
    printf("Min %d\n", min(l,0)->data.id);


    printf("Max %d\n", max(l,0)->data.id);

    printf("\n");
    incSort(l);
    printList(l);


    printf("\n");
    decSort(l);
    printList(l);

	return 0;
}

