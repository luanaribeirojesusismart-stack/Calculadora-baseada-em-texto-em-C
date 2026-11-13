#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_BUFFER 128

/* Lê uma linha da entrada padrão. Encerra o programa se a entrada acabar (EOF). */
static void ler_linha(char *buffer, size_t tamanho) {
    if (fgets(buffer, (int)tamanho, stdin) == NULL) {
        printf("\nEntrada encerrada.\n");
        exit(0);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

/* Verifica se o restante da string contém apenas espaços. */
static int so_espacos(const char *s) {
    while (*s) {
        if (!isspace((unsigned char)*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

static void exibir_menu(void) {
    printf("\n===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
}

/* Lê e valida a opção do menu (inteiro entre 1 e 5). */
static int ler_opcao(void) {
    char buffer[TAM_BUFFER];
    char *fim;
    long valor;

    while (1) {
        printf("Opção: ");
        ler_linha(buffer, sizeof(buffer));

        valor = strtol(buffer, &fim, 10);
        if (fim != buffer && so_espacos(fim) && valor >= 1 && valor <= 5) {
            return (int)valor;
        }
        printf("Opção inválida. Digite um número inteiro entre 1 e 5.\n");
    }
}

/* Lê um número (inteiro ou decimal), repetindo até a entrada ser válida. */
static double ler_numero(const char *mensagem) {
    char buffer[TAM_BUFFER];
    char *fim;
    double valor;

    while (1) {
        printf("%s", mensagem);
        ler_linha(buffer, sizeof(buffer));

        /* Aceita vírgula como separador decimal também */
        for (char *p = buffer; *p; p++) {
            if (*p == ',') {
                *p = '.';
            }
        }

        valor = strtod(buffer, &fim);
        if (fim != buffer && so_espacos(fim)) {
            return valor;
        }
        printf("Entrada inválida. Digite um número válido.\n");
    }
}

/* Pergunta se o usuário quer outra operação.
   Retorna 1 para 's'/'y' (maiúsculo ou minúsculo) e 0 para 'n'/'N'. */
static int deseja_continuar(void) {
    char buffer[TAM_BUFFER];

    while (1) {
        printf("Deseja realizar outra operação? (s/n): ");
        ler_linha(buffer, sizeof(buffer));

        if (strlen(buffer) == 1) {
            char c = (char)tolower((unsigned char)buffer[0]);
            if (c == 's' || c == 'y') return 1;
            if (c == 'n') return 0;
        }
        printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
    }
}

static void despedida(void) {
    printf("Obrigado por usar a calculadora! Até a próxima.\n");
}

int main(void) {
    while (1) {
        exibir_menu();
        int opcao = ler_opcao();

        if (opcao == 5) {
            despedida();
            return 0;
        }

        double a = ler_numero("Digite o primeiro número: ");
        double b = ler_numero("Digite o segundo número: ");
        char operador = '+';
        double resultado = 0.0;
        int erro = 0;

        switch (opcao) {
            case 1:
                operador = '+';
                resultado = a + b;
                break;
            case 2:
                operador = '-';
                resultado = a - b;
                break;
            case 3:
                operador = '*';
                resultado = a * b;
                break;
            case 4:
                operador = '/';
                if (b == 0.0) {
                    erro = 1;
                } else {
                    resultado = a / b;
                }
                break;
        }

        if (erro) {
            printf("Erro: Divisão por zero não é permitida.\n");
        } else {
            printf("Resultado: %g %c %g = %g\n", a, operador, b, resultado);
        }

        if (!deseja_continuar()) {
            despedida();
            return 0;
        }
    }
}
