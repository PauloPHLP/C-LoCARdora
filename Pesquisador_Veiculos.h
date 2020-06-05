#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Veiculo3 Dados_Veiculo3;

struct Dados_Veiculo3 {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Pesquisador_Veiculos () {
	
	FILE *Veiculos;
	Dados_Veiculo3 Veiculo;
	char Pesquisa[100], *STR;
	int Op, Cont = 0;
	
	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
	Inicio:
	
	Veiculos = fopen ("Veiculos.dat", "rb");
	
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
	
	printf ("Legenda: 0 - Alugado, 1 - Devolvido/Livre\n\nVocê está no menu de pesquisa de veículos! Para começar digite o que procura: ");
	fflush (stdin);
	gets (Pesquisa);
	printf ("\n");
	
	while (!feof (Veiculos)) {

	if (fread (&Veiculo, sizeof (Dados_Veiculo3), 1, Veiculos) == 1 && Veiculo.Status != 2) {
		
		if (STR = strstr (strupr (Veiculo.Nome), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		} 
		
		if (STR = strstr (strupr (Veiculo.Marca), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		} 
		
		if (STR = strstr (strupr (Veiculo.Placa), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		} 
		
		if (STR = strstr (strupr (Veiculo.Carroceria), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		} 
		
		if (Veiculo.Ano == atoi (Pesquisa)) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		}
		
		if (STR = strstr (strupr (Veiculo.Cor), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		}
		
		if (STR = strstr (strupr (Veiculo.Cambio), strupr (Pesquisa))) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		} 
		
		if (Veiculo.Marchas == atoi (Pesquisa)) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		}
		
		if (Veiculo.Portas == atoi (Pesquisa)) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		}
		
		if (Veiculo.Assentos == atoi (Pesquisa)) {
			
			Sleep (50);
			printf ("Nome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			Cont++;
			
		}
		

		
	}
	
	if (feof (Veiculos) != 0 && Cont == 0) {
		
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

	fclose (Veiculos);
	
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
