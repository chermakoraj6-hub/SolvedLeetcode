/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int minrow = 0, maxrow = matrixSize - 1;
    int mincol = 0, maxcol = matrixColSize[0] - 1;

    int totalelement = matrixSize * matrixColSize[0];
    int* spiral = (int*)malloc(sizeof(int) * totalelement);
    int count = 0;

    while (count<totalelement) {
        for (int i = mincol; i <= maxcol; i++)
            spiral[count++] = matrix[minrow][i];
        minrow++;

        for (int j = minrow; j <= maxrow; j++)
            spiral[count++] = matrix[j][maxcol];
        maxcol--;

        if (minrow <= maxrow) {
            for (int k = maxcol; k >= mincol; k--)
                spiral[count++] = matrix[maxrow][k];
            maxrow--;
        }

        if (mincol <= maxcol) {
            for (int l = maxrow; l >=minrow ; l--)
                spiral[count++] = matrix[l][mincol];
            mincol++;
        }
    }

    *returnSize = count;
    return spiral;
}
