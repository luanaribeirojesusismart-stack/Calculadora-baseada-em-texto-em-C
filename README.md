Calculadora Baseada em Texto em C para o projeto da NEPS ACADEMY

Calculadora de terminal escrita em C. O programa exibe um menu, o usuário escolhe uma operação matemática, informa dois números e recebe o resultado na hora. Projeto de prática dos fundamentos da linguagem C: entrada e saída, condicionais, laços, funções e validação de dados.

Funcionalidades
Menu interativo com cinco opções: adição, subtração, multiplicação, divisão e sair.
Validação da opção do menu: só aceita inteiros de 1 a 5; letras e valores fora do intervalo geram erro e a pergunta é repetida.
Aceita números inteiros e decimais (aceita também vírgula como separador decimal, por exemplo 2,5).
Validação dos números digitados: entradas inválidas geram erro e são pedidas novamente.
Tratamento de divisão por zero com mensagem de erro.
Loop de múltiplas operações: após cada cálculo, pergunta se o usuário quer continuar (s ou n, maiúsculo ou minúsculo).
Mensagem de despedida ao sair.
Estrutura do projeto
.
├── main.c      # Código-fonte completo do programa
└── README.md   # Este arquivo
