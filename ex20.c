#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_alunos;
    printf("Insira o numero de alunos: ");
    scanf("%d", &num_alunos);

    char (*nomes)[41] = malloc(num_alunos * sizeof(char[41]));
    float *notas = malloc(num_alunos * sizeof(float));

    for (int i = 0; i < num_alunos; i++) {
        printf("Insira o nome do aluno %d: ", i + 1);
        scanf("%40s", nomes[i]);
        printf("Insira a nota final do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    FILE *file = fopen("notas.txt", "w");
    for (int i = 0; i < num_alunos; i++) {
        int tam = strlen(nomes[i]);
        for (int j = tam; j < 40; j++) {
            nomes[i][j] = ' ';
        }
        nomes[i][40] = '\0';
        fprintf(file, "%s %.2f\n", nomes[i], notas[i]);
    }
    fclose(file);

    free(nomes);
    free(notas);
    return 0;
}
