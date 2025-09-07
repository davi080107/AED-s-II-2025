// Aluno: Davi Martins; Matr�cula: 885013

#include <stdio.h>

// Converte letra mai�scula para min�scula
char min(char letra) {
    if (letra >= 'A' && letra <= 'Z') {
        return letra + 32;
    }
    return letra;
}

// Retorna true se a string representar um n�mero inteiro
int numeroInteiro(char txt[]) {
    for (int j = 0; txt[j] != '\0'; j++) {
        if (txt[j] < '0' || txt[j] > '9') {
            return 0;
        }
    }
    return 1;
}

// Retorna true se a string for formada apenas por consoantes
int soConsoantes(char txt[]) {
    for (int j = 0; txt[j] != '\0'; j++) {
        char ch = min(txt[j]);
        if (!((ch >= 'a' && ch <= 'z'))) {
            return 0; // n�o � letra
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return 0; // � vogal
        }
    }
    return 1;
}

// Retorna true se a string representar um n�mero real (pode ter no m�x. 1 ponto ou v�rgula)
int numeroReal(char txt[]) {
    int separador = 0;
    for (int j = 0; txt[j] != '\0'; j++) {
        char ch = txt[j];
        if ((ch < '0' || ch > '9') && ch != '.' && ch != ',') {
            return 0;
        }
        if (ch == '.' || ch == ',') {
            separador++;
        }
    }
    if (separador > 1) {
        return 0;
    }
    return 1;
}
// Retorna true se a string for formada apenas por vogais
int soVogais(char txt[]) {
    for (int j = 0; txt[j] != '\0'; j++) {
        char ch = min(txt[j]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            return 0;
        }
    }
    return 1;
}


int main() {
    char palavra[1000];
    scanf("%[^\n]", palavra);
    getchar();

    while (!(palavra[0] == 'F' && palavra[1] == 'I' && palavra[2] == 'M' && palavra[3] == '\0')) {
        if (soVogais(palavra)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        }

        if (soConsoantes(palavra)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        }

        if (numeroInteiro(palavra)) {
            printf("SIM ");
        } else {
            printf("NAO ");
        }

        if (numeroReal(palavra)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        scanf("%[^\n]", palavra);
        getchar();
    }
}
