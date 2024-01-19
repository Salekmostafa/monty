#include "monty.h"

int main(int argc, char *argv[])
{
    // ... (unchanged part)

    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        execute_opcode(line, &stack, line_number);
    }

    fclose(file);
    free(line);
    free_stack(stack);

    return EXIT_SUCCESS;
}

