#include <stdio.h>
#include <iostream>
#include <math.h>
#include <locale>
#include <string>
#include <windows.h>

using namespace std;

struct dados
{
    char nome[100];
};

int calc_imc();
int calc_desconto_inss();
int calc_desconto_irpf();
int decimo();
int ferias();
int menu();
char opcao_9();
dados cadastro();
int reiniciar();


//-----------Cadastro do nome-----------------
dados cadastro()
{
    struct dados b;
    printf("Oi, tudo bem?\nQual o seu nome? ");// Pegunta o nome do Usuário
    fflush(stdin);
    cin.getline(b.nome, 100);
    return b;
}

//------Função principal (main)----------------

int main()
{
    struct dados a;
    a = cadastro();
    system("cls");
    printf("----------Sitema de interacao ao usuario----------\n");
    printf("Prazer %s, estarei lhe apresentando algumas opcoes para sua escolha:\n",a.nome);
    Sleep(5000);
    int op;
    op = menu();
    switch (op){
        case 1:
            system("cls");
            printf("----------Sitema de interacao ao usuario----------\n");
            printf(" %s, voce escolheu a opcao do Calculo de IMC.\n",a.nome);
            Sleep(5000);
            calc_imc();
            break;
        case 2:
            system("cls");
            printf("----------Sitema de interacao ao usuario----------\n");
            printf("  %s, voce escolheu calculo do desconto do INSS (mensal).\n",a.nome);
            Sleep(5000);
            calc_desconto_inss();
            break;
        case 3:
            system("cls");
            printf("----------Sitema de interacao ao usuario----------\n");
            printf("  %s, voce escolhe a opcao do calculo do desconto do IRPF (mensal) \n",a.nome);
            Sleep(5000);
            calc_desconto_irpf();
            break;
        case 4:
            system("cls");
            printf("----------Sitema de interacao ao usuario----------\n");
            printf("  %s, voce escolhe a opcao do calculo do decimo ter salario.\n",a.nome);
            Sleep(5000);
            decimo();
            break;
        case 5:
            system("cls");
            printf("----------Sitema de interacao ao usuario----------\n");
            printf("  %s, Voce escolhe a opcao do calculo de ferias.\n",a.nome);
            ferias();
            break;
        case 9:
            system("cls");
            Sleep(5000);
            opcao_9();
            break;
        default:
            system("cls");
            printf("----------Sitema de interacao ao usuario----------\n");
            printf("Opcao invalida!! informe uma opcao valida.");
            menu();
            break;
    }
    return 0;
}

//----------------Menu------------------------

int menu()
{
    struct dados c;
    int escolha;
    system("cls");
    printf("----------Sitema de interacao ao usuario----------\n");
    printf("Temos algumas opcoes para voce escolher, o que deseja saber?\n");
    printf("1 - Realizar o calculo de IMC;\n2 - Realizar o calculo do desconto do INSS (mensal);\n3 - Realizar o calculo do desconto do IRPF (mensal);\n4 - Realizar o calculo de 13 salario do empregado;\n5 - Realizar o calculo de ferias do empregado;\n9 - Para sair do Programa;\n");
    printf("Digite o valor da opcao desejada:");
    scanf("%d",&escolha);
    return escolha;
}

//---------------Cálculo do IMC---------------

int calc_imc()
{
    system("cls");
    printf("----------Sitema de interacao ao usuario----------\n");
    float IMC, temp, peso, altura;
    //Cálculo do IMC
    printf("Para calcular precisamos de algumas informacoes, como peso e altura;\n");
    printf("Atualmente quanto voce esta pesando? ");
    scanf("%f",&peso);
    printf("Atualmente voce temquanto de altura (Ex.: 1.8)? ");
    scanf("%f",&altura);

    IMC = peso;
    temp = altura*altura;
    IMC = peso/temp;
    //-------------Respostas para cada resultado----------------------

    if (IMC<18.5)
    {
        printf("Voce esta abaixo do peso. Seu IMC, e: %.2f.\n",IMC);
    }
    else if (IMC>=18.5 && IMC<=24.9)
    {
        printf("Seu peso esta normal. Seu IMC, e: %.2f.\n",IMC);
    }
    else if (IMC>=25 && IMC<=29.9)
    {
        printf("Voce esta com sobrepeso. Seu IMC, e: %.2f.\n",IMC);
    }
    else if (IMC>=30 && IMC<=34.9)
    {
        printf("Voce esta com Obesidade grau 1. Seu IMC, e: %.2f.\n",IMC);
    }
    else if (IMC>=35 && IMC<=39.9)
    {
        printf("Voce esta com Obesidade grau 2. Seu IMC, e: %.2f.\n",IMC);
    }
    else if (IMC>40)
    {
        printf("Voce esta com Obesidade grau 3. Seu IMC. Seu IMC, e: %.2f.\n",IMC);
    }
    Sleep(6000);
    reiniciar();
}

//------------Cálculo do INSS----------------------

