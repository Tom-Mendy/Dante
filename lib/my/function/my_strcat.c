/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** return char
*/

char *my_strcat(char *dest, char const *src)
{
    int count;
    int count2;

    count = 0;
    count2 = 0;
    while (dest[count] != '\0') {
        count += 1;
    }
    while (src[count2] != '\0') {
        dest[count] = src[count2];
        count += 1;
        count2 += 1;
    }
    return (dest);
}
