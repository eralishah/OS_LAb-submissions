/* Referenced with varsha teckchandani and juhi maheshwari */


#include <stdio.h>

 
int main()
{
	int safeState=0;
	int iCnt = 0;
	int i, j, flag, r_id, p_id;


    printf("\nEnter the number of processes: ");
    scanf("%d", &p_id);
    printf("\nEnter the number of resources: ");
    scanf("%d", &r_id);
 
    int ProcessDone[p_id];
    int tempAlloc[p_id][r_id],claim[p_id][r_id], available[r_id];
    int alloc[r_id];
    int resource[r_id]; 
    
    for (i = 0; i < p_id; i++) {
        ProcessDone[i] = 1;
        iCnt++;
    }    
    for(i=0;i<r_id;i++)
    {
    	alloc[i]=0;
    }
    for (i = 0; i < r_id; i++) { 
        printf("\nEnter the resource for instance %d: ", i);
        scanf("%d", &resource[i]);
    }
 
    printf("\nEnter claim resource table:\n");
    for (i = 0; i < p_id; i++) {
        for(j = 0; j < r_id; j++) {
            scanf("%d", &claim[i][j]);
        }
    }
 
    printf("\nEnter allocated resource table:\n");
    for (i = 0; i < p_id; i++) {
        for(j = 0; j < r_id; j++) {
            scanf("%d", &tempAlloc[i][j]);
        }
    }
 
    for (i = 0; i < p_id; i++) {
        for (j = 0; j < r_id; j++) {
            alloc[j] += tempAlloc[i][j];
        }
    }
 
    
    for (i = 0; i < r_id; i++) {
        available[i] = resource[i] - alloc[i];
    }
 
    printf("\nAvailable vector:");
    for (i = 0; i < r_id; i++) {
        printf("\t%d", available[i]);
    }
    printf("\n");
 
    while (iCnt != 0) {
        safeState = 0;
        for (i = 0; i < p_id; i++) {
            if (ProcessDone[i]) {
                flag = 1;
                for (j = 0; j < r_id; j++) {
                    if (claim[i][j] - tempAlloc[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    printf("\nProcess%d is executing\n", i + 1);
                    ProcessDone[i] = 0;
                    iCnt--;
                    safeState = 1;
 
                    for (j = 0; j < r_id; j++) {
                        available[j] += tempAlloc[i][j];
                    }
 
                    break;
                }
            }
        }
        if (!safeState) {
            printf("\nUnsafe state\n");
            break;
        } else {
            printf("\nSafe state");
            printf("\nAvailable vector: ");
 
            for (i = 0; i < r_id; i++) {
                printf("\t%d", available[i]);
            }
 
            printf("\n");
        }
    }
}

