#include <stdio.h>
#include <conio.h>

int main(){
	int n1 = 0,n2 = 1,termo,cont;
	
	printf("Funcao fibonnaci termo numero - ");
	scanf("%d",&termo);
	
	for(cont = 0;cont < termo;cont++){
		n2 += n1;
		n1 = n2 - n1;				
	}
	printf("\ntermo %d eh %d",cont,n2);
	
	getch();
	return 0;
}

