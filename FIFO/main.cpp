#include<stdio.h>
int main()
{
    int a,b,n,i[50],frame[10],no,c,usage,count=0;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    printf("\nEnter page reference string:\n");
    for(a=1;a<=n;a++)
        scanf("%d",&i[a]);
        printf("\nEnter the number of page frames: ");
        scanf("%d",&no);
    for(a=0;a<no;a++)
        frame[a]= -1;
        b=0;
        printf("\tReference String\t Page Frames\n");
    for(a=1;a<=n;a++)
    {
        printf("%d\t\t",i[a]);
        usage=0;
        for(c=0;c<no;c++)
            if(frame[c]==i[a])
                usage=1;
            if (usage==0)
            {
                frame[b]=i[a];
                b=(b+1)%no;
                count++;
                for(c=0;c<no;c++)
                    printf("%d\t",frame[c]);
            }
            printf("\n");
    }
    printf("Total Page Fault: %d",count);
    return 0;
}
