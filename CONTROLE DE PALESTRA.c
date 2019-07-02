#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> //delarações para todas as funções na API do Windows, 
#include<time.h>
#include<stdbool.h>

//função para mostrar o painel nas telas

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


int cont_base,x,ticket;
char ra[200][70],nome[200][70],email[200][70],curso[200][70];
float data[200][100],datar,cpf[200][70];


int zerari,zerarj,linha,coluna,j,i;
bool cad[17][10],pdccad[1][10],convcad[2][10];

int zeraripcd,zerarjpcd,linhapcd,colunapcd;
bool pcdcad[1][10];

int zerariconv,zerarjconv,linhaconv,colunaconv;
bool convcad[2][10];

//sorteio

int contsorteio[100];
int numsorte;

int validap, validapcd, validac;
	validap=0;
	validapcd=0;
	validac=0;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void painelc()
{

			printf("\t\t\t\t\t\t ____________________________________________________________\n");
			printf("\t\t\t\t\t\t|                                                            |\n");
			printf("\t\t\t\t\t\t|------------------ SISTEMA DE CADASTOS ---------------------|\n");
			printf("\t\t\t\t\t\t|____________________________________________________________|\n\n\n\n\n\n\n");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void painelcert()
{

			printf("\t\t\t\t\t\t ____________________________________________________________\n");
			printf("\t\t\t\t\t\t|                                                            |\n");
			printf("\t\t\t\t\t\t|------------------ CONFIRMACAO DE ENVIO --------------------|\n");
			printf("\t\t\t\t\t\t|____________________________________________________________|\n\n\n\n\n\n\n");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void painels()
{

			printf("\t\t\t\t\t\t ____________________________________________________________\n");
			printf("\t\t\t\t\t\t|                                                            |\n");
			printf("\t\t\t\t\t\t|----------------- SORTEIO DE BRINDES -----------------------|\n");
			printf("\t\t\t\t\t\t|____________________________________________________________|\n\n\n\n\n\n\n");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void painelcer()
{

			printf("\t\t\t\t\t\t ____________________________________________________________\n");
			printf("\t\t\t\t\t\t|                                                            |\n");
			printf("\t\t\t\t\t\t|----------------- CERTIFICADO DA PALESTRA-------------------|\n");
			printf("\t\t\t\t\t\t|____________________________________________________________|\n\n\n\n\n\n\n");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void planta()
{
	printf("\n\n");
			printf("\t\t\t\t.__________________________________________________________________________________________.\n");
			printf("\t\t\t\t|..........................................................................................|\n");
			printf("\t\t\t\t|..........................................Palco...........................................|\n");
			printf("\t\t\t\t|__________________________________________________________________________________________|\n\n\n");
	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------


void paineli()
{

			printf("\t\t\t\t\t\t==============================================================\n");
			printf("\t\t\t\t\t\t================= Noite de Palestas - UNIP====================\n");
			printf("\t\t\t\t\t\t==============================================================\n\n\n\n\n\n\n");
	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void novocadastro()
{
	int escolha;
	system("cls");
	paineli();
	printf("\n\n\n\n\n\nDeseja um novo cadastro\n0- Sim\n9- Voltar ao menu\n");

	scanf("%i",&escolha);
		
		switch(escolha)
		{	
			case 0:
				sistema_cadastro();
			case 9:
				menu();
				system("cls");
			default:		//caso seja digitado uma função que nao existe o default faz a tratativa do erro
				printf("Voce digitou uma opcao invalida, tente novamente!!!\n");
				system("pause\n");
				menu();
				break;					
		}
	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu()
{		

	// função onde vai mostrar o menu do programa

	system("cls");		// limpa todos os dados que aparecem na tela do programa, deixando em branco
	
	int escolha;		// declarando variaveis do tipo inteiro
	
	paineli(); 			// chamando função do void painel para apresentar o painel em cima da tela
	
	printf("1- CADASTRO\n2- VISUALIZAR CERTIFICADO\n3- ENVIAR CERTIFICCADO POR E-MAIL\n4- SORTEIO DE BRINDES\n5- VISUALIZAR LUGARES\n6- SAIR\n\n");  //exibindo na tela os itens do menu e no scanf esta lendo a opção digitada
	scanf("%i",&escolha);
					//quando escolhe switch o menu fica interativo, pois de acordo com a leitura da opção digitada ele vai executar algum comando
		switch(escolha)
		{

			case 1:
			system("cls");		//limpando a tela
			painelc();
			printf("\n\n\n\nAbrindo Cadastro...\n0- Seguir P/ Cadastro\n9- Voltar ao menu\n");
			scanf("%i",&escolha);
		
				switch(escolha)
				{			//outro switch, pois no printf acima ele mostra duas opções
				case 0:
				sistema_cadastro();
				case 9:
				menu();
				system("cls");
		
			default:		//caso seja digitado uma função que nao existe o default faz a tratativa do erro
				printf("Voce digitou uma opcao invalida, tente novamente!!!\n");
				system("pause\n");
				menu();
				break;			
				
		}
	break;

	case 2:

		certificado(); 		//chama a função void sistema_cadastro
		break;				//break faz com que o sistema interrompa o switch

	case 3:
		system("cls");
		painelcert();
		printf("\n\n\n\n\n\n\n\n");
		printf("Enviando Todos os Certificados Por E-mail, aguarde...\n\n\n\n");
		
		   Sleep(5000);
				
			

				printf("\t***FINALIZADO***\n");		
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				system("pause");
		menu();
		break;
	case 4:

		sis_sorteio();
		break;
	case 5:

		lugaresconv();
		break;
	case 6:

		exit(0);
		system("exit");

	default:		//caso seja digitado uma função que nao existe o default faz a tratativa do erro

		printf("Voce digitou uma opcao invalida, tente novamente!!!\n");
		system("pause\n");
		menu();
		break;	
}
	
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void sistema_cadastro()
{
	system("cls"); 
	int assento;

	 							// informei que o 'x' que é do tipo inteiro recebe um valor de 200 - que seria a quantidade de assento disponivel

	if(cont_base!=x)
	{
			for(assento=cont_base;assento<=105;assento++)
			{							//utilizado o for, e colocando a condição que assento vale 1 e enquanto ele for menor ou igual a 200 o looping do for continua rodando
	
				x--; 						//x seria nosso contador e é o valor que aparece no printf abaixo mostrando a quantidade de assento vago
				cadastro();
				system("cls");
				cont_base=assento+1;
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				// system pause faz uma pausa no programa e aguarda a interação com o usuario
				system("cls");
				novocadastro();
			}
	}
	
	else
	{
		printf("Nao temos mais assentos disponiveis!\n\t\tMuito Obrigado.\n\n\n\n\n\n\n\n\n");
		system("pause");
		
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void cadastro()
{
int f;


system("cls");
SYSTEMTIME hora;		//variave que faz com que o programa identifique a hora do sistema
GetLocalTime(&hora);

	for(i=0;i<1;i++)
	{
		painelc();
		ticket=(((cont_base-1)+2018)*9);
		definir_lugar();
		printf("\nHora Cadastro: %d:%d %d/%d/%d\n\n",hora.wHour,hora.wMinute,hora.wDay,hora.wMonth,hora.wYear);
		printf("RA: ");
		scanf(" %s",&ra[cont_base-1][0]);
		printf("Nome: ");
		scanf(" %70[^\n]s ",&nome[cont_base-1][0]);			//quando utiliza "  %70[^\n]s", o espaço inicial desconsidera qualquer tipo de espaço ou quabra de linha digitado no scanf acima, %70 identifico que esse scanf pode pegar ate 70 char [^\n] ignora qualquer espaço ou quebra de linha digitado nesse scanf, exe: ao digitar Joao da Silva, ele vai reconhecer os 3 nomes e sem isso ele reconhece apenas joao
		printf("CPF: ");
		scanf(" %s",&cpf[cont_base-1][0]);
		printf("E-mail: ");
		scanf(" %70[^\n]s",&email[cont_base-1][0]);
		printf("Curso: ");
		scanf(" %70[^\n]s\n",&curso[cont_base-1][0]);
		Sleep(405);
		printf("\n\n\n\n\n\n\n\n\n\nUsuario Cadastrado!\n");
		Sleep(705);
system("cls");	
 
//abaixo a função apenas mostra os valores digitados na tela anteriormente, para poder verificar as informações
}
			painelc();
			
			printf("\nHora Cadastro: %d:%d %d/%d/%d\n\n",hora.wHour,hora.wMinute,hora.wDay,hora.wMonth,hora.wYear); 		//funções para retornar hora, minuto, dia, mes e ano do sistema, trazendo informações da API		
			printf("\nTickeT: %i",ticket);
			printf("\nNome do Participante: %s",nome[cont_base-1]);
			printf("\nRA: %s",ra[cont_base-1]);
			printf("\nCPF: %s",cpf[cont_base-1]);
			printf("\nE-mail: %s",email[cont_base-1]);
			printf("\nCurso: %s\n\n\n",curso[cont_base-1]);

			
			system("pause");
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void sis_sorteio()
{
	system("cls");
 	int sorteio,qtdnum,escolha,verificaa,verificab;
    

     	painels();
				
     // o if abaixo impede que voce faça um sorteio sem que tenha nenhuma pessoa cadastrada na palestra
if(numsorte==1)
{
	printf("\n\n\n\tNao temos numeros para sorteio\n\n\n\n\n\n\n\n\n");
	system("pause");
	menu();
}
else
{     
 	 printf("Os numeros sorteados foram:\n\n");
     srand(time(NULL));
   
   	
           /* gerando valores aleatórios entre zero e quantidade de pessoas */
			verificaa=1;
			verificab=1;
			
			while(verificaa==verificab && verificab==0 && verificaa==0)
			{
			verificaa=rand() % numsorte;
			verificab=rand() % numsorte;
							
				
			}
			
        	printf("|%d| |%d| 	",verificaa,verificab);
    	 
    }
    
    
    printf("\n\n\n\n\n\n\nDigite os numeros sorteados abaixo:\n");
     
	 
	 	for (sorteio= 1;sorteio<3; sorteio++)
     	{
           // abaixo os sitema vai pedir para o usuario digitar o numero que apareceu acima, e ele mostra na tela o ticket do ganhador, podendo consultar na tela de visualizar certificado

			printf("|\t: ");
			scanf("%i",&qtdnum);
			printf("\t");
			printf("%i\n",contsorteio[qtdnum]);
    	 }
    
    	 
    	 
		printf("\n\n\n\n\nDeseja um novo Sorteio?\n0- Sim\n9- Voltar ao menu\n");
		
		scanf("%i",&escolha);
		
		switch(escolha)
		{			//outro switch, pois no printf acima ele mostra duas opções
			case 0:
				sis_sorteio();
			case 9:
				menu();
				system("cls");
			default:		//caso seja digitado uma função que nao existe o default faz a tratativa do erro
				printf("Voce digitou uma opcao invalida, tente novamente!!!\n");
				system("pause\n");
				menu();
				break;	
		}
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void inicio_prog()
{	
//função abaixo e a tela de carregamento no inicio do projeto


	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
	system("pause");
	int ii,jj;
	

	for (ii = 0; ii < 3; ii++) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      		printf("\t\t\t\t\t\t\t\t\t\tCARREGANDO \n\n");
        	printf("\t\t\t\t\t\t\t");
      		for (jj = 0; jj < 50; jj++) {
            printf("|");
            Sleep(25);
        }
        printf("\r");
        for (jj = 0; jj < 120; jj++) {
            printf(" "); // apaga a linha anterior
            Sleep(10);
        }
        printf("\r");
        
		}
		Sleep(500);
		for (jj = 0; jj < 3; jj++) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\tControle de Palestra - UNIP \n");
		printf("\n\n\n\n\n");			
            printf("\t\t\t\t\t\t\t\t\t\tC");
            Sleep(105);
            printf("A");
            Sleep(105);
            printf("R");            
            Sleep(105);
            printf("R");
            Sleep(105); 
			printf("E");
			Sleep(105);
			printf("G");
			Sleep(105);
			printf("A");
			Sleep(105);
			printf("N");
			Sleep(105);
			printf("D");            
			Sleep(105);
			printf("O");
            Sleep(155);
        }
		Sleep(700);
		zerarlugar();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void certificado()
{
	//visualização do certificado, onde o usuario vai digitar o numero do ticket e ele busca os valores
	
	system("cls");
	
	SYSTEMTIME hora;		//variave que faz com que o programa identifique a hora do sistema
	GetLocalTime(&hora);

	int procura,procurax;
	
	printf("\n\n\n\n\n\n\n\n\nPor Favor Informe o Ticket! ");
	scanf("%i",&procurax);
		
	
	procura=((procurax/9)-2018);
	
	system("cls");
	
	
	painelcer();
			
			printf("\nHora Cadastro: %d:%d %d/%d/%d\n\n",hora.wHour,hora.wMinute,hora.wDay,hora.wMonth,hora.wYear);		//funções para retornar hora, minuto, dia, mes e ano do sistema, trazendo informações da API		
			printf("\nNome do Participante: %s",nome[procura]);
			printf("\nRA: %s",ra[procura]);
			printf("\nCPF: %s",cpf[procura]);
			printf("\nE-mail: %s",email[procura]);
			printf("\nCurso: %s",curso[procura]);
			printf("\n\n\n\n");

	system("pause");
	
	menu(); 

}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void definir_lugar()
{
	int descolha;
	system("cls");
	painelc();
	
	printf("\n\n\n1- Convidados\n2- PCD\n3- Plateia\n\n\n");
	scanf("%i",&descolha);
	
	switch(descolha)
	{
		
	case 1:
			
			for (i=0;i<2;i++)
			 {
			 	for(j=0;j<10;j++)
			 	{
			 		if(convcad[i][j]==1)
			 		{
			 			validap=validap+1;
			 		}
			 	
				 }
				 
			}
			
//			if abaixo verifica se todos os assentos foram estao preenchidos

			 if(validap>=20) //  20 é a quantidade maxima de pessoas que podem ocupar os assentos para convidados
				 {	
				 	system("cls");
				 	painelc();
					printf("\n\n\n\n\n\t\t\t\tNao temos mais assentos disponiveis!\n\tMuito Obrigado.\n\n\n\n\n\n\n\n\n");
					system("pause");
					system("cls");
				 	definir_lugar();
			
				 }
				 else
				 {

				 	system("cls");
				 	painelc();
				 	printf("\nFila: ");
					scanf("%i",&linha);
					printf("\nColuna: ");
					scanf("%i",&coluna);
					
					
			 		if(linha>2 || linha==0 || coluna>10 || coluna==0)  // o sistema esta validando se o numero de cadeira é valida e esta disponivel
					{
								system("cls");
				 				painelc();
								printf("\n\n\n\n\n\t\t\t\tDigite cadeira valida!!!!\n\n\n\n\n");
								system("pause");
								system("cls");
								 sistema_cadastro();
					}
					else
					{	
					convcad[linha-1][coluna-1]=1;
					}
				 }
				
				
		break;	
	case 2:
			
			
			for (i=0;i<1;i++)
			 {
			 	for(j=0;j<5;j++)
			 	{
			 		if(pcdcad[i][j]==1)
			 		{
			 			validapcd=validapcd+1;
			 		}
			 	
				 }
				 
			}
			
			 if(validapcd>=5) //  05 é a quantidade maxima de pessoas que podem ocupar os assentos para pessoas com deficiencias PCD
				 {	
				 	system("cls");
				 	painelc();
					printf("\n\n\n\n\n\t\t\t\tNao temos mais assentos disponiveis!\n\tMuito Obrigado.\n\n\n\n\n\n\n\n\n");
					system("pause");
					system("cls");
				 	definir_lugar();
			
				 }
				 else
				 {
				 	
				 	system("cls");
				 	painelc();
				 	printf("\nTickeT: %i",ticket);
				 	printf("\nFila: ");
					scanf("%i",&linha);
					printf("\nColuna: ");
					scanf("%i",&coluna);
					
						if(linha>1 || linha==0 || coluna>5 || coluna==0) // o sistema esta validando se o numero de cadeira é valida e esta disponivel
					{
								system("cls");
				 				painelc();
								printf("\n\n\n\n\n\t\t\t\tDigite cadeira valida!!!!\n\n\n\n\n");
								system("pause");
								system("cls");
								definir_lugar();
					}
					else
					{	
							if(pcdcad[linha-1][coluna-1]==1)
								{
								system("cls");
				 				painelc();
								printf("\n\n\n\n\n\t\t\t\tcadeira ja esta ocupada!!!!\n\n\n\n\n");
								system("pause");
								system("cls");
								definir_lugar();
								}
							else
								{			
								pcdcad[linha-1][coluna-1]=1;
								contsorteio[numsorte]=ticket;
								numsorte=numsorte+1;
								}
					}
				 }
		break;		
		

					

	case 3:
			
			
			for (i=0;i<8;i++)
			 {
			 	for(j=0;j<10;j++)
			 	{
			 		if(cad[i][j]==1)
			 		{
			 			validac=validac+1;
			 		}
			 	
				 }
				 
			}
			
			 if(validac>=80)  //  80 é a quantidade maxima de pessoas que podem ocupar os assentos para plateia geral
				 {	
				 	system("cls");
				 	painelc();
					printf("\n\n\n\n\n\t\t\t\tNao temos mais assentos disponiveis!\n\tMuito Obrigado.\n\n\n\n\n\n\n\n\n");
					system("pause");
					system("cls");
				 	definir_lugar();
			
				 }
				 else
				 {
				 	system("cls");
				 	painelc();
				 	printf("\nTickeT: %i",ticket);
				 	printf("\nFila: ");
					scanf("%i",&linha);
					printf("\nColuna: ");
					scanf("%i",&coluna);
					
					if(linha>8 || linha==0 ||coluna>10 || coluna==0)  // o sistema esta validando se o numero de cadeira é valida e esta disponivel
					{
								system("cls");
				 				painelc();
								printf("\n\n\n\n\n\t\t\t\tDigite cadeira valida!!!!\n\n\n\n\n");
								system("pause");
								system("cls");
								definir_lugar();
					}
					else
					{				
							if(cad[linha-1][coluna-1]==1)
								{
								system("cls");
				 				painelc();
								printf("\n\n\n\n\n\t\t\t\tcadeira ja esta ocupada!!!!\n\n\n\n\n");
								system("pause");
								system("cls");
								definir_lugar();
								}
							else
								{			
								cad[linha-1][coluna-1]=1;
								contsorteio[numsorte]=ticket;
								numsorte=numsorte+1;
								}
					}

		break;					
					
	default:		//caso seja digitado uma função que nao existe o default faz a tratativa do erro
	
		printf("Voce digitou uma opcao invalida, tente novamente!!!\n");
		system("pause\n");
		system("cls");
		menu();
		break;	
	}
 }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

 void lugares()
{
// função printa na tela as cadeiras disponivel e ocupadas com desenhos de acordo com a tabela ascii, mostrando apenas as plateias
 for (i=0;i<8;i++)
 {
 	
 		 printf("\t\t\t\t");
 	for(j=0;j<10;j++)
 	{
 		if(cad[i][j]==0)
 		{
 			printf("%i%c%i\t",i+1,176,j+1);
 		}
 		else
 		{
 			printf("%i%c%i\t",i+1,219,j+1);
		 }
	 }
	 printf("\t : Plat.\n");
 }
 printf("\n\n\n\n\n\n\n\n\n");
 system("pause");
 menu();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

 void lugarespcd()
{

// função printa na tela as cadeiras disponivel e ocupadas com desenhos de acordo com a tabela ascii, mostrando apenas os pcd
 for (i=0;i<1;i++)
 {
 	
 		 printf("\t\t\t\t");
 	for(j=0;j<5;j++)
 	{
 		if(pcdcad[i][j]==0)
 		{
 			printf("\t%i%c%i\t",i+1,176,j+1);
 		}
 		else
 		{
 			printf("\t%i%c%i\t",i+1,219,j+1);
		 }
	 }
	 printf("\t : PCD \n");
 }
lugares();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

 void lugaresconv()
{
	
	// função printa na tela as cadeiras disponivel e ocupadas com desenhos de acordo com a tabela ascii, mostrando apenas os convidados
	system("cls");

		 printf("\n\n\n\n\n");	
		 	planta();
 for (i=0;i<2;i++)
 {
 	
 		 printf("\t\t\t\t");
 	for(j=0;j<10;j++)
 	{
 		if(convcad[i][j]==0)
 		{
 			printf("%i%c%i\t",i+1,176,j+1);
 		}
 		else
 		{
 			printf("%i%c%i\t",i+1,219,j+1);
		 }
	 }
	 printf("\t : Conv.\n");
 }

 lugarespcd();
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void zerarlugar()
{
// função abaixo zera toda a matriz oonde contem informação de cadeiras
 for (zerari=0;zerari<10;zerari++)
 {
 	 for (zerarj=0;zerarj<10;zerarj++)
 	 {
 	 	cad[zerari][zerarj]=0;
	  }
 }
 
  for (zeraripcd=0;zeraripcd<1;zeraripcd++)
 {
 	 for (zerarjpcd=0;zerarjpcd<10;zerarjpcd++)
 	 {
 	 	pcdcad[zeraripcd][zerarjpcd]=0;
	  }
 }
 
   for (zerariconv=0;zerariconv<2;zerariconv++)
 {
 	 for (zerarjconv=0;zerarjconv<10;zerarjconv++)
 	 {
 	 	convcad[zerarjconv][zerarjconv]=0;
	  }
 }
 menu();
}
  
 //--------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{

	// inicio do programa

int escolha;
x=105;
numsorte=1;

	cont_base=1;
inicio_prog();				//chama o void menu(), e começa a rodar o programa

return 0; 
}
