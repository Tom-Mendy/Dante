/*
** EPITECH PROJECT, 2023
** file
** File description:
** file
*/

#include <sys/stat.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *file_not_valid(char const *filename)
{
    struct stat s;
    int fd = 0;
    char *buffer = NULL;
    if (lstat(filename, &s) == -1) {
        write(2, "File not found\n", 15);
        return NULL;
    }
    stat(filename, &s);
    if ((s.st_mode & __S_IFMT) != __S_IFREG)
        return NULL;
    if (s.st_size == 0)
        return NULL;
    buffer = malloc(sizeof(char) * (s.st_size + 1));
    if (buffer == NULL)
        return NULL;
    buffer[s.st_size] = '\0';
    fd = open(filename, O_RDONLY);
    read(fd, buffer, s.st_size);
    close(fd);
    return buffer;
}
