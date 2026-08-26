#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

// Verifica se a e b sao anagramas, comparando as frequencias de cada letra em cada um
int saoAnagramas(char a[], char b[]) {
    int freq[26] = {0};
    int i = 0;
    while (a[i] != '\0') {
        char c = a[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        }
        i++;
    }
    i = 0;
    while (b[i] != '\0') {
        char c = b[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        if (c >= 'a' && c <= 'z') {
            freq[c - 'a']--;
        }
        i++;
    }
    int igual = 1;
    for (i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            igual = 0;
        }
    }
    return igual;
}

int main(void) {
    char linha1[TAM];
    char linha2[TAM];
    while (fgets(linha1, TAM, stdin) != NULL) {
        if (fgets(linha2, TAM, stdin) == NULL) {
            break;
        }
        int len1 = 0;
        while (linha1[len1] != '\0') len1++;
        if (len1 > 0 && linha1[len1 - 1] == '\n') linha1[len1 - 1] = '\0';

        int len2 = 0;
        while (linha2[len2] != '\0') len2++;
        if (len2 > 0 && linha2[len2 - 1] == '\n') linha2[len2 - 1] = '\0';

        if (saoAnagramas(linha1, linha2)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}
