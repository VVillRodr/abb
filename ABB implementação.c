#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Arvore{
    int num;
    struct Arvore *esq;
    struct Arvore *dir;

}Arvore;
//Aloca um ponteiro para arvore
Arvore* criaNo(int numero){
    Arvore* No = (Arvore*)malloc(sizeof(struct Arvore));
    No->num = numero;
    No->esq = NULL;
    No->dir = NULL;

    printf("O no %d foi criado com sucesso \n",No->num);

    return(No);
}
Arvore* inserirNo(Arvore* arv, int num){


    if (arv == NULL) { //se não houver nó, será criado um novo usando a função criaNo descrita à cima e retornar um no da arvore
        return criaNo(num);
    }
    else if (num <= arv->num) { // se for menor ou igual os nós criados anteriormente-tudo por recursividade- vamos inserir um nó à esquerda
        arv->esq = inserirNo(arv->esq, num);
    }
    else{ //caso contrário, vamos inserir à direita
        arv->dir = inserirNo(arv->dir, num);
    }
    return arv;
}

//Questão 2
int procuraMin(Arvore* arv){ //o menor elemento vai ser o mais à esquerna na abb


    if(arv == NULL){
        return(-1);

    }
    while(arv->esq != NULL){
        arv = arv->esq;

    }
    printf("\nO menor valor eh  %d  \n",arv->num);
    return(arv->num);


}
//Questão 2
int procuraMax(Arvore* arv){ //seguindo a ideia do exemplo à cima, o maior elemento vai ser o mais à direita

    if(arv == NULL)
        return(-1);

    while(arv->dir != NULL)
        arv = arv->dir;

    printf("\nO Maior valor que encontramos eh %d\n",arv->num);

    return (arv->num);



}

//Funçao Pre Ordem RED
void preOrdem(Arvore* arv){

    if(arv != NULL){
        printf("%d ",arv->num);
        preOrdem(arv->esq);
        preOrdem(arv->dir);
    }


}
// Questão 3: imprimir a lista de forma decrescente

void imprimirDecrescente(Arvore* arv){
    if(arv == NULL)
        return;
    imprimirDecrescente(arv->dir);
    printf("%d ",arv->num);
    imprimirDecrescente(arv->esq);
}
//Ordem Crescente é só inverter a função decrescente
void imprimirCrescente(Arvore* arv){
    if(arv == NULL)
        return;
    imprimirCrescente(arv->esq);
    printf("%d ",arv->num);
    imprimirCrescente(arv->dir);
}
int getmax (int a, int b)
{
	 if (a > b)
   {
     return a;
   }
   else
   {
     return b;
   }
}

int maior_ramo(Arvore* a)
{
    if (a == NULL)
    {
      return 0;
    }
    else
    {
        return (getmax(maior_ramo(a->esq),maior_ramo(a->dir))+a->num);
    }
}

Arvore* criaArvGrande(int ini, int fim) { //a função vai criando nós com as metades e metades das metades e metade das metades das metades...
    if (ini > fim){
        return NULL;
    }
    int mid = (ini + fim) / 2;
    Arvore* arv = criaNo(mid);
    arv->esq = criaArvGrande(ini, mid - 1);
    arv->dir = criaArvGrande(mid + 1, fim);
    return arv;
}
int buscarNum(Arvore* arv,int numBusca){

    if(arv == NULL)
        return 0;

    else if(numBusca < arv->num)
        return buscarNum(arv->esq,numBusca);
    else if (numBusca > arv->num)
        return buscarNum(arv->dir,numBusca);
    else{
        printf("Encontramos seu Numero\n");
        return 1;
    }

}
int main(){
    //Criando a Arvore do Exerc�cio
    srand(time(NULL));

   /* Arvore* arv = NULL; //Tive que iniciar como null, senão repetia no primeiro if na função inserirNo e dava problema
    arv = inserirNo(arv,50);
    arv = inserirNo(arv,30);
    arv = inserirNo(arv,90);
    arv = inserirNo(arv,20);
    arv = inserirNo(arv,40);
    arv = inserirNo(arv,95);
    arv = inserirNo(arv,10);
    arv = inserirNo(arv,35);
    arv = inserirNo(arv,45);
    arv = inserirNo(arv,3);
    arv = inserirNo(arv,2);
    arv = inserirNo(arv,1);
    */

     //Criar arvore de 1 à 100000
    Arvore* arv;
    arv = NULL;
    //pesquisando, vi que meu erro era que eu estava iniciando a criar a arvore desde o início e não do meio dela
   /* for(int d = 50000;d<100000;d++){ //porém, a arvore está deformada, como se fosse dois grandes galhos, so para a esquerda e outro so pra direita
        arv = inserirNo(arv,d);
    }
    //for(int d = 50000;d>0;d--){
        arv = inserirNo(arv,d);
    }
    */

    /*
    int num;
    for(int g = 0;g<10;g++){
        num = rand() % 100000;
        arv = inserirNo(arv,num);
    }
*/

    arv = criaArvGrande(1, 10); //utilizando a função do chatGPT
    printf("Encontramos o Termo, retorno: %d \n",buscarNum(arv,963));
    printf("\nA SOMA DO MAIOR RAMO %d \n",maior_ramo(arv));
    preOrdem(arv);
    printf("Achamos o %d ",procuraMin(arv));
    printf("Achamos o maior valor %d ",procuraMax(arv));
    printf("\nOrdem Decrescente: ");
    imprimirDecrescente(arv);
    printf("\nOrdem Crescente: ");
    imprimirCrescente(arv);


}
