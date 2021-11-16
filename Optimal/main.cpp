#include<stdio.h>

int main()
{
    int numOfFrames, numOfPages, frames[10], pages[30], temp[10], f1, f2, f3, a, b, c, position, max, faults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numOfFrames);
    printf("Enter the number of pages: ");
    scanf("%d", &numOfPages);
    printf("Enter the page reference string: ");
    for(i = 0; a < numOfPages; ++a){
        scanf("%d", &pages[a]);
    }
    for(a = 0; a < numOfFrames; ++a){
        frames[a] = -1;
    }
    for(a = 0; a < numOfPages; ++a){
        f1 = f2 = 0;
        for(b = 0; b < numOfFrames; ++b){
            if(frames[b] == pages[a]){
                f1 = f2 = 1;
                break;
            }
        }
  
        if(f1 == 0){
            for(b = 0; b < numOfFrames; ++b){
                if(frames[b] == -1){
                    faults++;
                    frames[b] = pages[a];
                    f2 = 1;
                    break;
                }
            }   
        }
        if(f2 == 0){
            f3 =0;
            for(b = 0; b < numOfFrames; ++b){
                temp[j] = -1;
                for(c = a + 1; c < numOfPages; ++c){
                        if(frames[b] == pages[c]){
                                temp[b] = c;
                                break;
                        }
                }
            }
            for(b = 0; b < numOfFrames; ++b){
                if(temp[b] == -1){
                    position = b;
                    f3 = 1;
                    break;
                }
            }
            if(f3 ==0){
                max = temp[0];
                position = 0;
                for(b = 1; b < numOfFrames; ++b){
                    if(temp[b] > max){
                        max = temp[j];
                        position = b;
                    }
                    }
            }
        frames[position] = pages[a];
        faults++;
    }
    printf("\n");
    for(b = 0; b < numOfFrames; ++b){
        printf("%d\t", frames[b]);
    }
    }
printf("\n\nTotal Page Faults = %d", faults);
return 0;
}
