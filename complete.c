
// header file
#include<stdio.h>
#include<string.h>
// structure initialize
struct employee{
    int emp_id;
    char emp_name[50];
    char emp_gender[10];
    int emp_age;
    char emp_department[50];
     long int salary;
};
void update(struct employee emp[],int size){
    char old_name[20],new_name[20];
    int i;
    int found=0;
    int employee_new_id,employee_new_age;
    long int employee_new_salary;
    char c;
     FILE *ep;
    FILE *temp;
    ep=fopen("empdata.txt","r");
     temp=fopen("tempdata.txt","w");
     if(temp==NULL||ep==NULL){
        printf("Unable to open file!");
        return;
     }
     struct employee current;// temporary variable to store the data of the file
     printf("Enter name that you want to replace:");
     scanf("%s", old_name);  
     printf("Enter the new_name:");
     scanf("%s", new_name);  
        // using loop
             while(fscanf(ep,"%d %s %s %d %ld %s",&current.emp_id,current.emp_name,current.emp_gender,&current.emp_age,&current.salary,current.emp_department)==6)
    {
        if(strcmp(current.emp_name,old_name)==0){

            found=1;
              // update name
            strcpy(current.emp_name,new_name);

            printf("Do you want to update ID (y/n): ");
            scanf(" %c",&c);
            if(c=='y'||c=='Y'){
                printf("Enter new ID: ");
                scanf("%d",&current.emp_id);
            }

            printf("Do you want to update age (y/n): ");
            scanf(" %c",&c);
            if(c=='y'||c=='Y'){
                printf("Enter new age: ");
                scanf("%d",&current.emp_age);
            }

            printf("Do you want to update salary (y/n): ");
            scanf("  %c",&c);   // here double space is used to avoid the buffer problem
            if(c=='y'||c=='Y'){
                printf("Enter new salary: ");
                scanf("%ld",&current.salary);

            }
        }

        fprintf(temp,"%d %s %s %d %ld %s\n",current.emp_id,current.emp_name,current.emp_gender,current.emp_age,current.salary,current.emp_department);
    }
                   fclose(ep);
                   fclose(temp);

                   remove("empdata.txt");
                   rename("tempdata.txt","empdata.txt");

        if(found==0){
            printf("Name not found in the file.\n");
        }
        else{
        printf("Do you want to see the updated list(y/n): ");
         scanf(" %c", &c);  // space %c is used to avoid the buffer problem
            if(c=='y'||c=='Y') {
                ep=fopen("empdata.txt","r"); 
                if(ep==NULL){
                    printf("FILE NOT FOUND!");

                }
             while(fscanf(ep,"%d %s %s %d %ld %s",&current.emp_id,current.emp_name,current.emp_gender,&current.emp_age,&current.salary,&current.emp_department)==6){  
                   printf("%d %s %s %d %ld %s\n",current.emp_id,current.emp_name,current.emp_gender,current.emp_age,current.salary,current.emp_department);  
                   } 
       fclose(ep);
                   }                          
                }
}

void search_employee(struct employee emp[],int size){
    char search_name[20];
    int i;
    char c;
    int found=0;
     FILE *ep;
    ep=fopen("empdata.txt","r");
     if(ep==NULL){
        printf("Unable to open file!");
        return;
     }
     do{
        rewind(ep);  // to reset the file pointer to the beginning of the file 
     printf("Enter search name:");
     scanf("%s",&search_name);
     struct employee current; 
     while(fscanf(ep,"%d %s %s %d %ld %s",&current.emp_id,current.emp_name,current.emp_gender,&current.emp_age,&current.salary,&current.emp_department)==6){
             
        if(strcmp(current.emp_name,search_name)==0){
        printf("Detail of search employee:\n");
        printf("ID=%d\n",current.emp_id);
        printf("NAME=%s\n",current.emp_name);    
        printf("GENDER=%s\n",current.emp_gender);
        printf("AGE=%d\n",current.emp_age);
        printf("DEPARTMENT=%s\n",current.emp_department);
        printf("SALARY=%ld\n",current.salary);
        found=1;
    }
        }
       if(found==0){
        printf("Name not found in the file.\n");
       }
       printf("Do you want to search again(y/n): ");
       scanf("  %c", &c);  // space %c is used to avoid the buffer problem   
    } while(c=='y'||c=='Y');
    printf("\n");
}

