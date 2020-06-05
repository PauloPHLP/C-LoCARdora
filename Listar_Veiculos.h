#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Veiculo2 Dados_Veiculo2;

struct Dados_Veiculo2 {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Listar_Veiculos () {
	
	FILE *Veiculos;
	Dados_Veiculo2 Veiculo;
	int Op, Cod;

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	Inicio:
		
	printf ("O que voc� deseja ver?\n\n");
	Sleep (250);
	printf ("1 - Todos os ve�culos\n");
	Sleep (50);
	printf ("2 - Ve�culos dispon�veis para loca��o\n");
	Sleep (50);
	printf ("3 - Ve�culos alugados\n");
	Sleep (50);
	printf ("4 - Voltar\n");
	Sleep (50);
	printf ("\nOp��o: ");
	scanf ("%i", &Cod);

	Veiculos = fopen ("Veiculos.dat", "rb");
	
	if (Veiculos == NULL) {
		
		printf ("\nErro ao abrir o arquivo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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

	if (Cod == 1) {

	OP1:

		system ("cls");
		printf ("Legenda: 0 - Alugado, 1 - Livre.\n\nLista de todos os ve�culo:\n\n");
			
		while (fread (&Veiculo, sizeof (Dados_Veiculo2), 1, Veiculos) == 1) {
		
			if (Veiculo.Status != 2) {
			 	
				Sleep (100);
				printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
		
			}
		}
		
		printf ("Deseja ver outra lista? (1 - Sim) (2 - N�o): ");
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
		
	if (Cod == 2) {
		
	OP2:
		
		system ("cls");
		printf ("Lista de ve�culos dispon�veis para loca��o:\n\n");

		while (fread (&Veiculo, sizeof (Dados_Veiculo2), 1, Veiculos) == 1) {
		
			if (Veiculo.Status == 1 && Veiculo.Status != 2) {
			 	
				Sleep (100);
				printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
		
			}

		}
		
		printf ("Deseja ver outra lista? (1 - Sim) (2 - N�o): ");
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
	
	if (Cod == 3) {
		
	OP3:
	
		system ("cls");
		printf ("Lista de ve�culos alugados:\n\n");

		while (fread (&Veiculo, sizeof (Dados_Veiculo2), 1, Veiculos) == 1) {
		
			if (Veiculo.Status == 0 && Veiculo.Status != 2) {
			 	
				Sleep (100);
				printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
		
			}

		}
		
		printf ("Deseja ver outra lista? (1 - Sim) (2 - N�o): ");
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
	
	if (Cod == 4) {
		
		system ("cls");
		return 2;
		
	}
	
	while (Cod < 1 || Cod > 4) {
			
		printf ("\nErro! Digite um c�digo v�lido: ");
		scanf ("%i", &Cod);
			
		if (Cod == 1) {
			
			system ("cls");
			goto OP1;
			
		} else if (Cod == 2) {
			
			system ("cls");
			goto OP2;			
			
		} else if (Cod == 3) {
			
			system ("cls");
			goto OP3;			
			
		} else if (Cod == 4) {
			
			system ("cls");
			return 2;
			
		}
			
	}
	
	fclose (Veiculos);
	
}
