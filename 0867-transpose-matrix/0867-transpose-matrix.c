/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = matrixColSize[0];
    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));
    int** res = malloc(n * sizeof(int*));
    for (int j = 0; j < n; j++) {
        (*returnColumnSizes)[j] = m;
        res[j] = malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            res[j][i] = matrix[i][j];
    }
    return res;
}