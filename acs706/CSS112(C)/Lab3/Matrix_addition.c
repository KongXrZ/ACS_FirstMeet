#include <stdio.h>
int main(){
    int i, j, R, C; //ประกาศตัวแปร
    scanf("%d %d",&R,&C); //รับค่ามิติ
    int matrix_A[R][C], matrix_B[R][C], matrix_C[R][C]; //ประกาศmatrixจากมิติที่รับมา
    
    if (R >= 2 && R <= 10 && C >= 2 && C <= 10)
    {
            for (i = 0; i < R; i++) //ลูปรับค่าของmatrix_A
            {
                for(j = 0;j < C; j++){
                    scanf("%d",&matrix_A[i][j]);
                }
            }
        
            for (i = 0; i < R; i++) //ลูปรับค่าของmatrix_B
            {
                for(j = 0;j < C; j++){
                    scanf("%d",&matrix_B[i][j]);
                }
            }
        
            for (i = 0; i < R; i++) //ลูปเอาค่ามารวมกกัน
            {
                for(j = 0;j < C; j++){
                    matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
                }
            }
        
            for (i = 0; i < R; i++) //ลูปอ่านค่าในmatrix c
            {
                for(j = 0;j < C; j++){
                    printf("%d ",matrix_C[i][j]);
                }
                printf("\n");
            }
    }
    
    return 0;
}