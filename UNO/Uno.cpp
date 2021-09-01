#include "Pilha.h"
#include "listase.h"
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

bool Existe ( int valores[] , int tam , int valor ) {
	for ( int i = 0 ; i < tam ; i++) {
		if(valores[i] == valor )
			return true;
	}
	return false;
}

void GerarNumeros (int numeros[], int quantNumeros , int limite ) {
	srand(time(NULL));
	int v;
	for ( int i = 0 ; i < quantNumeros ; i++) {
		v = rand() % limite;
		while (Existe(numeros,i,v)) {
			v = rand() % limite;
		}
		if ( v != 10) {
			numeros[i] = v;
		} else {
			i--;
		}
	}
	for(int i=0; i<25; i++) {
		if(numeros[i] > 10 && numeros[i] < 20) {
			numeros[i] = numeros[i] - 10;
		}
	}
}

void GerarNumerosPretos (int numerosPretos[], int quantNumeros , int limite ) {
	srand(time(NULL));
	int v;
	for ( int i = 0 ; i < quantNumeros ; i++) {
		v = rand() % limite;
		while (Existe(numerosPretos,i,v)) {
			v = rand() % limite;
		}
		if ( v != 10) {
			numerosPretos[i] = v;
		} else {
			i--;
		}
	}
}

int CriarBaralho(tp_pilha *Baralho) {
	setlocale(LC_ALL,"");
	carta c;
	tp_pilha pilhaRed,pilhaBlue,pilhaYellow,pilhaGreen,pilhaBlack;
	inicializa_pilha(&pilhaRed);
	inicializa_pilha(&pilhaBlue);
	inicializa_pilha(&pilhaYellow);
	inicializa_pilha(&pilhaGreen);
	inicializa_pilha(&pilhaBlack);
	inicializa_pilha(Baralho);
	int i,j,aleatorio=0;
	int numeros[25],numerosPretos[8];
	GerarNumerosPretos(numerosPretos , 8 , 8);
	GerarNumeros(numeros , 25 , 26);
	for(j = 0; j < 25; j++) {
		c.numero = numeros[j];
		strcpy(c.cor, "Blue");
		if(numeros[j]>19 && numeros[j]<22) {
			strcpy(c.efeito, "+2");
			push(&pilhaBlue,c);
		} else if(numeros[j]>21 && numeros[j]<24) {
			strcpy(c.efeito, "Block");
			push(&pilhaBlue,c);
		} else if(numeros[j]>23 && numeros[j]<26) {
			strcpy(c.efeito, "Refresh");
			push(&pilhaBlue,c);
		} else {
			strcpy(c.efeito, "Normal");
			push(&pilhaBlue,c);
		}
	}
	for(j = 0; j < 25; j++) {
		c.numero = numeros[j];
		strcpy(c.cor, "Yellow");
		if(numeros[j]>19 && numeros[j]<22) {
			strcpy(c.efeito, "+2");
			push(&pilhaYellow,c);
		} else if(numeros[j]>21 && numeros[j]<24) {
			strcpy(c.efeito, "Block");
			push(&pilhaYellow,c);
		} else if(numeros[j]>23 && numeros[j]<26) {
			strcpy(c.efeito, "Refresh");
			push(&pilhaYellow,c);
		} else {
			strcpy(c.efeito, "Normal");
			push(&pilhaYellow,c);
		}
	}
	for(j = 0; j < 25; j++) {
		c.numero = numeros[j];
		strcpy(c.cor, "Green");
		if(numeros[j]>19 && numeros[j]<22) {
			strcpy(c.efeito, "+2");
			push(&pilhaGreen,c);
		} else if(numeros[j]>21 && numeros[j]<24) {
			strcpy(c.efeito, "Block");
			push(&pilhaGreen,c);
		} else if(numeros[j]>23 && numeros[j]<26) {
			strcpy(c.efeito, "Refresh");
			push(&pilhaGreen,c);
		} else {
			strcpy(c.efeito, "Normal");
			push(&pilhaGreen,c);
		}
	}
	for(j = 0; j < 25; j++) {
		c.numero = numeros[j];
		strcpy(c.cor, "Red");
		if(numeros[j]>19 && numeros[j]<22) {
			strcpy(c.efeito, "+2");
			push(&pilhaRed,c);
		} else if(numeros[j]>21 && numeros[j]<24) {
			strcpy(c.efeito, "Block");
			push(&pilhaRed,c);
		} else if(numeros[j]>23 && numeros[j]<26) {
			strcpy(c.efeito, "Refresh");
			push(&pilhaRed,c);
		} else {
			strcpy(c.efeito, "Normal");
			push(&pilhaRed,c);
		}
	}
	for(j = 0; j < 8; j++) {
		strcpy(c.cor, "Black");
		if(numerosPretos[j] >= 0 && numerosPretos[j] < 4) {
			c.numero = 66;
			strcpy(c.efeito, "+4");
			push(&pilhaBlack,c);
		} else if(numerosPretos[j] >= 4 && numerosPretos[j] < 8) {
			c.numero = 65;
			strcpy(c.efeito, "Mudar Cor");
			push(&pilhaBlack,c);
		}
	}
	//srand(time(NULL));
	for ( i = 0 ; i < 108 ; i++) {
		aleatorio = rand () % 5;
		if(aleatorio == 0) {
			if(!pilha_vazia(&pilhaRed)) {
				pop(&pilhaRed,&c);
				push(Baralho,c);
			} else {
				aleatorio = rand() % 5;
				i--;
			}
		} else if(aleatorio == 1) {
			if(!pilha_vazia(&pilhaBlue)) {
				pop(&pilhaBlue,&c);
				push(Baralho,c);
			} else {
				aleatorio = rand() % 5;
				i--;
			}
		} else if(aleatorio == 2) {
			if(!pilha_vazia(&pilhaYellow)) {
				pop(&pilhaYellow,&c);
				push(Baralho,c);
			} else {
				aleatorio = rand() % 5;
				i--;
			}
		} else if(aleatorio == 3) {
			if(!pilha_vazia(&pilhaGreen)) {
				pop(&pilhaGreen,&c);
				push(Baralho,c);
			} else {
				aleatorio = rand() % 5;
				i--;
			}
		} else if(aleatorio == 4) {
			if(!pilha_vazia(&pilhaBlack)) {
				pop(&pilhaBlack,&c);
				push(Baralho,c);
			} else {
				aleatorio = rand() % 5;
				i--;
			}
		}
	}
}

