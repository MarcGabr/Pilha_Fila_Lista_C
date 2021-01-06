#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disciplina
{
    int periodo;
    char nome[100];
//char *professor;
//char *ementa;
} disciplina;

typedef struct no
{
    struct no *anterior;
    disciplina *dados;
    struct no *proximo;
} no;
typedef struct descritor
{
    struct no *inicio;
    int qt;
    struct no *fim;
} descritor;

void cad(no *novo,int a, char *b){//Função para inserir os dados.
    disciplina *dnov = (disciplina*)malloc(sizeof(disciplina));
    dnov->periodo = a;
    novo->dados = dnov;
    strcpy(dnov->nome, b);
}
int test(no *aux,no *novo){//FUNÇÃO QUE VERIFICA SE UM PERIODO E MAIOR E SE A PALAVRA E MENOR OU NAO
    no *aux2;
    aux2 = aux->proximo;

    if(aux->dados->periodo >novo->dados->periodo){// VERIFICA UM PERIODO E MAIOR OU MENOR
            //printf("Aux = %d\n",aux->dados->periodo);
             //printf("novo = %d\n",novo->dados->periodo);
    return 5;
    }
   // printf("Aux = %d\n",aux->dados->periodo);
     //      printf("novo = %d\n",novo->dados->periodo);
if(strcmp(aux->dados->nome,novo->dados->nome)==0){// VERIFICA SE OS NOMES DAS MATERIAIS SAO IGUAIS
            printf("entrei aki 2\n");
            return 0;
        }else if(strcmp(aux->dados->nome,novo->dados->nome)>0){// VERIFICA SE A MATERIA A E MAIOR QUE a B
            printf("entrei aki 3\n");
            return 1;
        }else{ // VERIFICA SE A MATERIA B E MENOR QUE A
            printf("entrei aki 4\n");
            return -1;
        }
}
void inserir(descritor *list,int a, char *b){
    no *novo=(no*)malloc(sizeof(no));
    cad(novo,a,b);
    novo->proximo = NULL;
    novo->anterior = NULL;
    no *aux, *aux2, *aux3, *aux4;
    aux = list->inicio;
    list->qt++;
    if(list->inicio==NULL)
    {
        list->inicio = novo;
        list->fim = novo;
    }
    else if(a <= aux->dados->periodo)
    {int x = 0,z=0;
        do{
        if(aux!=NULL){
            aux2 = aux->proximo;
        }
        if(aux2==NULL){
        x = test(aux,novo);
        if(x>=0){//Adiciona no começo
        novo->proximo = list->inicio;
        list->inicio->anterior = novo;
        list->inicio = novo;
        }else{//Adiciona no fim
        aux->proximo = novo;
        novo->anterior = aux;
        }
        x=0;
        }else if(aux==NULL){
        x = test(aux2,novo);
        if(x>=0){//Adiciona no começo
        novo->proximo = list->inicio;
        list->inicio->anterior = novo;
        list->inicio = novo;
        }
        else {
            aux2->proximo = novo;
            novo->anterior = aux2;
        }
        x=0;
        }
        else{
        x = test(aux,novo);
        z = test(aux2,novo);
        if (x<=0 && z >=0){//Adiciona no meio
            printf("Aki 2\n");
            aux->proximo = novo;
            novo->anterior = aux;
            novo->proximo = aux2;
            aux2->anterior = novo;
            x=0;
        }else if (x==5){
        novo->proximo = list->inicio;
        list->inicio->anterior = novo;
        list->inicio = novo;
        x=0;
        }
        aux = aux2->proximo;
        }

        }while(x!=0);
    }
    else
    {
        do
        {
            aux2 = aux->proximo;
            if(a >= aux->dados->periodo && aux2!=NULL && a <= aux2->dados->periodo)
            {
                int x=0, z=0;
                x = test(aux2,novo);
                if(x==5 || x==1){//Inserir quando for periodo novo
                printf("Aki 1\n");
                aux->proximo = novo;
                novo->anterior = aux;
                novo->proximo = aux2;
                aux2->anterior = novo;
                break;
                }else{

                do{
                  aux3 = aux2->proximo;
                x = test(aux2,novo);
                if(aux3!=NULL){
                    z = test(aux3,novo);
                    aux4 = aux3->proximo;
                }
                printf("x = %d\n", x);
                printf("z = %d\n", z);

        if((x<=0 && aux3==NULL)){
            aux2->proximo = novo;
            novo->anterior = aux2;
            break;
         }else if(x<0 && z<0 && aux4==NULL){
            aux3->proximo = novo;
            novo->anterior = aux3;
            break;
         }else if ((x<=0 && z>=0)){
        printf("Aki 3\n");
        aux2->proximo = novo;
        novo->anterior = aux2;
        novo->proximo = aux3;
        aux3->anterior = novo;
        break;
        }else if(x>=0 && z <=0){
            printf("aki 4\n");
        aux3->proximo = novo;
        novo->anterior = aux3;
        novo->proximo = aux2;
        aux2->anterior = novo;
        break;
        }
        aux2 = aux3->proximo;
        }while(x!=0);
        break;
        }

    }
            else if (a>=aux->dados->periodo && aux2==NULL)// Adiciona no final
            {
                aux->proximo = novo;
                novo->anterior=aux;
                list->fim = novo;
                break;
            }
            aux = aux->proximo;
        }
        while(1);
    }
    printf("Adicionando %d---",a );
    printf("--- nome: %s\n", b);
}


