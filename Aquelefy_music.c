#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h> 
#include <conio.h>
#include <time.h>
#include <string.h>

typedef struct Cadastro
{
	int id_musica;
	char nome_musica [80];
	char nome_artista [80];
	char estilo [80];
	int tempo;
	int dia;
	int mes;
	int ano;
}CADASTRO;

void escolhamusica()
int contadorlinhas();
void cabecalho();
void Cadastrar_musica();
void Mostrar_musica();
void Pesquisar_musica();
void Alterar_musica();
void Excluir_musica();
void Tempo_total();
void Musica_maior_menor();

int main()
{
	int op;
	int music;
	
	
	setlocale(LC_ALL, "Portuguese");
	do{
		music = contadorlinhas();
		cabecalho();
		printf("\t\t\t========================== MENU ========================\n\n"
			"\t\t\t\t\t1- Cadastrar Musica (%d/30)\n"
			"\t\t\t\t\t2- Mostrar Musica\n"
			"\t\t\t\t\t3- Pesquisar Musica\n"
			"\t\t\t\t\t4- Alterar Musica\n"
			"\t\t\t\t\t5- Deletar Musica\n"	
			"\t\t\t\t\t6- Tempo Total de Exibição\n"	
			"\t\t\t\t\t7- Musica de maior/menor duração\n"
			"\t\t\t\t\t8- Encerrar o programa\n"
			"\t\t\t========================================================\n\n"
			"\t\t\tESCOLHA UMA OPÇÃO: ", music);
		scanf("%d",&op);	
		switch (op)
		{
			case 1:
				Cadastrar_musica();
				break;
	
			case 2:
				Mostrar_musica();
				break;
	
			case 3:
				Pesquisar_musica();
				break;
			
			case 4:
				Alterar_musica();
				break;
			
			case 5:
				Excluir_musica();
				break;
	
			case 6:
				Tempo_total();
				break;
	
			case 7:
				Musica_maior_menor();
				break;
	
			case 8:
				system("cls");
				printf("ENCERRANDO PROGRAMA...\n");
				Sleep(1500);
			   	break;
			   
			default:
				printf("OPÇÃO INVALIDA!\n");
				getch();
				break;
		}
		system("cls");   
	} while (op != 8);
	getch();
	return 0;
}
void escolhamusica(){
	FILE *arq;
	CADASTRO c;
	cabecalho();
	arq = fopen("musicas.txt", "rb");
	
	if (arq == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}
	else{
		printf("%-7s %-25s","ID", "Nome da Musica" 
		"\n=================================\n");
		while(fread(&c,sizeof(CADASTRO), 1, arq) == 1){
			if (c.id_musica>0){
				printf("%-7d %-25s\n", c.id_musica, c.nome_musica);
				printf("__________________________________\n");	
			}
		}
	}
	fclose(arq);
}

int contadorlinhas()
{
	FILE *arq;
	CADASTRO c;
	int cont=0;
	
	arq = fopen("musicas.txt", "rb");
	while(fread(&c,sizeof(CADASTRO), 1, arq) == 1){
		if (c.id_musica>0){
			cont++;	
		}
				  		  		
	}		
    fclose(arq);
	return cont;
}

void cabecalho(){
	system("cls");
	printf("\t\t\t--------------------------------------------------------\n");
	printf("\t\t\t\t\t\tAQUELEFY\n");
	printf("\t\t\t--------------------------------------------------------\n");
}

