// Problem URL: https://zerojudge.tw/ShowProblem?problemid=a349

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){

    int Memory[8], Register[8] ;
    int i;
    for(i=0;i<8;i++)
    {
        Memory[i] = 0 ;
        Register[i] = 0 ;
    }

    printf("Input the initial values of each memory(total:8):\n") ;
    
    for(i=0;i<8;i++)
    {
        printf("Memory %d: ",i+1) ;
        scanf("%d",&Memory[i]) ;
    }
    
    int comNum ;
    printf("\nEnter the amount of commands: ") ;
    scanf("%d",&comNum) ;

    printf("Enter the commands to execute:\n") ;

    char command[15] ;
    int RS, RS1, RS2 ; // register source
    int RD ; // register destination
    int MS ; // memory source
    int MD ; // memory destination

    for(i=1;i<=comNum;i++)
    {
        printf("command %d: ",i) ;
        scanf("%s",command) ;
        
        if(0==strcmp(command,"LOAD"))
        {
            scanf("%d %d",&RD,&MS) ;
            Register[RD] = Memory[MS] ;
        }
        else if(0==strcmp(command,"STORE"))
        {
            scanf("%d %d",&MD,&RS) ;
            Memory[MD] =  Register[RS] ;
        }
        else if(0==strcmp(command,"ADD"))
        {
            scanf("%d %d %d",&RD,&RS1,&RS2) ;
            Register[RD] = Register[RS1] + Register[RS2] ;
        }
        else if(0==strcmp(command,"MOVE"))
        {
            scanf("%d %d",&RD,&RS) ;
            Register[RD] = Register[RS] ;
        }
        else
        printf("This command is not exist.\n") ;

    }

    printf("\nThe first(number:0) register's value: %d",Register[0]) ;
    printf("\nThe first(number:0) memory's value: %d",Memory[0]) ;
    

    printf("\n\n") ;
    system("pause") ;
    return 0 ;
}