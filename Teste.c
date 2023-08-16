#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca responsavel pelas strings

int registro() //Fun��o respos�vel por cadastrar os usu�rios no sistema
{
	//Inic�o da cria��o das vari�veis/strings
	char arquivo[40]; //o colchetes significa que isso aqui � uma string 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando infor��oes do usu�rio
	scanf("%s", cpf);  //%s se refere a string
	
	strcpy(arquivo, cpf);  //responsavel por copiar o valor das strings
	
	FILE *file;  //cria o arquivo no banco de dados, busca na biblioteca para criar o aqruivo
	file = fopen(arquivo, "w");  //cria o arquivo, "W" significa "escrever"
	fprintf(file,cpf);  //onde salva o valor da vari�vel
	fclose(file);  //aqui fecha o arquivo
	
	file = fopen(arquivo, "a"); //est� abrindo o arquivo que j� est� salvo, o "a" � uma atualiza��o, n�o est� criando um novo arquivo
	fprintf(file,","); //ele est� salvando uma informa��o junto do arquivo, que no caso � uma v�rgula para separar as informa��es
	fclose(file); //fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //est� perguntando o nome para o usu�rio
	scanf("%s",nome); //tudo que o usu�rio digitar vai ser salvo numa string "%s" de vari�vel "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo novamente e atualiza as informa��es
	fprintf(file,nome); //salva o conte�do da vari�vel "nome" dentro do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, ","); //acrescenta a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //pergunta o sobrenome ao usu�rio
	scanf("%s", sobrenome); //armazena dentro da vari�vel "sobrenome"
	
	file = fopen(arquivo, "a"); //abre o arquivo e salva l� dentro
	fprintf(file, sobrenome); //joga essa informa��o no arquivo, atualizando ele
	fclose(file); //fecha o  arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo
	fprintf(file, ","); //acrescenta a virgula para separar as novas informa��es
	fclose(file); //fecha
	
	printf("Digite o cargo a ser cadastrado: ");  //pede para o usuario digitar o cargo do funcionario a ser cadastrado
	scanf("%s", cargo); //salva na vari�vel "cargo'
	
	file = fopen(arquivo, "a"); //salva a informa��o anterior dentro do arquivo tamb�m e atualiza
	fprintf(file, cargo); //coloca as informa��es dentro do arquivo
	fclose(file); //fecha o arquivo
	
	system("pause"); //para dar tempo do usuario conferir as informa��es
	
	
	
}

int consulta()  //fun��o respos�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: "); //pede ao usu�rio para digitar o cpf que ser� consultado
	scanf("%s",cpf); 
	
	FILE *file;  //aqui cria o arquivo
	file = fopen(cpf, "r"); //respos�vel por abrir o arquivo e ler ele, "r" de "read"
	
	if(file == NULL) //ele analisa o conte�do que est� entre parenteses e executa, caso ele exista
	{
		printf("N�o foi poss�vel abrir o aqruivo, n�o foi localizado!. \n"); //mensagem que � dada ao usu�rio quando o programa n�o encontra o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //mensagem eviado ao usu�rio
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
 
int deletar() //fun��o respos�vel por deletar os usu�rios cadastrados no sistema
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: "); 
	scanf("%s",cpf); 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)  
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause"); //respos�vel por deixar a mensagem na tela at� que o usu�rio saia
	}
	
	
}


int main()
{
	int opcao=0; //Estamos definindo as vari�veis
	int x=1;
	
	for(x=1; x=1;) //faz com que o usu�rio s� saia da tela se ele clicar na op��o de sair
	{ //tudo que estiver dentro das chaves sempre vai voltar, indo do inic�o ao fim e voltando para inic�o e assim por diante 
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("### Escolha a op��o desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");  //� o fim do menu
	printf("\t4 - Sair do distema\n");
	
	printf("Opcao: ");
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	system("cls"); //respos�vel por limpar a tela
	
	switch(opcao) //in�cio da sele��o do menu
	{
		case 1: 
		registro();	//chamada de fun��es
		break; //encerramento
		
		case 2:
		consulta(); //chamada de fun��es
		system("pause");
		break;  //encerramento
		
		case 3: 
		deletar(); //chamada de fun��es
		system("pause");
		break; //encerramento
		
		case 4:
		printf("Obrigado por utilizar o nosso sistema!\n");
		return 0;
		break;
		
		default: //quando � selecionada uma op��o fora do mapeamento/fora do padr�o
		printf("Essa op��o n�o est� disponivel! \n");  //Aqui � o fim da sele��o
		system("pause"); //respos�vel pela mensagem continuar na tela at� que o usu�rio clique para sair
		break; //encerramento
			
	}
}
	
}
