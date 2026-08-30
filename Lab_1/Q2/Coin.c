#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int fairHeads = 0, fairTails = 0;
    int biasedHeads = 0, biasedTails = 0;
    double pHead;

    printf("Enter number of tosses: ");
    scanf("%d", &n);

    srand(time(NULL));

    // Fair Coin Simulation
    for(i = 0; i < n; i++)
    {
        if(rand() % 2 == 0)
            fairHeads++;
        else
            fairTails++;
    }

    // Biased Coin Simulation (70% Head)
    for(i = 0; i < n; i++)
    {
        pHead = (double)rand() / RAND_MAX;

        if(pHead < 0.7)
            biasedHeads++;
        else
            biasedTails++;
    }

    printf("\n--- Fair Coin ---\n");
    printf("Heads = %d\n", fairHeads);
    printf("Tails = %d\n", fairTails);
    printf("Probability of Head = %.4f\n",
           (double)fairHeads / n);

    printf("\n--- Biased Coin (70%% Head) ---\n");
    printf("Heads = %d\n", biasedHeads);
    printf("Tails = %d\n", biasedTails);
    printf("Probability of Head = %.4f\n",
           (double)biasedHeads / n);

    return 0;
}