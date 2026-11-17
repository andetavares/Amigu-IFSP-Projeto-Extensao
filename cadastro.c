#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 50
#define MAX_PESSOAS 50
#define MAX_DOACOES 200

/* ---------- Estruturas ---------- */

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char nome[50];
    int quantidade;
} Produto;

typedef struct
{
    char nome[50];
    char cpf[12];
} Pessoa;

typedef struct
{
    int pessoa;      // posicao da pessoa no vetor pessoas
    int produto;     // posicao do produto no vetor produtos
    int quantidade;
    Data data;
} Doacao;

/* ---------- Variaveis globais ---------- */

Produto produtos[MAX_PRODUTOS];
int total_produtos = 0;

Pessoa pessoas[MAX_PESSOAS];
int total_pessoas = 0;

Doacao doacoes[MAX_DOACOES];
int total_doacoes = 0;

/* ---------- Funcoes de leitura com validacao ---------- */

// le um inteiro e so aceita valores entre minimo e maximo
int leia_inteiro(char *mensagem, int minimo, int maximo)
{
    int valor, rs;

    do
    {
        printf("%s", mensagem);
        fflush(stdin);
        rs = scanf("%d", &valor);

        if (rs != 1)
        {
            printf("Digite apenas numeros!\n");
        }
        else if (valor < minimo || valor > maximo)
        {
            printf("O valor deve estar entre %d e %d!\n", minimo, maximo);
        }
    } while (rs != 1 || valor < minimo || valor > maximo);

    return valor;
}

// le um texto com no minimo 3 caracteres
void leia_nome(char *mensagem, char *str)
{
    do
    {
        printf("%s", mensagem);
        fflush(stdin);
        scanf(" %49[^\n]", str);

        if (strlen(str) < 3)
        {
            printf("O nome deve ter pelo menos 3 caracteres!\n");
        }
    } while (strlen(str) < 3);
}

// le um CPF com exatamente 11 caracteres
void leia_cpf(char *str)
{
    do
    {
        printf("CPF (11 numeros): ");
        fflush(stdin);
        scanf(" %11[^\n]", str);

        if (strlen(str) != 11)
        {
            printf("O CPF deve ter exatamente 11 caracteres!\n");
        }
    } while (strlen(str) != 11);
}

/* ---------- Telas do programa ---------- */

void tela_cadastrar_produto()
{
    char nome[50];
    int quantidade, i, achou;

    system("cls");
    printf("CADASTRAR PRODUTO\n\n");

    if (total_produtos == MAX_PRODUTOS)
    {
        printf("Nao ha mais espaco para produtos!\n");
        system("pause");
        return;
    }

    leia_nome("Nome do produto: ", nome);
    quantidade = leia_inteiro("Quantidade: ", 1, 10000);

    // se o produto ja existe, apenas soma a quantidade
    achou = 0;
    for (i = 0; i < total_produtos; i++)
    {
        if (strcmp(produtos[i].nome, nome) == 0)
        {
            produtos[i].quantidade = produtos[i].quantidade + quantidade;
            achou = 1;
        }
    }

    if (achou == 0)
    {
        strcpy(produtos[total_produtos].nome, nome);
        produtos[total_produtos].quantidade = quantidade;
        total_produtos++;
    }

    printf("\nProduto cadastrado com sucesso!\n");
    system("pause");
}

void tela_cadastrar_pessoa()
{
    system("cls");
    printf("CADASTRAR PESSOA\n\n");

    if (total_pessoas == MAX_PESSOAS)
    {
        printf("Nao ha mais espaco para pessoas!\n");
        system("pause");
        return;
    }

    leia_nome("Nome da pessoa: ", pessoas[total_pessoas].nome);
    leia_cpf(pessoas[total_pessoas].cpf);
    total_pessoas++;

    printf("\nPessoa cadastrada com sucesso!\n");
    system("pause");
}

void tela_ver_produtos()
{
    int i;

    system("cls");
    printf("PRODUTOS EM ESTOQUE:\n\n");

    if (total_produtos == 0)
    {
        printf("Nenhum produto cadastrado.\n");
    }

    for (i = 0; i < total_produtos; i++)
    {
        printf("%d - %s (quantidade: %d)\n", i + 1, produtos[i].nome, produtos[i].quantidade);
    }

    printf("\n");
    system("pause");
}

