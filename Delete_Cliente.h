#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados6 Dados6;

struct Dados6 {

	char Nome[50], Endereco[100], CPF[20], RG[20], CNH[20];
	int Idade, Status;
	
};

int Delete_Cliente () {
	
	FILE *Clientes;
	Dados6 Cliente;
	int Op, Cont = 0, Posicao = 0, Resultado;
	char CPF[20], *STR;
	
	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
	Inicio:
	
	Clientes = fopen ("Clientes.dat", "rb+");
	
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
	
	printf ("Você está no menu de deletar de clientes!\n\nPara começar digite o CPF do cliente que deseja deletar o cadastro: ");
	fflush (stdin);
	gets (CPF);
	printf ("\n");
	
	while (!feof (Clientes)) {

	if (fread (&Cliente, sizeof (Dados6), 1, Clientes) == 1 && Cliente.Status != 2) {
		
		if (strcmp (CPF, Cliente.CPF) == 0) {
			
			Sleep (50);
			printf ("Dados do cliente:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			break;
			
		}
		
	}
	
	}
	
	printf ("Deseja apagar o cadastro deste cliente? (1 - Sim) (2 - Não): ");
	scanf ("%i", &Op);
		
	if (Op == 1) {
		
	rewind (Clientes);
	
		while (fread (&Cliente, sizeof (Dados6), 1, Clientes) == 1) {
		
			if (strcmp (strupr (CPF), strupr (Cliente.CPF)) == 0) {
			 	
				Cliente.Status = 2;
				Posicao = Cont;
			
			}

		Cont++;

		}
		

		Cliente.Status = 2;
		fseek (Clientes, sizeof (Dados6) * Posicao, SEEK_SET);
		Resultado =	fwrite (&Cliente, sizeof (Dados6), 1, Clientes);
		
		if (Resultado == 1) {
		
		Sleep (500);
		printf ("\nCliente deletado com sucesso!\n\nDeseja deletar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
	} else {
		
		printf ("\nErro ao deletar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
	} else if (Op == 2) {
			
		system ("cls");
		return 2;
			
	}
		
	while (Op < 1 || Op > 2) {
			
		printf ("\nErro! Digite um código válido: ");
		scanf ("%i", &Op);
			
		if (Op == 1) {
			
		fseek (Clientes, sizeof (Dados6) * Posicao, SEEK_SET);
		Resultado = fwrite (&Cliente, sizeof (Dados6), 1, Clientes);
		
		if (Resultado == 1) {
		
		Sleep (500);
		printf ("\nCliente deletado com sucesso!\n\nDeseja deletar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
	} else {
		
		printf ("\nErro ao deletar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
	} else if (Op == 2) {
			
		system ("cls");
		return 2;
			
	}
			
	}	
	
	fclose (Clientes);
	
}
