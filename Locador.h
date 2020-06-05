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

	printf ("Voc� est� no menu de loca��o! Digite o CPF do cliente que deseja locar um ve�culo: ");
	setbuf (stdin, NULL);
	gets (CPF);
	
	while (fread (&Cliente, sizeof (Dados4), 1, Clientes) == 1 && Cliente.Status != 2) {
		
		if (strcmp (CPF, Cliente.CPF) != 0 && !feof (Clientes)) {
			
			printf ("\nCliente n�o cadastrado!\n\nPara o cliente poder alugar um ve�culo realize o cadastro dele.\n\nDeseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		} else if (strcmp (CPF, Cliente.CPF) == 0) {
			
			printf ("\nCliente j� cadastrado! Prossiga com o processo.\n\nOs modelos de ve�culos dispon�veis para a loca��o s�o:\n\n");
			goto Start;
			
		} 
		
	}
	
	fclose (Clientes);
	
	Start: 
	
	Veiculos = fopen ("Veiculos.dat", "rb");
	
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
	
	rewind (Veiculos);
	
	while (fread (&Veiculo, sizeof (Dados_Veiculo4), 1, Veiculos) == 1) {
		
		if (Veiculo.Status == 1 && Veiculo.Status != 2) {
			 	
			Sleep (100);
			printf ("\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco);
		
		}
		
	}
	
	printf ("Digite aqui a placa do ve�culo que o cliente deseja: ");
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
		
		printf ("\nErro. Nenhum ve�culo com esta placa foi encontrado. Tentar mais uma vez? (1 - Sim) (2 - N�o): ");
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
	
	printf ("Quantos dias o cliente ficar� com o ve�culo? ");
	scanf ("%i", &Locacao.Num_Dias);
	printf ("\nDigite a data de loca��o do ve�culo (dd/mm/aa): ");
	scanf ("%i/%i/%i", &Locacao.Dia_I, &Locacao.Mes_I, &Locacao.Ano_I);
	printf ("\nDigite a data de entrega do ve�culo (dd/mm/aa): ");
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
	
	printf ("\nO pre�o total da loca��o � R$%0.2f.\n\nDeseja confirmar loca��o? (1 - Sim) (2 - N�o): ", Calculo);
	scanf ("%i", &Op);
		
	if (Op == 2) {
		
		system ("cls");
		return 2;
		
	} 
	
	while (Op < 1 || Op > 2) {
		
		printf ("\nErro! Digite um c�digo v�lido: ");
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
		printf ("\nVe�culo locado com sucesso! C�digo da loca��o: %i\n\nPara a loca��o aparecer nas listas reinicie o programa.\n\nDeseja realizar outra loca��o? (1 - Sim) (2 - N�o): ", Locacao.Numero_Locacao);
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
		
		printf ("\nErro ao fazer a loca��o! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
	
	fclose (Clientes);
	fclose (Veiculos);
	fclose (Locacoes);
	
}
