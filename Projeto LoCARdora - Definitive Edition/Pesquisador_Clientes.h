#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados3 Dados3;

struct Dados3 {

	char Nome[50], Endereco[100], CPF[20], RG[20], CNH[20];
	int Idade, Status;
	
};

int Pesquisador_Clientes () {
	
	FILE *Clientes;
	Dados3 Cliente;
	char Pesquisa[100], *STR;
	int Op, Cont = 0;
	
	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
	Inicio:
	
	Clientes = fopen ("Clientes.dat", "rb");
	
	if (Clientes == NULL) {
		
		printf ("Erro ao abrir o arquivo! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
		scanf ("%i", &Op);
		
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
		
		while (Op < 1 || Op > 2) {
			
			printf ("\nErro! Digite um código válido: ");
			scanf ("%i", &Op);
			
			if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
			
		}
		
	}
	
	printf ("Você está no menu de pesquisa de clientes! Para começar digite o que procura: ");
	fflush (stdin);
	gets (Pesquisa);
	printf ("\n");
	
	while (!feof (Clientes)) {

	if (fread (&Cliente, sizeof (struct Dados3), 1, Clientes) == 1 && Cliente.Status != 2) {
		
		if (STR = strstr (strupr (Cliente.Nome), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			Cont++;
			
		} 
		
		if (Cliente.Idade == atoi (Pesquisa)) {
			
			Sleep (50);
			printf ("Nome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			Cont++;
			
		}
		
		if (STR = strstr (strupr (Cliente.RG), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			Cont++;
			
		}
		
		if (STR = strstr (strupr (Cliente.CPF), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			Cont++;
			
		}
		
		if (STR = strstr (strupr (Cliente.CNH), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			Cont++;
			
		}
		
		if (STR = strstr (strupr (Cliente.Endereco), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			Cont++;
			
		}
		
	}
	
	if (feof (Clientes) != 0 && Cont == 0) {
		
		printf ("\nA busca não retornou resultados! Deseja tentar mais uma vez? (1 - Sim) (2 - Não): ");
		scanf ("%i", &Op);
		
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
		
		while (Op < 1 || Op > 2) {
			
			printf ("\nErro! Digite um código válido: ");
			scanf ("%i", &Op);
			
				if (Op == 1) {
			
					system ("cls");
					goto Inicio;
				
				} else if (Op == 2) {
			
					system ("cls");
					return 2;
			
				}
			
		}
		
	}
	
	}

	fclose (Clientes);
	
	printf ("Deseja realizar mais uma pesquisa? (1 - Sim) (2 - Não): ");
	scanf ("%i", &Op);
	
	if (Op == 1) {
			
		system ("cls");
		goto Inicio;
			
	} else if (Op == 2) {
			
		system ("cls");
		return 2;
			
	}
		
	while (Op < 1 || Op > 2) {
			
		printf ("\nErro! Digite um código válido: ");
		scanf ("%i", &Op);
			
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
			
	}
		
}
