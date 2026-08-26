#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

// Cifra recursivamente a partir da posicao i (sem lacos, sem variaveis globais)
void cifrarCesarRec(char s[], char resp[], int i) {
    if (s[i] == '\0') {
        resp[i] = '\0';
    } else {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            resp[i] = 'a' + (c - 'a' + 3) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            resp[i] = 'A' + (c - 'A' + 3) % 26;
        } else {
            resp[i] = c;
        }
        cifrarCesarRec(s, resp, i + 1);
    }
}

// Metodo inicializador que chama a versao recursiva a partir da posicao 0
void cifrarCesar(char s[], char resp[]) {
    cifrarCesarRec(s, resp, 0);
}

int main(void) {
    char linha[TAM];
    char cifrada[TAM];
    while (fgets(linha, TAM, stdin) != NULL) {
        int len = 0;
        while (linha[len] != '\0') len++;
        if (len > 0 && linha[len - 1] == '\n') linha[len - 1] = '\0';
        cifrarCesar(linha, cifrada);
        printf("%s\n", cifrada);
    }
    return 0;
}
