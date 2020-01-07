#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void login_Page();                                              //Display Login Page void main_Page();                                               //Main Options Page
void insert(char* a);                                           //Insert data in linked list
void clear();                                                   //Clear whole linked list
void get_Data2(char a[]);                                       //Get data from permanent stored file
void count(char a[],int i);                                     //Count allotted and remaining rooms
void del(char rno[], char a[]);                                 //Delete from file void save_Customer_details(char rno[][4],int n,int a);          //Save Customer Details to a File
void save_Data(char rno[], char a[], char b[]);                 //Save Room Data to a File
void display(char a[]);                                         //Display Elements of Linked List
void check_In(int k);                                           //For Check-In a Customer
void rem_Rooms(int a);                                          //Display Remaining Rooms
void print_Info_Rooms(int a);                                   //Display Room Options Menu
void print_Rooms();                                             //Room Options Menu
void check_Out();                                               //Check Out and Calculate Payable Amount


//Code for Login Page Begin
 int i=0;
char user[10],pass[10];

struct details
{
    char data[10];
    struct details *next;}*start,*temp,*end;

void ins(char *d) {
    temp = (struct details *)malloc(sizeof(struct details));     strcpy(temp->data,d);     temp->next = NULL;     if(start == NULL) {         start = temp;         end = start;}     else {
        end->next = temp;         end = temp;}
}  void pr_Back(int a) {     system("@cls");
    printf(" \t \t \t Welcome To Hotel TRANSYLVANIA");     if(a == 1)
        printf("\n\n\t\t\t\t   LOG-IN");     else
        printf("\n\n\t\t\t\t   SIGN-UP");     printf("\n\n \t \tEnter Username: %s\n",user);     printf(" \t \tEnter Password: ");

}

char* get_Pass(int a) {     char c,pswd[10];     int j=0,k;     while(1) {         c=getch();         if(c == 13)             break;         if(c == 8) {             j--;             pswd[j] = NULL;             pr_Back(a);             for(k=0;k<j;k++)                 printf("*");             continue;}         pswd[j] = c;         printf("*");         j++;}     pswd[j] = '\0';     return pswd;
}  void signUp() {     system("@cls");     FILE *l;
    l = fopen("loginData.txt", "a");     printf(" \t \t \t Welcome To Hotel Asendra");     printf("\n\n\t\t\t\t   SIGN-UP");     printf("\n\n \t \tEnter Username: ");     scanf("%s",user);     printf(" \t \tEnter Password: ");     strcpy(pass,get_Pass(2));     fprintf(l,"%s_%s,",user,pass);     fclose(l);
    printf("\n \t \tSigned Up Successfully.");     printf("\n\n \t \tPress Enter To Continue...");     char c = getch();     if(c == 13)         login_Page();
}  void get_Data() {     FILE *l;
    l = fopen("loginData.txt", "r");     char s[100];     fscanf(l,"%s,",s);     fclose(l);     char *ptr = strtok(s,"_,");     while(ptr != NULL) {     ins(ptr);     ptr = strtok(NULL,"_,");     i++;}
}  void login() {     int j=0;     system("@cls");
    printf(" \t \t \t Welcome To Hotel Asendra");     printf("\n\n\t\t\t\t   LOG-IN");     printf("\n\n \t \tEnter Username: ");     scanf("%s",user);
    printf(" \t \tEnter Password: ");     strcpy(pass,get_Pass(1));
    for(temp=start; temp->next!=NULL; temp=temp->next)
 	 	if(strcmp(temp->data,user) == 0 && strcmp(temp->next->data,pass) ==
0) {             system("@cls");             main_Page();             return;}
    printf("\nUsername/Password is incorrect.\n");
}
void print_Info_Log(int a) {     system("@cls");
    printf(" \t \t \t Welcome To Hotel Asendra");     printf("\n\n\t\t\t\tChoose An Option: ");     if(a == 1) {
        printf("\n\t\t\t\t+-----------+\n");         printf("\t\t\t\t| 1. LOG-IN |");         printf("\n\t\t\t\t+-----------+\n");         printf("\t\t\t\t2. SIGN-UP\n");}     else {
        printf("\n\t\t\t\t1. LOG-IN");         printf("\n\t\t\t\t+------------+\n");         printf("\t\t\t\t| 2. SIGN-UP |");         printf("\n\t\t\t\t+------------+\n");}
}  void login_Page() {     get_Data();     char c;     int k = 1;     print_Info_Log(1);     while(1) {         c = getch();         if(c == '1') {             k = 1;             print_Info_Log(1);}         else if(c == '2') {             k = 2;             print_Info_Log(2);}         else if(c == 13) {             if(k == 1)                 login();             else if (k == 2)                 signUp();}         else
            printf("\n \t \tINVALID INPUT\n");}
}

