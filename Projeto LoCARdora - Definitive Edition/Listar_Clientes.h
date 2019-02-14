#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados2 Dados2;

struct Dados2 {

	char Nome[50], Endereco[100], CPF[20], RG[20], CNH[20];
	int Idade, Status;
	
};

int Listar_Clientes () {
	
	FILE *Clientes;
	Dados2 Cliente;
	int Op;

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	Inicio:
		
	printf ("Os clientes cadastrados são:\n\n");

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
	
	while (fread (&Cliente, sizeof (Dados2), 1, Clientes)) {
		
		if (Cliente.Status == 1) {
			
			Sleep (100);
			printf ("Nome: %s\nIdade: %i\nRG: %s\nCPF: %s\nCNH: %s\nEndereço: %s\nStatus: %i\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco, Cliente.Status);
			
		}
		
	}
	
	fclose (Clientes);
	
	system ("pause");	
	system ("cls");
	return 2;
	
}
