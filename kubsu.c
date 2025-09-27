
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

char input[1000];

while(1){
fgets(input,100,stdin);
input[strlen(input) -1] ='\0';
if(strcmp(input, "\\q") == 0){
break;
}
printf("enter command to continue\n");
fgets(input, sizeof(input),stdin);
input[strcspn(input , "\n")] = 0;
if(strncmp(input, "debug ", 6) == 0){
printf("%s\n", input + 6);

printf("%s: command not found\n", input);
}
return 0;
}
