#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Veiculo Dados_Veiculo;

struct Dados_Veiculo {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Cad_Veiculos () {

	FILE *Veiculos;
	Dados_Veiculo Veiculo;
	char Teste[20];
	int Op, Result;

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	Inicio:

	Veiculos = fopen ("Veiculos.dat", "ab+");
	
	if (Veiculos == NULL) {
		
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
	
	printf ("Você está no menu de cadastro de veículos à frota! Para continuar digite a placa do veículo: ");
	fflush (stdin);
	gets (Teste);
	
	while (fread (&Veiculo, sizeof (Dados_Veiculo), 1, Veiculos) == 1) {
		
		if (strcmp (Teste, Veiculo.Placa) == 0 && Veiculo.Status != 2) {
			
			printf ("\nVeículo já cadastrado! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
			break;
			
		} 
		
	}
	
	Veiculo.Status = 1;
	strcpy (Veiculo.Placa, Teste);
	printf ("\nVeículo ainda não cadastrado. Continue com o cadastro!\n\nNome: ");
	fflush (stdin);
	gets (Veiculo.Nome);
	printf ("Marca: ");
	fflush (stdin);
	gets (Veiculo.Marca);
	printf ("Carroceria: ");
	fflush (stdin);
	gets (Veiculo.Carroceria);
	printf ("Ano de lançamento: ");
	scanf ("%i", &Veiculo.Ano);
	fflush (stdin);
	printf ("Cor: ");
	fflush (stdin);
	gets (Veiculo.Cor);
	printf ("Câmbio: ");
	fflush (stdin); 
	gets (Veiculo.Cambio);
	printf ("Número de marchas: ");
	scanf ("%i", &Veiculo.Marchas);
	printf ("Número de portas: ");
	scanf ("%i", &Veiculo.Portas);
	printf ("Número de assentos: ");
	scanf ("%i", &Veiculo.Assentos);
	printf ("Preço da diária: R$");
	scanf ("%f", &Veiculo.Preco);
	printf ("\n");
	
	Result = fwrite (&Veiculo, sizeof (Dados_Veiculo), 1, Veiculos);
	
	if (Result == 1) {
		
		Sleep (500);
		printf ("\Veículo cadastrado com sucesso! Para o veículo aparecer nas listas reinicie o programa.\n\nDeseja cadastrar outro veículo? (1 - Sim) (2 - Não): ");
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
		
		printf ("\nErro ao cadastrar o veículo! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
	
	fclose (Veiculos);
}
