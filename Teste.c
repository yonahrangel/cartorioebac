#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responsavel pelas strings

int registro() //Função resposável por cadastrar os usuários no sistema
{
	//Inicío da criação das variáveis/strings
	char arquivo[40]; //o colchetes significa que isso aqui é uma string 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando inforçãoes do usuário
	scanf("%s", cpf);  //%s se refere a string
	
	strcpy(arquivo, cpf);  //responsavel por copiar o valor das strings
	
	FILE *file;  //cria o arquivo no banco de dados, busca na biblioteca para criar o aqruivo
	file = fopen(arquivo, "w");  //cria o arquivo, "W" significa "escrever"
	fprintf(file,cpf);  //onde salva o valor da variável
	fclose(file);  //aqui fecha o arquivo
	
	file = fopen(arquivo, "a"); //está abrindo o arquivo que já está salvo, o "a" é uma atualização, não está criando um novo arquivo
	fprintf(file,","); //ele está salvando uma informação junto do arquivo, que no caso é uma vírgula para separar as informações
	fclose(file); //fechando o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //está perguntando o nome para o usuário
	scanf("%s",nome); //tudo que o usuário digitar vai ser salvo numa string "%s" de variável "nome"
	
	file = fopen(arquivo, "a"); //abre o arquivo novamente e atualiza as informações
	fprintf(file,nome); //salva o conteúdo da variável "nome" dentro do arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, ","); //acrescenta a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //pergunta o sobrenome ao usuário
	scanf("%s", sobrenome); //armazena dentro da variável "sobrenome"
	
	file = fopen(arquivo, "a"); //abre o arquivo e salva lá dentro
	fprintf(file, sobrenome); //joga essa informação no arquivo, atualizando ele
	fclose(file); //fecha o  arquivo
	
	file = fopen(arquivo, "a"); //abre o aqruivo
	fprintf(file, ","); //acrescenta a virgula para separar as novas informações
	fclose(file); //fecha
	
	printf("Digite o cargo a ser cadastrado: ");  //pede para o usuario digitar o cargo do funcionario a ser cadastrado
	scanf("%s", cargo); //salva na variável "cargo'
	
	file = fopen(arquivo, "a"); //salva a informação anterior dentro do arquivo também e atualiza
	fprintf(file, cargo); //coloca as informações dentro do arquivo
	fclose(file); //fecha o arquivo
	
	system("pause"); //para dar tempo do usuario conferir as informações
	
	
	
}

int consulta()  //função resposável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: "); //pede ao usuário para digitar o cpf que será consultado
	scanf("%s",cpf); 
	
	FILE *file;  //aqui cria o arquivo
	file = fopen(cpf, "r"); //resposável por abrir o arquivo e ler ele, "r" de "read"
	
	if(file == NULL) //ele analisa o conteúdo que está entre parenteses e executa, caso ele exista
	{
		printf("Não foi possível abrir o aqruivo, não foi localizado!. \n"); //mensagem que é dada ao usuário quando o programa não encontra o arquivo
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); //mensagem eviado ao usuário
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
 
int deletar() //função resposável por deletar os usuários cadastrados no sistema
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: "); 
	scanf("%s",cpf); 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)  
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause"); //resposável por deixar a mensagem na tela até que o usuário saia
	}
	
	
}


int main()
{
	int opcao=0; //Estamos definindo as variáveis
	int x=1;
	
	for(x=1; x=1;) //faz com que o usuário só saia da tela se ele clicar na opção de sair
	{ //tudo que estiver dentro das chaves sempre vai voltar, indo do inicío ao fim e voltando para inicío e assim por diante 
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n");
	printf("### Escolha a opção desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");  //É o fim do menu
	printf("\t4 - Sair do distema\n");
	
	printf("Opcao: ");
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	system("cls"); //resposável por limpar a tela
	
	switch(opcao) //início da seleção do menu
	{
		case 1: 
		registro();	//chamada de funções
		break; //encerramento
		
		case 2:
		consulta(); //chamada de funções
		system("pause");
		break;  //encerramento
		
		case 3: 
		deletar(); //chamada de funções
		system("pause");
		break; //encerramento
		
		case 4:
		printf("Obrigado por utilizar o nosso sistema!\n");
		return 0;
		break;
		
		default: //quando é selecionada uma opção fora do mapeamento/fora do padrão
		printf("Essa opção não está disponivel! \n");  //Aqui é o fim da seleção
		system("pause"); //resposável pela mensagem continuar na tela até que o usuário clique para sair
		break; //encerramento
			
	}
}
	
}
