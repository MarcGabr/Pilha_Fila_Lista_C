#include <stdio.h>
#include <stdlib.h>

/*
UNIVERSIDADE FEDERAL DO TOCANTINS
BACHARELADO EM CIENCIA DA COMPUTAÇÃO
ALUNO: MARCOS GABRIEL PEREIRA ARAUJO
*/

typedef struct no
{
    char *pac;
    struct no *proximo;
} no;
typedef struct fila
{
    no *fim;
    no *comeco;
} Fila;

void adicionar (Fila *fila, char *a)
{
    no *novo=(no*)malloc(sizeof(no));
    novo->pac = a;
    novo->proximo=NULL;

    if(fila->comeco==NULL)
    {
        fila->comeco=novo;
    }
    else
    {
        fila->fim->proximo = novo;
    }
    fila->fim=novo;
    printf("A pessoa foi adicionada: %s\n\n", fila->fim->pac);
}

void retirar (Fila *fila)
{
    no *aux;
    char *a;
    if(fila->comeco==NULL)
    {
        printf("Fila vazia\n");
    }
    a = fila->comeco->pac;
    aux = fila->comeco;
    fila->comeco = fila->comeco->proximo;
    free(aux);
    printf("A pessoa atendida sera  %s\n\n", a);

}

Fila* inicializa()
{
    Fila *fila=(Fila*)malloc(sizeof(Fila));
    fila->comeco=NULL;
    fila->fim=NULL;
    return fila;
}
char *Entrada()
{
    getchar();
    char d;
    char *nome=NULL;
    int a=0;
    do
    {
        d=getchar();
        nome=(char*)realloc(nome,a+1);
        nome[a]=d;
        a++;
    }
    while(d!='\n');
    nome[a-1]='\0';
    return nome;
}
int main()
{
    Fila *Vermelha=inicializa();
    Fila *Amarelo =inicializa();
    Fila *Verde=inicializa();
    char* nome;
    char q;
    int c=0;
    do
    {   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n---------Fila de Hospital----------\n");
        printf("---------(1)ADICIONAR----------\n");
        printf("---------(2)ATENDER----------\n");
        printf("---------(0)SAIR----------\n");
        scanf(" %c",&q);
        switch(q)
        {

        case '1':
            printf("Qual o nome do individuo\n");
            nome=Entrada();

            do{

            printf("Qual a cor de atendimento -- (1)Vermelho,-- (2)Amarelo -- (3)Verde\n");
            scanf("%d", &c);

            if(c==1)
            {
                adicionar(Vermelha,nome);
                printf("\nA fila vermelha\n");
            }
            else if(c==2)
            {
                adicionar(Amarelo,nome);
                printf("\nA fila Amarela\n");
            }
            else if(c==3)
            {
                adicionar(Verde,nome);
                printf("\nA fila Verde\n");
            }
            else{
                printf("\nAtendimento invalido\n");
                c=0;
            }
            }while(c==0);
            break;
        case '2':
            if(Vermelha->comeco!=NULL)
            {
                printf("\nDa fila Vermelha\n");
                retirar(Vermelha);
            }
            else
            {
                if(Amarelo->comeco!=NULL)
                {
                    printf("\nDa fila Amarela\n");
                    retirar(Amarelo);
                }
                else
                {
                    if(Verde->comeco!=NULL)
                    {
                        printf("\nDa fila Verde\n");
                        retirar(Verde);
                    }
                    else
                    {
                        printf("\n\n\nSem pessoas na fila\n");
                    }
                }
            }
            break;
        case '0':
        break;
default: printf("\nInvalido\n");
    }

    }
    while(q!='0');
}
