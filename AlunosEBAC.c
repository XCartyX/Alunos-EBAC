#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings 

int registro()//Função de regtstro de usuários 
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//fim  da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação de usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);// responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salvo o valor da variavel
	fclose(file);//fechar o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Nome a ser cadastrado:");//coletando informação do usuário²
	scanf("%s", nome);//%s refere-se a string
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informação do usuário³
	scanf("%s", sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar
	fprintf(file, ",");
	fclose(file);
    
	printf("Digite o cargo a ser cadastrado:");//coletando informação do usuário
    scanf("%s", cargo);//%s refere-se a string
    
    file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");//pausa na operação 
	
	
	
	
}

int consulta()//Função de consulta
{
	setlocale(LC_ALL,"Portuguese");//Definindo a Linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)//comando caso o arquivo não exista
	{
		printf("CPF não localizado\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)//comando que mostra as informações a serem consultadas
	{
		printf ("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
 } 

int deletar()//função deletar
{
	char cpf[40];
	
    printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);// comando de deletar os arquivos
	printf("CPF deletado\n");
	
	
	
	FILE *file;
	file = fopen(cpf, "r");//abre o arquivo e o "r" significa ler
	
	if(file == NULL)//comando caso o arquivo for nulo/inexistente
	{
		printf("Usuário nâo se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;//Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 system("cls");	
	
	    setlocale(LC_ALL,"Portuguese");//Definindo a Linguagem
	
    	printf("*** Alunos EBAC *** \n\n");//Inicio do menu
	    printf("Acesse a opção desejada no menu:\n\n");
        printf("\t1 - Registrar nome\n");
	    printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n\n");
	    printf("Opção:");//Fim do menu
	
	
	    scanf("%d",&opcao);//Armazenando a escolha do usuário
	
        system("cls");//responsável por limpar a tela
        
        switch (opcao)//inicio da seleção do menu
        {
        case 1:
         registro();//chamada de funções
	    break;
	    
	    case 2:
	    consulta();
		break;
		
		case 3:
		deletar();
		
		default:
		printf("opção nâo disponivel!\n");
		system("pause");
		break;
		}//fim da seleção
			
			
		}
	
}


