#include <stdio.h>

#define LEFT -1
#define RIGHT 1

void printPermutation(int perm[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}


int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {

        
        if(dir[perm[i] - 1] == LEFT && i != 0) {
            if(perm[i] > perm[i - 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        
        if(dir[perm[i] - 1] == RIGHT && i != n - 1) {
            if(perm[i] > perm[i + 1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

void johnsonTrotter(int n) {
    int perm[n];
    int dir[n];


    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while(1) {

        int mobileIndex = getMobile(perm, dir, n);

       
        if(mobileIndex == -1)
            break;

        int mobile = perm[mobileIndex];

        
        if(dir[mobile - 1] == LEFT) {
            int temp = perm[mobileIndex];
            perm[mobileIndex] = perm[mobileIndex - 1];
            perm[mobileIndex - 1] = temp;

            mobileIndex--;
        }
        else {
            int temp = perm[mobileIndex];
            perm[mobileIndex] = perm[mobileIndex + 1];
            perm[mobileIndex + 1] = temp;

            mobileIndex++;
        }

      
        for(int i = 0; i < n; i++) {
            if(perm[i] > mobile) {
                dir[perm[i] - 1] *= -1;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}