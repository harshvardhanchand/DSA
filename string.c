#include<stdio.h>
#include<stdlib.h>

//ASCII code take up 1 byte and Unicode code take up 2 bytes Hexadecimal representation is used  for storing Unicode code
// printf("%d",'A'); will give you the ASCII code of 'A' i.e 65
// char name[10] = "Hello";//automatically adds a null character at the end of the string char name[10] = {'H','e','l','l','o','\0'};
int length(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
//chnaging lower case to upper case and vice versa
void alternate_case(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
}
//count vowels and consonants
void count_vowels_consonants(char *str)
{
    int i=0,vowels=0,consonants=0;
    while(str[i]!='\0')
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
        {
            vowels++;
        }
        else if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z')
        {
            consonants++;
        }
        i++;
    }
    printf("Vowels: %d\nConsonants: %d\n",vowels,consonants);
}
//count number of words in a string
void count_words(char *str)
{
    int i=0,words=0;
    while(str[i]!='\0')
    {
        if(str[i]==' '&&str[i+1]!='\0')
        {
            words++;
        }
       
        i++;
    }   
    printf("Words: %d\n",words+1);
}
//check whether string is valid or not (only alphabets and numbers and spaces are allowed)
int check_validity(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0' && str[i]<='9' || str[i]==' ')
        {
            i++;
        }
        else
        {
            
            return 0;
        } 
    }
    return 1;
}
//reverse a string
void reverse_string(char *str)
{
    int i=0,j=length(str)-1;
    while(i<j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
//check whether string is palindrome or not
int check_palindrome(char *str)
{
    int i=0,j=length(str)-1;
    while(i<j)
    {
        if(str[i]!=str[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
//compare the strings
int compare_strings(char *str1,char *str2)
{
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
        {
            return 0;
        }
        i++;
    }
    if(str1[i]=='\0' && str2[i]=='\0')
    {
        return 1;
    }
    return 0;
}
//There are 3 methods  to find duplicate characters in a string
//1.Compare with other letters
//2.Using hashtable
//3.Using bitwise operation

void find_duplicate_characters(char *str)
{
    int i=0,j=0;
    while(str[i]!='\0')
    {
        j=i+1;
        while(str[j]!='\0')
        {
            if(str[i]==str[j])
            {
                printf("%c\n",str[i]);
            }
            j++;
        }
        i++;
    }
}
//There are 2 options either we assume only certain ascii codes are present or we take the whole ascii range 0-122 but lets assume only lower case letters are present
void find_duplicate_hash(char *str)
{
    int i =0;
    int B[25];
    for(i=0;i<26;i++)
    {
        B[i]=0;
    }
    for(i=0;i<26;i++)
    {
        B[str[i]-97]++;
    }
    for(i=0;i<26;i++)
    {
        if(B[i]>1)
        {
            printf("character %c is repeated %d times",i+97,B[i]);
        }
    }

   

}