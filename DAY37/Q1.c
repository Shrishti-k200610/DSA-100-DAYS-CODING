#include <stdio.h>

int pq[100];
int size = 0;

void insert(int x)
{
    pq[size] = x;
    size++;
}

void delete()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = 0;
    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[min])
            min = i;
    }

    printf("%d\n", pq[min]);

    for(int i = min; i < size-1; i++)
        pq[i] = pq[i+1];

    size--;
}

void peek()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    int min = pq[0];
    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
            min = pq[i];
    }

    printf("%d\n", min);
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(op[0] == 'i')
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd')
        {
            delete();
        }
        else if(op[0] == 'p')
        {
            peek();
        }
    }

    return 0;
}
