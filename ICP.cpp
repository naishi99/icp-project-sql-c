/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 *
 * Created on 30 November 2017, 12:26
 */


#include<stdio.h>
#include<string.h>

FILE *fp1,*fp2,*fp3,*fp4;
int cnt=0;
char quearr[20][20];
void query_split(char *query_pointer[]);
struct Participant
{
    int participantId;
    char firstName[20];
    char lastName[20];
    char gender;
    int age;
    long int contactNo;
    char city[100];
};
typedef struct Participant part;
struct Audition
{
    char final_state[20];
    int date;
};
typedef struct Audition audi;
struct Talent
{
    char category[25];
    char achievements[100];
    char profession[20];
    char reason_talent[50]; 
};
typedef struct Talent tale;
struct Performance
{
    char performance_type;
    int time;
    char music[20];
    char risky[10];
    char props[20];
};
typedef struct Performance perf;
int main(int argc, char** argv) 
{
    
    FILE *fp=fopen("temp.txt","a");
    char query[50];
    printf("Enter your query:");
    gets(query);
    fwrite(query,sizeof(query),1,fp);
    fclose(fp);
    query_split(query);
    query1();
    query2();
}
void query_split(char *query_pointer[])  
{
    FILE *fp=fopen("temp.txt","w");
    
    
    int pa,a,t,per;
    cnt=0;
    int i,j=0;
    for(i=0;i<=(strlen(*query_pointer));i++)
    {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if(query_pointer[i]==' '||query_pointer[i]=='\0'||query_pointer[i]==',')
        {
            quearr[cnt][j]='\0';
            cnt++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            quearr[cnt][j]=query_pointer[i];
            j++;
        }
    }
     
}

int* participant()
{
    int i=0;

    char cont;
    FILE *fp1=fopen("Participant.dat","a");
        do 
        {
            part  *par;
            
            par->participantId=17000+i;
            fwrite(par->participantId,sizeof(par->participantId),1,fp1);
            fprintf(fp1,"\t");
            printf("Enter your first name:");
            gets(par->firstName);
            fwrite(par->firstName,sizeof(par->firstName),1,fp1);
            fprintf(fp1,"\t");
            printf("Enter your last name:");
            gets(par->lastName);
            fwrite(par->lastName,sizeof(par->lastName),1,fp1);
            fprintf(fp1,"\t");
            printf("Enter your gender:");
            gets(par->gender);
            fwrite(par->gender,sizeof(par->gender),1,fp1);
            fprintf(fp1,"\t");
            printf("Enter your age:");
            gets(par->age);
            fwrite(par->age,sizeof(par->age),1,fp1);
            fprintf(fp1,"\t");
            printf("Enter your contact number:");
            gets(par->contactNo);
            fwrite(par->contactNo,sizeof(par->contactNo),1,fp1);
            fprintf(fp1,"\t");
            printf("Enter your city:");
            gets(par->city);
            fwrite(par->city,sizeof(par->city),1,fp1);
            fprintf(fp1,"\n");
            
            printf("Do you want to continue?(Y/N)");
            scanf("%c",&cont);
            i++;
        }while(cont=='Y'||'y');
        return fp1;
        fclose(fp1);
}
int* audition()
{
    char cont;
    FILE *fp2=fopen("Audition.dat","a");
        do 
        {
            audi  *aud;
            printf("Enter your state preference:");
            gets(aud->final_state);
            fwrite(aud->final_state,sizeof(aud->final_state),1,fp2);
            fprintf(fp2,"\t");
            printf("Enter your audition date:");
            gets(aud->date);
            fwrite(aud->date,sizeof(aud->date),1,fp2);
            fprintf(fp2,"\n");
            
            printf("Do you want to continue?(Y/N)");
            scanf("%c",&cont);
        }while(cont=='Y'||'y');
        return fp2;
        fclose(fp2);
}
int* talent()
{
    char cont;
    FILE *fp3=fopen("Talent.dat","a");
        do 
        {
            tale *tal;
            
            printf("Enter your category of talent:");
            gets(tal->category);
            fwrite(tal->category,sizeof(tal->category),1,fp3);
            fprintf(fp3,"\t");
            printf("Enter your profession:");
            gets(tal->profession);
            fwrite(tal->profession,sizeof(tal->profession),1,fp3);
            fprintf(fp3,"\t");
            printf("Enter your achievements in brief:");
            gets(tal->achievements);
            fwrite(tal->achievements,sizeof(tal->achievements),1,fp3);
            fprintf(fp3,"\t");
            printf("Enter your reason of interest :");
            gets(tal->reason_talent);
            fwrite(tal->reason_talent,sizeof(tal->reason_talent),1,fp3);
            fprintf(fp3"\n");
            
            
            printf("Do you want to continue?(Y/N)");
            scanf("%c",&cont);
        }while(cont=='Y'||'y');
        return fp3;
        fclose(fp3);
}

