#include "main.h"
#include "readcom.h"
/*
 * readcom - Reads command from stdin
 * @buf: command buffer
 * Return: 1 if fails else 0
 */
int readcom(char **buf)
{
    ssize_t c_size = 0;
    size_t alloc_size = 512;
    char *tmpbuf = malloc(32);
    ssize_t nbc;

    if (tmpbuf == NULL) return (1);
    while(c_size < QURRY_BUF_SIZE)
    {
        nbc = getline(&tmpbuf, &alloc_size, stdin), c_size += nbc;
        if(nbc == 0) exit(1);
        tmpbuf[nbc - 1] = '\0';
        *buf = strcat(*buf, tmpbuf);
        if(tmpbuf[nbc - 2] == ENDC)
        {
            free(tmpbuf);
            return (0);
        }
    }
    return (1);
}
