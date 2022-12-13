#include <stdio.h>
struct details {
    int id;
    char name1[50],name2[50];
    int phoneno;
    int d,m,y;
    float salary;
    int cl,sl,pl;
    int totalleavescl;
    int totalleavessl;
    int totalleavespl;
};
struct clleaves{
    int number;
};
struct slleaves{
    int number;
};
struct plleaves{
    int number;
};
int main(){
    int temp=0,choice,idemp,i=1,change;
    char type;
    
    struct details s[100];
    struct clleaves cl[100];
    struct slleaves sl[100];
    struct plleaves pl[100];
    
    printf("\n\n------WELCOME TO LEAVE MANAGEMENT SYSTEM------");
    printf("\n\n----If you are a new employee, then please register yourself first----\n");
            
            
    while(temp<=0){
        
        printf("\n\n------------------HOME--------------------\n");
        printf("\n 1.Register");
        printf("\n 2.Ask for leave");
        printf("\n 3.Show details");
        printf("\n 4.Modify details");
        printf("\n 5.Exit");
        printf("\nChoose option : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:   
                for(;i<=100;){ 
                s[i].cl = 5;
                s[i].sl = 10;
                s[i].pl = 5;
                s[i].totalleavescl=0;
                s[i].totalleavessl=0;
                s[i].totalleavespl=0;

                printf("Enter ID:");
                scanf("%d",&s[i].id);
                printf("Enter Name:");
                scanf("%s%s",&s[i].name1,&s[i].name2);
                printf("Enter Phone Number:");
                scanf("%d",&s[i].phoneno);
                printf("Enter DOB in (dd mm yy) format:");
                scanf("%d%d%d",&s[i].d,&s[i].m,&s[i].y);
                printf("Enter Salary:");
                scanf("%f",&s[i].salary);
                printf("\n----------------You have successfully registered----------------\n");
                i++;
                break;
                }
                break;
        case 2:
                printf("Enter id:");
                scanf("%d",&idemp);
                for(i=1;i<=100;i++){
                       
                        if(s[i].id==idemp){
                            printf("-------------WELCOME-------------\n");
                            printf("Available CL:%d\nAvailable SL:%d\nAvailable PL:%d\n",s[i].cl,s[i].sl,s[i].pl);
                            printf("\nWhich type of leave do you want?\nEnter c for Common Leave , s for Sick leave and p for privilaged leave :");
                            //EACH LEAVE IS OF A SINGLE DAY
                            scanf(" %c",&type); 
                    
                            switch (type)
                            {
                            case 'c':
                                for(;i<=100;)
                                {
                                    printf("Enter the number of leaves you want : ");
                                    scanf("%d",&cl[i].number);
                                    if(s[i].cl>=cl[i].number){
                                        s[i].cl=s[i].cl-cl[i].number;
                                        printf("\nYour leave is granted");
                                        printf("\nYour remaining common leaves are %d",s[i].cl); 
                                        s[i].totalleavescl=s[i].totalleavescl+cl[i].number;
                                        break;
                                    }
                                    else{
                                        printf("\nsorry! You dont have enough number of common leaves left.");
                                        break;
                                    }
                                }
                                break;
                            case 's':
                                for(;i<=100;)
                                {
                                    printf("Enter the number of leaves you want : ");
                                    scanf("%d",&sl[i].number);
                                    if(s[i].sl>=sl[i].number){
                                        s[i].sl=s[i].sl-sl[i].number;
                                        printf("\nYour leave is granted");
                                        printf("\nYour remaining sick leaves are %d",s[i].sl); 
                                        s[i].totalleavessl=s[i].totalleavessl+sl[i].number;
                                        break;
                                    }
                                    else{
                                        printf("\nsorry! You dont have enough number of sick leaves left.");
                                        break;
                                    }
                                }
                                break;
                            case 'p':
                                for(;i<=100;)
                                {
                                    printf("Enter the number of leaves you want : ");
                                    scanf("%d",&pl[i].number);
                                    if(s[i].pl>=pl[i].number){
                                        s[i].pl=s[i].pl-pl[i].number;
                                        printf("\nYour leave is granted");
                                        printf("\nYour remaining privilaged leaves are %d",s[i].pl); 
                                        s[i].totalleavespl=s[i].totalleavespl+pl[i].number;
                                        break;
                                    }
                                    else{
                                        printf("\nsorry! You dont have enough number of privileged leaves left.");
                                        break;
                                    }
                                }
                                break;
                            
                            default:
                                printf("Wrong input");
                    
                            }
                            i++;
                            break;
                        }
                        else{
                            if(i>=100){
                             printf("\n-------------SORRY! WRONG ID-------------\n");
                            }
                            
                        }
                        
                    }
                break;
        case 3:
           
                printf("Enter id :");
                scanf("%d",&idemp);
                for(i=1;i<=100;i++){
                    if(s[i].id==idemp){
                        
                        printf("\n-------------YOUR DETAILS ARE-------------\n");
                        printf("\nName:%s %s\nPhone Number : %d\nDOB : %d %d %d\nSalary : %f\n",s[i].name1,s[i].name2,s[i].phoneno,s[i].d,s[i].m,s[i].y,s[i].salary);
                        printf("Remaining CL:%d\nRemaining SL:%d\nRemaining PL:%d\n",s[i].cl,s[i].sl,s[i].pl);
                        printf("Number of CL taken:%d\n",s[i].totalleavescl);
                        printf("Number of SL taken:%d\n",s[i].totalleavessl);
                        printf("Number of PL taken:%d\n",s[i].totalleavespl);
                        i++;
					    break;
                    } 
                    else{
                        if(i>=100){
                            printf("\n-------------SORRY! WRONG ID-------------\n");
                        }
                    }
                }
                
            
            break;
        case 4:
            printf("Enter id :");
                scanf("%d",&idemp);
                for(i=1;i<=100;i++){
                    if(s[i].id==idemp){
                        printf("\n-------------Welcome %s %s-------------\n",s[i].name1,s[i].name2);
                        printf("\n-------------YOUR DETAILS ARE-------------\n");
                        printf("\nName:%s %s\nPhone Number : %d\nDOB : %d %d %d\nSalary : %f\n",s[i].name1,s[i].name2,s[i].phoneno,s[i].d,s[i].m,s[i].y,s[i].salary);
                        printf("\nWhich Detail would you like to modify?");
                        printf("\nEnter 1 for name,\nEnter 2 for Phone Number,\nENter 3 for DOB,\nEnter 4 for Salary.");
                        scanf("%d",&change);

                        if(change==1){
                            printf("Enter New Name : ");
                            scanf("%s %s",&s[i].name1,&s[i].name2);
                            printf("\n--------------Details updated-----------------");
                        }
                        else if(change==2){
                            printf("Enter New Phone Number : ");
                            scanf("%d",&s[i].phoneno);
                            printf("\n--------------Details updated-----------------");
                        }
                        else if(change==3){
                            printf("Enter New DOB in (dd mm yy) format : ");
                            scanf("%d%d%d",&s[i].d,&s[i].m,&s[i].y);
                            printf("\n--------------Details updated-----------------");

                        }
                        else{
                            printf("Enter New Salary:");
                            scanf("%f",&s[i].salary);
                            printf("--------------Details updated-----------------");

                        }
					    break;
                    } 
                    else{
                        if(i>=100){
                            printf("\n-------------SORRY! WRONG ID-------------\n");
                        }
                    }
                }
            break;
        case 5:
            temp=1;
            printf("\nYOU HAVE EXITED THE LEAVE MANAGEMENT SYSTEM\n");
            printf("\n------------------------------------THANK YOU------------------------------------");
            break;
        }
        
    } 
    return 0;
}