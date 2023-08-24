#include <stdio.h> // biblioteca de comunica�ao com o usuario
#include <stdlib.h> // biblioteca para aloca�ao de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> // biblioteca responsavel por cuidar das strings

int cadastrar()//fun��o responsavel para cadastrar um novo usu�rio
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	//inicio de cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria�ao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado:");//coletando informa��es do usuario 
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo,cpf);// responsavel por copiar o valor das strings

	FILE *file;// crioa o arquivo na pasta do programa
	file = fopen(arquivo,"w");//cria um novo arqivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variavel/string
	fclose(file);//fecha o arquivo

	file = fopen(arquivo,"a");//abre o arquivo e o "a" quer dizer atualizar
	fprintf(file,",");//coloca dentro do arquivo apos a variavel uma ","
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando informa��es do usuario
	scanf("%s",nome);//%s referese a string
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" sgnifica que vai atualizar
	fprintf(file,nome);//salva o valor da variavel no arquivol
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" siginifica atualizar
	fprintf(file,",");//salva uma virgula apos a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informa��es do usu�rio 
	scanf("%s",sobrenome);//refere-se a strings
	
	file = fopen(arquivo,"a");//abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome);//salva o valor da variavel no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar
	fprintf(file,",");//salva uma virgula ap�s a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser executado:");//coleta de dados do usu�rio
	scanf("%s",cargo);//%s refere-se a strings
	
	file = fopen(arquivo,"a");//abre o arquivo e "a" significa atualizar 
	fprintf(file,cargo);//salva o valor da variavel no arquivo 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e a "a" siginifica atualizar
	fprintf(file,",");//adiciona uma virgula no arquivo
	fclose(file);//fehca o arquivo
	
	system("cls");//responsavel por limpar a tela 
	
	printf("\t\t\nVoc� cadastrou um novo usu�rio!\n\n");//indica que o usu�rio foi cadastrado
	system("pause");//pausa a tela para vizualizar o que esta escrito
	
	
	
}

int consultar()//fun��o responsavel por consultar um usu�rio ja existente
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	//inicio da defini��o de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da defini��o de variaveis
	printf("Digite o CPF a ser consultado:");//pede o dado "cpf" para consulta de usuario
	scanf("%s", cpf);//refere-se a string "cpf"
	
	FILE *file;//abre o arquivo file
	file = fopen(cpf, "r");//abre o arquivo o "r" siginifica olhar
	
	if(file == NULL)//fun��o para o "cpf" n�o encontrado
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//fun��o para mostrar os dados do usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//pausa para poder olhar a tela e os dados do usu�rio
	
	
	
}

int excluir()
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	
	char cpf[40];//cria�ao da variavel/string
	
	printf("Digite o CPF do usuario a ser deletado:\n ");
	scanf("%s",cpf);
	
	remove(cpf);//comando para apagar dados
	
	FILE *file;//abrindo arquivo
	file = fopen(cpf,"r");//abre o arquivo e olha dentro 
	
	if (file == NULL)//fun�ao para mostrar que o usuario n�o se encontra no sistema
	{
		printf("Esse usuario n�o se encontra no sistema!");
		system("pause");
	}
	
	
	
}


int main()//fun�ao principal
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");//responsavel por limpar a tela
	
	    setlocale(LC_ALL, "portuguese");//definindo linguagem 
	
	    printf("\t Cart�rio da EBAC\n\n"); //inicio do menu 
	    printf("Selecione a op��o desejada:\n\n"); 
	    printf("\t1- Cadastrar usu�rio\n\n");
	    printf("\t2- Consultar usu�rio\n\n");
	    printf("\t3- Excluir usu�rio\n\n\n"); 
	    printf("op��o:");//fim do menu

        scanf("%d", &opcao);// armazenando a escolha do usuario 
    
	    system("cls");//limpa a tela
	    
	    
	    switch (opcao)//in�cio da sele��o 
	    {
	    	case 1:
	    	cadastrar();//chamada de fun��es
	        break;
	        
	        case 2:
	        consultar();//chamada de fun��es
		    break;
		    
		    case 3:
		    excluir();//chamada de fun��es
		    break;
		    
		    default:	
		    printf("\nesta op��o n�o esta disponivel!\n\n");//se a op��o for errada
		    system("pause");
		    break;
		}//fim da sele��o
	
	    
	
	
    }
}