void delete_employee(struct employee emp[],int size){
    char delete_name[20];
    int i;
    char c;
    int found=0;
     FILE *ep;
    FILE *temp;
    ep=fopen("empdata.txt","r");
     temp=fopen("tempdata.txt","w");
     if(temp==NULL||ep==NULL){
        printf("Unable to open file!");
        return;
     }
     printf("Enter name that you want to delete:");
     scanf("%s", delete_name);  
        
        struct employee current;// temporary variable to store the data of the file
             while(fscanf(ep,"%d %s %s %d %ld %s",&current.emp_id,current.emp_name,current.emp_gender,&current.emp_age,&current.salary,&current.emp_department)==6){  
                   if(strcmp(current.emp_name,delete_name)!=0){
                    fprintf(temp,"%d %s %s %d %ld %s\n",current.emp_id,current.emp_name,current.emp_gender,current.emp_age,current.salary,current.emp_department);  
                   }
                } 
                printf("Employee deleted successfully!\n");
                   fclose(ep);
                   fclose(temp);

                   remove("empdata.txt");
                   rename("tempdata.txt","empdata.txt");

                  printf("Do you want to see the updated list(y/n): ");
                   scanf(" %c", &c);  // space %c is used to avoid the buffer problem
                    if(c=='y'||c=='Y') {
                      ep=fopen("empdata.txt","r"); 
                      if(ep==NULL){
                          printf("FILE NOT FOUND!");
                     }
                          while(fscanf(ep,"%d %s %s %d %ld %s",&current.emp_id,current.emp_name,current.emp_gender,&current.emp_age,&current.salary,&current.emp_department)==6){  
                         printf("%d %s %s %d %ld %s\n",current.emp_id,current.emp_name,current.emp_gender,current.emp_age,current.salary,current.emp_department);  
                        }
                          fclose(ep);
                    }
                    }
void add_employee(struct employee emp[],int size){
    struct employee new_emp;  // temporary variable to store the data of the new employee  
    FILE *ep;
    int i;
    char c;
    do{
    ep=fopen("empdata.txt","a"); // opening file in append mode
        if(ep==NULL){
            printf("Unable to open file!");
            return;
        }
        
        // Read all existing employee IDs from file
        FILE *check_ep = fopen("empdata.txt","r");
        int id_exists = 0;
        
        do{
            printf("\nEnter unique employee ID:");
            scanf("%d",&new_emp.emp_id);
            
            // Check if ID already exists in file
            id_exists = 0;
            if(check_ep != NULL){
                rewind(check_ep);
                struct employee existing_emp;
                while(fscanf(check_ep,"%d %s %s %d %ld %s",&existing_emp.emp_id,existing_emp.emp_name,existing_emp.emp_gender,&existing_emp.emp_age,&existing_emp.salary,existing_emp.emp_department)==6){
                    if(new_emp.emp_id == existing_emp.emp_id){
                        id_exists = 1;
                        printf("ERROR: This ID already exists! Please enter a different ID.\n");
                        break;
                    }
                }
            }
        }
        while(id_exists);
        
        if(check_ep != NULL) fclose(check_ep);
        
        printf("Enter employee name:");
        scanf("%s",&new_emp.emp_name);  
        printf("Enter employee gender:");
        scanf("%s",new_emp.emp_gender);
        printf("Enter employee age:");
        scanf("%d",&new_emp.emp_age);
        printf("Enter employee salary:");
        scanf("%ld",&new_emp.salary);
        printf("Enter employee department:");
        scanf("%s",new_emp.emp_department);
        fprintf(ep,"%d %s %s %d %ld %s\n",new_emp.emp_id,new_emp.emp_name,new_emp.emp_gender,new_emp.emp_age,new_emp.salary,new_emp.emp_department);
        fclose(ep);
        printf("\nEmployee added successfully!\n"); 

        printf("Do you want to add another employee(y/n):");
        scanf("  %c",&c);
    }  while(c=='y'||c=='Y');
        printf("Do you want to see the updated list(y/n): ");
         scanf("  %c", &c);  // space %c is used to avoid the buffer problem
            if(c=='y'||c=='Y') {
                ep=fopen("empdata.txt","r"); 
                if(ep==NULL){
                    printf("FILE NOT FOUND!");  
                }
            }  while(fscanf(ep,"%d %s %s %d %ld %s",&new_emp.emp_id,new_emp.emp_name,new_emp.emp_gender,&new_emp.emp_age,&new_emp.salary,&new_emp.emp_department)==6){
                   printf("%d %s %s %d %ld %s\n",new_emp.emp_id,new_emp.emp_name,new_emp.emp_gender,new_emp.emp_age,new_emp.salary,new_emp.emp_department);  
                   }  
            fclose(ep);
            }

