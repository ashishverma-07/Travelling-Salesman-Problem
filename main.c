#include <stdio.h>
#include <limits.h>
#include <time.h>

#define SIZE 20

int minCost, maxCost, minTour[SIZE];
int c[SIZE][SIZE];
int A[SIZE];


void swap(int *a, int* b){
    int c=*a;
    *a=*b;
    *b=c;
}

void perm(int start,int n){
    int j, cost;
   if (start < (n-1))
      for (j=start; j<n; j++){
         swap(&A[j],&A[start]);
         perm(start+1,n);
         swap(&A[j], &A[start]);
      }
   else

         {
             cost=0;
             for (j = 0; j < n-1; j++){
             cost+=c[A[j]][A[j+1]];
             }
             cost+=c[A[n-1]][A[0]];


       if(cost>maxCost)
           maxCost=cost;
       if(cost<minCost){
           minCost=cost;

           for (j = 0; j < n; j++){
               minTour[j]=A[j];

           }
       }

   }

}

int main()
{
    FILE *inFile, *outFile;
    int i,j,k,l,n,problemNumber=1;
    time_t start, end;


    minCost = INT_MAX;

    maxCost = INT_MIN;

    inFile = fopen("input.txt", "r");
   outFile = fopen("out.txt", "w");

   if (inFile == NULL)
        {
            printf("Error Reading File\n");
            return 0;
        }

    if (outFile == NULL)
        {
            printf("Error Writing File\n");
            return 0;
        }

     while(!feof(inFile)){
     start = clock();
     fscanf(inFile, "%d", &n);
            for (i = 0; i < n; i++){

                A[i]=i;

                for (j = 0; j < n; j++)
                {
                    fscanf(inFile, "%d%d", &k, &l );
                    fscanf(inFile, "%d", &c[k][l] );

                }
            }

            for (i = 0; i < n; i++){
                for (j = 0; j < n; j++)
                {
                   printf("%d\t", c[i][j]);
                }
               printf("\n");
            }



    perm(0,n);

    end=clock();

    printf( "%d %d %d %d %ld\n",problemNumber, n, minCost, maxCost,  1000*(end-start)/CLOCKS_PER_SEC);
    fprintf(outFile, "%d %d %d %d %ld\n",problemNumber++, n, minCost, maxCost, 1000*(end-start)/CLOCKS_PER_SEC);



    for (i = 0; i < n; i++){
         fprintf(outFile, "%d\n", minTour[i]);
         printf( "%d\n", minTour[i]);

    }

    }
     fclose(inFile);
     fclose(outFile);

    return 0;
}
