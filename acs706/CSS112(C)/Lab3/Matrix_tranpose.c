#include <stdio.h>
int main(){
    int i, j, R, C, temp; //ประกาศตัวแปร
    scanf("%d %d",&R,&C); //รับค่ามิติ
    int matrix[R][C]; //ประกาศmatrixจากมิติที่รับมา
    for (i = 0; i < R; i++) //ลูปรับค่าของmatrix_A
    {
        for(j = 0;j < C; j++){
            scanf("%d",&matrix[i][j]);
        }
    }

    for (j = 0; j < C; j++)
    {
        for(i = 0; i < R; i++){
            printf("%d  ",matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}