int main(){
struct employee emp[24];
int i,j;
int number,num; 
char password[50],c;
int checked=0;
FILE *ep;
//using the password here 
for(j=0;j<3;j++){  // how much time user can try the password
     printf("Enter the password to access employee data: ");
        scanf("%s", password);
            if(strcmp(password,"Project@123")==0){
                checked=1;
                  break;
                    }
                       else{
                                printf("INCORRECT, TRY AGAIN !\n");
                                 }
                                     } 
         if(checked==0){   // if user enter wrong password 3 times then access will be denied
               printf("PERMISSION DENIED!\n");
                  return 1;
                     }
                     
do{

printf("1.Update the list of data:\n");
printf("2.Search:\n");
printf("3.Deleted the data of the person:\n");
printf("4.Add the new employee data:\n");
printf("5.Highest and Lowest salary,from it department,above salary,counting from each department:\n");
printf("\nEnter the number(between 1-5):");
scanf("%d",&num);
switch(num){
case 1:
    update(emp,24);
    break;
case 2:
    search_employee(emp,24);
    break;
case 3:
    delete_employee(emp,24);
     break;
    break;
case 4: 
add_employee(emp,24);
break;
case 5:
    do{        
    ep=fopen("empdata.txt","r"); // opening file in read mode   
           if(ep==NULL){              //checking file is exist or not
             printf("FILE NOT FOUND!");
                      return 0;
           }
        struct employee new_data,min,max;  // temporary variable to store the data of the file
           
 printf("\n1.For highest and lowest salary:\n");
 printf("2.For displaying employees from the IT department:\n");
 printf("3.For employees with salary above the average salary:\n");
 printf("4.For counting employees in each department:\n");
 printf("\nEnter a number (between 1-4):");
 scanf("%d",&number);
  switch(number){
    case 1:
    int f=0;
while(fscanf(ep,"%d %s %s %d %ld %s",&new_data.emp_id,new_data.emp_name,new_data.emp_gender,&new_data.emp_age,&new_data.salary,&new_data.emp_department)==6){
    f++;
    if(f==1){  // for the first time assign the salary of the first employee to both max and min
        max = new_data;
        min = new_data;
    }
    if(new_data.salary > max.salary){
        max = new_data;
    }
    if(new_data.salary < min.salary){
        min = new_data;
    }
}

printf("\nHIGHEST SALARY EMPLOYEE:\n");
printf("ID=%d\n",max.emp_id);
printf("NAME=%s\n",max.emp_name);
printf("GENDER=%s\n",max.emp_gender);
printf("AGE=%d\n",max.emp_age);
printf("DEPARTMENT=%s\n",max.emp_department);
printf("SALARY=%ld\n",max.salary);

printf("\nLOWEST SALARY EMPLOYEE:\n");
printf("ID=%d\n",min.emp_id);
printf("NAME=%s\n",min.emp_name);
printf("GENDER=%s\n",min.emp_gender);
printf("AGE=%d\n",min.emp_age);
printf("DEPARTMENT=%s\n",min.emp_department);
printf("SALARY=%ld\n",min.salary);
 printf("\n");    // to break the line for another input  of switch 
                 break;             // for avoiding unnecessary condition
    case 2 :
         printf("Details of employees from IT department:\n");                  // using loop
             while(fscanf(ep,"%d %s %s %d %ld %s",&new_data.emp_id,new_data.emp_name,new_data.emp_gender,&new_data.emp_age,&new_data.salary,&new_data.emp_department)==6){  
                 if(strcmp(new_data.emp_department,"IT-Support")==0){     //checking for employees details from IT department{
                    printf("ID=%d\n",new_data.emp_id);
                     printf("NAME=%s\n",new_data.emp_name);
                       printf("GENDER=%s\n",new_data.emp_gender);
                        printf("AGE=%d\n",new_data.emp_age);
                         printf("DEPARTMENT=%s\n",new_data.emp_department);
                          printf("SALARY=%ld\n",new_data.salary);
                            printf("\n");
            
                             }
                            }
                              printf("\n");    // to break the line for another input  of switch 
                                    break;
    case 3:
    int number_of_employees = 0;
    long int sum = 0;
        float avg;
                while(fscanf(ep,"%d %s %s %d %ld %s",&new_data.emp_id,new_data.emp_name,new_data.emp_gender,&new_data.emp_age,&new_data.salary,&new_data.emp_department)==6){  
        // calculate sum
            sum = sum + new_data.salary;
            number_of_employees++;
        }

        avg = sum / (float)number_of_employees;  // calculate average salary
         printf("%-15s | %-6s | %-10s | %-5s | %-25s | %-10s\n",   // %-15 width  of the name and so on
       "NAME", "ID", "GENDER", "AGE", "DEPARTMENT", "SALARY");
        rewind(ep);  // to reset the file pointer to the beginning of the file
        //display employees above average
        while(fscanf(ep,"%d %s %s %d %ld %s",&new_data.emp_id,new_data.emp_name,new_data.emp_gender,&new_data.emp_age,&new_data.salary,&new_data.emp_department)==6){
            if(new_data.salary > avg){
                printf("%-15s | %-6d | %-10s | %-5d | %-25s | %-10ld\n", 
                new_data.emp_name, new_data.emp_id, new_data.emp_gender, new_data.emp_age, new_data.emp_department, new_data.salary);
            }
        }
                      break;
    case 4:
                    char software[]="Software-Development";
                    char network[]="Network-Administration";
                    char data[]="Data-Management";
                    char cyber[]="Cybersecurity";
                    char it[]="IT-Support";
                    int count_software=0, count_fin=0, count_data=0, count_cyber=0, count_it=0;

                    //Counting number of employees in each department
                while(fscanf(ep,"%d %s %s %d %ld %s",&new_data.emp_id,new_data.emp_name,new_data.emp_gender,&new_data.emp_age,&new_data.salary,&new_data.emp_department)==6){
                       if(strcmp(new_data.emp_department,software)==0){
                            count_software++;
                       }
                      if(strcmp(new_data.emp_department,network)==0){
                            count_fin++;
                        }
                        if(strcmp(new_data.emp_department,data)==0){
                            count_data++;
                        }
                        if(strcmp(new_data.emp_department,cyber)==0){
                            count_cyber++;
                        }
                        if(strcmp(new_data.emp_department,it)==0){
                            count_it++;
                        }
                    }

                    printf("Number of employees in each department:\n");
                    printf("%s: %d\n",software,count_software);
                    printf("%s: %d\n",network,count_fin);
                    printf("%s: %d\n",data,count_data);
                    printf("%s: %d\n",cyber,count_cyber);
                    printf("%s: %d\n",it,count_it);
    
                    break;
  
    default: 
             printf("Invalid number you have enter");  
                 printf("\n");
                             }
                                      printf("Do you want to continue(y/n): ");
                                           scanf(" %c", &c);  // space %c is used to avoid the buffer problem
                                                     }
                                                  while(c=='y'||c=='Y');
                                                   printf("Exiting the inner menu...\n\n"); 
                                                   break;
                                                

default:
printf("Invalid number you have enter");
                                                }
printf("Do you want to continue the main menu(y/n):");
scanf(" %c",&c);
                                            }while(c=='y'||c=='Y');
                                            printf("Exiting the program...");

fclose(ep);  //closing file   
return 0;
}

