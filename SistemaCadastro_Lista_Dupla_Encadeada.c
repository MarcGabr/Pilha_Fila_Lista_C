#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disciplina
{
    int periodo;
    char *nome;
    char *professor;
    char *ementa;
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


int test(no *aux,no *novo){//FUNÇÃO QUE VERIFICA SE UM PERIODO E MAIOR E SE A PALAVRA E MENOR OU NAO
    no *aux2;
    aux2 = aux->proximo;

    if(aux->dados->periodo >novo->dados->periodo){// VERIFICA UM PERIODO E MAIOR OU MENOR
    return 5;
    }
if(strcmp(aux->dados->nome,novo->dados->nome)==0){// VERIFICA SE OS NOMES DAS MATERIAIS SAO IGUAIS
            return 0;
        }else if(strcmp(aux->dados->nome,novo->dados->nome)>0){// VERIFICA SE A MATERIA A E MAIOR QUE a B
            return 1;
        }else{ // VERIFICA SE A MATERIA B E MENOR QUE A
            return -1;
        }
}
char *Entrada()//Funçao para inserir qualquer palavra
{
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
void cad(no *novo,int a){//Função para inserir os dados.
    disciplina *dnov = (disciplina*)malloc(sizeof(disciplina));
    dnov->periodo = a;
    char* nome;
    printf("Digite o nome da Materia\n");
    nome = Entrada();
    dnov->nome = nome;

    printf("Digite o nome do Professor\n");
    nome = Entrada();
    dnov->professor = nome;
    printf("Digite o nome da Emenda\n");
    nome = Entrada();
    dnov->ementa = nome;

    novo->dados = dnov;
}
void inserir(descritor *list,int a){//Funçao que insere
    no *novo=(no*)malloc(sizeof(no));
    getchar();
    cad(novo,a);
    novo->proximo = NULL;
    novo->anterior = NULL;
    no *aux, *aux2, *aux3, *aux4;
    aux = list->inicio;
    list->qt++;
    if(list->inicio==NULL)//inserir no inicio
    {
        list->inicio = novo;
        list->fim = novo;
    }
    else if(a <= aux->dados->periodo)//Inserir antes do inicio
    {int x = 0,z=0;
        do{
       if(aux!=NULL){//Se aux for diferente do NULL vai pro proximo
            aux2 = aux->proximo;
       }
        if(aux2==NULL){//Verifica se tem apenas um item na lista
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
        }else if(aux==NULL){//Verifica se tem 2
        x = test(aux2,novo);
        if(x>=0){//Adiciona no começo
        novo->proximo = list->inicio;
        list->inicio->anterior = novo;
        list->inicio = novo;
        }
        else {//Adiciona no fim
            aux2->proximo = novo;
            novo->anterior = aux2;
        }
        x=0;
        }
        else{//Adiciona caso seja atras e tenha mais de 2
        x = test(aux,novo);
        z = test(aux2,novo);
        if (x<=0 && z >=0){//Adiciona no meio
            aux->proximo = novo;
            novo->anterior = aux;
            novo->proximo = aux2;
            aux2->anterior = novo;
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
            if(a >= aux->dados->periodo && aux2!=NULL && a <= aux2->dados->periodo)//Adiciona no meio
            {
                int x=0, z=0;
                x = test(aux2,novo);
                if(x==5 || x==1){//Inserir quando for periodo novo
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
        if((x<=0 && aux3==NULL)){//Inseri no final quando nao tem mais outro
            aux2->proximo = novo;
            novo->anterior = aux2;
            break;
         }else if(x<0 && z<0 && aux4==NULL){//Inseri no primeiro antes do final
            aux3->proximo = novo;
            novo->anterior = aux3;
            break;
         }else if ((x<=0 && z>=0)){//Inseri no primeiro do começo
        aux2->proximo = novo;
        novo->anterior = aux2;
        novo->proximo = aux3;
        aux3->anterior = novo;
        break;
        }else if(x>=0 && z <=0){//Inseri antes do inicio ou depois
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
    printf("--- nome: %s\n", novo->dados->nome);
}

void remocao(descritor *list, char *a){
    no *aux, *aux2, *aux3;
    printf("%s\n", a);
    aux = list->inicio;
    if(strcasecmp(list->inicio->dados->nome, a)==0){//Remove no inicio
        printf("No periodo %d e %s\n",aux->dados->periodo, aux->dados->nome);
        printf("Removido com sucesso\n");
        list->inicio->anterior= NULL;
        free(aux);
    }else if(strcasecmp(list->fim->dados->nome, a)==0){//Remove no fim
        printf("No periodo %d e %s\n",list->fim->dados->periodo, list->fim->dados->nome);
        printf("Removido com sucesso\n");
        aux = list->fim;
        aux2 = list->fim->anterior;
        aux2->proximo=NULL;
        list->fim = aux2;
        free(aux);
    }else{//Remove no meio
        do{
        aux2=aux;
        aux = aux->proximo;
        if(aux==NULL){
        printf("Nao conseguimos encontrar\n");
        break;
        }
        if(strcasecmp(aux->dados->nome, a)==0){
            printf("No periodo %d e %s\n",aux->dados->periodo, aux->dados->nome);
            printf("Removido com sucesso\n");
            aux3 = aux->proximo;
            aux2->proximo = aux3;
            aux3->anterior = aux2;
            free(aux);
            break;
        }
    }while(aux!=NULL);
    }
}
int Imprimemateria(descritor *list, char *a){//Imprime a partir de uma palavra
    no *aux, *aux2;
    aux=list->inicio;
    int d;
    while(aux!=NULL)
    {
        if(strcmp(aux->dados->nome, a)==0){//Imprime o primeiro
            printf(" Nome = %s\n ",aux->dados->nome );
            printf(" Periodo = %d \n", aux->dados->periodo);
            printf(" Professor = %s\n ",aux->dados->professor );
            printf(" Ementa = %s \n", aux->dados->ementa);
            do{
                printf("Digite 1 para ir pra frente ou 2 para ir pra tras ou 0 pra sair\n");
                scanf("%d",&d);
            if(d==1){
            if(aux==list->fim){// Imprime pra frente se for null
            aux = list->inicio;
            printf(" Nome = %s\n ",aux->dados->nome );
            printf(" Periodo = %d \n", aux->dados->periodo);
            printf(" Professor = %s\n ",aux->dados->professor );
            printf(" Ementa = %s \n", aux->dados->ementa);
            }else{//Imprime pra frente caso nao seja null
            aux = aux->proximo;
            printf(" Nome = %s\n ",aux->dados->nome );
            printf(" Periodo = %d \n", aux->dados->periodo);
            printf(" Professor = %s\n ",aux->dados->professor );
            printf(" Ementa = %s \n", aux->dados->ementa);
            }
            }else if(d==2){
            if(aux==list->inicio){
            aux = list->fim;//Vai pra tras caso seja NULL
            printf(" Nome = %s\n ",aux->dados->nome );
            printf(" Periodo = %d \n", aux->dados->periodo);
            printf(" Professor = %s\n ",aux->dados->professor );
            printf(" Ementa = %s \n", aux->dados->ementa);
            }else{//Vai pra tras caso nao seja null
            aux = aux->anterior;
            printf(" Nome = %s\n ",aux->dados->nome );
            printf(" Periodo = %d \n", aux->dados->periodo);
            printf(" Professor = %s\n ",aux->dados->professor );
            printf(" Ementa = %s \n", aux->dados->ementa);
            }
            }
            }while(d!=0);
            break;
        }
        aux = aux->proximo;
    }
    printf("Desculpe nao encotramos essa palavra\n");
   return 1;
    }
void Imprimirperiodo(descritor *list){
    no *aux, *aux2, *aux3, *aux4, *aux5;
    aux = list->inicio;
    aux3 = aux;
    aux5 = aux3;
    int a= aux->dados->periodo;
    int d=0;

    while(a==aux->dados->periodo){//Imprime o periodo
            printf("Periodo - %d\n",a);
            printf("Nome da disciplina %s\n", aux->dados->nome);
            aux=aux->proximo;
            if(aux==NULL){//Caso seja NULL
                printf("Deseja detalhar 1 ou Sair 0");
                scanf("%d", &d);
                if(d==1){
                    d = Imprimemateria(list,aux3->dados->nome);
                    if(d==1){
                        d = 5;
                        break;
                    }
                }else{
                    d = 5;
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
            do{//Vai pra frente
            printf("Periodo - %d\n",a);
            printf("Nome da disciplina %s\n", aux->dados->nome);
            aux=aux->proximo;
            if(aux==NULL){
                break;
            }
          }while(aux->dados->periodo==a );

          if(aux==NULL){//Se for o final da lista
                printf("Final da Lista\n");
            aux = aux2;
            aux5 = aux->anterior;
            aux3 = aux2;
          }else{
            aux3 = aux2;
            aux5 = aux3->anterior;
          }

        }
        else if(d==2){//Vai pra tras se for o final
            if(aux3==list->inicio){
                printf("Estamos no inicio da Lista\n");
            }else{
                a = aux5->dados->periodo;
                aux=aux3;
               do{
              aux3 = aux3->anterior;
              printf("%d\n", aux3->dados->periodo);
              if(aux3==list->inicio){
                break;
                }
                if(aux3->dados->periodo==a && aux3->anterior->dados->periodo<a){
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
            Imprimemateria(list,aux2->dados->nome);
            break;
        }
    }while(d!=0);
        }
}

void quat(descritor *list){
    printf("A quantidade de questoes cadastradas foram %d\n", list->qt);
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
    char *nome;char c;int g;
    do{
        printf("---------------SISTEMA DE CADASTRO UFT------------------\n");
        printf("-----------------------DIGITE---------------------------\n");
        printf("---------------------<C>ADASTRO-------------------------\n");
        printf("---------------------<R>EMOVER--------------------------\n");
        printf("---------------------<I>MPRIMIR(NOME)-------------------\n");
        printf("---------------------<P>IMPRIMIR(PERIODOS)---------------\n");
        printf("---------------------<Q>UANTIDADE(CAD)-------------------\n");
        printf("--------------------------<0>SAIR------------------------\n");
        scanf("%c",&c);
        switch(c){
        case 'c':
        printf("Digite o numero do periodo\n");
        scanf("%d", &g);
        inserir(list,g);
        break;
        case 'r':
        printf("Digite o nome da Materia a ser removida\n");
        getchar();
        nome = Entrada();
        remocao(list,nome);
        break;
        case 'i':
        printf("Digite o nome da Materia a ser procurada\n");
        getchar();
        nome = Entrada();
        Imprimemateria(list,nome);
        break;
        case 'p':
        Imprimirperiodo(list);
        break;
        case 'q':
        quat(list);
        }
    }while(c!='0');

    return 0;
}
