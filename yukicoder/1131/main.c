# include <stdio.h>
# define N_MAX (100000)
int main(void)
{
    int N;
    int x[N_MAX];
    double A = 0.0;
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x[i]);
        A += x[i];
    }
    A /= N;

    for (i = 0; i < N; i++)
    {
        printf("%d\n", (int)(50 - (A - x[i]) / 2));
    }

    return 0;
}
