#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30
#define FNAME "elenco.csv"

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    studente elenco[N];
    int i, controllo;
    FILE *puntaFile;
    
    puntaFile = fopen(FNAME, "w");
    if(puntaFile == NULL) {
        fprintf(stderr,"Errore nell'apertura del file %s\n", FNAME);
        exit(1);
    }
    else {
        printf("File %s creato correttamente\n", FNAME);
    }
    fprintf(puntaFile, "nome;cognome;eta';classe\n");
    for(i = 0; i < N; i++) {
        printf("Inserisci il nome dello studente %d : ", i);
        scanf("%s", elenco[i].nome);
        printf("Inserisci il cognome dello studente %d : ", i);
        scanf("%s", elenco[i].cognome);
        printf("Inserisci l'eta' dello studente %d : ", i);
        scanf("%d", &(elenco[i].eta));
        printf("Inserisci la classe dello studente %d : ", i);
        scanf("%s", elenco[i].classe); 
        controllo = fprintf(puntaFile, "%s;%s;%d;%s\n", elenco[i].nome, elenco[i].cognome, elenco[i].eta, elenco[i].classe);
        if(controllo < 0) {
            fprintf(stderr, "Errore di scrittura nel file\n");
            exit(2);
        }
        else {
        printf("Dato scritto\n");
        }
    }
    fclose(puntaFile);
    printf("Dati salvati in %s\n", FNAME);
    return (EXIT_SUCCESS);
}