void Cadastrar_musica()
{
	FILE* arq;
	CADASTRO c;
	struct tm *data_hora_atual;
	int num, i, music;
	
	music = contadorlinhas();
	if (music == 30){
		printf("A capacidade maxima de cadastro é de 30 musicas e voce ja atingiu há esse limite\n");
		getch();
	}
	else {
		printf("Quantas musicas deseja cadastrar? ");
		scanf("%d", &num);
		for(i=0;i<num;i++){
			arq = fopen("musicas.txt", "ab");
			
			if (arq == NULL){
				printf("Problemas na abertura do arquivo!\n");
			}
			else{
				
				cabecalho();
				printf("\t\t\t____________________CADASTRAR MUSICA____________________\n\n");
				
				fflush(stdin);
				srand(time(NULL));
				c.id_musica = rand() % 1000;
				
				fflush(stdin);
				printf("Nome da musica: ");
				gets(c.nome_musica);
			
				fflush(stdin);
				printf("Nome do Artista/Banda: ");
				gets(c.nome_artista);
				
				fflush(stdin);
				printf("Estilo: ");
				gets(c.estilo);
				
				fflush(stdin);
				printf("Tempo em segundos: ");
				scanf("%d",&c.tempo);
				
				//Verifica a data da maquina que esta operando o programa
				time_t data;
				time(&data);
				data_hora_atual = localtime(&data);
				c.dia= data_hora_atual->tm_mday;
				c.mes= data_hora_atual->tm_mon+1;
				c.ano= data_hora_atual->tm_year+1900;
				printf("Data do Cadastro: %d/%d/%d\n", c.dia, c.mes, c.ano);
				Sleep(1000);
				
				fwrite(&c,sizeof(CADASTRO), 1, arq);
				fclose(arq);
				printf("Musica cadastrada com sucesso!\n\n");
				Sleep(1000);
			}
		}	
	}	
}

