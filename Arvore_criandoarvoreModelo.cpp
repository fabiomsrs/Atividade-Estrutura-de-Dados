#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class No{
   public: 
	char info;
	No *esq;
	No *dir;
	No(char n,No *e,No *d){
		info = n;
		esq = e;
		dir = d;
	}
	
};

class Arvore{
	public:
		No *raiz;
		Arvore(){
			raiz=NULL;
		}
		
		No *cria_vazia(){
			return NULL;
		}
		No *cria_No(char n, No *e,No *d){
			No *novo=new No(n,e,d);
			return novo;			
		}
	
		No *cria_Raiz(char n, No *e,No *d){
			No *novo=new No(n,e,d);
			raiz = novo;
			return raiz;			
		}
		
		int arv_vazia(No *n){
			return (n==NULL);	
			
		}
		
		
		void imprime(No *n){
			
			if (n==NULL){
				cout<<"";
			}
			else{				
				cout<<n->info<<endl;
				imprime(n->esq);
				imprime(n->dir);
							   
			}
											
		}
		
		int altura(No *n){
			if(n == NULL){
				return -1;
			}
			else{
				int esq = altura(n->esq);
				int dir = altura(n->dir);
				if(esq < dir){
					return dir + 1;
				}
				else{
					return esq + 1;
				}
			}
		}
		
	int qtdNo(No *n){
		if (n==NULL){
			return 0;			
		}
		else{				
			int qtd = 1;			
			qtd += qtdNo(n->esq);
			qtd += qtdNo(n->dir);						   
			return qtd;
		}
		
	}
	int alturaMinima(No *n){
		int qtd = qtdNo(n);
		
		return log2(qtd) + 1;
	}
	
	void ehCompleta(No *n){
		if(alturaMinima(n) == altura(n) + 1){
			cout << "completa" <<endl;			
		}
		else{
			cout<<"incompleta"<<endl;
		}
	}

};



main(){
	Arvore *arv = new Arvore();
	No *a = arv->cria_No('a',NULL,NULL);
	No *b = arv->cria_No('b',NULL,NULL);	
	No *c = arv->cria_No('c',b,NULL);
	arv->raiz = arv->cria_Raiz('r',c,a);
	arv->imprime(arv->raiz);
	
	arv->ehCompleta(arv->raiz);
	
}
