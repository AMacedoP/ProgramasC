#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *read_fp;
    char buffer[BUFSIZ + 1];
    int chars_read;

    // Llenas el buffer de \0
    memset(buffer, '\0', sizeof(buffer));
    // Llamas a un comando y mandas el stdout a este programa
    read_fp = popen("uname -a", "r");
    // Verificas que halla sido creado correctamente
    if(read_fp != NULL) {
        // Y leemos el stdout del comando en la variable buffer
        chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
        // Si se han leído más de 0 bytes se escribe el resultado
        if(chars_read > 0) {
            printf("Output was:-\n%s\n", buffer);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}