void remover(descritor *list, int a){
    no *aux, *aux2, *aux3, *aux4;
    aux = list->inicio;
    if(list==NULL)
    {
        printf("Nao tem nada aki\n");
    }
    else if(a == aux->dados->periodo)
    {
        list->inicio = aux->proximo;
        list->inicio->anterior= NULL;
        free(aux);
    }
    else
    {
        do
        {
            aux2 = aux;
            aux = aux->proximo;
            if(aux->proximo==NULL)
            {
                aux2->proximo=NULL;
                list->fim = aux2;
                free(aux);
                break;
            }
            else if(a == aux->dados->periodo)
            {
                aux3 = aux->proximo;
                aux2->proximo = aux3;
                aux3->anterior = aux2;
                free(aux);
                break;
            }
        }
        while(1);
    }
}

void remocao(descritor *list, char *a){
    no *aux, *aux2, *aux3;
    printf("%s\n", a);
    aux = list->inicio;
    if(strcasecmp(list->inicio->dados->nome, a)==0){
        printf("No periodo %d e %s 1\n",aux->dados->periodo, aux->dados->nome);
        list->inicio = NULL;
        free(aux);
    }else if(strcasecmp(list->fim->dados->nome, a)==0){
        printf("No periodo %d e %s 2\n",list->fim->dados->periodo, list->fim->dados->nome);
        aux = list->fim;
        aux2 = list->fim->anterior;
        aux2->proximo=NULL;
        list->fim = aux2;
        free(aux);
    }else{
        do{
        aux2=aux;
        aux = aux->proximo;
        if(aux==NULL){
        printf("Nao conseguimos encontrar\n");
        break;
        }
        if(strcasecmp(aux->dados->nome, a)==0){
            printf("No periodo %d e %s\n",aux->dados->periodo, aux->dados->nome);
            aux3 = aux->proximo;
            aux2->proximo = aux3;
            aux3->anterior = aux2;
            free(aux);
            break;
        }
    }while(aux!=NULL);
    }
    printf("Removido com sucesso");
}
void imprimir(descritor *list, int a){ //Imprime a partir de um numero dado
    no *aux,*aux2;
    aux=list->inicio;

    if(list!=NULL){
    while(aux!=NULL)
    {
        if(aux->dados->periodo==a){
        printf(" %d--- ", aux->dados->periodo);
        printf(" ---%s\n ",aux->dados->nome );
        break;
        }
        aux = aux->proximo;
    }
    aux2= aux;
    do{
        aux = aux->proximo;
        if(aux!=aux2){
        printf(" %d--- ", aux->dados->periodo);
        printf(" ---%s\n ",aux->dados->nome );
        }
        if(aux==list->fim){
        aux = list->inicio;
        printf(" %d--- ", aux->dados->periodo);
        printf(" ---%s\n ",aux->dados->nome );
        }
    }while(aux2!=aux);

    }
}
int imprimir3(descritor *list, char *a){//Imprime a partir de uma palavra
    printf("Pelo menos chegay");
    no *aux, *aux2;
    aux=list->inicio;
    int d;
    while(aux!=NULL)
    {
        if(strcmp(aux->dados->nome, a)==0){
        printf(" %d ", aux->dados->periodo);
         printf(" ---%s\n ",aux->dados->nome );
            do{
                printf("Digite 1 para ir pra frente ou 2 para ir pra tras ou 0 pra sair\n");
                scanf("%d",&d);
            if(d==1){
            if(aux==list->fim){
            aux = list->inicio;
            printf(" %d ", aux->dados->periodo);
            printf(" ---%s\n ",aux->dados->nome );
            }else{
            aux = aux->proximo;
            printf(" %d ", aux->dados->periodo);
            printf(" ---%s\n ",aux->dados->nome );
            }
            }else if(d==2){
            if(aux==list->inicio){
            aux = list->fim;
            printf(" %d ", aux->dados->periodo);
            printf(" ---%s\n ",aux->dados->nome );
            }else{
            aux = aux->anterior;
            printf(" %d ", aux->dados->periodo);
            printf(" ---%s\n ",aux->dados->nome );
            }
            }
            }while(d!=0);
            break;
        }
        aux = aux->proximo;
    }
   return 1;
    }

