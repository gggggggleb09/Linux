#include <stdio.h>
#include <string.h>

int main(){
char input[100];
fgets(input,100, stdin);
while(	 )
input[strlen(input)-1]= '\0';

printf("%s: command not found\n", input);

return 0;
}
