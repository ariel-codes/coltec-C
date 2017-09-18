#include <stdio.h>
#include <string.h>

FILE *output;

void depositos(int iter, int n)
{
    int j = 0, z = 0, i = n - 1;
    int out[n];
    for (; n > 0; n--)
    {
        int dj, dz;
        scanf("%d %d", &dj, &dz);
        if (dj < 0 || dz < 0)
            out[n - 1] = -1;
        else
        {
            j += dj;
            z += dz;
            out[n - 1] = j - z;
        }
    }
    fprintf(output, "Teste %d\n", iter);
    for (; i >= 0; i--)
    {
        if (out[i] == -1)
            fprintf(output, "Vovo Vitoria nao tira dinheiro dos cofrinhos.\n");
        else
            fprintf(output, "%d\n", out[i]);
    }
}

int main()
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
