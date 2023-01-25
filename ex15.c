#include <stdio.h>

int main(int argc, char *argv[]) {
    int currentYear, birthYear;
    char name[41];
    FILE *in, *out;

    // Recebe o ano corrente como argumento
    if (argc < 2) {
        printf("Ano corrente não informado\n");
        return 1;
    }
    currentYear = atoi(argv[1]);

    // Verifica se os arquivos de entrada e saída foram informados
    if (argc < 4) {
        printf("Arquivos de entrada e saída não informados\n");
        return 1;
    }

    // Abre os arquivos de entrada e saída
    in = fopen(argv[2], "r");
    out = fopen(argv[3], "w");
    if (!in || !out) {
        printf("Erro ao abrir os arquivos\n");
        return 1;
    }

    // Lê o arquivo de entrada e escreve no arquivo de saída
    while (fscanf(in, "%40s %d", name, &birthYear) == 2) {
        int age = currentYear - birthYear;
        if (age < 18) {
            fprintf(out, "%s menor de idade\n", name);
        } else if (age == 18) {
            fprintf(out, "%s entrando na maior idade\n", name);
        } else {
            fprintf(out, "%s maior de idade\n", name);
        }
    }

    // Fecha os arquivos
    fclose(in);
    fclose(out);

    return 0;
}
