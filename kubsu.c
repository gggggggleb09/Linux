  GNU nano 7.2                                                                                                        kubsu.c                                                                                                                 
#define FUSE_USE_VERSION 31
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>

#define HISTORY_FILE ".kubsh_history"
sig_atomic_t signal_received = 0;

void echo(char *line) {
        printf("%s\n", line);
}

void sig_handler(int signum) {
        signal_received = signum;
        printf("Configuration reloaded");
}

void disk_info(char* device) {
        printf("Disk information for %s: \n", device);

        char command[256];
        snprintf(command, sizeof(command), "sudo fdisk -l %s 2>/dev/null", device);

        int result = system(command);

        if (result != 0) {
                printf("Error: Can not get disk information for %s\n", device);
                printf("Try running with sudo or check device name\n");
        }
}

void print_env(char* var_name) {
        char* value = getenv(var_name);
        if (value == NULL) {
                printf("Env variable %s not found\n", var_name);
                return;
        }

        printf("Env variable %s\n", var_name);

        char* copy = strdup(value);
        if (copy == NULL) {
                printf("Memory allocation error\n");
                                                                                        [ line  34/140 (24%), col  1/ 1 (100%), char  712/2973 (23%) ]
^G Справка        ^O Записать       ^W Поиск          ^K Вырезать       ^T Выполнить      ^C Позиция        M-U Отмена        M-A Установить метM-] На скобку     M-Q Предыдущий    ^B Назад          ^◂ ПредСлово      ^A Начало
^X Выход          ^R ЧитФайл        ^\ Замена         ^U Вставить       ^J Выровнять      ^/ К строке       M-E Повтор        M-6 Копировать    ^Q Обр. поиск     M-W Следующий     ^F Вперёд         ^▸ СледСлово      ^E Конец
