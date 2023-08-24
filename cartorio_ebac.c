#include <stdio.h> // biblioteca de comunicaçao com o usuario
#include <stdlib.h> // biblioteca para alocaçao de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por região 
#include <string.h> // biblioteca responsavel por cuidar das strings

int cadastrar()//função responsavel para cadastrar um novo usuário
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	//inicio de criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criaçao de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado:");//coletando informações do usuario 
	scanf("%s",cpf);//%s refere-se a strings
	
	strcpy(arquivo,cpf);// responsavel por copiar o valor das strings

	FILE *file;// crioa o arquivo na pasta do programa
	file = fopen(arquivo,"w");//cria um novo arqivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variavel/string
	fclose(file);//fecha o arquivo

	file = fopen(arquivo,"a");//abre o arquivo e o "a" quer dizer atualizar
	fprintf(file,",");//coloca dentro do arquivo apos a variavel uma ","
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando informações do usuario
	scanf("%s",nome);//%s referese a string
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" sgnifica que vai atualizar
	fprintf(file,nome);//salva o valor da variavel no arquivol
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" siginifica atualizar
	fprintf(file,",");//salva uma virgula apos a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado:");//coletando informações do usuário 
	scanf("%s",sobrenome);//refere-se a strings
	
	file = fopen(arquivo,"a");//abre o arquivo e "a" significa atualizar
	fprintf(file,sobrenome);//salva o valor da variavel no arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar
	fprintf(file,",");//salva uma virgula após a string
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser executado:");//coleta de dados do usuário
	scanf("%s",cargo);//%s refere-se a strings
	
	file = fopen(arquivo,"a");//abre o arquivo e "a" significa atualizar 
	fprintf(file,cargo);//salva o valor da variavel no arquivo 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e a "a" siginifica atualizar
	fprintf(file,",");//adiciona uma virgula no arquivo
	fclose(file);//fehca o arquivo
	
	system("cls");//responsavel por limpar a tela 
	
	printf("\t\t\nVocê cadastrou um novo usuário!\n\n");//indica que o usuário foi cadastrado
	system("pause");//pausa a tela para vizualizar o que esta escrito
	
	
	
}

int consultar()//função responsavel por consultar um usuário ja existente
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	//inicio da definição de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da definição de variaveis
	printf("Digite o CPF a ser consultado:");//pede o dado "cpf" para consulta de usuario
	scanf("%s", cpf);//refere-se a string "cpf"
	
	FILE *file;//abre o arquivo file
	file = fopen(cpf, "r");//abre o arquivo o "r" siginifica olhar
	
	if(file == NULL)//função para o "cpf" não encontrado
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//função para mostrar os dados do usuário
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");//pausa para poder olhar a tela e os dados do usuário
	
	
	
}

int excluir()
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	
	char cpf[40];//criaçao da variavel/string
	
	printf("Digite o CPF do usuario a ser deletado:\n ");
	scanf("%s",cpf);
	
	remove(cpf);//comando para apagar dados
	
	FILE *file;//abrindo arquivo
	file = fopen(cpf,"r");//abre o arquivo e olha dentro 
	
	if (file == NULL)//funçao para mostrar que o usuario não se encontra no sistema
	{
		printf("Esse usuario não se encontra no sistema!");
		system("pause");
	}
	
	
	
}


int main()//funçao principal
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");//responsavel por limpar a tela
	
	    setlocale(LC_ALL, "portuguese");//definindo linguagem 
	
	    printf("\t Cartório da EBAC\n\n"); //inicio do menu 
	    printf("Selecione a opção desejada:\n\n"); 
	    printf("\t1- Cadastrar usuário\n\n");
	    printf("\t2- Consultar usuário\n\n");
	    printf("\t3- Excluir usuário\n\n\n"); 
	    printf("opção:");//fim do menu

        scanf("%d", &opcao);// armazenando a escolha do usuario 
    
	    system("cls");//limpa a tela
	    
	    
	    switch (opcao)//início da seleção 
	    {
	    	case 1:
	    	cadastrar();//chamada de funções
	        break;
	        
	        case 2:
	        consultar();//chamada de funções
		    break;
		    
		    case 3:
		    excluir();//chamada de funções
		    break;
		    
		    default:	
		    printf("\nesta opção não esta disponivel!\n\n");//se a opção for errada
		    system("pause");
		    break;
		}//fim da seleção
	
	    
	
	
    }
}
