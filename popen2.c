#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE *write_fp;
    char buffer[BUFSIZ + 1];

    // La cadena que vas a enviar
    sprintf(buffer, "Once upon a time, there was...\n");
    // "od -c" es un comando que va a leer lo anterior
    write_fp = popen("od -c", "w");
    // Verificas que se halla creado correctamente
    if(write_fp != NULL) {
        // Escribes en el stdin del comando "od -c"
        fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
        pclose(write_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}