void Mostrar_musica()
{
	FILE *arq;
	CADASTRO c;
	
	arq = fopen("musicas.txt", "rb");
	
	cabecalho();
	if (arq == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	
	else{
		printf("%-7s %-25s %-30s %-25s %-10s %s","ID", "Nome da Musica", 
			"Nome do Artista", "Estilo", "Tempo", "Data de Cadastro\n"
			"============================================================="
			"==========================================================\n");
		while(fread(&c,sizeof(CADASTRO), 1, arq) == 1){
			if (c.id_musica>0){
				printf("%-7d %-25s %-30s %-25s %-10d %d/%d/%d\n", c.id_musica, c.nome_musica,
				c.nome_artista, c.estilo, c.tempo, c.dia, c.mes, c.ano);
				printf("___________________________________________________________"
					"____________________________________________________________\n");	
			}			  		  		
		}
		
	}
    fclose(arq);
	getch();
}

void Pesquisar_musica()
{
	FILE *arq;
	CADASTRO c;
	int id, contador=0;
	
	cabecalho();
	escolhamusica();
	
	arq = fopen("musicas.txt", "rb");
	
	fflush(stdin);
	printf("DIGITE O ID DA MUSICA PARA VER OS DETALHES: \n");
	scanf("%d", &id);
	while (fread(&c, sizeof(CADASTRO), 1, arq) == 1){
		system("cls");
		if (id == c.id_musica && c.id_musica>0){
			cabecalho();
			printf("%-7s %-25s %-30s %-25s %-10s %s","ID", "Nome da Musica", 
			"Nome do Artista", "Estilo", "Tempo", "Data de Cadastro\n"
			"============================================================="
			"==========================================================\n");
			printf("%-7d %-25s %-30s %-25s %-10d %d/%d/%d\n", c.id_musica, c.nome_musica,
			c.nome_artista, c.estilo, c.tempo, c.dia, c.mes, c.ano);
			contador++;
			break;
		}
	}
	if (contador == 0){
		printf("Não há nenhuma musica com esse ID\n");
	}
	fclose(arq);
	getch();
}

void Alterar_musica ()
{
	FILE *arq;
	CADASTRO c;
	struct tm *data_hora_atual;
	int id, contador=0;
	
	cabecalho();
	escolhamusica();
		
	fflush(stdin);
	arq = fopen("musicas.txt", "r+b");
	printf("DIGITE O ID DA MUSICA QUE DESEJA ALTERAR: \n");
	scanf("%d", &id);
	while (fread(&c, sizeof(CADASTRO), 1, arq) == 1){
		system("cls");
		if (id == c.id_musica){
			fseek(arq,-sizeof(CADASTRO), SEEK_CUR);
			if(ferror(arq)){
				printf("Erro no posicionamento do vetor\n");
			}
			else{
				cabecalho();
				printf("\t\t\t____________________CADASTRAR MUSICA____________________\n\n");
				
				fflush(stdin);
				srand(time(NULL));
				c.id_musica = rand() % 1000;
				
				fflush(stdin);
				printf("Nome da musica: ");
				gets(c.nome_musica);
			
				fflush(stdin);
				printf("Nome do Artista/Banda: ");
				gets(c.nome_artista);
				
				fflush(stdin);
				printf("Estilo: ");
				gets(c.estilo);
				
				fflush(stdin);
				printf("Tempo em segundos: ");
				scanf("%d",&c.tempo);
				
				//Verifica a data da maquina que esta operando o programa
				time_t data;
				time(&data);
				data_hora_atual = localtime(&data);
				c.dia= data_hora_atual->tm_mday;
				c.mes= data_hora_atual->tm_mon+1;
				c.ano= data_hora_atual->tm_year+1900;
				printf("Data do Cadastro: %d/%d/%d\n", c.dia, c.mes, c.ano);
				Sleep(1000);
				
				fwrite(&c,sizeof(CADASTRO), 1, arq);
				printf("Musica cadastrada com sucesso!\n\n");
				Sleep(1000);
				contador++;
				break;
			}
		}
	}
	if (contador == 0){
		printf("Não há nenhuma musica com esse ID\n");
	}
	fclose(arq);
	getch();
}

void Excluir_musica ()
{
	FILE *arq;
	CADASTRO c;
	int id, contador=0;
	
	cabecalho();
	escolhamusica();
		
	fflush(stdin);
	arq = fopen("musicas.txt", "r+b");
	printf("DIGITE O ID DA MUSICA QUE DESEJA EXCLUIR: \n");
	scanf("%d", &id);
	while (fread(&c, sizeof(CADASTRO), 1, arq) == 1){
		system("cls");
		if (id == c.id_musica){
			fseek(arq,-sizeof(CADASTRO), SEEK_CUR);
			if(ferror(arq)){
				printf("Erro no posicionamento do vetor\n");
			}
			else{
				memset(&c,0, sizeof(CADASTRO));
				fwrite(&c,sizeof(CADASTRO), 1, arq);
				printf("Musica deletada com sucesso!\n\n");
				Sleep(1000);
				contador++;
				break;
			}		
		}
	}
	if (contador == 0){
		printf("Não há nenhuma musica com esse ID\n");
	}
	fclose(arq);
	getch();
}

void Tempo_total()
{
	FILE* arq;
	CADASTRO c;
	float soma=0, minutos;
	
	arq= fopen("musicas.txt", "rb");
	if (arq == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	else{
		system("cls");
		cabecalho();
		while(fread(&c,sizeof(CADASTRO),1, arq) == 1){
			soma+=c.tempo;
		}
		minutos=(soma/60);
		printf("O TEMPO TOTAL DE EXIBIÇÃO EM MINUTOS É DE: %.1f m\n", minutos);
	}
	fclose(arq);
	getch();
}

void Musica_maior_menor()
{
	FILE* arq;
	CADASTRO c, maior, menor;
	int count=0;
	
	arq= fopen("musicas.txt", "rb");
	if (arq == NULL){
		printf("Problemas na abertura do arquivo!");
	}
	else{
		system("cls");
		cabecalho();
		fflush(stdin);
		while(fread(&c, sizeof(CADASTRO), 1, arq) == 1){
			
			if (c.id_musica>0){	
				count ++;
				if (count==1){
					maior= c;
					menor= c;
				}
				else if (c.tempo > maior.tempo){
					maior = c;
				}
				else if (c.tempo < menor.tempo){
					menor = c;	
				}
			}
		}
		printf("Música com maior duração: %s\n", maior.nome_musica);
		printf("Música com menor duração: %s\n", menor.nome_musica);
		
	}	
	fclose(arq);
	getch();
}