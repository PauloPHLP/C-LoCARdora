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
		
	printf ("Legenda: 0 - Alugado, 1 - Devolvido/Livre\n\nOs dados das loca��es s�o:\n\n");
	printf ("==========================================================");

	Locacoes = fopen ("Locacoes.dat", "rb");
	
	if (Locacoes == NULL) {
		
		printf ("\n\nErro ao abrir o arquivo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
	
	while (fread (&Locacao, sizeof (Dados_Locacao2), 1, Locacoes) == 1) {
		
		Sleep (100);
		printf ("\n\nDados do cliente:\n\nC�digo da loca��o: %i\nNome: %s\nIdade: %i\nRG: %s\nCPF: %s\nCNH: %s\nEndere�o: %s\n\n", Locacao.Numero_Locacao, Locacao.Nome_Cliente, Locacao.Idade, Locacao.RG, Locacao.CPF, Locacao.CNH, Locacao.Endereco);
		printf ("Dados do ve�culo:\n\nStatus da loca��o: %i\nNome do ve�culo: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nAssentos: %i\nDia de loca��o: %i/%i/%i\nDia de entrega: %i/%i/%i\nValor da di�ria: R$%0.2f\nValor total do aluguel: R$%0.2f\n\n", Locacao.Status, Locacao.Nome_Carro, Locacao.Marca, Locacao.Placa, Locacao.Carroceria, Locacao.Ano, Locacao.Cor, Locacao.Cambio, Locacao.Marchas, Locacao.Portas, Locacao.Assentos, Locacao.Dia_I, Locacao.Mes_I, Locacao.Ano_I, Locacao.Dia_F, Locacao.Mes_F, Locacao.Ano_F, Locacao.Valor, Locacao.Total);
		printf ("==========================================================");
		
	}

	fclose (Locacoes);
	
	printf ("\n\n");
	
	system ("pause");	
	system ("cls");
	return 2;
	
}
