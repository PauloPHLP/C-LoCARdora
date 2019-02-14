#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Locacao2 Dados_Locacao2;

struct Dados_Locacao2 {
	
	char Nome_Cliente[50], Endereco[100], CPF[20], RG[20], CNH[20], Nome_Carro[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Idade, Ano, Marchas, Portas, Assentos, Numero_Locacao, Dia_I, Dia_F, Mes_I, Mes_F, Ano_I, Ano_F, Num_Dias, Status;
	float Valor, Total;
	
};

int Listar_Alugueis () {
	
	FILE *Locacoes;
	Dados_Locacao2 Locacao;
	int Op;

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	Inicio:
		
	printf ("Legenda: 0 - Alugado, 1 - Devolvido/Livre\n\nOs dados das locações são:\n\n");
	printf ("==========================================================");

	Locacoes = fopen ("Locacoes.dat", "rb");
	
	if (Locacoes == NULL) {
		
		printf ("\n\nErro ao abrir o arquivo! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
	
	while (fread (&Locacao, sizeof (Dados_Locacao2), 1, Locacoes) == 1) {
		
		Sleep (100);
		printf ("\n\nDados do cliente:\n\nCódigo da locação: %i\nNome: %s\nIdade: %i\nRG: %s\nCPF: %s\nCNH: %s\nEndereço: %s\n\n", Locacao.Numero_Locacao, Locacao.Nome_Cliente, Locacao.Idade, Locacao.RG, Locacao.CPF, Locacao.CNH, Locacao.Endereco);
		printf ("Dados do veículo:\n\nStatus da locação: %i\nNome do veículo: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nAssentos: %i\nDia de locação: %i/%i/%i\nDia de entrega: %i/%i/%i\nValor da diária: R$%0.2f\nValor total do aluguel: R$%0.2f\n\n", Locacao.Status, Locacao.Nome_Carro, Locacao.Marca, Locacao.Placa, Locacao.Carroceria, Locacao.Ano, Locacao.Cor, Locacao.Cambio, Locacao.Marchas, Locacao.Portas, Locacao.Assentos, Locacao.Dia_I, Locacao.Mes_I, Locacao.Ano_I, Locacao.Dia_F, Locacao.Mes_F, Locacao.Ano_F, Locacao.Valor, Locacao.Total);
		printf ("==========================================================");
		
	}

	fclose (Locacoes);
	
	printf ("\n\n");
	
	system ("pause");	
	system ("cls");
	return 2;
	
}
