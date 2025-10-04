
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>

void debug(char *line){
printf("%s\n", line);
}


int main(){
char *input;

while(1){
input = readline("$ ");

if(input == NULL||*input == '\0'){
free(input);
break;
}

if(!strcmp(input, "\\q")){
break;
} else if(strncmp(input, "debug ", 6) == 0){
debug(input);
}else{
printf("%s: command not found\n", input);
}
free(input);
}

return 0;

}

