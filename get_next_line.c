/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get next line of a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int my_putstr(char const *str);

void first_chara(int fd, char *chara)
{
    static char *save_res = NULL;
    static int len = 0;
    char *res = malloc(READ_SIZE + 1);

    if (len == 0) {
        len = read(fd, res, READ_SIZE);
        save_res = res;
        if (save_res[1] == '\0' || save_res[0] == '\0') {
            *chara = save_res[0];
            save_res++;
            len--;
            return;
        }
    }
    if (len == 0)
        return;
    *chara = save_res[0];
    save_res++;
    len--;
}

char *get_next_line(int fd)
{
    char *res = malloc(READ_SIZE + 1);
    char chara = 0;
    int i = 0;

    if (res == NULL)
        return NULL;
    first_chara(fd, &chara);
    if (fd == -1 || chara == 0)
        return NULL;
    for (; chara != '\n' && chara != '\0'; i++) {
        res[i] = chara;
        first_chara(fd, &chara);
    }
    res[i] = '\0';
    return (res);
}