int calc_desconto_inss()
{
    system("cls");
    printf("----------Sitema de interacao ao usuario----------\n");
    float salario,final,alternativa;
    printf("Atualmente qual o seu salario?");
    scanf("%f",&salario);
    printf("A tabela do INSS atualizou em virtude do aumento salarial.\n");
    if (salario<=1212)
    {
        alternativa=salario*0.075;//cálculo do desconto
        final=salario-alternativa;//Cálculo valor liquido
        printf("Em virtude de seu salario o desconto e de 7,5 Porcento. Entao seu desconto, foi de: R$ %.2f.\n",alternativa);
        printf("O seu salario liquido, e: %.2f",final);
    }
    else if (salario>=1212.12 && salario <=2427.35)
    {
        alternativa=salario*0.9;//cálculo do desconto
        final=salario-alternativa;//Cálculo valor liquido
        printf("Em virtude de seu salario o desconto e de 9 Porcento. Entao seu desconto, foi de: R$ %.2f.\n",alternativa);
        printf("O seu salario liquido, e: %.2f",final);
    }
    else if (salario>=2427.36 && salario <=3641.03)
    {
        alternativa=salario*0.12;//cálculo do desconto
        final=salario-alternativa;//Cálculo valor liquido
        printf("Em virtude de seu salario o desconto e de 12 Porcento. Entao seu desconto, foi de: R$ %.2f.\n",alternativa);
        printf("O seu salario liquido, e: %.2f",final);
    }
    else if (salario>=3641.04)
    {
        alternativa=salario*0.14;//cálculo do desconto
        final=salario-alternativa;//Cálculo valor liquido
        printf("Em virtude de seu salario o desconto e de 12 Porcento. Entao seu desconto, foi de: R$ %.2f.\n",alternativa);
        printf("O seu salario liquido, e: %.2f",final);
    }
    Sleep(6000);
    reiniciar();
}

//----Cálculo de desconto do Imposto de Renda-----------

int calc_desconto_irpf()
{
    float salario, f, fim;
    printf("Qual seu salario? ");
    scanf("%f",&salario);
    if (salario<=1903.98)
    {
        printf("Seu calculo e zerado por esta abaixo de R$ 1903.98");
    }
    else if (salario>=1903.99 && salario<=2826.65)
    {
        f=salario*0.075;
        fim = salario - f;
        printf("seu valor de imposto mensal, e: %.2f\n",salario);
        printf("Seu valor liquido sem o imposto, e: %.f\n",fim);
    }
    else if (salario>=2826.66 && salario<=3751.05)
    {
        f=salario*0.15;
        fim = salario - f;
        printf("Seu valor de imposto mensal, e: %.2f\n",salario);
        printf("Seu valor liquido sem o imposto, e: %.f\n",fim);
    }
    else if (salario>=3751.06 && salario<=4664.68)
    {
        f=salario*0.225;
        fim = salario - f;
        printf("Seu valor de imposto mensal, e: %.2f\n",salario);
        printf("Seu valor liquido sem o imposto, e: %.f\n",fim);
    }
    else if (salario>=4.664,69)
    {
        f=salario*0.275;
        fim = salario - f;
        printf("Seu valor de imposto mensal, e: %.2f\n",salario);
        printf("Seu valor liquido sem o imposto, e: %.f\n",fim);
    }
    Sleep(6000);
    reiniciar();
}

//------------Cálculo do décimo----------------------

int decimo()
{
    float tempo,salario,s;
    printf("Qual seu salario? ");
    scanf("%f",&salario);
    printf("Quanto tempo voce tem de empresa (Em meses)?");
    scanf("%f",&tempo);
    s = salario/12;
    s = s*tempo;
    printf("Voce ira receber %.2f de decimo terceiro.",s);
    Sleep(6000);
    reiniciar();
}

//------Cálculo de férias---------------------

int ferias()
{
    float salario_mes, salario, tempo;
    printf("Qual e seu salario atualmente?");
    scanf("%f",&salario);
    printf("Quanto tempo desde as ultimas ferias?");
    scanf("%f", &tempo);
    salario_mes = (salario/12)*tempo; //Calculo das ferias em reais
    printf("Seu salario de ferias, e: %.2f\n",salario_mes);
    Sleep(6000);
    reiniciar();
}

//------------------Opção nove--------------------------

char opcao_9()
{
    printf("Obrigado por utilizar o nosso programa, ate mais!!");
    Sleep(6000);
    return 0;
}
//------------reiniciar o programa----------------------

int reiniciar()
{
	char opcao;
    system("cls");
    printf("----------Sitema de interacao ao usuario----------\n");
    cout << "\n Quer realizar um novo procedimento? \n(Sim - S ou Nao - N):";
	cin >> opcao;
	opcao = toupper(opcao);
    if(opcao=='S'){
		system("cls");
		main();
    }else if(opcao =='N'){
        printf(" Obrigado por ter utilizado o meu codigo.");
        return 0;
    }else {
        printf("\nOpcao invalida!! O digito informado e invalido! Digite novamente!");
        reiniciar();
    }
}