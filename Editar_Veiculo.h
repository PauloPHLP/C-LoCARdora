#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados_Veiculo7 Dados_Veiculo7;

struct Dados_Veiculo7 {

	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Cor[50];
	int Ano, Marchas, Portas, Assentos, Status, Codigo;
	float Preco;
	
};

int Editar_Veiculo () {
	
	FILE *Veiculos;
	Dados_Veiculo7 Veiculo;
	char Nome[50], Carroceria[50], Cambio[50], Marca[50], Placa[20], Placa_CPY[20], Cor[50], *STR;
	int Op, Resultado, OK = 0, Cont = 0, Posicao = 0, Ano, Marchas, Portas, Assentos;
	float Preco;

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
	
	printf ("Voc� est� no menu de edi��o de cadastro de ve�culo!\n\nPara continuar digite a placa do ve�culo: ");
	fflush (stdin);
	gets (Placa);
	
	while (!feof (Veiculos)) {

	if (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1 && Veiculo.Status != 2) {
		
		if (strcmp (strupr (Placa), strupr (Veiculo.Placa)) == 0) {
			
			system ("cls");
			Sleep (50);
			printf ("Dados do ve�culo:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
			OK = 1;
			break;
			
		}
		
	}
	
	} 
	
	if (OK == 0) {
		
		printf ("\nErro! Ve�culo n�o encontrado! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
	
	printf ("O que voc� deseja modificar?\n\n1 - Tudo\n2 - Nome\n3 - Marca\n4 - Placa\n5 - Carroceria\n6 - Ano de lan�amento\n7 - Cor\n8 - C�mbio\n9 - N�mero de marchas\n10 - N�mero de portas\n11 - N�mero de assentos\n12 - Pre�o da di�ria\n\nOp��o: ");
	scanf ("%i", &Op);
	
	switch (Op) {
		
		case 1:
			
			system ("cls");
			
			printf ("Voc� optou por alterar tudo. Digite os novos dados: ");
			printf ("\n\nNome: ");
			fflush (stdin);
			gets (Nome);
			printf ("Marca: ");
			fflush (stdin);
			gets (Marca);
			printf ("Placa: ");
			fflush (stdin);
			gets (Placa_CPY);
			printf ("Carroceria: ");
			fflush (stdin);
			gets (Carroceria);
			printf ("Ano de lan�amento: ");
			scanf ("%i", &Ano);
			fflush (stdin);
			printf ("Cor: ");
			fflush (stdin);
			gets (Cor);
			printf ("C�mbio: ");
			fflush (stdin); 
			gets (Cambio);
			printf ("N�mero de marchas: ");
			scanf ("%i", &Marchas);
			printf ("N�mero de portas: ");
			scanf ("%i", &Portas);
			printf ("N�mero de assentos: ");
			scanf ("%i", &Assentos);
			printf ("Pre�o da di�ria: R$");
			scanf ("%f", &Preco);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
					
					system ("cls");
					Sleep (50);
					printf ("Novos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Nome, Marca, Placa_CPY, Carroceria, Ano, Cor, Cambio, Marchas, Portas, Assentos, Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				strcpy (Veiculo.Nome, Nome);
				strcpy (Veiculo.Marca, Marca);
				strcpy (Veiculo.Placa, Placa_CPY);
				strcpy (Veiculo.Carroceria, Carroceria);
				Veiculo.Ano = Ano;
				strcpy (Veiculo.Cor, Cor);
				strcpy (Veiculo.Cambio, Cambio);
				Veiculo.Marchas = Marchas;
				Veiculo.Portas = Portas;
				Veiculo.Assentos = Assentos;
				Veiculo.Preco = Preco;
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
		
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		case 2:
			
			system ("cls");
			
			printf ("Voc� optou por alterar o nome. Digite o novo nome: ");
			fflush (stdin);
			gets (Nome);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					strcpy (Veiculo.Nome, Nome);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
		
		break;
		
		case 3:
			
			system ("cls");
			
			printf ("Voc� optou por alterar a marca. Digite a nova marca: ");
			fflush (stdin);
			gets (Marca);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					strcpy (Veiculo.Marca, Marca);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		case 4:
			
			system ("cls");
			
			printf ("Voc� optou por alterar a placa. Digite a nova placa: ");
			fflush (stdin);
			gets (Placa_CPY);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					strcpy (Veiculo.Placa, Placa_CPY);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		case 5:
			
			system ("cls");
			
			printf ("Voc� optou por alterar a carroceria. Digite a nova carroceria: ");
			fflush (stdin);
			gets (Carroceria);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					strcpy (Veiculo.Carroceria, Carroceria);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		case 6:
			
			system ("cls");
			
			printf ("Voc� optou por alterar o ano de lan�amento. Digite o novo ano: ");
			fflush (stdin);
			scanf ("%i", &Ano);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					Veiculo.Ano = Ano;
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
		
		break;
		
		case 7:
			
			system ("cls");
			
			printf ("Voc� optou por alterar a cor. Digite a nova cor: ");
			fflush (stdin);
			gets (Cor);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					strcpy (Veiculo.Cor, Cor);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
		
		break;
		
		case 8:
			
			system ("cls");
			
			printf ("Voc� optou por alterar o tipo de c�mbio. Digite o novo tipo de c�mbio: ");
			fflush (stdin);
			gets (Cambio);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					strcpy (Veiculo.Cambio, Cambio);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		case 9:
			
			system ("cls");
			
			printf ("Voc� optou por alterar o n�mero de marchas. Digite o novo n�mero de marchas: ");
			fflush (stdin);
			scanf ("%i", &Marchas);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					Veiculo.Marchas = Marchas;
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
		
		break;
		
		case 10:
			
			system ("cls");
			
			printf ("Voc� optou por alterar o n�mero de portas. Digite o novo n�mero de portas: ");
			fflush (stdin);
			scanf ("%i", &Portas);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					Veiculo.Portas = Portas;
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		case 11:
		
			system ("cls");
			
			printf ("Voc� optou por alterar o n�mero de assentos. Digite o novo n�mero de assentos: ");
			fflush (stdin);
			scanf ("%i", &Assentos);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					Veiculo.Assentos = Assentos;
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
		
		break;
		
		case 12:
			
			system ("cls");
			
			printf ("Voc� optou por alterar o pre�o da di�ria. Digite o novo pre�o da di�ria: R$");
			fflush (stdin);
			scanf ("%f", &Preco);
			
			rewind (Veiculos);
	
			while (fread (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos) == 1) {
		
				if (strcmp (Veiculo.Placa, Placa) == 0) {
			 	
					Veiculo.Preco = Preco;
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nMarca: %s\nPlaca: %s\nCarroceria: %s\nAno de lan�amento: %i\nCor: %s\nC�mbio: %s\nN�mero de marchas: %i\nN�mero de portas: %i\nN�mero de assentos: %i\nPre�o da di�ria: %0.2f\nStatus: %i\n\n", Veiculo.Nome, Veiculo.Marca, Veiculo.Placa, Veiculo.Carroceria, Veiculo.Ano, Veiculo.Cor, Veiculo.Cambio, Veiculo.Marchas, Veiculo.Portas, Veiculo.Assentos, Veiculo.Preco, Veiculo.Status);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a altera��o? (1 - Sim) (2 - N�o): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Veiculos, sizeof (Dados_Veiculo7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Veiculo, sizeof (Dados_Veiculo7), 1, Veiculos);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nVe�culo atualizado com sucesso!\n\nDeseja alterar o cadastro de outro ve�culo? (1 - Sim) (2 - N�o): ");
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
		
				printf ("\nErro ao atualizar cadastro do ve�culo! Deseja tentar novamente? (1 - Sim) (2 - N�o): ");
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
			
		break;
		
		default:
			
			while (Op < 1 || Op > 7) {
			
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
	
	fclose (Veiculos);
	
}
