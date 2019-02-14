#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Veiculo6 Dados_Veiculo6;

struct Dados_Veiculo6 {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Delete_Veiculo () {
	
	FILE *Veiculos;
	Dados_Veiculo6 Veiculo;
	int Op, Cont = 0, Posicao = 0, Resultado;
	char Placa[20], *STR;
	
	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
	Inicio:
	
	Veiculos = fopen ("Veiculos.dat", "rb+");
	
	if (Veiculos == NULL) {
		
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
	
	printf ("Voc� est� no menu de deletar de ve�culos da frota!\n\nPara come�ar digite a placa do ve�culo que deseja deletar da frota: ");
	fflush (stdin);
	gets (Placa);
	printf ("\n");
	
	while (!feof (Veiculos)) {

	if (fread (&Veiculo, sizeof (Dados_Veiculo6), 1, Veiculos) == 1 && Veiculo.Status != 2) {
		
		if (strcmp (Placa, Veiculo.Placa) == 0) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			break;
			
		}
		
	}
	
	}
	
	printf ("Deseja apagar este ve�culo da frota? (1 - Sim) (2 - N�o): ");
	scanf ("%i", &Op);
		
	if (Op == 1) {
		
	rewind (Veiculos);
	
		while (fread (&Veiculo, sizeof (Dados_Veiculo6), 1, Veiculos) == 1) {
		
			if (strcmp (Placa, Veiculo.Placa) == 0) {
			 	
				Veiculo.Status = 2;
				Posicao = Cont;
			
			}

		Cont++;

		}

		Veiculo.Status = 2;
		fseek (Veiculos, sizeof (Dados_Veiculo6) * Posicao, SEEK_SET);
		Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo6), 1, Veiculos);
		
		if (Resultado == 1) {
		
		system ("cls");
		Sleep (500);
		printf ("Ve�culo deletado com sucesso!\n\nDeseja deletar outro ve�culo da frota? (1 - Sim) (2 - N�o): ");
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
		
		printf ("\nErro ao deletar o ve�culo da frota! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
	} else if (Op == 2) {
			
		system ("cls");
		return 2;
			
	}
		
	while (Op < 1 || Op > 2) {
			
		printf ("\nErro! Digite um c�digo v�lido: ");
		scanf ("%i", &Op);
			
		if (Op == 1) {
			
		fseek (Veiculos, sizeof (Dados_Veiculo6) * Posicao, SEEK_SET);
		Resultado = fwrite (&Veiculo, sizeof (Dados_Veiculo6), 1, Veiculos);
		
		if (Resultado == 1) {
		
		Sleep (500);
		printf ("\nVe�culo deletado com sucesso!\n\nDeseja deletar outro ve�culo da frota? (1 - Sim) (2 - N�o): ");
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
		
		printf ("\nErro ao deletar o ve�culo da frota! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
	} else if (Op == 2) {
			
		system ("cls");
		return 2;
			
	}
			
	}	
	
	fclose (Veiculos);
	
}
