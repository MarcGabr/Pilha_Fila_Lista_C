#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
UNIVERSIDADE FEDERAL DO TOCANTINS
BACHARELADO EM CIENCIA DA COMPUTAÇÃO
ALUNO: MARCOS GABRIEL PEREIRA ARAUJO
*/
typedef struct top
{
    int disco;
    struct top *proximo;
    int h;
} pilhag;

void push(pilhag **pilha,int n)
{
    pilhag *novo =(pilhag*)malloc(sizeof(pilhag));
    novo->proximo= *pilha;
    novo->disco=n;
    if(*pilha==NULL)
    {novo->h=0;}
    else
    {novo->h = (*pilha)->h+1;}
    *pilha=novo;
}
int pop(pilhag **pilha)
{
    pilhag *aux;
    int auxi;
    if(*pilha!=NULL)
    {
        aux=*pilha;
        *pilha=(*pilha)->proximo;
        auxi=aux->disco;
        free(aux);
        return auxi;
    }

}

void imprimir(pilhag *A, pilhag *B, pilhag *C, int n )
{

    int i;

    printf("      [A]");
    printf("           [B]");
    printf("         [C]\n");
    printf("\n");

    for(i=n; i>=1; i--)
    {
        if(i <= A->h)
        {
            printf("       %d",altura(A,A->h,i));
        }
        else
        {
            printf("       0");
        }
        if(i<=B->h)
        {
            printf("             %d",altura(B,B->h,i));
        }
        else
        {
            printf("             0");
        }
        if(i<=C->h)
        {
            printf("           %d",altura(C,C->h,i));
        }
        else
        {
            printf("           0");
        }
        printf("\n");
    }
    printf("  ___________  ___________ ___________ \n");
}

int altura(pilhag *A,int a,int b)
{
    if(a==b)
    {
        return A->disco;
    }
    else
    {
        return altura(A->proximo,a-1,b);
    }
}


int main()
{
    int i,n=0;
    char d[10];
    pilhag *A = NULL;
    pilhag *B = NULL;
    pilhag *C = NULL;
    push(&A,0);
    push(&B,0);
    push(&C,0);
    do
    {
    do{
        //system("cls");
        printf("Qual o nivel da torre de Hanoi ou digite Sair para sair\n");
        printf("|----Facil---- Para 3 discos  |\n");
        printf("|----Medio---- Para 5 discos  |\n");
        printf("|----Dificil--Para 7 discos   |\n");
        scanf(" %s", d);
        if(strcasecmp(d,"Facil")==0){
            n=3;
        }else if(strcasecmp(d,"Medio")==0){
            n=5;
        }else if(strcasecmp(d,"Dificil")==0){
            n=7;
        }else if(strcasecmp(d,"Sair")==0){
            return 0;
        }else{
           n=0;
        }
    }while(n==0);
        for(i=n; i>0; i--)
        {
            push(&A,i);
        }

        //system("cls");
        imprimir(A,B,C,n);
        char a;
        char b;
         printf("Digite a Letra da torre que deseja enviar o disco e a Letra que vai receber o disco ou 0 para Sair \n\n");
            scanf(" %c", &a);
        while(a!= '0')
        {
            scanf(" %c", &b);
            //system("cls");
            switch(a){
                case 'A':
                    if(b=='B'&&(B->disco>A->disco||B->disco==0)&&A->disco!=0){
                        push(&B,pop(&A));
                    }else{
                        if(b=='C'&&(C->disco>A->disco||C->disco==0)&&A->disco!=0){
                            push(&C,pop(&A));
                        }
                    }
                    break;
                case 'B':
                    if(b=='A'&&(A->disco>B->disco||A->disco==0)&&B->disco!=0){
                        push(&A,pop(&B));
                    }else{
                        if(b=='C'&&(C->disco>B->disco||C->disco==0)&&B->disco!=0){
                            push(&C,pop(&B));
                        }
                    }
                    break;
                case 'C':
                    if(b=='A'&&(A->disco>C->disco||A->disco==0)&&C->disco!=0){
                        push(&A,pop(&C));
                    }else{
                        if(b=='B'&&(B->disco>C->disco||B->disco==0)&&C->disco!=0){
                            push(&B,pop(&C));
                        }
                    }
                    break;
        }

            if(((A->h==0 && C->h==0) && B->h==3) || (A->h==0 && B->h==0 && C->h==3)){
                printf("Gannhou Parabens\n");
                imprimir(A,B,C,n);
                //system("pause");
                break;
            }
            imprimir(A,B,C,n);
             printf("Digite a Letra da torre que deseja enviar o disco e a Letra que vai receber o disco ou 0 para Sair \n\n");
            scanf(" %c", &a);
        }

        for(i=n;i>=1;i--){
            if(A->h!=0)pop(&A);
            if(B->h!=0)pop(&B);
            if(C->h!=0)pop(&C);
        }
    }
    while(d!='0');

}
