#include <stdio.h>	
#include <stdlib.h>	

struct arvore{
	int x;
	struct arvore * fesq;
	struct arvore * fdir;
};

struct arvore * adicionar (int valor, struct arvore *no){
	if (no == NULL){
		struct arvore * add=(struct arvore *)malloc(sizeof(struct arvore));
		add->x = valor;
		add->fesq = NULL;
		add->fdir = NULL;
		system("cls");
		return add;
	}else if (no != NULL){
		if(valor > no->x){
			if (no->fdir == NULL){
				no->fdir=(struct arvore *)malloc(sizeof(struct arvore));	
				no->fdir->x = valor;
				no->fdir->fdir = NULL;
				no->fdir->fesq = NULL;
				system("cls");
				return no;
			}else{
				system("cls");
				no->fdir= adicionar(valor,no->fdir);
				return no;
			}
		}
		if(valor < no->x){
			if (no->fesq == NULL){
				no->fesq=(struct arvore *)malloc(sizeof(struct arvore));	
				no->fesq->x = valor;
				no->fesq->fdir = NULL;
				no->fesq->fesq = NULL;
				system("cls");
				return no;
			}else{
				system("cls");
				no->fesq= adicionar(valor,no->fesq);
				return no;
			}
		}
	}
}

struct arvore mostraPre (struct arvore *no){
	if (no != NULL){
		printf("%d\n", no -> x);
		mostraPre(no->fesq);
		mostraPre(no->fdir);			
	}
}

struct arvore mostraPos (struct arvore *no){
	if (no==NULL)
		return;
	mostraPos(no->fesq);
	mostraPos(no->fdir);			
	printf("%d\n",no->x);
}

void mostraEmOrdem (struct arvore *no){
	if (no == NULL)
		return;
	mostraPre(no->fesq);
	printf("%d\n",no->x);
	mostraPre(no->fdir);	
}


struct arvore Excluir(int valor,struct arvore *no){
	
	if(no != NULL){
		
		if(valor > no->x){
			Excluir(valor,no->fdir);
		}else if(valor < no->x){
			Excluir(valor,no->fesq);
		}else if((no->fdir!=NULL)&&(no->fesq!=NULL)){
			//Completar
		}
		else{
			//Completar
		}
	}
	
}

int altura (struct arvore * no) 
{
   if (no == NULL) 
      return -1; 
   else {
      int aux1 = altura(no->fesq);
      int aux2 = altura(no->fdir);
      if (aux1 < aux2) return aux2 + 1;
      else return aux1 + 1;
   }
}

void imprimeAltura(struct arvore * no)
{
	int x;
	x = altura(no);
	if(x==-1)
		printf("\nArvore vazia!\n");
	else
		printf("\nAltura da arvore: %d\n",x);	
}

struct arvore buscaValor(int valor, struct arvore *no){
	if (no != NULL){
		if (no->x == valor){
			printf("\nValor encontrado !\n");
		}else if (valor > no->x ){
			buscaValor(valor,no->fdir);
		}else if (valor < no->x){
			buscaValor(valor, no->fesq);
		}
	}else{
		printf("\nValor inexistente !\n");
		return;
	}
}

int main(){
	int op=0,sair=1,valor;
	struct arvore * t=NULL, * aux;

	do{
	printf("Menu");
	printf("\n1 - Adicionar no ");
	printf("\n2 - Excluir no");
	printf("\n3 - Mostrar arvore modo prefixado");
	printf("\n4 - Mostrar arvore modo infixado");
	printf("\n5 - Mostrar arvore modo posfixado");
	printf("\n6 - Buscar n0");
	printf("\n7 - Mostrar altura da arvore");
	printf("\n8 - Sair");
	printf("\nDigite a opcao desejada => ");
	scanf ("%d",&op);
	
	switch(op)
	{
		case 1:
			system("cls");
			printf("\nInforme o valor a ser adicionado: ");
			scanf ("%d",&valor);
			t=adicionar(valor, t);
			break;	
		case 2:
			printf("\nInforme o valor a ser removido: ");
			scanf ("%d",&valor);
			Excluir(valor,t);
			break;
		case 3:
			system("cls");
			printf("\nModo pre-fixado:\n");
			mostraPre(t);
			break;
		case 4:
			system("cls");
			printf("\nModo infixado:\n");
			mostraEmOrdem(t);
			break;
		case 5:
			system("cls");
			printf("\nModo pos-fixado:\n");
			mostraPos(t);
			break;
		case 6:
			printf("\nInforme o valor a ser buscado: ");
			scanf ("%d",&valor);
			buscaValor(valor,t);
			break;
		case 7:
			imprimeAltura(t);
			break;
		case 8:
			sair = 0;
			break;
	}
	
	}while(sair == 1);
	
	return 0;
}
