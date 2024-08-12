#include<stdio.h>
#include<string.h>
int is_palindrome(char str[])
{
    int i,l;
    l=strlen(str);
    for(i=0;i<l/2;i++)
        if(str[i]!=str[l-1-i])
            return 0;
    return 1;
}
char* trim(char str[])
{
    int i=0,j,k,count=0;
    for(k=strlen(str)-1;str[k]==' ';k--)
        count++;
    k=strlen(str);
    while(str[i]==' ')
        i++;
    for(j=0;str[j+i];j++)
        str[j]=str[i+j];
    str[k-count-i]='\0';
    return str;
}
int count_words(char str[])
{
    int i,count=0;
    trim(str);
    for(i=0;str[i];i++)
    {
        if(str[i]==' ')
        {
            if(str[i]==str[i+1])
                continue;
            else
                count++;    
        }
    }
    return count+1;
}
char * reverse_word_wise(char str[])
{
    int j,i,word_count,k;
    word_count=count_words(str);
    char s[word_count][50];
    
    for(i=0,j=0,k=0;str[i];i++,k++)
    {
        if(str[i]!=' ')
            s[j][k]=str[i];
        else
        {
            s[j][k]='\0';
            j++;
            k=-1;
        }
    }

    str[0]='\0';
    for(j=word_count-1;j>=0;j--)
    {
        if(str[0]!='\0')
            strcat(str," ");
        strcat(str,s[j]);
    }
    str[strlen(str)]='\0';
    return str;
}
int compare_case_ignore(char s1[],char s2[] )
{
    int i;
    for(i=0;s1[i];i++)
        if(s1[i]>='a'&&s1[i]<='z')
            s1[i]-=32;
    for(i=0;s2[i];i++)
        if(s2[i]>='a'&&s2[i]<='z')
            s2[i]-=32;
    for(i=0;s1[i]&&s2[i];i++)
        if(s1[i]!=s2[i])
            return 0; //not same
    if(s1[i]==s2[i])
        return 1; //same strings
    else
        return 0; //not same
}
void print_frquency(char str[])
{
    int f[128]={0},i;
    for(i=0;str[i];i++)
        f[str[i]]++;
    for(i=0;i<=127;i++)
        if(f[i]!=0)
            printf("%c - %d\n",i,f[i]);
}
int find_word(char str[],char word[])
{
    int i,j;
    int l;
    for(l=0;word[l];l++);
    for(i=0;str[i+l-1];i++)
    {
        for(j=0;word[j] ;j++)
        {
            if(str[i+j]!=word[j])
                break;
        }
        if(!word[j])
            if(i==0&&(str[i+l]==' '||str[i+l]=='\0')|| str[i-1]==' '&&(str[i+l]==' '||str[i+l]=='\0'))
                return i;
    }
    return -1;
    
}
char * capitalize(char str[])
{
    int i=0;
    if(str[i]>='a'&&str[i]<='z')
        str[i]-=32;
    for(i=1;str[i];i++)
    {
        if(str[i]==' ')
            if(str[i+1]!=0&&str[i+1]!=' ')
                if(str[i+1]>='a'&&str[i+1]<='z')
                    str[i+1]-=32;
    }
    return str;
}
char* accronym(char str[])
{
    int j,i,word_count,k;
    word_count=count_words(str);
    char s[word_count][50];
    
    for(i=0,j=0,k=0;str[i];i++,k++)
    {
        if(str[i]!=' ')
            s[j][k]=str[i];
        else
        {
            s[j][k]='\0';
            j++;
            k=-1;
        }
    }
    s[j][k]='\0';

    str[0]='\0';
    for(k=1,i=0;k<word_count;k++,i++)
    {
        str[i]=s[k-1][0];
        if(str[i]>='a'&&str[i]<='z')
            str[i]-=32;
        i++;
        str[i]=' ';
    }
    strcpy(str+i,s[word_count-1]);
    return str;
}
char * concatenate(char s1[],char s2[])
{
    int i,j;
    for(i=0;s1[i];i++);
    for(j=0;s2[j];j++)
        s1[i+j]=s2[j];
    s1[i+j]='\0';
    return s1;

}
int main()
{

    char str[]="RAM SITA";
    printf("%s",concatenate(str,"\nRADHE RADHE"));
    
    
    printf("\n");
    return 0;
}