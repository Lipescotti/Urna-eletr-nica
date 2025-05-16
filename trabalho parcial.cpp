#include <stdio.h>
#include <locale.h>
#include<stdlib.h>



/*Dupla:
1) Fellipe Cavalcante Scotti
2) Ryan Augusto Matos Santos

Curso de engenharia de software
2º período noturno 
Código da turma: ENGS241N01
*/


main ()
{
	setlocale(LC_ALL, "Portuguese");
	
	int eleitores, jaVotaram, escolha, totalDeVotos, numeroDoCandidato[4], senha, senhaADM, anoBissexto;
	int controleDeRepeticao = 0, primeiro = -1, votosPrimeiro = -1, p = -1, segundo =-1, s = -1, votosSegundo = -1, ganhador = -1, idadeAno = 0, idadeMes = 0, votos[4];
	int votoAntesDeConfirmar = -1, anoAtual, anoCandidato[4], mesAtual, mesCandidato[4], diaAtual, diaCandidato[4]; // inicializa com um valor invalido!
	char candidato1[20], candidato2[20] ,candidato3[20], candidato4[20], confirmacao, proximo;
	bool numeroPermitido = 0;
	bool turno = 1; // declar se vai ter um segundo turno//
	
	//   AREA DO ADMINISTRADOR   //
	printf("|||          ÁREA DO ADMINISTRADOR          |||\n");
	
	printf("Cria uma senha para o Adm (numerica): ");
	scanf("%d", &senhaADM);	
	
	do
	{
		printf("Ano atual (valor minimo de 1996): ");
		scanf("%d", &anoAtual);
		if(anoAtual < 1996)
		{
			printf("ANO INVALIDO\n");
		}
	}while(anoAtual < 1996);
	
	do
	{
		printf("Mês atual: ");
		scanf("%d", &mesAtual);
		
		if(mesAtual<1 || mesAtual>12)
		{
			printf("MÊS INVALIDO\n");	
		}	
	}while(mesAtual<1 || mesAtual>12);
	
	do
	{
		anoBissexto = anoAtual % 4;
		if(anoBissexto == 0)
		{
			printf("///   Ano bissexto   ///\n");
		}
		printf("Dia atual: ");
		scanf("%d", &diaAtual);
		if(diaAtual < 1 || (diaAtual > 31 && (mesAtual == 1 || mesAtual == 3 || mesAtual == 5 || mesAtual == 7 || mesAtual == 8 || mesAtual == 10 || mesAtual == 12)) || (diaAtual > 30 && (mesAtual == 4 || mesAtual == 6 || mesAtual == 9 || mesAtual == 11)) || (diaAtual > 29 && mesAtual == 2 && (anoAtual%4 == 0)) || (diaAtual > 28 && mesAtual == 2 && (anoAtual%4 != 0)))
		{
			printf("\nDIA INVALIDO\n");	
		}
	}while (diaAtual < 1 || (diaAtual > 31 && (mesAtual == 1 || mesAtual == 3 || mesAtual == 5 || mesAtual == 7 || mesAtual == 8 || mesAtual == 10 || mesAtual == 12)) || (diaAtual > 30 && (mesAtual == 4 || mesAtual == 6 || mesAtual == 9 || mesAtual == 11)) || (diaAtual > 29 && mesAtual == 2 && (anoAtual%4 == 0)) || (diaAtual > 28 && mesAtual == 2 && (anoAtual%4 != 0)));

	
	do
	{
		printf("Quantidade de eleitores na cidade: "); 
		scanf("%d", &eleitores);
		if (eleitores <= 0)
		{
			printf("Quantidade invalida\n");
		}
	}while (eleitores <= 0);
	jaVotaram = eleitores;
	
	do
	{
		system("cls");
		
		if(controleDeRepeticao == 0)
		{
		printf("Nome do 1º candidato: ");
		scanf(" %[^\n]c", &candidato1);
		}
		
		else if(controleDeRepeticao == 1)
		{
		printf("Nome do 2º candidato: ");
		scanf(" %[^\n]c", &candidato2);
		}
		
		else if(controleDeRepeticao == 2)
		{
		printf("Nome do 3º candidato: ");
		scanf(" %[^\n]c", &candidato3);
		}
		
		else if(controleDeRepeticao == 3)
		{
		printf("Nome do 4º candidato: ");
		scanf(" %[^\n]c", &candidato4);
		}
		
		do
		{
			numeroPermitido = 1;
			printf("Número do candidato: ");
			scanf("%d", &numeroDoCandidato[controleDeRepeticao]);
			if(numeroDoCandidato[controleDeRepeticao] <= 0)
			{
				printf("\nnumero invalido\n");
				numeroPermitido = 0;
			}
			else
			{
				if(controleDeRepeticao > 0)
				{
					for (int abcd = 0; abcd < controleDeRepeticao; abcd++)
					{
						if(numeroDoCandidato[controleDeRepeticao] == numeroDoCandidato[abcd])
						{
							printf("\nnumero invalido\n");
							numeroPermitido = 0;
						}
					}
				}
				else
					{
						numeroPermitido = 1;
						
					
					}
			}
		}while(numeroPermitido == 0);
		
		printf("\n///  DATA ATUAL: %d/%d/%d  ///\n\n", diaAtual, mesAtual, anoAtual);
		do
		{
			printf("Ano de nascimento do candidato: ");
			scanf("%d", &anoCandidato[controleDeRepeticao]);
			
			idadeAno = anoAtual - anoCandidato[controleDeRepeticao];
			if(idadeAno < 21)
			{
				printf("Ano invalido\n");
			}
		}while(idadeAno < 21);
		
		do
		{
			printf("Mes de nascimento do candidato: ");
			scanf("%d", &mesCandidato[controleDeRepeticao]);
			
			idadeMes = mesAtual - mesCandidato[controleDeRepeticao];
			if((mesCandidato[controleDeRepeticao] < 1 || mesCandidato[controleDeRepeticao] > 12) && ((idadeAno == 21 && idadeMes < 0) || (idadeAno < 21))) 
			{
				printf("Mês invalido\n");
			}
		}while((mesCandidato[controleDeRepeticao] < 1 || mesCandidato[controleDeRepeticao] > 12) && ((idadeAno == 21 && idadeMes < 0) || (idadeAno < 21))) ;
		
		do
		{
			anoBissexto = anoCandidato[controleDeRepeticao] % 4;
			if(anoBissexto == 0)
			{
				printf("///   Ano bissexto   ///\n");
			}
			printf("Dia de nascimento do candidato: ");
			scanf("%d", &diaCandidato[controleDeRepeticao]);

			
			if(diaCandidato[controleDeRepeticao] < 1 &&( (diaCandidato[controleDeRepeticao] > 30  && (mesCandidato[controleDeRepeticao] == 4 || mesCandidato[controleDeRepeticao] == 6 || mesCandidato[controleDeRepeticao] == 9 || mesCandidato[controleDeRepeticao] == 11)) || (diaCandidato[controleDeRepeticao] > 31  && (mesCandidato[controleDeRepeticao] == 1 || mesCandidato[controleDeRepeticao] == 3 || mesCandidato[controleDeRepeticao] == 5 || mesCandidato[controleDeRepeticao] == 7 || mesCandidato[controleDeRepeticao] == 8 || mesCandidato[controleDeRepeticao] == 10 || mesCandidato[controleDeRepeticao] == 12)) || (diaCandidato[controleDeRepeticao] > 28  && mesCandidato[controleDeRepeticao] == 2 && (anoCandidato[controleDeRepeticao]%4 == 0)) || (diaCandidato[controleDeRepeticao] > 28  && mesCandidato[controleDeRepeticao] == 2 && (anoBissexto == 0)) || (diaCandidato[controleDeRepeticao] > 29  && mesCandidato[controleDeRepeticao] == 2 && anoBissexto != 0)) )
			{
				printf("Mês invalido\n");	
			}
		}while(diaCandidato[controleDeRepeticao] < 1 &&( (diaCandidato[controleDeRepeticao] > 30  && (mesCandidato[controleDeRepeticao] == 4 || mesCandidato[controleDeRepeticao] == 6 || mesCandidato[controleDeRepeticao] == 9 || mesCandidato[controleDeRepeticao] == 11)) || (diaCandidato[controleDeRepeticao] > 31  && (mesCandidato[controleDeRepeticao] == 1 || mesCandidato[controleDeRepeticao] == 3 || mesCandidato[controleDeRepeticao] == 5 || mesCandidato[controleDeRepeticao] == 7 || mesCandidato[controleDeRepeticao] == 8 || mesCandidato[controleDeRepeticao] == 10 || mesCandidato[controleDeRepeticao] == 12)) || (diaCandidato[controleDeRepeticao] > 28  && mesCandidato[controleDeRepeticao] == 2 && (anoCandidato[controleDeRepeticao]%4 == 0)) || (diaCandidato[controleDeRepeticao] > 28  && mesCandidato[controleDeRepeticao] == 2 && (anoBissexto == 0)) || (diaCandidato[controleDeRepeticao] > 29  && mesCandidato[controleDeRepeticao] == 2 && anoBissexto != 0)) );

		
		controleDeRepeticao++;
	}while(controleDeRepeticao < 4);
	


	
	// FIM DA AREA DO ADMINISTRADOR  //
	
		system("cls");
		printf("Primeiro turno das eleições\n");
		do
		{
			confirmacao = 'N';
			do
			{
			printf("Digite o número do candidato: ");
			scanf("%d", &escolha);
			
			votoAntesDeConfirmar = -1;
            for (int i = 0; i < 4; i++) {
                if (escolha == numeroDoCandidato[i]) {
                    printf("Candidato: %s\n", (i == 0) ? candidato1 : (i == 1) ? candidato2 : (i == 2) ? candidato3 : candidato4);
                    votoAntesDeConfirmar = i;
                    break;
                }
            }
            if (votoAntesDeConfirmar == -1) {
                printf("BRANCO / NULO\n");
            }
            printf("\nDeseja confirmar o seu voto (S/N)? ");
            scanf(" %c", &confirmacao);
        } while (confirmacao != 'N' && confirmacao != 'n' && confirmacao != 's' && confirmacao != 'S');

        if (votoAntesDeConfirmar != -1) {
            votos[votoAntesDeConfirmar]++;
            printf("FFFFFFF  IIIII   M     M\n");
    		printf("F          I     MM   MM\n");
 	 		printf("FFFFFFF    I     M M M M\n");
 		    printf("F          I     M  M  M\n");
		    printf("F        IIIII   M     M\n");
        }
		
		senha = senhaADM + 58;
		
		do
		{
			printf("Senha do ADM: ");
			scanf("%d", &senha);
			
			if(senha != senhaADM)
			{
				printf("SENHA INCORRETA\nTENTE NOVAMENTE\n");
			}
		}while(senha != senhaADM);
		
		if(jaVotaram > 1)
		{
        	printf("ADMINISTRADOR: Próximo eleitor (S|N)? ");
        	scanf(" %c", &proximo);
		}
		else
		{
			proximo = 's';
		}
	jaVotaram--;
		}while(jaVotaram > 1 && proximo == 's' || proximo == 'S');
	
	
	system("cls");
	// defininir o ganhador//
	for (int v = 0; v < 4; v++)
	{
		if(votosPrimeiro < votos[v])
		{
			primeiro = numeroDoCandidato[v];
			votosPrimeiro = votos[v];
		}
		if(votosSegundo < votos[v] && votosPrimeiro >= votosSegundo && segundo != primeiro)
		{
			segundo = numeroDoCandidato[v];
			votosSegundo = votos[v];
		}
	}
	
	//definir se terá segundo turno//
	totalDeVotos = votos[0] + votos[1] + votos[2] + votos[3];
	if ((votosPrimeiro/totalDeVotos) <= 0.5 && eleitores >= 200000)
	{
		turno = 0;
	}
	
	// ganhador / segundo turno //
	
	if (turno)
	{
		for (int g = 0; g < 4; g++) 
		{
                if (primeiro == numeroDoCandidato[g]) 
				{
                	ganhador = g;  
                }
		}
		switch (ganhador)
		{
			case 0:
				printf("O candidato %s ganhou", candidato1);
			break;
		
			case 1:
				printf("O candidato %s ganhou", candidato2);
			break;
		
			case 2:
				printf("O candidato %s ganhou", candidato3);
			break;
		
			case 3:
				printf("O candidato %s ganhou", candidato4);
			break;
			
			default:
				printf("Não houve votação");
		}
	}
			// SEGUNDO TURNO // 
	else
	{
		for (int c = 0; c < 4; c++)
		{
				votos[c] = 0;
		}
			jaVotaram = eleitores;

			system("cls");
		printf("Segundo turno das eleições\n");
		do
		{
			confirmacao = 'N';
			do
			{
			printf("Digite o número do candidato: ");
			scanf("%d", &escolha);
			
			votoAntesDeConfirmar = -1;
            for (int i = 0; i < 4; i++)
			{
                if (escolha == primeiro)
				{
                    printf("Candidato: %s\n", (i == 0) ? candidato1 : (i == 1) ? candidato2 : (i == 2) ? candidato3 : candidato4);
                    votoAntesDeConfirmar = i;
                    break;
            	}
				else if (escolha == segundo) {
                    printf("Candidato: %s\n", (i == 0) ? candidato1 : (i == 1) ? candidato2 : (i == 2) ? candidato3 : candidato4);
                    votoAntesDeConfirmar = i;
                    break;
                }
            }
            if (votoAntesDeConfirmar == -1) {
                printf("BRANCO / NULO\n");
            }
            printf("\nDeseja confirmar o seu voto (S/N)? ");
            scanf(" %c", &confirmacao);
        } while (confirmacao != 'N' && confirmacao != 'n' && confirmacao != 's' && confirmacao != 'S');

        if (votoAntesDeConfirmar != -1) {
            votos[votoAntesDeConfirmar]++;
            printf("VOTO CONFIRMADO\n");
        }
		
		senha = senhaADM + 58;
		
		do
		{
			printf("Senha do ADM: ");
			scanf("%d", &senha);
			
			if(senha != senhaADM)
			{
				printf("SENHA INCORRETA\nTENTE NOVAMENTE\n");
			}
		}while(senha != senhaADM);
		if(jaVotaram > 1)
		{
        	printf("ADMINISTRADOR: Próximo eleitor (S|N)? ");
        	scanf(" %c", &proximo);
		}
		else
		{
			proximo = 's';
		}
		jaVotaram--;
		}while(jaVotaram > 1 && proximo == 's' || proximo == 'S');
		
		for (int colocacao = 0; colocacao < 4; colocacao++) 
			{
                if (primeiro == numeroDoCandidato[colocacao]) 
				{
                	p = colocacao;  
                }
                else if (primeiro == numeroDoCandidato[colocacao]) 
				{
                	s = colocacao;  
                }
		}
		if (votos[p] > votos [s])
		{
		
			switch (p)
			{
				case 0:
					printf("O candidato %s ganhou", candidato1);
				break;
		
				case 1:
					printf("O candidato %s ganhou", candidato2);
				break;
		
				case 2:
					printf("O candidato %s ganhou", candidato3);
				break;
		
				case 3:
					printf("O candidato %s ganhou", candidato4);
				break;
			
				default:
					printf("Não houve votação");
			}
		}
		else if (votos[p] < votos [s])
		{
			switch (s)
			{
				case 0:
					printf("O candidato %s ganhou", candidato1);
				break;
		
				case 1:
					printf("O candidato %s ganhou", candidato2);
				break;
		
				case 2:
					printf("O candidato %s ganhou", candidato3);
				break;
		
				case 3:
					printf("O candidato %s ganhou", candidato4);
				break;
			
				default:
					printf("Não houve votação");
			}
		}
		else if (votos[p] == votos [s])
		{
			if (anoCandidato[p] < anoCandidato[s])
			{
				switch (p)
				{
					case 0:
						printf("O candidato %s ganhou", candidato1);
					break;
		
					case 1:
						printf("O candidato %s ganhou", candidato2);
					break;
		
					case 2:
						printf("O candidato %s ganhou", candidato3);
					break;
		
					case 3:
						printf("O candidato %s ganhou", candidato4);
					break;
			
					default:
						printf("Não houve votação");
				}	
			}
			else if (anoCandidato[p] > anoCandidato[s])
			{
				switch (s)
				{
					case 0:
						printf("O candidato %s ganhou", candidato1);
					break;
		
					case 1:
						printf("O candidato %s ganhou", candidato2);
					break;
		
					case 2:
						printf("O candidato %s ganhou", candidato3);
					break;
		
					case 3:
						printf("O candidato %s ganhou", candidato4);
					break;
			
					default:
						printf("Não houve votação");
				}	
			}
			else if (anoCandidato[p] == anoCandidato[s])
			{
				if (mesCandidato[p] < mesCandidato[s])
				{
					switch (p)
					{
						case 0:
							printf("O candidato %s ganhou", candidato1);
						break;
			
						case 1:
							printf("O candidato %s ganhou", candidato2);
						break;
		
						case 2:
							printf("O candidato %s ganhou", candidato3);
						break;
		
						case 3:
							printf("O candidato %s ganhou", candidato4);
						break;
			
							default:
							printf("Não houve votação");
					}
				}
				else if (mesCandidato[p] > mesCandidato[s])
				{
					switch (s)
					{
						case 0:
							printf("O candidato %s ganhou", candidato1);
						break;
			
						case 1:
							printf("O candidato %s ganhou", candidato2);
						break;
		
						case 2:
							printf("O candidato %s ganhou", candidato3);
						break;
		
						case 3:
							printf("O candidato %s ganhou", candidato4);
						break;
			
							default:
							printf("Não houve votação");
					}
				}
				else if (mesCandidato[p] == mesCandidato[s])
			{
				if (diaCandidato[p] < diaCandidato[s])
				{
					switch (p)
					{
						case 0:
							printf("O candidato %s ganhou", candidato1);
						break;
			
						case 1:
							printf("O candidato %s ganhou", candidato2);
						break;
		
						case 2:
							printf("O candidato %s ganhou", candidato3);
						break;
		
						case 3:
							printf("O candidato %s ganhou", candidato4);
						break;
			
							default:
							printf("Não houve votação");
					}
				}
				else if (diaCandidato[p] > diaCandidato[s])
				{
					switch (s)
					{
						case 0:
							printf("O candidato %s ganhou", candidato1);
						break;
			
						case 1:
							printf("O candidato %s ganhou", candidato2);
						break;
		
						case 2:
							printf("O candidato %s ganhou", candidato3);
						break;
		
						case 3:
							printf("O candidato %s ganhou", candidato4);
						break;
			
							default:
							printf("Não houve votação");
					}
				}
				else if (diaCandidato[p] == diaCandidato[s])
				{
					printf("EMPATE CAUSADO POR GEMEOS UNIVITELINOS");
				}
			}	
			}
		}
	}		
}
