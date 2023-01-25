#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <arquivo> <caractere>\n", argv[0]);
        return 1;
    }
    
    char *filename = argv[1];
    char target = argv[2][0];
    int count = 0;
    
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return 1;
    }
    
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == target) {
            count++;
        }
    }
    
    printf("O caractere '%c' ocorre %d vezes no arquivo %s\n", target, count, filename);
    
    fclose(fp);
    return 0;
}
