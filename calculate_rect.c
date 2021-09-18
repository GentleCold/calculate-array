#include <stdio.h>

int calculate(int n, int row, int cols[], int array[][n])
{
    int ans=0, flag=-1, offset=0, ifexpand=0, k;

    if(row==n)
        return 1;

    for(k=0; k<n; k++)
    {
        flag = -flag;

        while(cols[k]==0)
        {
            k++;
            if(ifexpand==1)
                offset++;
            if(k==n)
            {
                if (ifexpand==1)
                    cols[k-offset-1]=1;
                return ans;
            }

        }

        if(k!=0&&ifexpand==1)
        {
            cols[k-1-offset]=1;
            offset=0;
        }

        cols[k]=0;
        ifexpand=1;
        
        ans+=array[row][k]*calculate(n, row+1, cols, array)*flag;

    }
    if (ifexpand==1)
        cols[k-offset-1]=1;
        
    return ans;

}
int main(void)
{
    int n;
    printf("Welcome to the programme by GentleCold!\n");
    printf("--------------------------------------------------------\n");
    printf("Please enter the N(enter the 'q' at any time to quit):");

    while(scanf("%d", &n) == 1)
    { 
        int array[n][n], cols[n];
        printf("Please enter the array(by rows):\n\n");
        while(getchar()!='\n')
            continue;
        for(int i=0;i<n;i++)
        {
            cols[i]=1;
            for(int j=0;j<n;j++)
            {
                scanf("%d", &array[i][j]);
            }
        }

        while(getchar()!='\n')
            continue;

        printf("\nResult:\n%d\n", calculate(n, 0, cols, array));
        printf("----------------------------------------------------------\n");
        printf("Please enter the N(enter the 'q' at any time to quit):");
    }   
    
}