#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings 

int registro()//Fun��o de regtstro de usu�rios 
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//fim  da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o de usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);// respons�vel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fechar o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Nome a ser cadastrado:");//coletando informa��o do usu�rio�
	scanf("%s", nome);//%s refere-se a string
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informa��o do usu�rio�
	scanf("%s", sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar
	fprintf(file, ",");
	fclose(file);
    
	printf("Digite o cargo a ser cadastrado:");//coletando informa��o do usu�rio
    scanf("%s", cargo);//%s refere-se a string
    
    file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");//pausa na opera��o 
	
	
	
	
}

int consulta()//Fun��o de consulta
{
	setlocale(LC_ALL,"Portuguese");//Definindo a Linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//comando caso o arquivo n�o exista
	{
		printf("CPF n�o localizado\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)//comando que mostra as informa��es a serem consultadas
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
 } 

int deletar()//fun��o deletar
{
	char cpf[40];
	
    printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);// comando de deletar os arquivos
	printf("CPF deletado\n");
	
	
	
	FILE *file;
	file = fopen(cpf, "r");//abre o arquivo e o "r" significa ler
	
	if(file == NULL)//comando caso o arquivo for nulo/inexistente
	{
		printf("Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 system("cls");	
	
	    setlocale(LC_ALL,"Portuguese");//Definindo a Linguagem
	
    	printf("*** Alunos EBAC *** \n\n");//Inicio do menu
	    printf("Acesse a op��o desejada no menu:\n\n");
        printf("\t1 - Registrar nome\n");
	    printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n\n");
	    printf("Op��o:");//Fim do menu
	
	
	    scanf("%d",&opcao);//Armazenando a escolha do usu�rio
	
        system("cls");//respons�vel por limpar a tela
        
        switch (opcao)//inicio da sele��o do menu
        {
        case 1:
         registro();//chamada de fun��es
	    break;
	    
	    case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		
		default:
		printf("op��o n�o disponivel!\n");
		system("pause");
		break;
		}//fim da sele��o
			
			
		}
	
}


