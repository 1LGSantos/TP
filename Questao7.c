#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

// Calcula o comprimento da maior substring sem repeticao
int maiorSubstringSemRepeticao(char s[]) {
    int ultimaPosicao[256];
    int i;
    for (i = 0; i < 256; i++) {
        ultimaPosicao[i] = -1;
    }
    int maior = 0;
    int inicio = 0;
    int fim = 0;
    while (s[fim] != '\0') {
        unsigned char c = s[fim];
        if (ultimaPosicao[c] >= inicio) {
            inicio = ultimaPosicao[c] + 1;
        }
        ultimaPosicao[c] = fim;
        int tamanhoAtual = fim - inicio + 1;
        if (tamanhoAtual > maior) {
            maior = tamanhoAtual;
        }
        fim++;
    }
    return maior;
}

int main(void) {
    char linha[TAM];
    while (fgets(linha, TAM, stdin) != NULL) {
        int len = 0;
        while (linha[len] != '\0') len++;
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';
        printf("%d\n", maiorSubstringSemRepeticao(linha));
    }
    return 0;
}
