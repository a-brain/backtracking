// Generate all permutations of length N over a given set of integers
// ---------------------------------------------------
// Author: Mihai Oltean
// https://mihaioltean.github.io
// ---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
// ---------------------------------------------------
void backtracking(
    int solution_length,
    int* set,
    int set_size,
    int *current_sol, 
    int current_pos,
    FILE *f,
    int *count_solutions,
    void* extra_data
)
{
    if (current_pos == solution_length){
        // store or print current solution
        if (f){// print to file
            for (int i = 0; i < solution_length; i++)
                fprintf(f, "%d", current_sol[i]);
            fprintf(f, "\n");
        }
        else{ // print to console
            for (int i = 0; i < solution_length; i++)
                printf("%d", current_sol[i]);
            printf("\n");
        }
        (*count_solutions)++;
    }
    else{
        if (current_pos == 0){
            // allocate array to test unicity
            extra_data = malloc(solution_length);
            for (int i = 0; i < solution_length; i++)
                ((char*)extra_data)[i] = 0;
        }
        for (int i = 0; i < set_size; i++){
            if (!((char*)extra_data)[i]){
                current_sol[current_pos] = set[i];
                ((char*)extra_data)[i] = 1; // mark it used
                backtracking(
                    solution_length, 
                    set, set_size, 
                    current_sol, current_pos + 1,
                    f, 
                    count_solutions,
                    extra_data
                );
                ((char*)extra_data)[i] = 0; // unmark it
            }
        }

        if (current_pos == 0){
            free(extra_data);
        }

    }
}
// ---------------------------------------------------
int main(void)
{
    int N = 3;
    int* set = (int*)malloc(N * sizeof(int));
    set[0] = 2;
    set[1] = 3;
    set[2] = 4;

    int *current_sol = (int*)malloc(N * sizeof(int)) ;
    int count_solutions = 0;

    FILE*f = NULL; // do not print to file

    backtracking(
        N,
        set, N, 
        current_sol, 0, 
        f, 
        &count_solutions, NULL
        );

    free(current_sol);
    free(set);

    printf("Num solutions = %d", count_solutions);

    if (f)
        fclose(f);

    return 0;
}
// ---------------------------------------------------
