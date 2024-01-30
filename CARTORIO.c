#include <stdio.h> // Biblioteca para transformar texto em linguagem de m�quina
#include <stdlib.h> // Biblioteca alocar mem�ria
#include <locale.h> // Biblioteca alocar ler caracteres da lingua da regi�o 
#include <string.h>// Biblioteca para o manuseio de strings

int registrar()//fun��o Registrar Usuario
{
	printf("-- REGISTRAR --\n\n");
	system("pause");// pausa o programa at� o usu�rio apertar 
	//qualquer tecla
	// -- INICIO cria��o de vari�veis --
	char cpf[16];//variavel que � a chave
	char nome[20];
	char sobrenome[20];
	char cargo[20];
	char arquivo[16];
	// -- FIM cria��o de vari�veis -- 
	printf("Digite o CPF => ");// --- CPF --- 
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores para
	// string - <string.h> - =>arquivo � o banco de dados. O nome do arquivo
	//sera o cpf digitado
	FILE *file;//FILE � uma fun��o j� pronta. Ela est� sendo acionada  
	//com o comando  *file  
	file = fopen(arquivo,"w");//abrir um arquivo =>fopen. Escrever = Write
	// " w " na variavel =>arquivo  
	fprintf(file,cpf);//armazena no arquivo a variavel =>cpf
	fclose(file);//fecha o arquivo
	file = fopen(arquivo,"a");// atualizar "a"
	fprintf(file,",");//inseri uma virgula apos o cpf
	fclose(file);
	
	printf("Digite o NOME => ");// --- NOME --- 
	scanf("%s",nome);
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o SOBRENOME => ");// --- SOBRENOME --- 
	scanf("%s",sobrenome);
	file = fopen(arquivo,"a"); 
	fprintf(file,sobrenome);
	fclose(file);
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o CARGO => ");// --- CARGO --- 
	scanf("%s",cargo);
	file= fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	file= fopen(arquivo,"a");
	fprintf(file,".");
	fclose(file);
	
}

int consultar()//fun��o Consultar Usuario
{
	setlocale(LC_ALL,"Portuguese");
	printf("-- CONSULTAR --\n\n");
	system("pause");
	
	char cpf[16];
	char conteudo[200];//variavel que vai ser exibida para o usuario
	
	printf("DIGITE O CPF PARA CONSULTA -- CPF =>");
	scanf("%s",cpf);
	FILE *file;
	file = fopen(cpf,"r");// Ler arquivo -- Ler = Read 
	//"r" => read , ler arquivo
	if(file == NULL)// -- CASO N�O TENHA DADOS --
	{
		printf(" USU�RIO N�O CADASTRADO \n\n");	
	} 
	while (fgets(conteudo,200,file)!=NULL)// fgets => Salvando no 'conteudo' 
	// 200 caracteres que est�o no arquivo 'file' enquanto n�o achar um valor nulo
	{
		printf("\nINFORMA��ES DO USU�RIO S�O => ");
		printf("%s", conteudo);
		printf("\n\n");
	}  
	system("pause");
}

int deletar()//fun��o Deletar Usu�rio
{
	char cpf[16];
	setlocale(LC_ALL,"Portuguese");
	printf("-- DELETAR --\n\n");
	system("pause");
	printf("DIGITE O CPF QUE DESEJA DELETAR => ");
	scanf("%s", cpf);
		
	FILE* file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nUSU�RIO N�O SE ENCONTRA NO SISTEMA\n");
		system("pause");
	}
	else
	{
		remove(cpf);// fun��o que vai remover o usu�rio com cpf 
	    //digitado
		printf("\nUSU�RIO DELETADO\n");
		system("pause");
	}
}

int main () // fun��o onde rodar� o n�cleo do programa
// -- () => simboliza fun��o -- int: fun��o do tipo inteiro
{
	int opcao = 0;// variavel que armazena o valor inteiro correspondente ao
	// a terefa escolhida 1-REGISTRAR   2-REGISTRAR   3-DELETAR.
	int x = 1;// vari�vel usada no loop infinito do for
	setlocale(LC_ALL,"Portuguese"); // indica qual idioma de refer�ncia
	// para a biblioteca <locate.h> o ';' indica fim de instru��o
	for(x=1;x=1;)// estruturado para fazer um loop infinito
	{
	
		system("cls");// Apaga tudo exibido no console at� aqui
		printf(" ----- CART�RIO DA EBAC -----\n\n\n"); //'\n' indica pular uma linha
		// na exibi��o para o usu�rio
		printf(" --- Escolha a op��o desejada ---\n\n");
		printf("\t1 -- REGISTRAR Usu�rio --\n"); //'t' espa�amento igual o TAB do
		// teclado
		printf("\t2 -- CONSULTAR Usu�rio --\n");
		printf("\t3 -- DELETAR Usu�rio --\n"); 
		printf("\t4 -- SAIR DO SISTEMA --\n\n"); 
		printf(" DIGITE OPCAO DESEJADA => ");
	
		scanf("%d", &opcao);//armazena na variavel opcao, o valor que o usuario 
		// digitar... %d - indica que a variavel sera convertida para o tipo inteiro.
		
		system("cls");// Apaga tudo exibido no console at� aqui
		
		switch(opcao)
		{
			case 1:
			registrar();	
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();	
			break;
			
			case 4:
			printf("\nTENHA UM BOM DIA ");
			return 0;//retornar 0 sistem entende que tem que sair
			break;
			
			default:// Caso nenhuma op��o acima seja atendida
				printf("-- Op��o Inv�lida --\n\n");
				system("pause");
			break;
		}
			
	}
}

