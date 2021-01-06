#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct no
{
    int ap;
    struct no *proximo;
    char nome[100];
    char end[100];
    char telefone[15];
    char obs[300];
} no;

void dados(no *novo, int a)
{
    novo->ap=a;
    printf("Qual o nome da Pessoa?\n");
    scanf(" %[^\n]",novo->nome);
    printf("Qual o seu endereco\n");
    scanf(" %[^\n]",novo->end);
    printf("Qual o seu telefone\n");
    scanf(" %[^\n]",novo->telefone);
    printf("Qual o sua abservacao\n");
    scanf(" %[^\n]",novo->obs);

}
void inserir(no **list, int a)
{

    no *novo = (no*)malloc(sizeof(no));
    no *aux, *aux2, *aux3;
    aux = *list;
    aux3 = *list;
    novo->proximo = NULL;
    if(*list==NULL)
    {
        dados(novo,a);
        (*list)=novo;
    }
    else if (a < aux->ap)
    {
        dados(novo,a);
        novo->proximo = aux;
        (*list)=novo;
    }
    else
    {
        do
        {
            aux2 = aux->proximo;
            if(a > aux->ap && aux2!=NULL && a < aux2->ap )
            {
                dados(novo,a);
                aux->proximo = novo;
                novo->proximo = aux2;
                (*list)=aux3;
                break;
            }
            else if(a==aux->ap)
            {
                printf("Quarto Ocupado\n");
                break;
            }
            else if(a> aux->ap && aux2==NULL)
            {
                dados(novo,a);
                aux->proximo=novo;
                (*list)=aux3;
                break;
            }

            aux = aux->proximo;
        }
        while(1);
    }
    printf("Adicionado ao quarto %d\n", a);
}
void remover(no **list, int a)
{
    no *aux, *aux2, *aux3, *aux4;
    aux = (*list);
    if(*list==NULL)
    {
        printf("Nao existe ocupantes no Hotel\n");
    }
    else if(a==aux->ap)
    {
        aux2=aux->proximo;
        free(aux);
        (*list)=aux2;
    }else if(aux->proximo==NULL){
        printf("Esse quarto nao esta ocupados\n");
    }
    else
    {
        do
        {
            aux2 = aux;
            aux = aux->proximo;
            aux3 = aux->proximo;

            if(a==aux->ap)
            {
                aux2->proximo=aux3;
                free(aux);
                printf("Saindo do Quarto %d\n", a);
                break;
            }
            if(aux3==NULL)
            {
                printf("Esse quarto nao esta ocupado\n");
                break;
            }
        }
        while(1);

    }

}
void imprimi(no **list, int a)
{
    if(*list==NULL){
        printf("Este quarto esta desocupado");
    }else{

    no *aux, *aux2;
    aux = *list;
    do
    {
        if(a==aux->ap)
        {   printf("Quarto Ocupado\n");
            printf("Dados do Ocupante\n");
            printf(" Dados [Nome] = [%s]\n", aux->nome);
            printf(" Dados [Endereco] = [%s]\n", aux->end);
            printf(" Dados [Telefone] = [%s]\n", aux->telefone);
            printf(" Dados [Observacoes] = [%s]\n", aux->obs);
            break;
        }
        aux = aux->proximo;
        if(aux==NULL)
        {
            printf("Quarto desocupado\n");
            break;
        }
    }
    while(1);
    }
}
void imprimir(no **list)
{
    no *aux2;
    aux2 = *list;
    while(aux2 != NULL)
    {
        printf("Imprimindo %d\n", aux2->ap);
        aux2 = aux2->proximo;
    }
}
int main()
{
    no *lista;
    lista = NULL;
    int b;
    int a;
    do
    {
        printf("\n\n\nBEM VINDO AO HOTEL UFT\n\n\n");
        printf(" OPCAO 1 - ADICIONAR UM QUARTO\n");
        printf(" OPCAO 2 - REMOVER DE UM QUARTO\n");
        printf(" OPCAO 3 - IMPRIMIR OS DADOS DE ALGUEM\n");
        printf(" OPCAO 0 - SAIR\n\n\n");
        scanf("%d", &a);

        switch(a)
        {
        case 1:
            printf("Qual o numero do quarto que deseja adicionar?\n");
            scanf("%d", &b);
            if(((b<100 || b>611)||(b%100 >11 || b%100 < 1)))
            {
                printf("Numero de quarto invalido\n");
            }
            else
            {
                inserir(&lista,b);
            }
            break;

        case 2:
            printf("Qual o numero do quarto que deseja remover?\n");
            scanf("%d", &b);
            if(((b<100 || b>611)||(b%100 >11 || b%100 < 1)))
            {
                printf("Numero de quarto invalido\n");
            }
            else
            {
                remover(&lista,b);
            }
            break;
        case 3:
            printf("Qual o quarto que deseja buscar os dados\n");
            scanf("%d", &b);
            if(((b<100 || b>611)||(b%100 >11 || b%100 < 1)))
            {
                printf("Numero de quarto invalido\n");
            }
            else
            {
                imprimi(&lista,b);
            }
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
            default:
            printf("Opcao invalida");
            break;
        }
    }
    while(a!=0);

    return 0;
}