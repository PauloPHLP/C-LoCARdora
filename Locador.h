#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Locacao Dados_Locacao;

struct Dados_Locacao {
	
	char Nome_Cliente[50], Endereco[100], CPF[20], RG[20], CNH[20], Nome_Carro[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Idade, Ano, Marchas, Portas, Assentos, Numero_Locacao, Dia_I, Dia_F, Mes_I, Mes_F, Ano_I, Ano_F, Num_Dias, Status;
	float Valor, Total;
	
};

typedef struct Dados4 Dados4;

struct Dados4 {

	char Nome[50], Endereco[100], CPF[20], RG[20], CNH[20];
	int Idade, Status;
	
};

typedef struct Dados_Veiculo4 Dados_Veiculo4;

struct Dados_Veiculo4 {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Locador () {
	
	FILE *Locacoes;
	FILE *Clientes;
	FILE *Veiculos;
	Dados4 Cliente;
	Dados_Veiculo4 Veiculo;
	Dados_Locacao Locacao;
	char Pesquisa[100], CPF[20], Placa[20], *STR;
	int Op, OK = 0, Cont = 0, Posicao = 0, Contador = 0, Pos = 0, Result;
	float Calculo;
	
	Inicio:
	
	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
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

	printf ("Você está no menu de locação! Digite o CPF do cliente que deseja locar um veículo: ");
	setbuf (stdin, NULL);
	gets (CPF);
	
