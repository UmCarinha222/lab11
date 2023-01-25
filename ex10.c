#include <stdio.h>
#include <string.h>

struct City {
    char name[41];
    int population;
} mostPopulous;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        printf("Error: could not open input file %s\n", argv[1]);
        return 1;
    }

    mostPopulous.population = 0;
    char line[80];
    while (fgets(line, sizeof(line), input)) {
        struct City city;
        sscanf(line, "%40s %d", city.name, &city.population);
        if (city.population > mostPopulous.population) {
            strcpy(mostPopulous.name, city.name);
            mostPopulous.population = city.population;
        }
    }
    fclose(input);

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        printf("Error: could not open output file %s\n", argv[2]);
        return 1;
    }

    fprintf(output, "City: %s\nPopulation: %d\n", mostPopulous.name, mostPopulous.population);
    fclose(output);

    return 0;
}
