#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct No{
    struct No *seguinte;
    int numeros;
} no;

typedef struct Listas{
    no *comeco;
    no *final;
} lista;

void criacao_(lista *_lista)
{
    _lista -> comeco = NULL;
    _lista -> final = NULL;
}

void inclusao(lista *_lista, int x)
{
    no *criar_no;
    criar_no = (no*)malloc(sizeof(no));

    if(criar_no!=NULL){
        criar_no -> numeros = x;
        no *novo, *anterior;
        anterior = NULL;
        novo = _lista -> comeco;

        while(novo != NULL && novo -> numeros < x)
        {
            novo = novo -> seguinte;
            anterior = novo;
        }
        criar_no -> seguinte = novo;
        if(anterior != NULL){
            anterior -> seguinte = criar_no;
        }else{
            _lista -> comeco = criar_no;
        }
    }else{
        printf("Erro\n");
    }
}

void consultar(lista *_lista)
{
    no *i;
    printf("Lista: ");
    for(i=_lista->comeco; i!=NULL; i=i->seguinte){
        printf("%d -> ", i->numeros);
    }
    printf("Vazio\n");
}

void alteracao(lista *_lista, int x, int y)
{
    no *novo, *anterior;
    novo = _lista->comeco;
    anterior = NULL;
    while(novo!=NULL && novo->numeros!=x){
        novo = novo->seguinte;
        anterior = novo;
    }
    if(anterior!=NULL){
        if(novo!=NULL){
            novo -> numeros = y;
            printf("Elemento alterado\n");
        }else{
            printf("Elemento não encontrado\n");
        }
    }else{
        printf("Ops, a lista está vazia\n");
    }

}

void remocao(lista *_lista, int x)
{
    no *novo, *anterior;
    novo = _lista -> comeco;
    anterior = novo;
    while(novo!=NULL && novo -> numeros != x){
        novo = novo -> seguinte;
        anterior = novo;
    }
    if(anterior!=NULL){
        if(novo!=NULL){
            anterior -> seguinte = novo -> seguinte;
            free(novo);
            printf("Elemento removido com sucesso\n");
        }else{
            printf("Ops, não encontrei o elemento\n");
        }
    }else{
        printf("Ops, a lista está vazia\n");
    }
}

void main()
{
    setlocale(LC_ALL, "Portuguese");
    int n1, n2, operador;
    lista nova_lista;
    criacao_(&nova_lista);

    while(1)
    {
        printf("\nIncluir um elemento (1)\n");
        printf("Consultar lista (2)\n");
        printf("Alterar elemento da lista (3)\n");
        printf("Remover um elemento da lista (4)\n");
        printf("----------\n");
        printf("Sair(5)\n");
        printf("===============");

        printf("\n Escolha uma opção: ");
        scanf("%d", &operador);
        system("cls");

        switch(operador){
            case 1:
                printf("Digite o elemento a ser incluído: ");
                scanf("%d", &n1);
                inclusao(&nova_lista, n1);
                break;

            case 2:
                consultar(&nova_lista);
                break;

            case 3:
                printf("Digite o elemento que deseja alterar: ");
                scanf("%d", &n1);
                printf("Insira um novo elemento: ");
                scanf("%d", &n2);

                alteracao(&nova_lista, n1, n2);
                break;

            case 4:
                printf("Elemetno a ser removido: ");
                scanf("%d", n1);
                remocao(&nova_lista, n1);
                break;

            case 5:
                exit(0);
                break;
        }
    }
}