int *performance()
{
    char cont,ch;
    FILE *fp4=fopen("Performance.dat","a");
    do
    {
        perf *per;
        
        printf("Enter the type of performance (group/duet/individual)");
        gets(per->performance_type);
        fwrite(per->performance_type,sizeof(per->performance_type),1,fp4);
        fprintf(fp4,"\t");
        printf("Enter the duration of performance");
        gets(per->time);
        fwrite(per->time,sizeof(per->time),1,fp4);
        fprintf(fp4,"\t");
        printf("Enter if music is used or not (Y/N)");
        gets(per->music);
        fwrite(per->music,sizeof(per->music),1,fp4);
        fprintf(fp4,"\t");
        printf("Enter if the performance is risky or not(Y/N)");
        gets(per->risky);
        fwrite(per->risky,sizeof(per->risky),1,fp4);
        fprintf(fp4,"\t");
        printf("Enter if props are used or not(Y/N)");
        gets(per->props);
        fwrite(per->props,sizeof(per->props),1,fp4);
        fprintf(fp4, "\t");
        
        
        printf("Do you want to continue?(Y/N)");
        scanf("%c",&cont);
    }while(cont=='Y'||'y');
    return fp4;
    fclose(fp4);
}
void general()
{
    int i=cnt-1;

    if(!strcmp(quearr[0],"SELECT")&&!strcmp(quearr[cnt-2],"FROM"))
    {
        if(!strcmp(quearr[i],"Participant"))
        {
            fp=fopen("Participant.dat","r");
        }
        else if(!strcmp(quearr[i],"Audition"))
        {
            fp=fopen("Audition.dat","r");
        }
        else if(!strcmp(quearr[i],"Talent"))
        {
            fp=fopen("Talent.dat","r");
        }
        else if(!strcmp(quearr[i],"Performance"))
        {
            fp=fopen("Performance.dat","r");
        }
        i--;
            
            
                if(!strcmp(quearr[i],"*"))
                {
                    query1(fp);
                }
                else 
                {
                    query2(fp);
                }
            }
    }
}
void query1(FILE *fp)   ///QUERY1
{
    int i;
    do
    {
        ch=fgetc(fp);
        putc(ch,stdout);
    }while(ch!=EOF);
    fclose(fp);
}
void query2(FILE *fp)        //QUERY2
{
    int i,tab=0;
    i=cnt-1;
    {
    if(!strcmp(quearr[0],"SELECT"))
    {
                    if(!strcmp(quearr[i],"Participant"))
                    {
                        fp=fopen("Participant.dat","r");
                    
                        i--;
                        if(!strcmp(quearr[i],"FROM"))
                        {
                            do
                            {
                            i--;
                        
                            if(strcmp(quearr[i],"participantId"))
                            {
                            do
                            {
                                do
                                {
                                    ch=fgetc(fp);
                                    putc(ch,stdout);
                                }while(ch!='\t');
                                for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"firstName"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==1)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            else if(!strcmp(quearr[i],"lastName"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==2)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            else if(!strcmp(quearr[i],"gender"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==3)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"age"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==4)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"contactNo"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==5)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"city"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==6)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                    }while(i>=1);
                else if(!strcmp(quearr[i],"Audition"))      //Audition
                    {
                        fp=fopen("Audition.dat","r");
                        i--;
                        if(!strcmp(quearr[i],"FROM"))
                        {
                            do
                            {
                            i--;
                        
                            if(!strcmp(quearr[i],"final_state"))
                            {
                            do
                            {
                                do
                                {
                                    ch=fgetc(fp);
                                    putc(ch,stdout);
                                }while(ch!='\t');
                                for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"date"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==1)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            }while(i>=1);
                            }
                            
                            
                else if(!strcmp(quearr[i],"Talent"))
                    {
                        fp=fopen("Talent.dat","r");
                        i--;
                        if(!strcmp(quearr[i],"FROM"))
                        {
                            do
                            {
                            i--;
                        
                            if(!strcmp(quearr[i],"category"))
                            {
                            do
                            {
                                do
                                {
                                    ch=fgetc(fp);
                                    putc(ch,stdout);
                                }while(ch!='\t');
                                for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"achievement"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==1)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            
                            else if(!strcmp(quearr[i],"profession"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==2)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            else if(!strcmp(quearr[i],"reason_talent"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==3)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                            }while(i>=1);
                            
                    else if(!strcmp(quearr[i],"Performance"))
                    {
                        fp=fopen("Performance.dat","r");
                        i--;
                        if(!strcmp(quearr[i],"FROM"))
                        {
                            do
                            {
                            i--;
                        
                            if(!strcmp(quearr[i],"performance_type"))
                            {
                            do
                            {
                                do
                                {
                                    ch=fgetc(fp);
                                    putc(ch,stdout);
                                }while(ch!='\t');
                                for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"time"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==1)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            else if(!strcmp(quearr[i],"music"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==2)
                                    {
                                    do
                                    {
                                        ch=fgetc(fp);
                                        putc(ch,stdout);
                                    }while(ch!='\t');
                                    for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }while(fp!=NULL);}
                            }
                            else if(!strcmp(quearr[i],"risky"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==3)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                            else if(!strcmp(quearr[i],"props"))
                            {
                            do
                            {
                                for(ch=fgetc(fp);ch!='\t'||ch=='\t'?tab++:1;ch=fgetc(fp));
                                
                                    if(tab==4)
                                    {
                                        do
                                        {
                                            ch=fgetc(fp);
                                            putc(ch,stdout);
                                        }while(ch!='\t');
                                        for(ch=fgetc(fp);ch!='\n';ch=fgetc(fp));
                                    }
                            }while(fp!=NULL);
                            }
                            }while(i>=1);
                    }
        }
                    fclose(fp);
            }
            else
            {
                    printf("Error: Query Invalid!");
                    exit(0);
            }
        }
        else
        {
            printf("Error: Query Invalid!");
            exit(0);
        }
    }
    else 
    {
            printf("Error: Query Invalid!");
            exit(0);
    }
}
}
}
    