lista* InserirCartaLista1(tp_pilha *Baralho, lista *aux1) {
	carta c;
	aux1 = inicializa();
	for(int i=0; i<7; i++) {
		pop(Baralho,&c);
		aux1 = insere(aux1,c);
	}
	return aux1;
}

lista* InserirCartaLista2(tp_pilha *Baralho, lista *aux2) {
	carta c;
	aux2 = inicializa();
	for(int i=0; i<7; i++) {
		pop(Baralho,&c);
		aux2 = insere(aux2,c);
	}
	return aux2;
}

void moveXY(int x, int y, char t[10]) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x,y};
	SetConsoleCursorPosition(hStdout, position);
	printf("%s", t);
}
void menu() {
	moveXY(32,1,"::: SEJA BEM VINDO AO UNO TRAVAZAP :::");
	moveXY(33,5,"INICIAR JOGO");
	moveXY(33,10,"EQUIPE");
	moveXY(33,15,"SAIR");
}
int Jogar() {
	char a;
	short posX = 30, posY = 5;
	moveXY(30,5, "->");
	do {
		system("COLOR 5f");
		tp_pilha Baralho, Descart;
		Lista* aux1 = NULL;
		Lista* aux2 = NULL;
		CriarBaralho(&Baralho);
		aux1 = InserirCartaLista1(&Baralho,aux1);
		aux2 = InserirCartaLista2(&Baralho,aux2);
		menu();
		moveXY(posX, posY, "->");
		a = toupper(getch());
		switch(a) {
			case 'H':
				if (posY > 5) {
					moveXY(30,posY, "  "); //verifica se a seta está na ultima opçõa, caso dê seta pra baixo de novo volta pra primeira
					posY-=5;
					moveXY(30,posY, "->");
					_beep(400,100);
				}
				break;

			case 'P':
				if (posY < 15) {
					moveXY(30,posY, "  "); //verifica se a seta está na primeira opção, caso esteje e seja seta pra cima de novo vai direto pra ultima
					posY+=5;
					moveXY(30,posY, "->");
					_beep(500,100);
				}
				break;

			case 13:  //pressionou enter
				if (posY == 5) { //iniciar jogo
					system("cls");
					setlocale(LC_ALL,"");
					carta c,cs,topo;
					inicializa_pilha(&Descart);
					int aleatorio=0,rep=0,opcao=0,jogou=0,round=1,resultado=0,cava=0,block=0,voltar=0,pegar2=0,pegar4=0,mudarcor=0;
					pop(&Baralho,&c);
					push(&Descart,c);
					topo = retornatopo(&Descart);
					aleatorio = rand () % 2;
					do {
						jogou=0;
						if(round == 1) {
							printf("===== Partida Começou =====\n");
							printf("De acordo com o sorteio, Jogador [%d] Começa jogando\n\n",aleatorio+1);
							if(strcmp(topo.cor,"Yellow")==0) {
								printf("----Primeira Carta da Mesa----\n");
								printf(ANSI_COLOR_YELLOW"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
							}
							if(strcmp(topo.cor,"Blue")==0) {
								printf("----Primeira Carta da Mesa----\n");
								printf(ANSI_COLOR_BLUE"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
							}
							if(strcmp(topo.cor,"Red")==0) {
								printf("----Primeira Carta da Mesa----\n");
								printf(ANSI_COLOR_RED"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
							}
							if(strcmp(topo.cor,"Green")==0) {
								printf("----Primeira Carta da Mesa----\n");
								printf(ANSI_COLOR_GREEN"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
							}
							if(strcmp(topo.cor,"Black")==0) {
								printf("----Primeira Carta da Mesa----\n");
								printf(ANSI_COLOR_BLACK"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
							}
							printf("Altura da Pilha Atualizada = [%d]\n\n",altura_pilha(&Baralho));
							if(aleatorio == 0) {
								printf("---- Mão do Jogador 1 ----\n");
								imprime(aux1);
								if (busca(&aux1,topo) == 0) {
									printf("\nVocê possui carta para jogar\n");
									while(jogou == 0) {
										printf("\nSelecione a carta que deseja jogar!\n");
										fflush(stdin);
										printf("Cor: ");
										gets(cs.cor);
										fflush(stdin);
										if(strcmp(cs.cor,"Black") == 0) {
											printf("Número: ");
											scanf("%d",&cs.numero);
											fflush(stdin);
											if(cs.numero == 66) {
												strcpy(cs.efeito, "+4");
											} else if(cs.numero == 65) {
												strcpy(cs.efeito, "Mudar Cor");
											}
										} else {
											printf("Número: ");
											scanf("%d",&cs.numero);
											fflush(stdin);
											if(cs.numero>19 && cs.numero<22) {
												strcpy(cs.efeito, "+2");
											} else if(cs.numero>21 && cs.numero<24) {
												strcpy(cs.efeito, "Block");
											} else if(cs.numero>23 && cs.numero<26) {
												strcpy(cs.efeito, "Refresh");
											} else {
												strcpy(cs.efeito, "Normal");
											}
										}
										resultado = strcmp(topo.cor,cs.cor);
										if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0  && topo.numero == cs.numero || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black")==0 || resultado == 0) {
											if (busca2(&aux1,cs) == 0) {
												system("cls");
												printf("Carta Jogada\n\n");
												printf("Sua mão atualizada\n");
												retira(&aux1,&cs);
												imprime(aux1);
												jogou = 1;
											} else {
												printf("Carta não encontrada na sua mão!\n");
											}
										} else {
											printf("Carta incorreta!\n");
										}
									}
									if(vazia(aux1)) {
										printf("\nO jogador 1 ganhou!\n");
										printf("Digite 0 para voltar ao menu!\n");
										scanf("%d",&opcao);
									} else {
										if(strcmp(cs.efeito, "Mudar Cor") == 0) {
											printf("\nVocê ativou o mudar de cor\n");
											printf("Digite a cor que deseja: ");
											gets(cs.cor);
											fflush(stdin);
											while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
												printf("\nCor Inválida!\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
											}
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"+4") == 0) {
											printf("\nVocê jogou +4 e ativou o mudar de cor\n");
											printf("Digite a cor que deseja: ");
											gets(cs.cor);
											fflush(stdin);
											while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
												printf("\nCor Inválida!\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
											}
											push(&Descart,cs);
										}
										printf("\nSua rodada terminou!\n");
										printf("Digite [1] para passar a vez ou [0] para sair do jogo\n");
										scanf("%d",&opcao);
										aleatorio = 1;
										block=0;
										voltar=0;
										pegar2=0;
										pegar4=0;
										mudarcor=0;
										if(strcmp(cs.efeito,"Block") == 0) {
											block++;
											aleatorio = 0;
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"Refresh") == 0) {
											voltar++;
											aleatorio = 0;
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"+2") == 0) {
											pegar2++;
											for(int i=0; i<2; i++) {
												pop(&Baralho,&c);
												aux2 = insere(aux2,c);
											}
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"+4") == 0) {
											pegar4++;
											for(int i=0; i<4; i++) {
												pop(&Baralho,&c);
												aux2 = insere(aux2,c);
											}
										}
										if(strcmp(cs.efeito,"Normal") == 0) {
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito, "Mudar Cor") == 0) {
											mudarcor++;
										}
									}
									round++;
									system("cls");
								} else {
									printf("\nVocê não tem carta da cor correspondente\n");
									printf("Digite [1] para cavar uma carta ou [Qualquer coisa] para cavar rapidamente\n");
									pop(&Baralho,&c);
									aux1 = insere(aux1,c);
									scanf("%d",&opcao);
									system("cls");
								}
							} else {
								imprime(aux2);
								if (busca(&aux2,topo) == 0) {
									printf("\nVocê possui carta para jogar\n");
									while(jogou == 0) {
										printf("\nSelecione a carta que deseja jogar!\n");
										fflush(stdin);
										printf("Cor: ");
										gets(cs.cor);
										fflush(stdin);
										if(strcmp(cs.cor,"Black") == 0) {
											printf("Número: ");
											scanf("%d",&cs.numero);
											fflush(stdin);
											if(cs.numero == 66) {
												strcpy(cs.efeito, "+4");
											} else if(cs.numero == 65) {
												strcpy(cs.efeito, "Mudar Cor");
											}
										} else {
											printf("Número: ");
											scanf("%d",&cs.numero);
											fflush(stdin);
											if(cs.numero>19 && cs.numero<22) {
												strcpy(cs.efeito, "+2");
											} else if(cs.numero>21 && cs.numero<24) {
												strcpy(cs.efeito, "Block");
											} else if(cs.numero>23 && cs.numero<26) {
												strcpy(cs.efeito, "Refresh");
											} else {
												strcpy(cs.efeito, "Normal");
											}
										}
										resultado = strcmp(topo.cor,cs.cor);
										if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0  && topo.numero == cs.numero || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black")==0 || resultado == 0) {
											if (busca2(&aux2,cs) == 0) {
												system("cls");
												printf("Carta Jogada\n\n");
												printf("Sua mão atualizada\n");
												retira(&aux2,&cs);
												imprime(aux2);
												jogou = 1;
											} else {
												printf("Carta não encontrada na sua mão!\n");
											}
										} else {
											printf("Carta incorreta!\n");
										}
									}
									if(vazia(aux2)) {
										printf("\nO jogador 2 ganhou!\n");
										printf("Digite 0 para voltar ao menu!\n");
										scanf("%d",&opcao);
									} else {
										if(strcmp(cs.efeito, "Mudar Cor") == 0) {
											printf("\nVocê ativou o mudar de cor\n");
											printf("Digite a cor que deseja: ");
											gets(cs.cor);
											fflush(stdin);
											while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
												printf("\nCor Inválida!\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
											}
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"+4") == 0) {
											printf("\nVocê jogou +4 e ativou o mudar de cor\n");
											printf("Digite a cor que deseja: ");
											gets(cs.cor);
											fflush(stdin);
											while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
												printf("\nCor Inválida!\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
											}
											push(&Descart,cs);
										}
										printf("\nSua rodada terminou!\n");
										printf("Digite [1] para passar a vez ou [0] para sair do jogo\n");
										scanf("%d",&opcao);
										aleatorio = 0;
										block=0;
										voltar=0;
										pegar2=0;
										pegar4=0;
										mudarcor=0;
										if(strcmp(cs.efeito,"Block") == 0) {
											block++;
											aleatorio = 1;
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"Refresh") == 0) {
											voltar++;
											aleatorio = 1;
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"+2") == 0) {
											pegar2++;
											for(int i=0; i<2; i++) {
												pop(&Baralho,&c);
												aux1 = insere(aux1,c);
											}
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito,"+4") == 0) {
											pegar4++;
											for(int i=0; i<4; i++) {
												pop(&Baralho,&c);
												aux1 = insere(aux1,c);
											}
										}
										if(strcmp(cs.efeito,"Normal") == 0) {
											push(&Descart,cs);
										}
										if(strcmp(cs.efeito, "Mudar Cor") == 0) {
											mudarcor++;
										}
									}
									round++;
									system("cls");
								} else {
									printf("\nVocê não tem carta da cor correspondente\n");
									printf("Digite [1] para cavar uma carta ou [Qualquer coisa] para cavar rapidamente\n");
									pop(&Baralho,&c);
									aux2 = insere(aux2,c);
									scanf("%d",&opcao);
									system("cls");
								}
							}
						} else {
							do {
								if(pilha_vazia(&Baralho) == 1) {
									printf("O BARALHO ACABOU, JOGO APAGADO MUAHAHAHAHA!");
									opcao = 0;
								} else
									topo = retornatopo(&Descart);
								jogou=0;
								if(block > 0) {
									printf("---- Você bloqueou o Jogador ----\n\n");
								}
								if(voltar > 0) {
									printf("---- Você Resetou seu Round, Jogue Novamente ----\n\n");
								}
								if(pegar2 > 0) {
									printf("---- Você Teve que cavar 2 cartas ----\n\n");
								}
								if(pegar4 > 0) {
									printf("---- Você Teve que cavar 4 cartas ----\n\n");
								}
								if(mudarcor > 0) {
									printf("---- A cor da carta na mesa foi alterada ----\n\n");
								}
								if(strcmp(topo.cor,"Yellow")==0) {
									printf("-------- Carta da Mesa --------\n");
									printf(ANSI_COLOR_YELLOW"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
								}
								if(strcmp(topo.cor,"Blue")==0) {
									printf("-------- Carta da Mesa --------\n");
									printf(ANSI_COLOR_BLUE"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
								}
								if(strcmp(topo.cor,"Red")==0) {
									printf("-------- Carta da Mesa --------\n");
									printf(ANSI_COLOR_RED"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
								}
								if(strcmp(topo.cor,"Green")==0) {
									printf("-------- Carta da Mesa --------\n");
									printf(ANSI_COLOR_GREEN"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
								}
								if(strcmp(topo.cor,"Black")==0) {
									printf("-------- Carta da Mesa --------\n");
									printf(ANSI_COLOR_BLACK"Cor = %s\nNúmero = %d\nEfeito = %s\n\n"ANSI_COLOR_RESET,topo.cor,topo.numero,topo.efeito);
								}
								printf("Altura da Pilha Atualizada = [%d]\n\n",altura_pilha(&Baralho));
								if(aleatorio == 0) {
									if(uno(aux2) == 1) {
										printf("---- O Jogador 2 Gritou UNO ----\n\n");
									}
									printf("---- Mão do Jogador 1 ----\n");
									imprime(aux1);
									if (busca(&aux1,topo) == 0) {
										printf("\nVocê possui carta para jogar\n");
										while(jogou == 0) {
											printf("\nSelecione a carta que deseja jogar!\n");
											fflush(stdin);
											printf("Cor: ");
											gets(cs.cor);
											fflush(stdin);
											if(strcmp(cs.cor,"Black") == 0) {
												printf("Número: ");
												scanf("%d",&cs.numero);
												fflush(stdin);
												if(cs.numero == 66) {
													strcpy(cs.efeito, "+4");
												} else if(cs.numero == 65) {
													strcpy(cs.efeito, "Mudar Cor");
												}
											} else {
												printf("Número: ");
												scanf("%d",&cs.numero);
												fflush(stdin);
												if(cs.numero>19 && cs.numero<22) {
													strcpy(cs.efeito, "+2");
												} else if(cs.numero>21 && cs.numero<24) {
													strcpy(cs.efeito, "Block");
												} else if(cs.numero>23 && cs.numero<26) {
													strcpy(cs.efeito, "Refresh");
												} else {
													strcpy(cs.efeito, "Normal");
												}
											}
											resultado = strcmp(topo.cor,cs.cor);
											if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0  && topo.numero == cs.numero || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black")==0 || resultado == 0) {
												if (busca2(&aux1,cs) == 0) {
													system("cls");
													printf("Carta Jogada\n\n");
													printf("Sua mão atualizada\n");
													retira(&aux1,&cs);
													imprime(aux1);
													jogou = 1;
												} else {
													printf("Carta não encontrada na sua mão!\n");
												}
											} else {
												printf("Carta incorreta!\n");
											}
										}
										if(vazia(aux1)) {
											printf("\nO jogador 1 ganhou!\n");
											printf("Digite 0 para voltar ao menu!\n");
											scanf("%d",&opcao);
										} else {
											if(strcmp(cs.efeito, "Mudar Cor") == 0) {
												printf("\nVocê ativou o mudar de cor\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
												while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
													printf("\nCor Inválida!\n");
													printf("Digite a cor que deseja: ");
													gets(cs.cor);
													fflush(stdin);
												}
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"+4") == 0) {
												printf("\nVocê jogou +4 e ativou o mudar de cor\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
												while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
													printf("\nCor Inválida!\n");
													printf("Digite a cor que deseja: ");
													gets(cs.cor);
													fflush(stdin);
												}
												push(&Descart,cs);
											}
											printf("\nSua rodada terminou!\n");
											printf("Digite [1] para passar a vez ou [0] para sair do jogo\n");
											scanf("%d",&opcao);
											aleatorio = 1;
											block=0;
											voltar=0;
											pegar2=0;
											pegar4=0;
											mudarcor=0;
											if(strcmp(cs.efeito,"Block") == 0) {
												block++;
												aleatorio = 0;
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"Refresh") == 0) {
												voltar++;
												aleatorio = 0;
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"+2") == 0) {
												pegar2++;
												for(int i=0; i<2; i++) {
													pop(&Baralho,&c);
													aux2 = insere(aux2,c);
												}
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"+4") == 0) {
												pegar4++;
												for(int i=0; i<4; i++) {
													pop(&Baralho,&c);
													aux2 = insere(aux2,c);
												}
											}
											if(strcmp(cs.efeito,"Normal") == 0) {
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito, "Mudar Cor") == 0) {
												mudarcor++;
											}
										}
										round++;
										system("cls");
									} else {
										printf("\nVocê não tem carta da cor correspondente\n");
										printf("Digite [1] para cavar uma carta ou [Qualquer coisa] para cavar rapidamente\n");
										pop(&Baralho,&c);
										aux1 = insere(aux1,c);
										scanf("%d",&opcao);
										system("cls");
									}
								} else {
									if(uno(aux1) == 1) {
										printf("---- O Jogador 1 Gritou UNO ----\n\n");
									}
									printf("---- Mão do Jogador 2 ----\n");
									imprime(aux2);
									if (busca(&aux2,topo) == 0) {
										printf("\nVocê possui carta para jogar\n");
										while(jogou == 0) {
											printf("\nSelecione a carta que deseja jogar!\n");
											fflush(stdin);
											printf("Cor: ");
											gets(cs.cor);
											fflush(stdin);
											if(strcmp(cs.cor,"Black") == 0) {
												printf("Número: ");
												scanf("%d",&cs.numero);
												fflush(stdin);
												if(cs.numero == 66) {
													strcpy(cs.efeito, "+4");
												} else if(cs.numero == 65) {
													strcpy(cs.efeito, "Mudar Cor");
												}
											} else {
												printf("Número: ");
												scanf("%d",&cs.numero);
												fflush(stdin);
												if(cs.numero>19 && cs.numero<22) {
													strcpy(cs.efeito, "+2");
												} else if(cs.numero>21 && cs.numero<24) {
													strcpy(cs.efeito, "Block");
												} else if(cs.numero>23 && cs.numero<26) {
													strcpy(cs.efeito, "Refresh");
												} else {
													strcpy(cs.efeito, "Normal");
												}
											}
											resultado = strcmp(topo.cor,cs.cor);
											if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0  && topo.numero == cs.numero || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black")==0 || resultado == 0) {
												if (busca2(&aux2,cs) == 0) {
													system("cls");
													printf("Carta Jogada\n\n");
													printf("Sua mão atualizada\n");
													retira(&aux2,&cs);
													imprime(aux2);
													jogou = 1;
												} else {
													printf("Carta não encontrada na sua mão!\n");
												}
											} else {
												printf("Carta incorreta!\n");
											}
										}
										if(vazia(aux2)) {
											printf("\nO jogador 2 ganhou!\n");
											printf("Digite 0 para voltar ao menu!\n");
											scanf("%d",&opcao);
										} else {
											if(strcmp(cs.efeito, "Mudar Cor") == 0) {
												printf("\nVocê ativou o mudar de cor\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
												while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
													printf("\nCor Inválida!\n");
													printf("Digite a cor que deseja: ");
													gets(cs.cor);
													fflush(stdin);
												}
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"+4") == 0) {
												printf("\nVocê jogou +4 e ativou o mudar de cor\n");
												printf("Digite a cor que deseja: ");
												gets(cs.cor);
												fflush(stdin);
												while(strcmp(cs.cor,"Red") != 0 && strcmp(cs.cor,"Yellow") != 0 && strcmp(cs.cor,"Green") != 0 && strcmp(cs.cor,"Blue") != 0 ) {
													printf("\nCor Inválida!\n");
													printf("Digite a cor que deseja: ");
													gets(cs.cor);
													fflush(stdin);
												}
												push(&Descart,cs);
											}
											printf("\nSua rodada terminou!\n");
											printf("Digite [1] para passar a vez ou [0] para sair do jogo\n");
											scanf("%d",&opcao);
											aleatorio = 0;
											block=0;
											voltar=0;
											pegar2=0;
											pegar4=0;
											mudarcor=0;
											if(strcmp(cs.efeito,"Block") == 0) {
												block++;
												aleatorio = 1;
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"Refresh") == 0) {
												voltar++;
												aleatorio = 1;
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"+2") == 0) {
												pegar2++;
												for(int i=0; i<2; i++) {
													pop(&Baralho,&c);
													aux1 = insere(aux1,c);
												}
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito,"+4") == 0) {
												pegar4++;
												for(int i=0; i<4; i++) {
													pop(&Baralho,&c);
													aux1 = insere(aux1,c);
												}
											}
											if(strcmp(cs.efeito,"Normal") == 0) {
												push(&Descart,cs);
											}
											if(strcmp(cs.efeito, "Mudar Cor") == 0) {
												mudarcor++;
											}
										}
										round++;
										system("cls");
									} else {
										printf("\nVocê não tem carta da cor correspondente\n");
										printf("Digite [1] para cavar uma carta ou [Qualquer coisa] para cavar rapidamente\n");
										pop(&Baralho,&c);
										aux2 = insere(aux2,c);
										scanf("%d",&opcao);
										system("cls");
									}
								}
							} while(opcao != 0);
						}
					} while(opcao != 0);
					system("color 3F");
					moveXY(30,1, ":::::::::Voltando para o menu:::::::::: ");
					Sleep(3000);
					system("cls");
				}

				if (posY == 10) {  //Nome da equipe
					system("cls");
					moveXY(30,1, ":::::::::EQUIPE:::::::::: ");
					moveXY(30,5, ":::::::::Bruno Felipe:::::::::: ");
					moveXY(30,6, ":::::::::Guilherme Abdon:::::::::: ");
					moveXY(30,7, ":::::::::Mateus Almeida:::::::::: ");
					moveXY(30,8, ":::::::::Natheus Patricio:::::::::: ");
					moveXY(30,9, ":::::::::Rogerio Magnavita:::::::::: ");
					Sleep(3000);
					system("cls");
				}
				if (posY == 15) {
					system("cls");
					exit(0);
				}
				break;
		}
	} while(1);
	system("pause");
	return 0;
}
/*void Jogar(tp_pilha *Baralho, tp_pilha *Descart, Lista *aux1, Lista *aux2) {
	setlocale(LC_ALL,"");
	carta c,cs,topo;
	inicializa_pilha(Descart);
	int aleatorio=0,rep=0,opcao=0,jogou=0,round=1,resultado=0,cava=0,block=0,voltar=0,pegar2=0,pegar4=0,mudarcor=0;
	pop(Baralho,&c);
	push(Descart,c);
	topo = retornatopo(Descart);
	aleatorio = 0;
	do {
		jogou=0;
		if(round == 1) {
			printf("===== Partida Começou =====\n");
			printf("De acordo com o sorteio, Jogador [%d] Começa jogando\n\n",aleatorio+1);
			printf("----Primeira Carta da Mesa----\nCor = %s\nNúmero = %d\nEfeito = %s\n\n",topo.cor,topo.numero,topo.efeito);
			printf("Altura da Pilha Atualizada = [%d]\n\n",altura_pilha(Baralho));
			if(aleatorio == 0) {
				printf("---- Mão do Jogador 1 ----\n");
				imprime(aux1);
				if (busca(&aux1,topo) == 0) {
					printf("\nVocê possui carta para jogar\n");
					while(jogou == 0) {
						printf("\nSelecione a carta que deseja jogar!\n");
						fflush(stdin);
						printf("Cor: ");
						gets(cs.cor);
						fflush(stdin);
						if(strcmp(cs.cor,"Black") == 0) {
							printf("Número: ");
							scanf("%d",&cs.numero);
							if(cs.numero == 66) {
								strcpy(c.efeito, "+4");
							} else if(cs.numero == 65) {
								strcpy(c.efeito, "Mudar Cor");
							}
						} else
							printf("Número: ");
						scanf("%d",&cs.numero);
						fflush(stdin);
						if(cs.numero>19 && cs.numero<22) {
							strcpy(cs.efeito, "+2");
						} else if(cs.numero>21 && cs.numero<24) {
							strcpy(cs.efeito, "Block");
						} else if(cs.numero>23 && cs.numero<26) {
							strcpy(cs.efeito, "Refresh");
						} else {
							strcpy(cs.efeito, "Normal");
						}
						resultado = strcmp(topo.cor,cs.cor);
						if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0 && strcmp(topo.efeito,cs.efeito) != 0 || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black") == 0) {
							if (busca(&aux1,cs) == 0) {
								system("cls");
								printf("Carta Jogada\n\n");
								printf("Sua mão atualizada\n");
								retira(&aux1,&cs);
								push(Descart,cs);
								imprime(aux1);
								jogou = 1;
							} else {
								printf("Carta não encontrada na sua mão!\n");
							}
						} else {
							printf("Carta incorreta!\n");
						}
					}
					if(vazia(aux1)) {
						printf("\nVocê ganhou!\n");
						printf("Digite 0 para voltar ao menu!\n");
						scanf("%d",&opcao);
					} else
						printf("\nSua rodade terminou!\n");
					printf("Digite 1 para passar a vez!\n");
					scanf("%d",&opcao);
					aleatorio = 1;
					block=0;
					voltar=0;
					pegar2=0;
					if(strcmp(cs.efeito,"Block") == 0) {
						block++;
						aleatorio = 0;
					}
					if(strcmp(cs.efeito,"Refresh") == 0) {
						voltar++;
						aleatorio = 0;
					}
					if(strcmp(cs.efeito,"+2") == 0) {
						pegar2++;
						for(int i=0; i<2; i++) {
							pop(Baralho,&c);
							aux2 = insere(aux2,c);
						}
					}
					round++;
					system("cls");
				} else {
					printf("\nVocê não tem carta da cor correspondente\n");
					printf("Digite [1] para usar o cava\n");
					pop(Baralho,&c);
					aux1 = insere(aux1,c);
					scanf("%d",&opcao);
				}
			} else {
				printf("---- Mão do Jogador 2 ----\n");
				imprime(aux2);
				if (busca(&aux2,topo) == 0) {
					printf("\nVocê possui carta para jogar\n");
					while(jogou == 0) {
						printf("\nSelecione a carta que deseja jogar!\n");
						fflush(stdin);
						printf("Cor: ");
						gets(cs.cor);
						fflush(stdin);
						if(strcmp(cs.cor,"Black") == 0) {
							printf("Número: ");
							scanf("%d",&cs.numero);
							if(cs.numero == 66) {
								strcpy(c.efeito, "+4");
							} else if(cs.numero == 65) {
								strcpy(c.efeito, "Mudar Cor");
							}
						} else
							printf("Número: ");
						scanf("%d",&cs.numero);
						fflush(stdin);
						if(cs.numero>19 && cs.numero<22) {
							strcpy(cs.efeito, "+2");
						} else if(cs.numero>21 && cs.numero<24) {
							strcpy(cs.efeito, "Block");
						} else if(cs.numero>23 && cs.numero<26) {
							strcpy(cs.efeito, "Refresh");
						} else {
							strcpy(cs.efeito, "Normal");
						}
						resultado = strcmp(topo.cor,cs.cor);
						if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0 && strcmp(topo.efeito,cs.efeito) != 0 || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black") == 0) {
							if (busca(&aux2,cs) == 0) {
								system("cls");
								printf("Carta Jogada\n\n");
								printf("Sua mão atualizada\n");
								retira(&aux2,&cs);
								push(Descart,cs);
								imprime(aux2);
								jogou = 1;
							} else {
								printf("Carta não encontrada na sua mão!\n");
							}
						} else {
							printf("Carta incorreta!\n");
						}
					}
					if(vazia(aux2)) {
						printf("\nVocê ganhou!\n");
						printf("Digite 0 para voltar ao menu!\n");
						scanf("%d",&opcao);
					} else
						printf("\nSua rodade terminou!\n");
					printf("Digite 1 para passar a vez!\n");
					scanf("%d",&opcao);
					aleatorio = 0;
					block=0;
					voltar=0;
					pegar2=0;
					if(strcmp(cs.efeito,"Block") == 0) {
						block++;
						aleatorio = 1;
					}
					if(strcmp(cs.efeito,"Refresh") == 0) {
						voltar++;
						aleatorio = 1;
					}
					if(strcmp(cs.efeito,"+2") == 0) {
						pegar2++;
						for(int i=0; i<2; i++) {
							pop(Baralho,&c);
							aux1 = insere(aux1,c);
						}
					}
					round++;
					system("cls");
				} else {
					printf("\nVocê não tem carta da cor correspondente\n");
					printf("Digite [1] para usar o cava\n");
					pop(Baralho,&c);
					aux2 = insere(aux2,c);
					scanf("%d",&opcao);
					system("cls");
				}
			}
		} else {
			do {
				topo = retornatopo(Descart);
				jogou=0;
				if(block > 0) {
					printf("---- Você bloqueou o Jogador ----\n\n");
				}
				if(voltar > 0) {
					printf("---- Você Resetou seu Round, Jogue Novamente ----\n\n");
				}
				if(pegar2 > 0) {
					printf("---- Você Teve que cavar 2 cartas ----\n\n");
				}
				printf("---- Carta da Mesa ----\nCor = %s\nNúmero = %d\nEfeito = %s\n\n",topo.cor,topo.numero,topo.efeito);
				printf("Altura da Pilha Atualizada = [%d]\n\n",altura_pilha(Baralho));
				if(aleatorio == 0) {
					printf("---- Mão do Jogador 1 ----\n");
					imprime(aux1);
					if (busca(&aux1,topo) == 0) {
						printf("\nVocê possui carta para jogar\n");
						while(jogou == 0) {
							printf("\nSelecione a carta que deseja jogar!\n");
							fflush(stdin);
							printf("Cor: ");
							gets(cs.cor);
							fflush(stdin);
							if(strcmp(cs.cor,"Black") == 0) {
								printf("Número: ");
								scanf("%d",&cs.numero);
								if(cs.numero == 66) {
									strcpy(c.efeito, "+4");
								} else if(cs.numero == 65) {
									strcpy(c.efeito, "Mudar Cor");
								}
							} else
								printf("Número: ");
							scanf("%d",&cs.numero);
							fflush(stdin);
							if(cs.numero>19 && cs.numero<22) {
								strcpy(cs.efeito, "+2");
							} else if(cs.numero>21 && cs.numero<24) {
								strcpy(cs.efeito, "Block");
							} else if(cs.numero>23 && cs.numero<26) {
								strcpy(cs.efeito, "Refresh");
							} else {
								strcpy(cs.efeito, "Normal");
							}
							resultado = strcmp(topo.cor,cs.cor);
							if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0 && strcmp(topo.efeito,cs.efeito) != 0 || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black") == 0) {
								if (busca(&aux1,cs) == 0) {
									system("cls");
									printf("Carta Jogada\n\n");
									printf("Sua mão atualizada\n");
									retira(&aux1,&cs);
									push(Descart,cs);
									imprime(aux1);
									jogou = 1;
								} else {
									printf("Carta não encontrada na sua mão!\n");
								}
							} else {
								printf("Carta incorreta!\n");
							}
						}
						if(vazia(aux1)) {
							printf("\nVocê ganhou!\n");
							printf("Digite 0 para voltar ao menu!\n");
							scanf("%d",&opcao);
						} else
							printf("\nSua rodade terminou!\n");
						printf("Digite 1 para passar a vez!\n");
						scanf("%d",&opcao);
						aleatorio = 1;
						block=0;
						voltar=0;
						pegar2=0;
						if(strcmp(cs.efeito,"Block") == 0) {
							block++;
							aleatorio = 0;
						}
						if(strcmp(cs.efeito,"Refresh") == 0) {
							voltar++;
							aleatorio = 0;
						}
						if(strcmp(cs.efeito,"+2") == 0) {
							pegar2++;
							for(int i=0; i<2; i++) {
								pop(Baralho,&c);
								aux2 = insere(aux2,c);
							}
						}
						system("cls");
					} else {
						printf("\nVocê não tem carta da cor correspondente\n");
						printf("Digite [1] para usar o cava\n");
						pop(Baralho,&c);
						aux1 = insere(aux1,c);
						scanf("%d",&opcao);
						system("cls");
					}
				} else {
					printf("---- Mão do Jogador 2 ----\n");
					imprime(aux2);
					if (busca(&aux2,topo) == 0) {
						printf("\nVocê possui carta para jogar\n");
						while(jogou == 0) {
							printf("\nSelecione a carta que deseja jogar!\n");
							fflush(stdin);
							printf("Cor: ");
							gets(cs.cor);
							fflush(stdin);
							if(strcmp(cs.cor,"Black") == 0) {
								printf("Número: ");
								scanf("%d",&cs.numero);
								if(cs.numero == 66) {
									strcpy(c.efeito, "+4");
								} else if(cs.numero == 65) {
									strcpy(c.efeito, "Mudar Cor");
								}
							} else
								printf("Número: ");
							scanf("%d",&cs.numero);
							fflush(stdin);
							if(cs.numero>19 && cs.numero<22) {
								strcpy(cs.efeito, "+2");
							} else if(cs.numero>21 && cs.numero<24) {
								strcpy(cs.efeito, "Block");
							} else if(cs.numero>23 && cs.numero<26) {
								strcpy(cs.efeito, "Refresh");
							} else {
								strcpy(cs.efeito, "Normal");
							}
							resultado = strcmp(topo.cor,cs.cor);
							if(resultado == 0 && strcmp(topo.efeito,cs.efeito) == 0 || resultado == 0 && strcmp(topo.efeito,cs.efeito) != 0 || topo.numero == cs.numero || strcmp(topo.efeito,cs.efeito) == 0 && strcmp(cs.efeito,"Normal")!=0 || strcmp(cs.cor,"Black") == 0) {
								if (busca(&aux2,cs) == 0) {
									system("cls");
									printf("Carta Jogada\n\n");
									printf("Sua mão atualizada\n");
									retira(&aux2,&cs);
									push(Descart,cs);
									imprime(aux2);
									jogou = 1;
								} else {
									printf("Carta não encontrada na sua mão!\n");
								}
							} else {
								printf("Carta incorreta!\n");
							}
						}
						if(vazia(aux2)) {
							printf("\nVocê ganhou!\n");
							printf("Digite 0 para voltar ao menu!\n");
							scanf("%d",&opcao);
						} else
							printf("\nSua rodade terminou!\n");
						printf("Digite 1 para passar a vez!\n");
						scanf("%d",&opcao);
						aleatorio = 0;
						block=0;
						voltar=0;
						pegar2=0;
						if(strcmp(cs.efeito,"Block") == 0) {
							block++;
							aleatorio = 1;
						}
						if(strcmp(cs.efeito,"Refresh") == 0) {
							voltar++;
							aleatorio = 1;
						}
						if(strcmp(cs.efeito,"+2") == 0) {
							pegar2++;
							for(int i=0; i<2; i++) {
								pop(Baralho,&c);
								aux1 = insere(aux1,c);
							}
						}
						system("cls");
					} else {
						printf("\nVocê não tem carta da cor correspondente\n");
						printf("Digite [1] para usar o cava\n");
						pop(Baralho,&c);
						aux2 = insere(aux2,c);
						scanf("%d",&opcao);
						system("cls");
					}
				}
			} while(opcao != 0);
		}
	} while(opcao != 0);
}*/



int main () {
	Jogar();
	return 0;
}

