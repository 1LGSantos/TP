#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

// Inverte a string e escreve o resultado em resp
void inverterString(char s[], char resp[]) {
    int tamanho = 0;
    while (s[tamanho] != '\0') {
        tamanho++;
    }
    int i;
    for (i = 0; i < tamanho; i++) {
        resp[i] = s[tamanho - 1 - i];
    }
    resp[tamanho] = '\0';
}

int main(void) {
    char linha[TAM];
    char invertida[TAM];
    while (fgets(linha, TAM, stdin) != NULL) {
        int len = 0;
        while (linha[len] != '\0') {
            len++;
        }
        if (len > 0 && linha[len - 1] == '\n') {
            linha[len - 1] = '\0';
        }
        inverterString(linha, invertida);
        printf("%s\n", invertida);
    }
    return 0;
}
