#include "monty.h"
info_t info = {NULL, NULL, NULL, 0};
/**
 * main - entry point of the program
 * @arc: count of arguments provided by user
 * @argv: array of argumbers provide by user
 * Return: 0 on success, 1 of faliur
 */
int main (int argc, char *argv[])
{
FILE *file;
char *content;
size_t len;
ssize_t read_line;
stack_t *stack;
unsigned int l_count;

stack = NULL;
content = NULL;
read_line = 0;
l_count = 0;

if (argc != 2)
{
    fprintf(stderr, "Usage: executable montyfilename\n");
    exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
info.file = file;
if (file == NULL)
{
    fprintf(stderr, "Error: File not found:\n");
    exit(EXIT_FAILURE);
}
/* start reading lines from monty file*/
while (read_line != -1)
{
    read_line = getline(&content, &len, file);
    if (ferror(file))
    {
        fprintf(stderr, "Error: error while reading file\n");
        exit(EXIT_FAILURE);
    }
    l_count++;
    info.content = content;
    if (read_line > 0)
        execute(content, &stack, l_count, file);
    /*printf("size of \tlen = %lu\tread: %ld\n", len, read_line);*/
}
free(content);
fclose(file);
return (0);
}
