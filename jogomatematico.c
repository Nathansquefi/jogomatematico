#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dificuldade; // variável feita para dar a dificuldade do jogo do 1 ao 4
    int valor1;      // variável estilo num1
    int valor2;      // variável estilo num2
    int operacao;    // responsável por fazer a operação
    int resultado;   // resultado da operação feita

} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);
int dividir(int resposta, Calcular calc);

int score = 0;

int main()
{
    // deve ser chamado só 1 vez
    srand(time(NULL));

    jogar();

    return 0;
}

void jogar()
{
    int pontos = 0;
    Calcular calc;
    int dificuldade;
    printf("informe o nivel de dificuldade [1,2,3 ou 4]:\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;

    calc.operacao = rand() % 3;

    if (calc.dificuldade == 1)
    {
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }
    else if (calc.dificuldade == 2)
    {
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }
    else if (calc.dificuldade == 3)
    {
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }
    else if (calc.dificuldade == 4)
    {
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    }
    else
    {
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }

    int resposta;
    printf("informe o resultado para o resultado da seguinte operacao: \n");

    if (calc.operacao == 0)
    {
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if (somar(resposta, calc))
        {
            pontos += 1;
            printf("Você tem %d ponto(s).\n", pontos);
        }
    }
    else if (calc.operacao == 1)
    {
        printf("%d - %d", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if (diminuir(resposta, calc))
        {
            pontos += 1;
            printf("Você tem %d ponto(s).\n", pontos);
        }
    }
    else if (calc.operacao == 2)
    {
        printf("%d * %d", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if (multiplicar(resposta, calc))
        {
            pontos += 1;
            printf("Você tem %d ponto(s).\n", pontos);
        }
    }
    else if (calc.operacao == 3)
    {
        printf("%d / %d", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if (dividir(resposta, calc))
        {
            pontos += 1;
            printf("Você tem %d ponto(s).\n", pontos);
        }
    }
    else
    {
        printf("Operação não reconhecida\n");
    }

    printf("Deseja continuar jogando? [1 - sim, 0 - não]\n");
    int continuar;
    scanf("%d", &continuar);

    if (continuar)
    {
        jogar();
    }
    else
    {
        printf("Voce finalizou com %d ponto(s).\n", pontos);
    }
}

void mostrarInfo(Calcular calc)
{
    char op[25];
    if (calc.operacao == 0) // 0 = somar
    {
        sprintf(op, "Somar");
    }
    else if (calc.operacao == 1) // 1 == diminuir
    {
        sprintf(op, "Diminuir");
    }
    else if (calc.operacao == 2) // 2 == multiplicar
    {
        sprintf(op, "Multiplicar");
    }
    else if (calc.operacao == 3)
    {
        sprintf(op, "Divisão");
    }
    else
    {
        sprintf(op, "Operacao desconhecida");
    }

    printf("Valor 1: %d\n Valor 2:%d \nDificuldade: %d \n Operacao %s", calc.valor1, calc.valor2, calc.dificuldade, op);
}

int somar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // se 0 == errou, 1 == acertou
    if (resposta == calc.resultado)
    {
        printf("Acertou mizeravi!\n");
        certo = 1;
    }
    else
    {
        printf("Errou!\n");
    }
    printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int diminuir(int resposta, Calcular calc)
{
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // se 0 == errou, 1 == acertou
    if (resposta == calc.resultado)
    {
        printf("Acertou mizeravi!\n");
        certo = 1;
    }
    else
    {
        printf("Errou!\n");
    }
    printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicar(int resposta, Calcular calc)
{
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // se 0 == errou, 1 == acertou
    if (resposta == calc.resultado)
    {
        printf("Acertou mizeravi!\n");
        certo = 1;
    }
    else
    {
        printf("Errou!\n");
    }
    printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int dividir(int resposta, Calcular calc)
{
    int resultado = calc.valor1 / calc.valor2;
    calc.resultado = resultado;
    int certo = 0; // se 0 == errou, 1 == acertou
    if (resposta == calc.resultado)
    {
        printf("Acertou mizeravi!\n");
        certo = 1;
    }
    else
    {
        printf("Errou!\n");
    }
    printf("%d / %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}
