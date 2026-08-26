#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

// Soma iterativamente os digitos de um numero inteiro (ignora o sinal)
int somaDigitos(int n) {
    if (n < 0) {
        n = -n;
    }
    int soma = 0;
    while (n > 0) {
        soma = soma + n % 10;
        n = n / 10;
    }
    return soma;
}

int main(void) {
    char linha[TAM];
    while (fgets(linha, TAM, stdin) != NULL) {
        int n = atoi(linha); // linha vazia ou nao numerica vira 0
        printf("%d\n", somaDigitos(n));
    }
    return 0;
}
