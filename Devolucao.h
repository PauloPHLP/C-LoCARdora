#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Locacao3 Dados_Locacao3;

struct Dados_Locacao3 {
	
	char Nome_Cliente[50], Endereco[100], CPF[20], RG[20], CNH[20], Nome_Carro[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Idade, Ano, Marchas, Portas, Assentos, Numero_Locacao, Dia_I, Dia_F, Mes_I, Mes_F, Ano_I, Ano_F, Num_Dias, Status;
	float Valor, Total;
	
};

struct Dados_Veiculo5 {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Devolucao () {
	
	FILE *Veiculos;
	FILE *Locacoes;
	Dados_Veiculo5 Veiculo;
	Dados_Locacao3 Locacao;
	char Pesquisa[100], *STR;
	int Op, Dias = 0, Result, Codigo, Pos = 0, Cont = 0;
	float Dano = 0, Atraso = 0;
	
	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
	Inicio:
		
	system ("cls");
	
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
	
	Locacoes = fopen ("Locacoes.dat", "rb+");
	
	if (Locacoes == NULL) {
		
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
	
	printf ("Voc� est� no menu de devolu��o! Digite a placa do ve�culo que o cliente deseja devolver: ");
	setbuf (stdin, NULL);
	gets (Pesquisa);
	printf ("\nDigite o c�digo da loca��o: ");
	scanf ("%i", &Codigo);
	
	rewind (Locacoes);
	
	while (fread (&Locacao, sizeof (Dados_Locacao3), 1, Locacoes) == 1) {
		
		if (strcmp (strupr (Pesquisa), strupr (Locacao.Placa)) != 0) {
			
			printf ("\nVe�culo n�o encontrado! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		} else if (strcmp (strupr (Pesquisa), strupr (Locacao.Placa)) == 0) {
			
			system ("cls");
			
			printf ("Dados da loca��o:\n\n");
		
			Sleep (100);
			printf ("Dados do cliente:\n\nC�digo da loca��o: %i\nNome: %s\nIdade: %i\nRG: %s\nCPF: %s\nCNH: %s\nEndere�o: %s\n\n", Locacao.Numero_Locacao, Locacao.Nome_Cliente, Locacao.Idade, Locacao.RG, Locacao.CPF, Locacao.CNH, Locacao.Endereco);
			printf ("Dados do ve�culo:\n\nStatus da loca��o: %i\nNome do ve�culo: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nAssentos: %i\nDia de loca��o: %i/%i/%i\nDia de entrega: %i/%i/%i\nValor total do aluguel: R$%0.2f\n\n", Locacao.Status, Locacao.Nome_Carro, Locacao.Marca, Locacao.Placa, Locacao.Carroceria, Locacao.Ano, Locacao.Cor, Locacao.Cambio, Locacao.Marchas, Locacao.Portas, Locacao.Assentos, Locacao.Dia_I, Locacao.Mes_I, Locacao.Ano_I, Locacao.Dia_F, Locacao.Mes_F, Locacao.Ano_F, Locacao.Total);
			printf ("==========================================================\n\n");
			
			
			printf ("O ve�culo foi entregue com atraso? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
			
			if (Op == 1) {
			
				printf ("\nQuantos dias? ");
				scanf ("%i", &Dias);
				
				Atraso = Locacao.Valor * Dias;
				Locacao.Total += Atraso;
				
				printf ("\nO ve�culo foi entregue com algum dano? (1 - Sim) (2 - N�o): ");
				scanf ("%i", &Op);
				
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				while (Op < 1 || Op > 2) {
			
					printf ("\nErro! Digite um c�digo v�lido: ");
					scanf ("%i", &Op);
			
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				}
				
			
			} else if (Op == 2) {
			
				printf ("\nO ve�culo foi entregue com algum dano? (1 - Sim) (2 - N�o): ");
				scanf ("%i", &Op);
				
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				while (Op < 1 || Op > 2) {
			
					printf ("\nErro! Digite um c�digo v�lido: ");
					scanf ("%i", &Op);
			
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				}
			
			}
			
			while (Op < 1 || Op > 2) {
			
				printf ("\nErro! Digite um c�digo v�lido: ");
				scanf ("%i", &Op);
			
				if (Op == 1) {
			
				printf ("Quantos dias?");
				scanf ("%i", &Dias);
				
				Atraso = Locacao.Valor * Dias;
				Locacao.Total += Atraso;
	
				printf ("\nO ve�culo foi entregue com algum dano? (1 - Sim) (2 - N�o): ");
				scanf ("%i", &Op);
				
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				while (Op < 1 || Op > 2) {
			
					printf ("\nErro! Digite um c�digo v�lido: ");
					scanf ("%i", &Op);
			
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				}
			
			} else if (Op == 2) {
			
				printf ("\nO ve�culo foi entregue com algum dano? (1 - Sim) (2 - N�o): ");
				scanf ("%i", &Op);
				
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				while (Op < 1 || Op > 2) {
			
					printf ("\nErro! Digite um c�digo v�lido: ");
					scanf ("%i", &Op);
			
				if (Op == 1) {
			
					printf ("\nDigite o custo do reparo: R$");
					scanf ("%f", &Dano);
			
					Locacao.Total += Dano;
			
				} else if (Op == 2) {
			
					goto Continue;
			
				}
			
				}
			
			}
			
			}
			
			Continue:

			system ("cls");

			printf ("Dados da loca��o:\n\nCliente: %s\nCPF: %s\nRG: %s\nVe�culo: %s\nPlaca: %s\nValor da di�ria: R$%0.2f\nDias de atraso: %i\nCusto por atraso: R$%0.2f\nCusto por danos: R$%0.2f\nTotal da loca��o: %0.2f\n\nConfirmar devolu��o? (1 - Sim) (2 - N�o): ", Locacao.Nome_Cliente, Locacao.CPF, Locacao.RG, Locacao.Nome_Carro, Locacao.Placa, Locacao.Valor, Dias, Atraso, Dano, Locacao.Total);
			scanf ("%i", &Op);
			
			if (Op == 1) {
			
				goto Modifique;
			
			} else if (Op == 2) {
			
				system ("cls");
				goto Inicio;
			
			}
			
			while (Op < 1 || Op > 2) {
			
				printf ("\nErro! Digite um c�digo v�lido: ");
				scanf ("%i", &Op);
			
				if (Op == 1) {
			
					goto Modifique;
			
			} else if (Op == 2) {
			
				system ("cls");
				goto Inicio;
			
			}
			
			}

		}
		
	}
	
	Modifique:
	
	rewind (Veiculos);
	
	while (fread (&Veiculo, sizeof (Dados_Veiculo5), 1, Veiculos) == 1) {
		
		if (STR = strstr (strupr (Veiculo.Placa), strupr (Pesquisa))) {
			 	
			Veiculo.Status = 1;
			Pos = Cont;
			break;
			
		}
		
		Cont++;
		
	}
	
	rewind (Locacoes);

	while (fread (&Locacao, sizeof (Dados_Locacao3), 1, Locacoes) == 1) {
		
		if (STR = strstr (strupr (Locacao.Placa), strupr (Pesquisa))) {
			 	
			Locacao.Status = 1;
			break;
			
		}

	}
	
	fseek (Veiculos, sizeof (Dados_Veiculo5) * Pos, SEEK_SET);
	Veiculo.Status = 1;
	fwrite (&Veiculo, sizeof (Dados_Veiculo5), 1, Veiculos);
	fseek (Locacoes, sizeof (Dados_Locacao3) * Codigo, SEEK_SET);
	fwrite (&Locacao, sizeof (Dados_Locacao3), 1, Locacoes);
	
	fclose (Veiculos);
	fclose (Locacoes);
	
}
