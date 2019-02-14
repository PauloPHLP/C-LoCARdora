#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct Dados7 Dados7;

struct Dados7 {

	char Nome[50], Endereco[100], CPF[20], RG[20], CNH[20];
	int Idade, Status;
	
};

int Editar_Cliente () {
	
	FILE *Clientes;
	Dados7 Cliente;
	char Nome[50], Endereco[100], CPF[20], CPF_CPY[20], RG[20], CNH[20], *STR;
	int Op, Resultado, OK = 0, Idade, Cont = 0, Posicao = 0;

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	Inicio:

	Clientes = fopen ("Clientes.dat", "rb+");
	
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
	
	printf ("Você está no menu de edição de cadastro de cliente!\n\nPara continuar digite o número do CPF do cliente: ");
	fflush (stdin);
	gets (CPF);
	
	while (!feof (Clientes)) {

	if (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1 && Cliente.Status != 2) {
		
		if (strcmp (strupr (CPF), strupr (Cliente.CPF)) == 0) {
			
			system ("cls");
			Sleep (50);
			printf ("Dados do cliente:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
			OK = 1;
			break;
			
		}
		
	}
	
	} 
	
	if (OK == 0) {
		
		printf ("\nErro! Cliente não encontrado! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
	
	printf ("O que você deseja modificar?\n\n1 - Tudo\n2 - Nome\n3 - Idade\n4 - Número do RG\n5 - Número do CPF\n6 - Número da CNH\n7 - Endereço\n\nOpção: ");
	scanf ("%i", &Op);
	
	switch (Op) {
		
		case 1:
			
			system ("cls");
			
			printf ("Você optou por alterar tudo. Digite os novos dados: ");
			fflush (stdin);
			printf ("\n\nNome: ");
			fflush (stdin);
			gets (Nome);
			printf ("Idade: ");
			fflush (stdin);
			scanf ("%i", &Idade);
			printf ("Número do RG: ");
			fflush (stdin);
			gets (RG);
			printf ("Número do CPF: ");
			fflush (stdin);
			gets (CPF_CPY);
			printf ("Número da CNH: ");
			fflush (stdin);
			gets (CNH);
			printf ("Endereço: ");
			fflush (stdin);
			gets (Endereco);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {

					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Nome, Idade, RG, CPF_CPY, CNH, Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				strcpy (Cliente.Nome, Nome);
				Cliente.Idade = Idade;
				strcpy (Cliente.RG, RG);
				strcpy (Cliente.CPF, CPF_CPY);
				strcpy (Cliente.CNH, CNH);
				strcpy (Cliente.Endereco, Endereco);
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
		
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
		break;
		
		case 2:
			
			system ("cls");
			
			printf ("Você optou por alterar o nome. Digite o novo nome: ");
			fflush (stdin);
			gets (Nome);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {
			 	
					strcpy (Cliente.Nome, Nome);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
		
		break;
		
		case 3:
			
			system ("cls");
			
			printf ("Você optou por alterar a idade. Digite a nova idade: ");
			scanf ("%i", &Idade);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {
			 	
					Cliente.Idade = Idade;
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
		break;
		
		case 4:
			
			system ("cls");
			
			printf ("Você optou por alterar o número do RG. Digite o novo número do RG: ");
			fflush (stdin);
			gets (RG);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {
			 	
					strcpy (Cliente.RG, RG);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
		break;
		
		case 5:
			
			system ("cls");
			
			printf ("Você optou por alterar o CPF. Digite o novo número do CPF: ");
			fflush (stdin);
			gets (CPF_CPY);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {
			 	
					strcpy (Cliente.CPF, CPF_CPY);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
		break;
		
		case 6:
			
			system ("cls");
			
			printf ("Você optou por alterar o número da CNH. Digite o novo número da CNH: ");
			fflush (stdin);
			gets (CNH);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {
			 	
					strcpy (Cliente.CNH, CNH);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
		
		break;
		
		case 7:
			
			system ("cls");
			
			printf ("Você optou por alterar o endereço. Digite o novo endereço: ");
			fflush (stdin);
			gets (Endereco);
			
			rewind (Clientes);
	
			while (fread (&Cliente, sizeof (Dados7), 1, Clientes) == 1) {
		
				if (strcmp (Cliente.CPF, CPF) == 0) {
			 	
					strcpy (Cliente.Endereco, Endereco);
					Sleep (50);
					printf ("\nNovos dados:\n\nNome: %s\nIdade: %i\nNúmero do RG: %s\nNúmero do CPF: %s\nNúmero da CNH: %s\nEndereço: %s\n\n", Cliente.Nome, Cliente.Idade, Cliente.RG, Cliente.CPF, Cliente.CNH, Cliente.Endereco);
					Posicao = Cont;
					break;
			
				}

			Cont++;

			}
			
			printf ("Deseja confirmar a alteração? (1 - Sim) (2 - Não): ");
			scanf ("%i", &Op);
		
			if (Op == 1) {
				
				fseek (Clientes, sizeof (Dados7) * Posicao, SEEK_SET);
				Resultado =	fwrite (&Cliente, sizeof (Dados7), 1, Clientes);	
				
			}
		
			if (Op == 2) {
		
				system ("pause");
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
			
			if (Resultado == 1) {
		
			Sleep (500);
			printf ("\nCliente atualizado com sucesso!\n\nDeseja alterar o cadastro de outro cliente? (1 - Sim) (2 - Não): ");
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
		
				printf ("\nErro ao atualizar cadastro do cliente! Deseja tentar novamente? (1 - Sim) (2 - Não): ");
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
			
		break;
		
		default:
			
			while (Op < 1 || Op > 7) {
			
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
	
}
