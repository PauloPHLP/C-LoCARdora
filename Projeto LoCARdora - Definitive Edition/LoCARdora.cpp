#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include "Cad_Clientes.h"
#include "Listar_Clientes.h"
#include "Pesquisador_Clientes.h"
#include "Editar_Cliente.h"
#include "Delete_Cliente.h"
#include "Cad_Veiculos.h"
#include "Listar_Veiculos.h"
#include "Pesquisador_Veiculos.h"
#include "Editar_Veiculo.h"
#include "Delete_Veiculo.h"
#include "Locador.h"
#include "Listar_Alugueis.h"
#include "Devolucao.h"

void Menu () {

	int Numero, Op, Opcao;
	
	system ("color f1");//Branco e azul marinho
	Sleep(100);
	printf("*******************************************************************************\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*         *    **   *****         *         ****                              *\n");
	Sleep(100);
	printf("*         *   *  * *     *       * *       *    *                             *\n");
	Sleep(100);
	printf("*         *   *  * *            *   *      *     *                            *\n");
	Sleep(100);
	printf("*         ***  **  *           *     *     *    *                             *\n");
	Sleep(100);
	printf("*                  *          *********    *****    ***   **   **     *       *\n");
	Sleep(100);
	printf("*                  *         *         *   *    *   *  * *  * *  *   * *      *\n");
	Sleep(100);
	printf("*                  *     *  *           *  *     *  *  * *  * ***   *****     *\n");
	Sleep(100);
	printf("*                   *****  *             * *      * ***   **  *  * *     *    *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*******************************************************************************\n");

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);

	printf ("Bem-vindo ao aplicativo LoCARdora!\n\n");
	system ("date/t");
	printf ("\nPor favor, digite o número da opção desejada:\n\n");

	printf ("1 - Cliente\n2 - Veículos\n3 - Locação\n4 - Sair\n\nOpção: ");
	scanf ("%i", &Opcao);

	if (Opcao == 1) {
		
		Inicio1:
			
		system ("cls");

	Sleep(100);
	printf("*******************************************************************************\n");
	Sleep(100);
	printf("*     *****      *         *    *******   *          *   **********  *******  *\n");
	Sleep(100);
	printf("*    *      *    *         *    *         *  *       *        *      *        *\n");
	Sleep(100);
	printf("*    *           *         *    ****      *    *     *        *      ****     *\n");
	Sleep(100);
	printf("*    *           *         *    *         *      *   *        *      *        *\n");
	Sleep(100);
	printf("*    *      *    *         *    *         *        * *        *      *        *\n");
	Sleep(100);
	printf("*      *****     *******   *    ********  *          *        *      ******** *\n");
	Sleep(100);
	printf("*******************************************************************************\n");
	
		Sleep (50);
		printf ("1 -> Adicionar novo cliente\n");
		Sleep (50);
		printf ("2 -> Lista de clientes\n");
		Sleep (50);
		printf ("3 -> Pesquisar por cliente\n");
		Sleep (50);
		printf ("4 -> Editar cadastro de cliente\n");
		Sleep (50);
		printf ("5 -> Excluir cadastro de cliente\n");
		Sleep (50);
		printf ("6 -> Voltar\n\n");
		printf ("Opção: ");
		scanf ("%i", &Op);
		
		switch (Op) {
		
			case 1:
			
				system ("cls");
			
				Op = Cad_Clientes();
				
				if (Op == 2) {
				
					system ("cls");
					goto Inicio1;
				
				}
			
			break;	
		
			case 2:
			
				system ("cls");
			
				Op = Listar_Clientes();
			
				if (Op == 2) {
				
					goto Inicio1;
				
				} 
		
			case 3:
			
				system ("cls");
			
				Op = Pesquisador_Clientes();
			
				if (Op == 2) {
				
					goto Inicio1;
				
				}
			
			break;
		
			case 4:
			
				system ("cls");
		
				Op = Editar_Cliente();
		
				if (Op == 2) {
			
					goto Inicio1;
					
				}
			
			break;
		
			case 5:
			
				system ("cls");
				
				Op = Delete_Cliente();
			
				if (Op == 2) {
				
					goto Inicio1;
				
				}
			
			break;
		
			case 6:
			
				system ("cls");
			
				Menu();
			
			break;
		
			default:

			while (Op < 1 || Op > 6) {
			
				printf ("\nErro! Código inválido. Deseja tentar mais uma vez? (1 - Sim) (2 - Não): ");
				scanf ("%i", &Op);
			
				if (Op == 1) {
			
					system ("cls");
					goto Inicio1;
			
				} else if (Op == 2) {
			
					system ("cls");
					Menu();
			
				}
			
			}
				
		}
		
	}
	
	if (Opcao == 2) {
		
		Inicio2:
		
		system ("cls");
		
		Sleep(100);
	printf("*******************************************************************************\n");
	Sleep(100);
	printf("*   *     *   *******  *    ****    *       *   *         ****      ***       *\n");
	Sleep(100);  
	printf("*   *     *   *        *  *      *  *       *   *       **    **   *   *      *\n");
	Sleep(100);
	printf("*   *     *   ****     *  *         *       *   *      *        *   *         *\n");
	Sleep(100);
	printf("*    *   *    *        *  *         *       *   *      *        *     *       *\n");
	Sleep(100);
	printf("*     * *     *        *  *      *   *     *    *       **    **   *   *      *\n");
	Sleep(100);
	printf("*      *      *******  *    ****       ***      *****     ****      ***       *\n");
	Sleep(100);
	printf("*******************************************************************************\n");
	
		Sleep (50);
		printf ("1 -> Adicionar novo veículo à frota\n");
		Sleep (50);
		printf ("2 -> Lista de veículos\n");
		Sleep (50);
		printf ("3 -> Pesquisar por veículo\n");
		Sleep (50);
		printf ("4 -> Editar cadastro de veículo\n");
		Sleep (50);
		printf ("5 -> Excluir veículo da frota\n");
		Sleep (50);
		printf ("6 -> Voltar\n\n");
		printf ("Opção: ");
		scanf ("%i", &Op);
		
		switch (Op) {
			
			case 1:
		
			system ("cls");
			
			Op = Cad_Veiculos();
		
			if (Op == 2) {
			
				goto Inicio2;
			
			}
		
			break;
			
		case 2:
		
			system ("cls");
			
			Op = Listar_Veiculos();
		
			if (Op == 2) {
			
				goto Inicio2;
			
			}
		
		break;
			
		case 3:
		
			system ("cls");
			
			Op = Pesquisador_Veiculos();
			
			if (Op == 2) {
				
				goto Inicio2;
				
			}
		
		break;
		
		case 4:
			
			system ("cls");
			
			Op = Editar_Veiculo();
			
			if (Op == 2) {
				
				goto Inicio2;
				
			}
			
		break;
		
		case 5:
			
			system ("cls");
			
			Op = Delete_Veiculo();
			
			if (Op == 2) {
				
				goto Inicio2;
				
			}
			
		break;
		
		case 6:
			
			system ("cls");
			
			Menu();
			
		break;
			
		default:	
		
			while (Op < 1 || Op > 6) {
			
				printf ("\nErro! Código inválido. Deseja tentar mais uma vez? (1 - Sim) (2 - Não): ");
				scanf ("%i", &Op);
			
				if (Op == 1) {
			
					system ("cls");
					goto Inicio2;
			
				} else if (Op == 2) {
			
					system ("cls");
					Menu();
			
				}
			
			}
			
		}
		
	}
	
	if (Opcao == 3) {
		
		Inicio3:
		
		system ("cls");
		
		Sleep(100);
		
	printf("*******************************************************************************\n");
	Sleep(100);
	printf("*   *       ****        ****        ***        ****        ~       ****       *\n");
	Sleep(100);  
	printf("*   *     **    **    *      *     *   *      *     *     **     **    **     *\n");
	Sleep(100);
	printf("*   *    *        *   *           *     *     *          *  *   *        *    *\n");
	Sleep(100);
	printf("*   *    *        *   *          *********    *     *   *    *  *        *    *\n");
	Sleep(100);
	printf("*   *     **    **    *      *  *         *     ****   ********  **    **     *\n");
	Sleep(100);
	printf("*   *****   ****        ****    *         *      *     *      *    ****       *\n");
	Sleep(100);
	printf("*******************************************************************************\n");
	
		Sleep (50);
		printf ("1 -> Locar um veículo\n");
		Sleep (50);
		printf ("2 -> Mostrar dados de locação\n");
		Sleep (50);
		printf ("3 -> Devolver um veículo\n");
		Sleep (50);
		printf ("4 -> Voltar\n\n");
		printf ("Opção: ");
		scanf ("%i", &Op);
		
		switch (Op) {
			
			case 1:
		
			system ("cls");
			
			Op = Locador();
			
			if (Op == 2) {
				
				goto Inicio3;
				
			}
		
		break;
		
		case 2:
		
			system ("cls");
			
			Op = Listar_Alugueis();
			
			if (Op == 2) {
				
				goto Inicio3;
				
			}
			
			
		break;
		
		case 3:
			
			system ("cls");
			
			Op = Devolucao();
			
			if (Op == 2) {
				
				goto Inicio3;
				
			}
			
		break;
		
		case 4:
			
			system ("cls");
			
			Menu();
			
		break;
			
		default:	
		
			while (Op < 1 || Op > 6) {
			
				printf ("\nErro! Código inválido. Deseja tentar mais uma vez? (1 - Sim) (2 - Não): ");
				scanf ("%i", &Op);
			
				if (Op == 1) {
			
					system ("cls");
					goto Inicio2;
			
				} else if (Op == 2) {
			
					system ("cls");
					Menu();
			
				}
			
			}
			
			
		}
		
		
	}
	
	if (Opcao == 4) {
		
		Inicio4:
		
		Sleep(100);
		
	printf ("\n");
	printf("*******************************************************************************\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*     ***   *     ***   *   ***       *    ***    ***     ***   ***  ***      *\n");
	Sleep(100); 
	printf("*    *   *  ***   *  *  *  *   *     * *   *   * *   *    *  * *   * *  *     *\n");
	Sleep(100);
	printf("*    *   *  * *   * *   *  *    **  *****  *   * *   *    ***  *   * * *      *\n");
	Sleep(100);
	printf("*     ***   ***   *  *  *   **** * *     * ****   ***     *     ***  *  *     *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*         *    *  *****  *  *     *  ****    **    ***        ***             *\n");
	Sleep(100);
	printf("*         *    *    *    *  *     *    *    *  *   *  *      *   *            *\n");
	Sleep(100);
	printf("*         *    *    *    *  *     *   *    ******  * *       *   *            *\n");
	Sleep(100);
	printf("*           **      *    *  ****  *  ****  *    *  *  *       ***             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*           **   ***  *    *   ****   **   *****  *  *    *   ***             *\n");
	Sleep(100);
	printf("*          *  *  *  * *    *  *      *  *    *    *  *    *  *   *            *\n");
	Sleep(100);
	printf("*         ****** ***  *    *  *     ******   *    *   *  *   *   *            *\n");
	Sleep(100); 
	printf("*         *    * *    **** *   **** *    *   *    *    **     ***             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100); 
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*        *    **   *****         *         ****                               *\n");
	Sleep(100);
	printf("*        *   *  * *     *       * *       *    *                              *\n");
	Sleep(100);
	printf("*        *   *  * *            *   *      *     *                             *\n");
	Sleep(100);
	printf("*        ***  **  *           *     *     *    *                              *\n");
	Sleep(100);
	printf("*                 *          *********    *****    ***   **   **     *        *\n");
	Sleep(100);
	printf("*                 *         *         *   *    *   *  * *  * *  *   * *       *\n");
	Sleep(100);
	printf("*                 *     *  *           *  *     *  *  * *  * ***   *****      *\n");
	Sleep(100);
	printf("*                  *****  *             * *      * ***   **  *  * *     *     *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*                                                                             *\n");
	Sleep(100);
	printf("*******************************************************************************\n");
	
		system ("pause");
		exit (1);
		
	}
	
	while (Opcao < 1 || Opcao > 3) {
		
		printf("\nErro! Opção inexistente. Digite uma opção válida: ");
		scanf ("%i", &Opcao);
		
		if (Opcao == 1) {
			
			goto Inicio1;
			
		} else if (Opcao == 2) {
			
			goto Inicio2;
			
		} else if (Opcao == 3) {
			
			goto Inicio3;
			
		} else if (Opcao == 4) {
			
			goto Inicio4;
			
		}
		
	}
			
}

int main() {
	
	system ("title LoCARdora");
	system ("cls");

	setlocale (LC_ALL, "PORTUGUESE");
	SetConsoleOutputCP (28591);
	SetConsoleCP (28591);
	
	Menu();
	
	system ("pause");
	return 0;
	
}
