//
// Created by cowba on 2024/10/22.
//

#include <stdio.h>
int main(void) {
    int n, m, i, j;
    scanf("%d %d\n", &n, &m);
    int A[n][m], B[n+2][m+2];
    int s1[(m * n) / 2][2], s2[(m * n) / 2][2];

    for(int I = 0; I < (m*n)/2; I++) {
        for(int J = 0; J < 2; J++) {
            s1[I][J] = 0;
            s2[I][J] = 0;
        }
    }

    for(int I = 0; I < n; I++) {
        for(int J = 0; J < m; J++) {
            scanf(" %d", &A[I][J]);
        }
    }

    for(int I = 0; I < n + 2; I++) {
        for(int J = 0; J < m + 2; J++) {
            B[I][J] = 0;
        }
    }

    for( i = 1; i < n + 1; i++) {
        for( j = 1; j < m + 1; j++) {
            B[i][j] = A[i-1][j-1];
            int x = B[i][j] - 1;
            if (s1[x][0] != 0 || s1[x][1] != 0) {
                s2[x][0] = i;
                s2[x][1] = j;
            }else {
                s1[x][0] = i;
                s1[x][1] = j;
            }
        }
    }

    int k = 1;
    while(k <= (n*m)/2) {
        int C[4] ={0}, D[4] ={0};
        i = s1[k-1][0], j = s1[k-1][1];
            for(int l = i-1; l >= 0; l--) {
                if(B[l][j] != 0) {
                    C[0] = 1;
                    break;
                }
            }
            for(int l = i+1; l <= n + 1; l++) {
                if(B[l][j] != 0) {
                    C[1] = 1;
                    break;
                }
            }
            for(int l = j-1; l >= 0; l--) {
                if(B[i][l] != 0) {
                    C[2] = 1;
                    break;
                }
            }
            for(int l = j+1; l <= m + 1; l++) {
                if(B[i][l] != 0) {
                    C[3] = 1;
                    break;
                }
            }

        i = s2[k-1][0], j = s2[k-1][1];
            for(int l = i-1; l >= 0; l--) {
                        if(B[l][j] != 0) {
                            D[0] = 1;
                            break;
                        }
                    }
            for(int l = i+1; l <= n + 1; l++) {
                        if(B[l][j] != 0) {
                            D[1] = 1;
                            break;
                        }
                    }
            for(int l = j-1; l >= 0; l--) {
                        if(B[i][l] != 0) {
                            D[2] = 1;
                            break;
                        }
                    }
            for(int l = j+1; l <= m + 1; l++) {
                        if(B[i][l] != 0) {
                            D[3] = 1;
                            break;
                        }
                    }

        for(int l = 0; l < 4; l++) {
            if(C[l] == 0 && D[l] == 0) {
                printf("%d ", k);
                B[s1[k-1][0]][s1[k-1][1]] = 0;
                B[s2[k-1][0]][s2[k-1][1]] = 0;
                break;
            }
        }
        k++;
    }
    return 0;
}