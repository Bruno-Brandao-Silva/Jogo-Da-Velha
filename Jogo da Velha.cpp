#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
int Menu();
void enunciado(), velha(), resultado(int temp), IA(int nivel), bot_impossivel(), rand_jogada();
int jogada(int temp, char jogador), verificador(), bot_facil(bool status), bot_medio(bool status);
char jogo[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int main()
{
	int temp, dificuldade;
	char jogador = 'O';
	do
	{
		system("color 80");
		setlocale(LC_ALL, "Portuguese");
		for(int x = 0; x < 3; x++)
		{
			for(int y = 0; y < 3; y++)
			{
				jogo[x][y] = ' ';
			}
		}
		do
		{
			enunciado();
			temp = Menu();
			system("cls");
		}
		while(temp != 1 && temp != 2 && temp != 3);
		if(temp == 3)
		{
			system("exit");
			return 0;
		}
		else if(temp == 2)
		{
			jogador = 'X';
			do
			{
				temp = verificador();
				if(temp == 0)
				{
					if(jogador == 'O')
					{
						jogador = 'X';
					}
					else if(jogador == 'X')
					{
						jogador = 'O';
					}
					do
					{
						enunciado();
						velha();
						temp = jogada(temp, jogador);
					}
					while(temp == 1);
				}
				enunciado();
				velha();
			}
			while(temp == 0);
			resultado(temp);
		}
		else if(temp == 1)
		{
			jogador = 'X';
			do{
				enunciado();
				printf("		DIFICULDADES: \n			1 - FÁCIL\n			2 - MÉDIO\n			3 - IMPOSSÍVEL\n			0 - VOLTAR\n		ESCOLHA UMA OPÇÃO: ");
				dificuldade = getche() - '0';
			}while(dificuldade != 0 && dificuldade != 1 && dificuldade != 2 && dificuldade !=3);
			if(dificuldade == 0)
			{
				temp = main();
				if(temp==0)
				{
					return 0;
				}
			}
			else if(dificuldade == 1)
			{
				IA(1);
			}
			else if(dificuldade == 2)
			{
				IA(2);
			}
			else if(dificuldade == 3)
			{
				IA(3);
			}
		}
		do
		{
		printf("\n		1-MENU\n		2-SAIR\n	ESCOLHA UMA OPÇÃO: ");
		temp = getche()-'0';	
		}while(temp != 1 && temp != 2);
		if(temp == 2)
		{
			return 0;
		}
	}while(temp == 1);
}
int Menu()
{
	int temp;
	printf("\n		MODOS: \n			1-JOGADOR vs. IA\n			2-JOGADOR vs. JOGADOR\n			3-SAIR\n\n		ESCOLHA UMA OPÇÃO: ");
	temp = getche() - '0';
	return temp;
}
void enunciado()
{
	system("cls");
	printf("\n		---------------------------------------------------------------------------------\n		|				JOGO DA VELHA					|\n		---------------------------------------------------------------------------------\n");
}
void velha()
{
	printf("\n						    X");
	printf("\n						1   2   3\n");
	printf("					      1 %c | %c | %c \n", jogo[0][0], jogo[0][1], jogo[0][2]);
	printf("					       ---+---+---\n");
	printf("					    Y 2 %c | %c | %c \n", jogo[1][0], jogo[1][1], jogo[1][2]);
	printf("					       ---+---+---\n");
	printf("					      3 %c | %c | %c \n", jogo[2][0], jogo[2][1], jogo[2][2]);
}
int jogada(int temp, char jogador)
{
	int i, j;
	if(temp == 1)
	{
		printf("	JOGADA INVÁLIDA");
	}
	printf("\n\n	JOGADOR %c", jogador);
	printf("\n 	 	DIGITE A POSIÇÃO X: ");
	j = getche() - '0';
	printf("\n		DIGITE A POSIÇÃO Y: ");
	i = getche() - '0';
	if(0 < i && i <= 3 && 0 < j && j <= 3 && jogo[i - 1][j - 1] == ' ')
	{
		jogo[i - 1][j - 1] = jogador;
		return 0;
	}
	else
	{
		return 1;
	}
}
int verificador()
{
	int contador = 0;
	bool status = false;
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(jogo[x][y] == ' ')
			{
				contador++;
			}
			else
			{
				if(jogo[0][0] == jogo[1][1] && jogo[0][0] == jogo[2][2])
				{
					status = true;
					if(jogo[0][0] == 'X')
					{
						return 2;
					}
					else if(jogo[0][0] == 'O')
					{
						return 3;
					}
				}
				else if(jogo[0][2] == jogo[1][1] && jogo[0][2] == jogo[2][0])
				{
					status = true;
					if(jogo[0][2] == 'X')
					{
						return 2;
					}
					else if(jogo[0][2] == 'O')
					{
						return 3;
					}
				}
				else if(jogo[x][0] == jogo[x][1] && jogo[x][2] == jogo[x][0])
				{
					status = true;
					if(jogo[x][0] == 'X')
					{
						return 2;
					}
					else if(jogo[x][0] == 'O')
					{
						return 3;
					}
				}
				else if(jogo[0][y] == jogo[1][y] && jogo[0][y] == jogo[2][y])
				{
					status = true;
					if(jogo[0][y] == 'X')
					{
						return 2;
					}
					else if(jogo[0][y] == 'O')
					{
						return 3;
					}
				}
			}
		}
	}
	if(status == false)
	{

		if(contador != 0)
		{
			return 0;
		}
		if(contador == 0)
		{
			return 1;
		}
	}
}
void resultado(int temp)
{
	if(temp == 2)
	{
		printf("	JOGADOR X GANHOU!");
	}
	else if(temp == 3)
	{
		printf("	JOGADOR O GANHOU!");
	}
	else if(temp == 1)
	{
		printf("	EMPATOU!");
	}
}
int bot_facil(bool status)
{
	//Verificar jogadas
	for(int x = 0; x < 3; x++)
	{
		//LINHA DE O
		if(jogo[x][0] == jogo[x][1] && jogo[x][0] == 'O' && jogo[x][2] == ' ')
		{
			jogo[x][2] = 'O';
			return 1;
		}
		else if(jogo[x][0] == jogo[x][2] && jogo[x][0] == 'O' && jogo[x][1] == ' ')
		{
			jogo[x][1] = 'O';
			return 1;
		}
		else if(jogo[x][1] == jogo[x][2] && jogo[x][1] == 'O' && jogo[x][0] == ' ')
		{
			jogo[x][0] = 'O';
			return 1;
		}
		//COLUNA DE O
		else if(jogo[0][x] == jogo[1][x] && jogo[0][x] == 'O' && jogo[2][x] == ' ')
		{
			jogo[2][x] = 'O';
			return 1;
		}
		else if(jogo[0][x] == jogo[2][x] && jogo[0][x] == 'O' && jogo[1][x] == ' ')
		{
			jogo[1][x] = 'O';
			return 1;
		}
		else if(jogo[2][x] == jogo[1][x] && jogo[2][x] == 'O' && jogo[0][x] == ' ')
		{
			jogo[0][x] = 'O';
			return 1;
		}
	}
	//DIAGONAL DE O
		if(jogo[0][0] == jogo[1][1] && jogo[0][0] == 'O' && jogo[2][2] == ' ')
		{
			jogo[2][2] = 'O';
			return 1;
		}
		else if(jogo[0][0] == jogo[2][2] && jogo[0][0] == 'O' && jogo[1][1] == ' ')
		{
			jogo[1][1] = 'O';
			return 1;
		}
		else if(jogo[2][2] == jogo[1][1] && jogo[2][2] == 'O' && jogo[0][0] == ' ')
		{
			jogo[0][0] = 'O';
			return 1;
		}
		//DIAGONAL INVERSA DE O
		else if(jogo[0][2] == jogo[1][1] && jogo[0][2] == 'O' && jogo[2][0] == ' ')
		{
			jogo[2][0] = 'O';
			return 1;
		}
		else if(jogo[2][0] == jogo[0][2] && jogo[0][2] == 'O' && jogo[1][1] == ' ')
		{
			jogo[1][1] = 'O';
			return 1;
		}
		else if(jogo[2][0] == jogo[1][1] && jogo[2][0] == 'O' && jogo[0][2] == ' ')
		{
			jogo[0][2] = 'O';
			return 1;
		}
	for(int x=0; x<3;x++)
	{
		//LINHAS DE X
		if(jogo[x][0] == jogo[x][1] && jogo[x][0] == 'X' && jogo[x][2] == ' ')
		{
			jogo[x][2] = 'O';
			return 1;
		}
		else if(jogo[x][0] == jogo[x][2] && jogo[x][0] == 'X' && jogo[x][1] == ' ')
		{
			jogo[x][1] = 'O';
			return 1;
		}
		else if(jogo[x][1] == jogo[x][2] && jogo[x][1] == 'X' && jogo[x][0] == ' ')
		{
			jogo[x][0] = 'O';
			return 1;
		}
		
		//COLUNAS DE X
		else if(jogo[0][x] == jogo[1][x] && jogo[0][x] == 'X' && jogo[2][x] == ' ')
		{
			jogo[2][x] = 'O';
			return 1;
		}
		else if(jogo[0][x] == jogo[2][x] && jogo[0][x] == 'X' && jogo[1][x] == ' ')
		{
			jogo[1][x] = 'O';
			return 1;
		}
		else if(jogo[2][x] == jogo[1][x] && jogo[2][x] == 'X' && jogo[0][x] == ' ')
		{
			jogo[0][x] = 'O';
			return 1;
		}
	}
	//DIAGONAL DE X
		 if(jogo[0][0] == jogo[1][1] && jogo[0][0] == 'X' && jogo[2][2] == ' ')
		{
			jogo[2][2] = 'O';
			return 1;
		}
		else if(jogo[0][0] == jogo[2][2] && jogo[0][0] == 'X' && jogo[1][1] == ' ')
		{
			jogo[1][1] = 'O';
			return 1;
		}
		else if(jogo[2][2] == jogo[1][1] && jogo[2][2] == 'X' && jogo[0][0] == ' ')
		{
			jogo[0][0] = 'O';
			return 1;
		}
		//DIAGONAL INVERSA DE X
		else if(jogo[0][2] == jogo[1][1] && jogo[0][2] == 'X' && jogo[2][0] == ' ')
		{
			jogo[2][0] = 'O';
			return 1;
		}
		else if(jogo[2][0] == jogo[0][2] && jogo[2][0] == 'X' && jogo[1][1] == ' ')
		{
			jogo[1][1] = 'O';
			return 1;
		}
		else if(jogo[2][0] == jogo[1][1] && jogo[2][0] == 'X' && jogo[0][2] == ' ')
		{
			jogo[0][2] = 'O';
			return 1;
		}
		if(status == true)
		{
			return 0;
		}else{
			rand_jogada();
			return 1;
		}
}
int bot_medio(bool status)
{
	int temp;
	int i;
	int j;
	temp = bot_facil(true);
	if(temp==0)
	{
		if(jogo[0][0] == jogo[2][2] && jogo[0][0] == 'X' && jogo[1][1] == 'O')
		{
			bool status;
			do
			{
				do
				{
				status = false;
				i = rand() % 3;
				j = rand() % 3;
				if(i==0&&j==1)
				{
					status = true;
				}
				if(i==1&&j==0)
				{
					status = true;
				}
				if(i==1&&j==2)
				{
					status = true;
				}
				if(i==2&&j==1)
				{
					status = true;
				}
				}while(status==false);
			}while(jogo[i][j] != ' ');
			jogo[i][j]='O';
			return 1;
		}
		else if(jogo[0][2] == jogo[2][0] && jogo[0][2] == 'X' && jogo[1][1] == 'O')
		{
			bool status;
			do
			{
				do
				{
				status = false;
				i = rand() % 3;
				j = rand() % 3;
				if(i==0&&j==1)
				{
					status = true;
				}
				if(i==1&&j==0)
				{
					status = true;
				}
				if(i==1&&j==2)
				{
					status = true;
				}
				if(i==2&&j==1)
				{
					status = true;
				}
				}while(status==false);
			}while(jogo[i][j] != ' ');
			jogo[i][j]='O';
			return 1;
		}
		else if(jogo[1][1] == ' ')
		{
			jogo[1][1] = 'O';
			return 1;
		}
		if(status == true)
		{
			return 0;
		}
		else
		{
			rand_jogada();
			return 1;
		}
	}
}
void bot_impossivel(){
	int temp;
	int i;
	int j;
	temp = bot_medio(true);
	
	if(temp==0)
	{
		if(jogo[0][1]==jogo[1][0] && jogo[0][1]=='X' && jogo[0][0]== ' ')
		{
			jogo[0][0]='O';
			return;
		}
		else if(jogo[0][1]==jogo[1][2] && jogo[0][1]=='X' && jogo[0][2]== ' ')
		{
			jogo[0][2]='O';
			return;
		}
		else if(jogo[2][1]==jogo[1][0] && jogo[2][1]=='X' && jogo[2][0]== ' ')
		{
			jogo[2][0]='O';
			return;
		}
		else if(jogo[2][1]==jogo[1][2] && jogo[2][1]=='X' && jogo[2][2]== ' ')
		{
			jogo[2][2]='O';
			return;	
		}
		//
		else if(jogo[0][1]==jogo[2][0] && jogo[0][1]=='X' && jogo[0][0]== ' ')
		{
			jogo[0][0]='O';
			return;
		}
		else if(jogo[0][1]==jogo[2][2] && jogo[0][1]=='X' && jogo[0][2]== ' ')
		{
			jogo[0][2]='O';
			return;
		}
		else if(jogo[2][1]==jogo[0][0] && jogo[2][1]=='X' && jogo[2][0]== ' ')
		{
			jogo[2][0]='O';
			return;
		}
		else if(jogo[2][1]==jogo[0][2] && jogo[2][1]=='X' && jogo[2][2]== ' ')
		{
			jogo[2][2]='O';
			return;	
		}
		//
		else if(jogo[1][0]==jogo[0][2] && jogo[1][0]=='X' && jogo[0][0]== ' ')
		{
			jogo[0][0]='O';
			return;
		}
		else if(jogo[1][0]==jogo[2][2] && jogo[1][0]=='X' && jogo[2][0]== ' ')
		{
			jogo[2][0]='O';
			return;
		}
		else if(jogo[1][2]==jogo[0][0] && jogo[1][2]=='X' && jogo[0][2]== ' ')
		{
			jogo[0][2]='O';
			return;
		}
		else if(jogo[1][2]==jogo[2][0] && jogo[1][2]=='X' && jogo[2][2]== ' ')
		{
			jogo[2][2]='O';
			return;	
		}
		//JOGADA NA QUINA DE O
		
		else if(jogo[0][0]== ' ' || jogo[0][2]== ' ' || jogo[2][0]== ' ' || jogo[2][2]== ' ')
		{	bool status;	
			do{
				status = false;
				i = rand()%3;
				j = rand()%3;
				if(jogo[i][j]==' '){
					if(i==0 && j==0)
					{
						status = true;
					}
					if(i==0&&j==2)
					{
						status = true;
					}
					if(i==2&&j==0)
					{
						status = true;
					}
					if(i==2 && j==2)
					{
						status = true;
					}
				}
			}while(status==false);
			if(status==true)
			{
				jogo[i][j] = 'O';
				return;
			}
		}
		else
		{
			rand_jogada();
		}
		
	}
}
void IA(int nivel)
{
	char jogador ='X';
	int temp = 0;
				do
				{
					if(temp == 0)
					{
						do
						{
							enunciado();
							velha();
							temp = jogada(temp, jogador);
						}
						while(temp == 1);
					}
					temp = verificador();
					if(temp == 0)
					{
						enunciado();
						velha();
						if(nivel == 1)
						{
							bot_facil(false);
						}
						else if(nivel == 2)
						{
							bot_medio(false);
						}
						else if(nivel == 3)
						{
							bot_impossivel();
						}
					}
					temp = verificador();
					enunciado();
					velha();
				}
				while(temp == 0);
				resultado(temp);	
}
void rand_jogada()
{
	int i, j;
	do
			{
			i = rand()%3;
			j = rand()%3;
			}while(jogo[i][j]!= ' ');
			jogo[i][j]='O';
			return;	
}
