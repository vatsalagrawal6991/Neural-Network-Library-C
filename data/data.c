/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int TRUE=1;
int FALSE=0;
int main()
{
    srand(time(0));
    printf("a");
    int i;
    for (i=0;i<100;i++){
        if (i%2){
            printf ("%lf ",(double)rand()/RAND_MAX*2);
            printf ("%lf ",(double)rand()/RAND_MAX*2);
            printf ("%d\n",TRUE);
        }
        else {
            printf ("%lf ",((double)rand()/RAND_MAX*2)+2);
            printf ("%lf ",(double)rand()/RAND_MAX*2);
            printf ("%d\n",FALSE);
        }
    }
     for (i=0;i<100;i++){
        if (i%2){
            printf ("%lf ",((double)rand()/RAND_MAX*2)+2);
            printf ("%lf ",((double)rand()/RAND_MAX*2)+2);
            printf ("%d\n",TRUE);
        }
        else {
            printf ("%lf ",(double)rand()/RAND_MAX*2);
            printf ("%lf ",((double)rand()/RAND_MAX*2)+2);
            printf ("%d\n",FALSE);
        }
    }
    
    return 0;
}
