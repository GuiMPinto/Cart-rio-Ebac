#include <stdio.h> // Biblioteca para transformar texto em linguagem de máquina
#include <stdlib.h> // Biblioteca alocar memória
#include <locale.h> // Biblioteca alocar ler caracteres da lingua da região 
#include <string.h>// Biblioteca para o manuseio de strings

int registrar()//função Registrar Usuario
{
	printf("-- REGISTRAR --\n\n");
	system("pause");// pausa o programa até o usuário apertar 
	//qualquer tecla
	// -- INICIO criação de variáveis --
	char cpf[16];//variavel que é a chave
	char nome[20];
	char sobrenome[20];
	char cargo[20];
	char arquivo[16];
	// -- FIM criação de variáveis -- 
	printf("Digite o CPF => ");// --- CPF --- 
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores para
	// string - <string.h> - =>arquivo é o banco de dados. O nome do arquivo
	//sera o cpf digitado
	FILE *file;//FILE é uma função já pronta. Ela está sendo acionada  
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

int consultar()//função Consultar Usuario
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
	if(file == NULL)// -- CASO NÃO TENHA DADOS --
	{
		printf(" USUÁRIO NÂO CADASTRADO \n\n");	
	} 
	while (fgets(conteudo,200,file)!=NULL)// fgets => Salvando no 'conteudo' 
	// 200 caracteres que estão no arquivo 'file' enquanto não achar um valor nulo
	{
		printf("\nINFORMAÇÕES DO USUÁRIO SÃO => ");
		printf("%s", conteudo);
		printf("\n\n");
	}  
	system("pause");
}

int deletar()//função Deletar Usuário
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
		printf("\nUSUÁRIO NÃO SE ENCONTRA NO SISTEMA\n");
		system("pause");
	}
	else
	{
		remove(cpf);// função que vai remover o usuário com cpf 
	    //digitado
		printf("\nUSUÁRIO DELETADO\n");
		system("pause");
	}
}

int main () // função onde rodará o núcleo do programa
// -- () => simboliza função -- int: função do tipo inteiro
{
	int opcao = 0;// variavel que armazena o valor inteiro correspondente ao
	// a terefa escolhida 1-REGISTRAR   2-REGISTRAR   3-DELETAR.
	int x = 1;// variável usada no loop infinito do for
	setlocale(LC_ALL,"Portuguese"); // indica qual idioma de referência
	// para a biblioteca <locate.h> o ';' indica fim de instrução
	for(x=1;x=1;)// estruturado para fazer um loop infinito
	{
	
		system("cls");// Apaga tudo exibido no console até aqui
		printf(" ----- CARTÓRIO DA EBAC -----\n\n\n"); //'\n' indica pular uma linha
		// na exibição para o usuário
		printf(" --- Escolha a opção desejada ---\n\n");
		printf("\t1 -- REGISTRAR Usuário --\n"); //'t' espaçamento igual o TAB do
		// teclado
		printf("\t2 -- CONSULTAR Usuário --\n");
		printf("\t3 -- DELETAR Usuário --\n"); 
		printf("\t4 -- SAIR DO SISTEMA --\n\n"); 
		printf(" DIGITE OPCAO DESEJADA => ");
	
		scanf("%d", &opcao);//armazena na variavel opcao, o valor que o usuario 
		// digitar... %d - indica que a variavel sera convertida para o tipo inteiro.
		
		system("cls");// Apaga tudo exibido no console até aqui
		
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
			
			default:// Caso nenhuma opção acima seja atendida
				printf("-- Opção Inválida --\n\n");
				system("pause");
			break;
		}
			
	}
}

