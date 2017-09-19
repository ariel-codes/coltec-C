#include <stdio.h>
#include <string.h>

FILE *output;

void depositos(int iter, int n)
{
    int j = 0, z = 0, i = n - 1;
    fprintf(output, "Teste %d\n", iter+1);
    for (; n > 0; n--)
    {
        int dj, dz;
        scanf("%d %d", &dj, &dz);
        if (dj < 0 || dz < 0)
            fprintf(output, "Vovo Vitoria nao tira dinheiro dos cofrinhos.\n");
        else
        {
            j += dj;
            z += dz;
            fprintf(output, "%d\n", j - z);
        }
    }
}

void main()
{
    int linhas, iter;
    output = tmpfile();
    for (iter = 0;; iter++)
    {
        scanf("%d", &linhas);
        if (linhas == 0)
            break;
        else
        {
            fprintf(output, "\n");
            depositos(iter, linhas);
        }
    }
    rewind(output);
    char buffer[100];
    while (!feof(output))
    {
        if (fgets(buffer, 50, output) == NULL)
            break;
        fputs(buffer, stdout);
    }
    fclose(output);
}
