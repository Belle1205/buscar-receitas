
#include <stdio.h>
#include <string.h> 

// criação da estrutura dos ingredientes
struct ingredientes { 
	char nome_ing[20]; 
	int quanto;
}; 

// criação da estrutura geral 
struct receita_geral { 
	char nome_recei[25]; 
	int num_ing; 
	struct ingredientes elementos[10]; // nomeando a estrutura ingredientes como vetor de 10 elementos
};

// nomeando a estrutura geral como vetor de 5 elementos
struct receita_geral receita[5]; 

int main () {
	
	int i = 0;
	int n = 0;
	
	
	printf ("Livro de receitas\n");
	
	// inicio da leitura dos ingredientes e das informações de cada receita
	for(i=0; i<5; i++) {
		
		printf("\n\n\nDigite o nome da receita %d: ", i+1);
		fgets(receita[i].nome_recei, 25, stdin);
		
		printf("Digite a quantidade de ingredientes: ");
		scanf("%d", &receita[i].num_ing);
		getchar();
		
		// para o n menor que o número de ingredientes digitados pelo usuário, faça os comandos abaixo
		for (n = 0; n < receita[i].num_ing; n++) {
			
			printf ("\n\nDigite o nome do ingrediente %d: ", n+1);
			fgets(receita[i].elementos[n].nome_ing, 30, stdin);
			
			printf ("Digite quanto voce vai precisar desse ingrediente: ");
			scanf ("%d", &receita[i].elementos[n].quanto);
			getchar();
				
		}
	}
	// fim da leitura e do loop
	
	int continuar;
	char nome[25];
	
	printf ("\n\n\n\n\n---------------------------------------------");
	printf ("BUSCANDO RECEITAS--------------------------------------");
	
	do {
		
		printf ("\n\nDigite o nome da receita que deseja buscar: ");
		fgets(nome, 25, stdin);
		
		int flag = 0;
		
		for (i=0; i<5; i++) {
		
			if (strcmp(nome, receita[i].nome_recei) == 0) {
			
				flag = 1;
						
				printf("\n\nReceita %s ", receita[i].nome_recei);
		
				printf("\nQuantidade de ingredientes da receita %s: %d ", receita[i].nome_recei, receita[i].num_ing);
		
				// para o n menor que o número de ingredientes digitados pelo usuário, faça os comandos abaixo
				for (n = 0; n < receita[i].num_ing; n++) {
			
					printf ("\n\nNome do ingreditente %d e: %s ", n+1, receita[i].elementos[n].nome_ing);
			
					printf ("\nQuantidade necessaria para o ingrediente %s: %d ", receita[i].elementos[n].nome_ing, receita[i].elementos[n].quanto);
				
				}
				
			}
			
			
		}
		
		if (flag == 0) {
			
			printf("Nao existe essa receita");
			break;
			
		}
		
		printf ("\n\n\nPara continuar consultando receitas digite 1: ");
		scanf ("%d", &continuar);
		getchar();
		
	}while (continuar == 1);
	
		
	
	return 0;
	
}







