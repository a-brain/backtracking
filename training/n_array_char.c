// Generate all strings of length N over a given alphabet
// ---------------------------------------------------
// Author: Mihai Oltean
// https://mihaioltean.github.io
// ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// ---------------------------------------------------
void backtracking(
    int solution_length,
    char* values,
    int values_count,
    char *current_sol, 
    int current_pos,
    FILE *f,
    int *count_solutions
)
{
    if (current_pos == solution_length){
        // store or print current solution
        if (f){// print to file
            for (int i = 0; i < solution_length; i++)
                fprintf(f, "%c", current_sol[i]);
            printf(f, "\n");
        }
        else{ // print to console
            for (int i = 0; i < solution_length; i++)
                printf("%c", current_sol[i]);
            printf("\n");
        }
        (*count_solutions)++;
    }
    else{
        for (int i = 0; i < values_count; i++){
            current_sol[current_pos] = values[i];
            backtracking(
                solution_length, 
                values, values_count, 
                current_sol, current_pos + 1,
                f, 
                count_solutions
                );
        }
    }
}
// ---------------------------------------------------
int main(void)
{
    int alphabet_size = 3;
    char* alphabet = (char*)malloc(alphabet_size);
    alphabet[0] = '0';
    alphabet[1] = '1';
    alphabet[2] = '2';

    int N;

    printf("N=");
    scanf("%d", &N);
    char *current_sol = (char*)malloc(N) ;
    int count_solutions = 0;

    FILE*f = NULL; // do not print to file

    backtracking(
        N,
        alphabet, alphabet_size, 
        current_sol, 0, 
        f, 
        &count_solutions
        );

    free(current_sol);
    free(alphabet);

    printf("Num solutions = %d", count_solutions);

    if (f)
        fclose(f);
}
// ---------------------------------------------------
