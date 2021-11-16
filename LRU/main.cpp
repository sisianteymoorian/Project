#include<stdio.h>

int LRU(int time[], int n){
    int a, min = time[0], position = 0;

    for(a = 1; a < n; ++a){
        if(time[a] < min){
            min = time[a];
            position = a;
        }
    }
    return position;
}
int main()
{
    int numOfFrames, numOfPages, frames[50], pages[100], counter = 0, time[30], f1, f2, a, b, position, faults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numOfFrames);
    printf("Enter the number of pages: ");
    scanf("%d", &numOfPages);
    printf("Enter page reference: \n");
    for(a = 0; a < numOfPages; ++a){
        scanf("%d", &pages[a]);
    }
    for(a = 0; a < numOfFrames; ++a){
        frames[a] = -1;
    }
    for(a = 0; a < numOfPages; ++a){
        f1 = f2 = 0;
        for(b = 0; b < numOfFrames; ++b){
            if(frames[b] == pages[a]){
            counter++;
            time[b] = counter;
            f1 = f2 = 1;
            break;
            }
        }
  
        if(f1 == 0){
            for(b = 0; b < numOfFrames; ++b){
                if(frames[b] == -1){
                    counter++;
                    faults++;
                    frames[b] = pages[a];
                    time[b] = counter;
                    f2 = 1;
                    break;
                }
            }
        }
        if(f2 == 0){
            position = LRU(time, numOfFrames);
            counter++;
            faults++;
            frames[position] = pages[a];
            time[position] = counter;
        }
        printf("\n");
        for(b = 0; b < numOfFrames; ++b){
            printf("%d\t", frames[b]);
        }
    }
  
printf("\nTotal Page Fault: %d", faults);
  
return 0;
}
