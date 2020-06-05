#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados Dados;

struct Dados {

	char Nome[50], Endereco[100], CPF[20], RG[20], CNH[20];
	int Idade, Status;
	
};

int Cad_Clientes () {
	
	FILE *Clientes;
	Dados Cliente;
	char Teste[20];
	int Op, Result;

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	Inicio:

	Clientes = fopen ("Clientes.dat", "ab+");
	
	if (Clientes == NULL) {
		
		printf ("Erro ao abrir o arquivo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
		scanf ("%i", &Op);
		
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
		
		while (Op < 1 || Op > 2) {
			
			printf ("\nErro! Digite um c�digo v�lido: ");
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
	
	printf ("Voc� est� no menu de cadastro de clientes! Para continuar digite o n�mero do CPF do cliente: ");
	fflush (stdin);
	gets (Teste);
	
	while (fread (&Cliente, sizeof (Dados), 1, Clientes) == 1) {
		
		if (strcmp (Teste, Cliente.CPF) == 0 && Cliente.Status != 2) {
			
			printf ("\nCliente j� cadastrado! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
			
			if (Op == 1) {
			
				system ("cls");
				goto Inicio;
			
			} else if (Op == 2) {
			
				system ("cls");
				return 2;
			
			}
			
			while (Op < 1 || Op > 2) {
			
				printf ("\nErro! Digite um c�digo v�lido: ");
				scanf ("%i", &Op);
			
				if (Op == 1) {
			
				system ("cls");
				goto Inicio;
			
			} else if (Op == 2) {
			
				system ("cls");
				return 2;
			
			}
			
			}
			
			break;
			
		} 
		
	}
	
	strcpy (Cliente.CPF, Teste);
	printf ("\nCliente ainda n�o cadastrado. Continue com o cadastro!\n\nNome: ");
	fflush (stdin);
	gets (Cliente.Nome);
	printf ("Idade: ");
	fflush (stdin);
	scanf ("%i", &Cliente.Idade);
	
	if (Cliente.Idade < 18) {
		
		printf ("\nERRO! Menores de idade n�o podem locar ve�culos. Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
		scanf ("%i", &Op);
			
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}	
		
		while (Op < 1 || Op > 2) {
			
			printf ("\nErro! Digite um c�digo v�lido: ");
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
	
	printf ("N�mero do RG: ");
	fflush (stdin);
	gets (Cliente.RG);
	printf ("N�mero da CNH: ");
	fflush (stdin);
	gets (Cliente.CNH);
	printf ("Endere�o: ");
	fflush (stdin);
	gets (Cliente.Endereco);
	Cliente.Status = 1;
	
	Result = fwrite (&Cliente, sizeof (Dados), 1, Clientes);
	
	if (Result == 1) {
		
		Sleep (500);
		printf ("\nCliente cadastrado com sucesso! Para o cliente aparecer nas listas reinicie o programa.\n\nDeseja cadastrar outro cliente? (1 - Sim) (2 - N�o): ");
		scanf ("%i", &Op);
		
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
		
		while (Op < 1 || Op > 2) {
			
			printf ("\nErro! Digite um c�digo v�lido: ");
			scanf ("%i", &Op);
			
			if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
			
		}
		
	} else {
		
		printf ("\nErro ao cadastrar o cliente! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
		scanf ("%i", &Op);
		
		if (Op == 1) {
			
			system ("cls");
			goto Inicio;
			
		} else if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}
		
		while (Op < 1 || Op > 2) {
			
			printf ("\nErro! Digite um c�digo v�lido: ");
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
	
	fclose (Clientes);
}