//Code for Login Page End

//Code for Main Page Begin
 char al[] = "AllottedRooms.txt", rr[] = "RemainingRooms.txt", cd[4][100] = {"CustomerDetails1.txt","CustomerDetails2.txt","CustomerDetails3.txt","CustomerDet ails4.txt"};
int countal[4], countrm[4];

struct node {     char rno[5];     struct node *next;
};
struct node *start1, *temp2, *end1, *temp1;
 struct customer_Details {     char name[20];     char address[100];
    char mob_No[11],age[3],no_Of_Persons[2],stay[2];
}cusdet;
void insert(char* a) {
    temp2 = (struct node *)malloc(sizeof(struct node));     strcpy(temp2->rno,a);     temp2->next = NULL;
     if(start1 == NULL) {         start1 = temp2;         end1 = start1;}     else {         end1->next = temp2;         end1 = temp2;}
}  void clear() {     temp2 = start1;     while(temp2 != NULL) {         temp1 = temp2->next;         free(temp2);         temp2 = temp1;
    }     start1 = NULL;
}
void get_Data2(char a[]) {     clear();     FILE *l;     l = fopen(a, "r");     char s[1000];     fscanf(l,"%s",s);     fclose(l);      char *p;     p = strtok(s,",");     while(p!=NULL) {         insert(p);         p = strtok(NULL,",");
    }
}  void count(char a[],int i) {     get_Data2(a);     int d;     for(d=0;d<4;d++) {         countal[d] = 0;         countrm[d] = 0;
    }
    for(temp2=start1;temp2!=NULL;temp2=temp2->next) {         d = temp2->rno[0]-'0';         if(i)             countal[d-1] += 1;         else
            countrm[d-1] += 1;
    }
}
void del(char rno[], char a[]) {     get_Data2(a);     temp2 = start1;     if(strcmp(start1->rno,rno) == 0) {         start1 = start1->next;         free(temp2);
    }     else {
        while(strcmp(temp2->rno,rno) != 0) {             temp1 = temp2;             temp2 = temp2->next;             if(temp2 == NULL) {                 return;
            }         }
        temp1->next = temp2->next;         free(temp2);
    }
     FILE *l;     l = fopen(a, "w");     fprintf(l,"%s","");     fclose(l);     l = fopen(a, "a");
    for(temp2 = start1;temp2 != NULL;temp2 = temp2->next)     fprintf(l,"%s,",temp2->rno);     fclose(l);
}
void save_Customer_details(char rno[][4],int n,int a) {     printf("\nEnter Name: ");     scanf("%s", cusdet.name);     printf("\nEnter Address: ");     scanf("%s", cusdet.address);     printf("\nEnter Mobile Number: ");     scanf("%s", cusdet.mob_No);     printf("\nEnter Age: ");     scanf("%s", cusdet.age);     printf("\nEnter Number of Persons: ");     scanf("%s", cusdet.no_Of_Persons);     printf("\nEnter Number of days: ");     scanf("%s", cusdet.stay);
    int i;     FILE *l;     l = fopen(cd[a-1], "a");     for(i=0;i<n;i++) {         fprintf(l,"%s_",rno[i]);
    } fprintf(l,":%s_%s_%s_%s_%s_%s,",cusdet.name,cusdet.stay,cusdet.address,cusdet.mob_
No,cusdet.age,cusdet.no_Of_Persons);     fclose(l);
}
void save_Data(char rno[], char a[], char b[]) {     FILE *l;     l = fopen(a, "a");     fprintf(l,"%s,",rno);     fclose(l);     del(rno, b);
}  void display(char a[]) {     get_Data2(a);
    for(temp2=start1;temp2!=NULL;temp2=temp2->next)         printf("%s ",temp2->rno);     printf("\n");
}  void check_In(int k) {     count(rr,0);     int i,j,b,d;
    printf("\nEnter Number of Rooms: ");     scanf("%d",&b);     if(b<=countrm[k-1]) {     char rar[b][4];     printf("\nAlloted Rooms:\n");     for(i=0;i<b;i++) {         get_Data2(rr);         temp2=start1;         d = temp2->rno[0]-'0';         while(d!=k) {             temp2=temp2->next;             d = temp2->rno[0]-'0';
        }
        strcpy(rar[i],temp2->rno);         printf("%s\n",rar[i]);         save_Data(rar[i],al,rr);
    }
    save_Customer_details(rar,b,k);     system("@cls");
    printf("Data Saved Successfully\n\n\nPress any key to continue...");     if(getch())         main_Page();     } else {
        printf("Not enough rooms\n");
    }
}  void rem_Rooms(int a) {     count(rr,0);     int i,d=0;     for(i=0;i<4;i++)         d+=countrm[i];
    printf("\n\t\tRemaining Rooms on %dth floor: %d",a,countrm[a-1]);     printf("\n\n\t\tTotal Remaining Rooms: %d\n",d); }
 void print_Info_Rooms(int a) {     system("@cls");
    printf(" \t \t \t Welcome To Hotel Asendra");     printf("\n\n\t\t\t\tSelect Room Type: ");     if(a == 1) {
        printf("\n\t\t\t\t+-----------+\n");         printf("\t\t\t\t| 1. Normal |");         printf("\n\t\t\t\t+-----------+\n");         printf("\t\t\t\t2. Deluxe\n");         printf("\t\t\t\t3. Super Deluxe\n");         printf("\t\t\t\t4. Suite\n");}     else if(a == 2) {         printf("\n\t\t\t\t1. Normal");         printf("\n\t\t\t\t+-----------+\n");         printf("\t\t\t\t| 2. Deluxe |");         printf("\n\t\t\t\t+-----------+\n");         printf("\t\t\t\t3. Super Deluxe\n");         printf("\t\t\t\t4. Suite\n");}     else if(a == 3) {         printf("\n\t\t\t\t1. Normal");         printf("\n\t\t\t\t2. Deluxe");         printf("\n\t\t\t\t+-----------------+\n");         printf("\t\t\t\t| 3. Super Deluxe |");         printf("\n\t\t\t\t+-----------------+\n");         printf("\t\t\t\t4. Suite\n");}     else if(a == 4) {         printf("\n\t\t\t\t1. Normal");         printf("\n\t\t\t\t2. Deluxe\n");         printf("\t\t\t\t3. Super Deluxe");         printf("\n\t\t\t\t+----------+\n");         printf("\t\t\t\t| 4. Suite |");         printf("\n\t\t\t\t+----------+\n");}
}  void print_Rooms() {     int k = 1;     print_Info_Rooms(1);     rem_Rooms(1);     while(1) {         char c = getch();         if(c == '1') {             k=1;             print_Info_Rooms(1);             rem_Rooms(1);         } else if (c == '2') {             k=2;             print_Info_Rooms(2);             rem_Rooms(2);         } else if (c == '3') {             k=3;             print_Info_Rooms(3);             rem_Rooms(3);         } else if (c == '4') {             k=4;             print_Info_Rooms(4);             rem_Rooms(4);         } else if(c == 13) {             check_In(k);
        }         else{
            printf("\n \t \tINVALID INPUT\n");
        }
    }
}  void check_Out() {     float charge = 2000;     printf("Enter room number: ");     char r[4];     scanf("%s",r);     int f = r[0]-'0';
     FILE *l;     l = fopen(cd[f-1],"r");     char s[1000];     fscanf(l,"%s",s);     fclose(l);

    char *p,d[1000][1000],rn[100][100],c[10][1000];     int i=0,j,k=0,z=0,x;     p = strtok(s,",");     while(p!=NULL) {         strcpy(d[i],p);         i++;
        p = strtok(NULL,",");
    }     for(j=0;j<i;j++) {         char *p;         p = strtok(d[j],":");         while(p!=NULL) {             if(isalpha(p[0])) {                 strcpy(c[k],p);k++;
            } else {
                strcpy(rn[z],p);z++;
            }
            p = strtok(NULL,":");
        }     }     for(j=0;j<z;j++) {         int w = 0;         char *p,tmp[100];         strcpy(tmp,rn[j]);         p = strtok(rn[j],"_");         while(p!=NULL) {             if(strcmp(p,r)==0) {                 char *pr;                 pr = strtok(c[j],"_");                 system("@cls");                 printf("Name: %s\n",pr);                 pr = strtok(NULL,"_");
                printf("Amount Due: %.2f\n",(*pr-'0')*charge);                 l = fopen(cd[f-1],"w");                 fprintf(l,"");                 fclose(l);                 l = fopen(cd[f-1],"a");                 for(x=0;x<k;x++) {                     if(x!=j) {
                        fprintf(l,"%s:%s,",rn[x],c[x]);
                    }                 }                 w = 1;             }             if(w == 1) {                 int h=0;                 char b[5];                 for(x=0;x<strlen(tmp);x++) {                     if(tmp[x]!='_') {                         b[h] = tmp[x];                         h++;                     } else {                         h = 0;                         save_Data(b,rr,al);
                    }                 }                 return;             }
            p = strtok(NULL,"_");
        }     }     system("@cls");     printf("\n\nData not found");     return;
}
  void print_Info_Menu(int a) {     system("@cls");
    printf(" \t \t \t Welcome To Hotel Asendra");     printf("\n\n\t\t\t\tChoose An Option: ");     if(a == 1) {
        printf("\n\t\t\t\t+------------+\n");         printf("\t\t\t\t| 1. CheckIn |");         printf("\n\t\t\t\t+------------+\n");         printf("\t\t\t\t2. CheckOut\n");         printf("\t\t\t\t3. Exit\n");}     else if(a == 2) {         printf("\n\t\t\t\t1. CheckIn");         printf("\n\t\t\t\t+-------------+\n");         printf("\t\t\t\t| 2. CheckOut |");         printf("\n\t\t\t\t+-------------+\n");         printf("\t\t\t\t3. Exit\n");}     else if(a == 3) {         printf("\n\t\t\t\t1. CheckIn\n");         printf("\t\t\t\t2. CheckOut");         printf("\n\t\t\t\t+---------+\n");         printf("\t\t\t\t| 3. Exit |");         printf("\n\t\t\t\t+---------+\n");}
}  void main_Page() {     system("@cls");     int k = 1;     print_Info_Menu(1);     while(1) {         char c = getch();         if(c == '1') {             k=1;
            print_Info_Menu(1);         } else if (c == '2') {             k=2;
            print_Info_Menu(2);         } else if (c == '3') {             k=3;
            print_Info_Menu(3);         } else if(c == 13) {             if(k == 1)                 print_Rooms();             else if(k == 2)                 check_Out();             else                 exit(0);
        }         else{
            printf("\n \t \tINVALID INPUT\n");
        }
    }
}

//Code for Main Page End
 void main() {     login_Page();
}

