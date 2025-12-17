#include <stdio.h>
#include <string.h>
#include <malloc.h>

const char* nloption = "-n";

int main(int argc, const char* argv[]){
    if (argc <= 1 || (argc == 2 && strcmp(argv[1], nloption) == 0))
    {
        char **inputargs = malloc(sizeof(char*) * 100);
        int inputargc = 0;
        for(int i = 0; i < 100; i++){
            printf("InputObject[%d]: ", i);
            char* input = malloc(sizeof(char*));
            fgets(input, 10, stdin);
            if(strcmp(input, "\n") == 0)
            {
                break;
            } else{
                inputargs[i] = input;
                inputargc++;
            }
            
        }

        for (int i = 0; i < inputargc; i++)
        {
            inputargs[i][strcspn(inputargs[i], "\n\r")] = '\0';
            printf("%s", inputargs[i]);
            if(i != inputargc - 1){
            printf(" ");
            }
        }
        free(inputargs);
    }
    else{
    int disableNewLine = strcmp(argv[1], nloption);
    for(int i = disableNewLine != 0 ? 1 : 2; i < argc; i++){
        printf("%s", argv[i]);
        if(i != argc - 1){
            printf(" ");
        }
    }
    if (disableNewLine != 0)
    {
        printf("\n");
    }
}
}