void tela_ver_pessoas()
{
    int i;

    system("cls");
    printf("PESSOAS CADASTRADAS\n\n");

    if (total_pessoas == 0)
    {
        printf("Nenhuma pessoa cadastrada.\n");
    }

    for (i = 0; i < total_pessoas; i++)
    {
        printf("%d - %s (CPF: %s)\n", i + 1, pessoas[i].nome, pessoas[i].cpf);
    }

    printf("\n");
    system("pause");
}

void tela_registrar_doacao()
{
    int i, pessoa, produto, quantidade;
    Data data;

    system("cls");
    printf("REGISTRAR DOACAO\n\n");

    if (total_pessoas == 0 || total_produtos == 0)
    {
        printf("Cadastre pelo menos uma pessoa e um produto antes!\n");
        system("pause");
        return;
    }

    if (total_doacoes == MAX_DOACOES)
    {
        printf("Nao ha mais espaco para doacoes!\n");
        system("pause");
        return;
    }

    // escolhe quem vai receber
    printf("Pessoas:\n");
    for (i = 0; i < total_pessoas; i++)
    {
        printf("%d - %s\n", i + 1, pessoas[i].nome);
    }
    pessoa = leia_inteiro("\nNumero da pessoa: ", 1, total_pessoas);

    // escolhe o que vai receber
    printf("\nProdutos:\n");
    for (i = 0; i < total_produtos; i++)
    {
        printf("%d - %s (quantidade: %d)\n", i + 1, produtos[i].nome, produtos[i].quantidade);
    }
    produto = leia_inteiro("\nNumero do produto: ", 1, total_produtos);

    if (produtos[produto - 1].quantidade == 0)
    {
        printf("\nEsse produto esta sem estoque!\n");
        system("pause");
        return;
    }

    quantidade = leia_inteiro("Quantidade: ", 1, produtos[produto - 1].quantidade);

    // le a data
    printf("\nData da doacao:\n");
    data.dia = leia_inteiro("Dia: ", 1, 31);
    data.mes = leia_inteiro("Mes: ", 1, 12);
    data.ano = leia_inteiro("Ano: ", 2020, 2100);

    // guarda a doacao e tira do estoque
    doacoes[total_doacoes].pessoa = pessoa - 1;
    doacoes[total_doacoes].produto = produto - 1;
    doacoes[total_doacoes].quantidade = quantidade;
    doacoes[total_doacoes].data = data;
    total_doacoes++;

    produtos[produto - 1].quantidade = produtos[produto - 1].quantidade - quantidade;

    printf("\nDoacao registrada com sucesso!\n");
    system("pause");
}

void tela_ver_doacoes()
{
    int i, p, pr;

    system("cls");
    printf("DOACOES REALIZADAS\n\n");

    if (total_doacoes == 0)
    {
        printf("Nenhuma doacao registrada.\n");
    }

    for (i = 0; i < total_doacoes; i++)
    {
        p = doacoes[i].pessoa;
        pr = doacoes[i].produto;

        printf("\n%d - %s recebeu %d de %s em %02d/%02d/%d\n\n",
               i + 1,
               pessoas[p].nome,
               doacoes[i].quantidade,
               produtos[pr].nome,
               doacoes[i].data.dia,
               doacoes[i].data.mes,
               doacoes[i].data.ano);
    }

    printf("\n");
    system("pause");
}

/* ---------- Menu principal ---------- */

int main()
{
    int opcao;

    do
    {
        system("cls");
        printf("===== AMIGU - Gestao de Doacoes =====\n\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Cadastrar pessoa\n");
        printf("3 - Registrar doacao\n");
        printf("4 - Ver produtos\n");
        printf("5 - Ver pessoas\n");
        printf("6 - Ver doacoes recebidas\n");
        printf("0 - Sair\n\n");

        opcao = leia_inteiro("Escolha uma opcao: ", 0, 6);

        switch (opcao)
        {
            case 1:
                tela_cadastrar_produto();
                break;

            case 2:
                tela_cadastrar_pessoa();
                break;

            case 3:
                tela_registrar_doacao();
                break;

            case 4:
                tela_ver_produtos();
                break;

            case 5:
                tela_ver_pessoas();
                break;

            case 6:
                tela_ver_doacoes();
                break;
        }

    } while (opcao != 0);

    printf("\nFim da execucao!\n");
    return 0;
}
