#include<stdio.h>

int main(){
    int i,n,j;
    int profit[20], weight[20], capacity;
    float ratio[20];
    float tprofit = 0, tweight = 0;

    printf("Enter no of objects:");
    scanf("%d",&n);

    printf("Enter weight and profit:");
    for(i=0;i<n;i++){
        scanf("%d%d",&weight[i],&profit[i]);
    }

    printf("Enter the bag capacity:");
    scanf("%d",&capacity);

    // Calculate ratio
    for(i=0;i<n;i++){
        ratio[i] = (float)profit[i] / weight[i];
    }

    // Sort in descending order of ratio
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[j] > ratio[i]){
                float temp;

                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Fractional Knapsack
    for(i=0;i<n;i++){
        if(capacity >= weight[i]){
            tweight += weight[i];
            capacity -= weight[i];
            tprofit += profit[i];
        }
        else if(capacity > 0){
            float fraction = (float)capacity / weight[i];
            tweight += capacity;
            tprofit += profit[i] * fraction;
            capacity = 0;
        }
    }

    printf("Total weight and profit: %.2f %.2f", tweight, tprofit);

    return 0;
}