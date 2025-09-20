#include <stdio.h>
#include <string.h>

int main(){

char input[100];

while(1){

printf("> ");
if(fgets (input,100,stdin) == NULL)
{

printf("Error\n");
break;

}
input[strcspn(input, "\n")] = '\0';

if(strcmp(input, "/q") == 0) {
printf("exiting programm...\n");
break;

}

printf("entering: %s \n",input);
}

return 0;
}