void imprimir4(descritor *list){
    no *aux, *aux2, *aux3, *aux4, *aux5;
    aux = list->inicio;
    aux3 = aux;
    aux5 = aux3;
    int a= aux->dados->periodo;
    int d=0;

    while(a==aux->dados->periodo){
            printf("Periodo - %d\n",a);
            printf("Nome da disciplina %s\n", aux->dados->nome);
            aux=aux->proximo;

            if(aux==NULL){
                getchar();
                printf("Deseja detalhar ou Sair");
                scanf("%d", &d);
                if(d==1){
                    d = imprimir3(list,aux3->dados->nome);
                    if(d==1){
                            printf("aki1");
                        d = 5;
                        break;
                    }
                }else{
                    printf("Aki2");
                    d = 0;
                    break;
                }
            }

        }
        if(d==0){
    do{
        printf("Digite 1 para ir pra frente ou dois para ir pra tras ou 0 para sair ou 3 para detalhar\n");
        scanf("%d",&d);
        a = aux->dados->periodo;
        if(d==1){
            aux2=aux;
          printf("Valor de A ==%d\n", a);
            do{
            printf("Periodo - %d\n",a);
            printf("Nome da disciplina %s\n", aux->dados->nome);
            aux=aux->proximo;
            if(aux==NULL){
                break;
            }
          }while(aux->dados->periodo==a );

          if(aux==NULL){
                printf("Chegamos no final\n");
            aux = aux2;
            aux5 = aux->anterior;
            aux3 = aux2;
          }else{
            aux3 = aux2;
            printf("AUX2 %d\n", aux2->dados->periodo);
            aux5 = aux3->anterior;
            printf("AUX5 %d\n", aux5->dados->periodo);
            printf("AUX %d\n", aux->dados->periodo);
          }

        }
        else if(d==2){
            if(aux3==list->inicio){
                printf("Estamos no inicio da Lista\n");
            }else{
                a = aux5->dados->periodo;
                printf("A == %d\n", a);
                aux=aux3;
               do{
              aux3 = aux3->anterior;
              printf("%d\n", aux3->dados->periodo);
              if(aux3==list->inicio){
                break;
                }
                if(aux3->dados->periodo==a && aux3->anterior->dados->periodo<a){
                printf("Entrei aki?");
                break;
              }

            }while(aux3->dados->periodo==a);
                if(aux3==list->inicio){
                    aux3= list->inicio;
                }
                aux4 = aux3;
                a = aux3->dados->periodo;
                while(a==aux3->dados->periodo){
                printf("Periodo - %d\n",a);
                printf("Nome da disciplina %s\n", aux3->dados->nome);
                aux3=aux3->proximo;
            }aux3 = aux4;
          aux5 = aux4->anterior;
            }

        }else if(d==3){
            imprimir3(list,aux2->dados->nome);
            break;
        }
    }while(d!=0);
        }
}

void imprimir2(descritor *list){
    no *aux;
    aux=list->inicio;
    while(aux!=NULL)
    {
        printf(" %d ", aux->dados->periodo);
         printf(" ---%s\n ",aux->dados->nome );
        aux = aux->proximo;
    }
}


descritor* inicializa(){
    descritor *fila=(descritor*)malloc(sizeof(descritor));
    fila->inicio=NULL;
    fila->fim=NULL;
    fila->qt = 0;
    return fila;
}
int main()
{
    descritor *list=inicializa();
    char a[30]= "a";
    char b[30]= "b";
    char c[30]= "c";
    //inserir(list,8,&c);
    //inserir(list,8,&a);
    //inserir(list,7,&c);

    //inserir(list,6,&b);
    //inserir(list,6,&a);
    inserir(list,1,&c);
    inserir(list,8,&b);
     inserir(list,9,&c);
     inserir(list,9,&a);
    imprimir4(list);
    //inserir(list,9,&b);
    //inserir(list,9,&c);
    //inserir(list,10,&a);
    //printf("%d\n", list->qt);
    //imprimir2(list);
    //printf("fim = %d\n", list->fim->dados->periodo);
    //remocao(list,"c");
    //imprimir4(list);
   // remocao(list,"a");
    //remover(list,5);
    //remover(list,10);
    //remover(list,8);
    //imprimir2(list);
    //imprimir(list, 9);
    //printf("\n");
    //remover(list,1);
    //remover(list,3);
    //remover(list,5);
    //imprimir2(list);

    //printf("\ninicio = %d\n", list->inicio->dados->periodo);
    //printf("fim = %d\n", list->fim->dados->periodo);
    return 0;
}