	while (fread (&Cliente, sizeof (Dados4), 1, Clientes) == 1 && Cliente.Status != 2) {
		
		if (strcmp (CPF, Cliente.CPF) != 0 && !feof (Clientes)) {
			
			printf ("\nCliente não cadastrado!\n\nPara o cliente poder alugar um veículo realize o cadastro dele.\n\nDeseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
		} else if (strcmp (CPF, Cliente.CPF) == 0) {
			
			printf ("\nCliente já cadastrado! Prossiga com o processo.\n\nOs modelos de veículos disponíveis para a locação são:\n\n");
			goto Start;
			
		} 
		
	}
	
	fclose (Clientes);
	
	Start: 
	
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
	
	rewind (Veiculos);
	
	while (fread (&Veiculo, sizeof (Dados_Veiculo4), 1, Veiculos) == 1) {
		
		if (Veiculo.Status == 1 && Veiculo.Status != 2) {
			 	
			Sleep (100);
			printf ("\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lançamento: %i\nCor: %s\nCâmbio: %s\nNúmero de marchas: %i\nNúmero de portas: %i\nNúmero de assentos: %i\nPreço da diária: %0.2f\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco);
		
		}
		
	}
	
	printf ("Digite aqui a placa do veículo que o cliente deseja: ");
	setbuf (stdin, NULL);
	gets (Placa);
	
	rewind (Veiculos);
	
	while (fread (&Veiculo, sizeof (Dados_Veiculo4), 1, Veiculos) == 1) {
		
		if (strcmp (strupr (Placa), strupr (Veiculo.Placa)) == 0 && Veiculo.Status != 2) {
	
			OK = 1;
			break;
	
		} 

	}
	
	fclose (Veiculos);
	
	if (OK == 0) {
		
		printf ("\nErro. Nenhum veículo com esta placa foi encontrado. Tentar mais uma vez? (1 - Sim) (2 - Não): ");
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
	
	system ("cls");
	
	Clientes = fopen ("Clientes.dat", "rb");
	
	Veiculos = fopen ("Veiculos.dat", "rb+");
	
	Locacoes = fopen ("Locacoes.dat", "a+b");
	
	rewind (Locacoes);
	
	while (!feof (Locacoes)) {
		
		if (fread (&Locacao, sizeof (Dados_Locacao), 1, Locacoes) == 1) {
			
			Cont++;
			
		}
	
	}

	rewind (Veiculos);
	
	printf ("Quantos dias o cliente ficará com o veículo? ");
	scanf ("%i", &Locacao.Num_Dias);
	printf ("\nDigite a data de locação do veículo (dd/mm/aa): ");
	scanf ("%i/%i/%i", &Locacao.Dia_I, &Locacao.Mes_I, &Locacao.Ano_I);
	printf ("\nDigite a data de entrega do veículo (dd/mm/aa): ");
	scanf ("%i/%i/%i", &Locacao.Dia_F, &Locacao.Mes_F, &Locacao.Ano_F);
	
	rewind (Veiculos);
	
	while (!feof (Veiculos)) {

	if (fread (&Veiculo, sizeof (struct Dados_Veiculo4), 1, Veiculos) == 1) {
		
		if (STR = strstr (strupr (Veiculo.Placa), strupr (Placa))) {
			
			Calculo = Locacao.Num_Dias * Veiculo.Preco;
				
			break;
				
		}	
		
	}
	
	}
	
	printf ("\nO preço total da locação é R$%0.2f.\n\nDeseja confirmar locação? (1 - Sim) (2 - Não): ", Calculo);
	scanf ("%i", &Op);
		
	if (Op == 2) {
		
		system ("cls");
		return 2;
		
	} 
	
	while (Op < 1 || Op > 2) {
		
		printf ("\nErro! Digite um código válido: ");
		scanf ("%i", &Op);	
		
		if (Op == 2) {
			
			system ("cls");
			return 2;
			
		}	
		
	}
			
	if (Op == 1) {
		
	Locacao.Status = 0;	
	
	rewind (Veiculos);
		
	while (!feof (Veiculos)) {
		
	if (fread (&Veiculo, sizeof (struct Dados_Veiculo4), 1, Veiculos) == 1) {
		
		if (STR = strstr (strupr (Veiculo.Placa), strupr (Placa))) {
			
				Locacao.Numero_Locacao = Cont;
				strcpy (Locacao.Nome_Carro, Veiculo.Nome);
				strcpy (Locacao.Marca, Veiculo.Marca);
				strcpy (Locacao.Placa, Veiculo.Placa);
				strcpy (Locacao.Carroceria, Veiculo.Carroceria);
				Locacao.Ano = Veiculo.Ano;
				strcpy (Locacao.Cor, Veiculo.Cor);
				strcpy (Locacao.Cambio, Veiculo.Cambio);
				Locacao.Marchas = Veiculo.Marchas;
				Locacao.Portas = Veiculo.Portas;
				Locacao.Assentos = Veiculo.Assentos;
				Locacao.Total = Calculo;
				Locacao.Valor = Veiculo.Preco;
				break;
		 
		}
		
	}
	
	}
	
	rewind (Clientes);
	
	while (!feof (Clientes)) {
		
	if (fread (&Cliente, sizeof (Dados4), 1, Clientes) == 1) {
		
		if (STR = strstr (strupr (Cliente.CPF), strupr (CPF))) {
	
				strcpy (Locacao.Nome_Cliente, Cliente.Nome);
				Locacao.Idade = Cliente.Idade;
				strcpy (Locacao.RG, Cliente.RG);
				strcpy (Locacao.CPF, Cliente.CPF);
				strcpy (Locacao.CNH, Cliente.CNH); 
				strcpy (Locacao.Endereco, Cliente.Endereco);
				break;
		 
		}
		
	}
	
	}
	
	}

	Result = fwrite (&Locacao, sizeof (Dados_Locacao), 1, Locacoes);
	
	rewind (Veiculos);
	
	while (!feof (Veiculos)) {
		
		fread (&Veiculo, sizeof (Dados_Veiculo4), 1, Veiculos);
		
			if (STR = strstr (Veiculo.Placa, Placa)) {

				Veiculo.Status = 0;
				Pos = Contador;
				break;
				
			}
				
		Contador++;
				
	}
	
	fseek (Veiculos, sizeof (Dados_Veiculo4) * Pos, SEEK_SET);
	fwrite (&Veiculo, sizeof (Dados_Veiculo4), 1, Veiculos);
	
	Locacao.Numero_Locacao = Cont;
		
	if (Result == 1) {
		
		Sleep (500);
		printf ("\nVeículo locado com sucesso! Código da locação: %i\n\nPara a locação aparecer nas listas reinicie o programa.\n\nDeseja realizar outra locação? (1 - Sim) (2 - Não): ", Locacao.Numero_Locacao);
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
		
		printf ("\nErro ao fazer a locação! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
	
	fclose (Clientes);
	fclose (Veiculos);
	fclose (Locacoes);
	
}
