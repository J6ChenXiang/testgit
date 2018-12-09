#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int m_col = 5;
    int m_row = 3;
    int **m_array = (int **)malloc(sizeof(int*)*m_row);

    for(int i=0;i<m_row;i++)
    {
         m_array[i] = (int *)malloc(sizeof(int)*m_col);
         //*m_array = &(**m_array)+sizeof(int*)*(m_col-1);
    }
    printf("\n");
    
    int *p = &(**m_array);

    for(int i=0;i<m_row;i++)
    {
        printf("%p ,", p);
        p = p+sizeof(int *)+1;
    }
    printf("\n");


    for(int i=0;i<m_row;i++)
    {
        printf("%p ,", &(**m_array)+(i+1)*sizeof(int *));
    }
    printf("\n");

    for(int i=0;i<m_row;i++)
    {
        for(int j=0;j<m_col;j++)
        {
            m_array[i][j] = i+j;
            printf("%p, ", &(*(*(m_array+i)+j)));
        }
        printf("\n");
    }

    for(int i=0;i<m_row;i++)
    {
        for(int j=0;j<m_col;j++)
        {
            printf("%d, ", *(*(m_array+i)+j));
        }
        printf("\n");
    }
    
    return 0;
}

