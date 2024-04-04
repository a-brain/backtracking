// Generate all binary strings of length N
// Binary strings are represented as arrays of characters ('0' and '1')
// ---------------------------------------------------
// Author: Mihai Oltean
// https://mihaioltean.github.io
// ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// ---------------------------------------------------
void backtracking(
    char *current_sol, 
    int current_pos, 
    int solution_length
    )
{
    if (current_pos == solution_length){
        // store or print current solution
        for (int i = 0; i < solution_length; i++)
            printf("%c", current_sol[i]);
        printf("\n");
    }
    else{
        current_sol[current_pos] = '0';
        backtracking(current_sol, current_pos+1, solution_length);
        current_sol[current_pos] = '1';
        backtracking(current_sol, current_pos+1, solution_length);
    }
}
// ---------------------------------------------------
int main(void)
{
    int N;
    printf("N=");
    scanf("%d", &N);
    char *current_sol = (char*)malloc(N) ;

    backtracking(current_sol, 0, N);

    free(current_sol);

    return 0;
}
// ---------------------------------------------------
