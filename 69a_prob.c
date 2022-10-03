#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//v.imp exe 12 : automated bill generator.
//refer generatebill.tex and bill.txt
//buildup knowledge in 69b.c and 67.c
//advanced level logic building each line has something to teach pay deep attending and try to understand everything.
//can do if understoon ...this is mind building exercise v.imp.
//solve 65b.c after this.

char *replaceword(const char *str, const char *oldword, const char *newword)
{
    int oldwordlength = strlen(oldword);
    int newwordlength = strlen(newword);
    int count = 0;

    //**count no. of times word occours.**
    for (int i = 0; str[i] != '\0'; i++)
    {

        if ((strstr(&str[i], oldword)) == &str[i]) //check code in 69b.c
        {
            count++;                   //will give no. of thimes the word occours in str.//we find count for dynamic memory allocation.
            i = i + oldwordlength - 1; //iteration will jump the word.
        }
    }

    //**to give size of resultstring ...dynamically allocating.**
    char *resultstring;
    resultstring = (char *)malloc(strlen(str) + count * (newwordlength - oldwordlength) + 1); //insted of strlen u could use i if declared outside the loop as it will store string length after loop.


    //**imagine actual working of this loop.//this is actual logic of programm.**
    int i = 0;   //declaring outside will keep it alive after the loop.
    while (*str) //why derefer? coz progrom will run until we get '\0' which is end of string derefernce vaalue.
    {
        if (strstr(str, oldword) == str) //here str is also &str[0] but we dont want to run it with i so done this.
        {
            strcpy(&resultstring[i], newword);
            i = i + newwordlength;//to jump after newword as it is printed to reverstring above.
            str = str + oldwordlength;//here str is address of parcular char block ...if we increase by oldwordlen i.e some no. then it will jump after oldword

        }
        else
        {
            resultstring[i] = *str;
            str = str + 1;
            i = i + 1;
        }
    }
    resultstring[i] = '\0';

    return resultstring; //we return a string in form of pointer.
}

int main()
{
    //****to oprn files,-- to read from one file and write to another file****
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr = fopen("bill.txt", "r");
    ptr2 = fopen("generatebill.txt", "w");

    // ****Reading from template file****
    char str[200];
    fgets(str, 200, ptr);
    printf("the given bill template was : %s\n", str);

    //****general info input taken by public.****
    char name[15];
    printf("enter yoyr name :\n");
    gets(name);
    char item[20];
    printf("enter item u purchased :\n");
    gets(item);
    char outlet[25];
    printf("enter yoyr store :\n");
    gets(outlet);

    // ****Actual performance****
    char *newstr; //this is pointer coz the thing we store in this is also pointer.
    //call the replaceword function passing arguments and generate newstr.
    newstr = replaceword(str, "{{name}}", name);
    newstr = replaceword(newstr, "{{item}}", item);
    newstr = replaceword(newstr, "{{outlet}}", outlet);

    //****printing content in console and writing in bill generating file****
    printf("the actual bill generated is : %s\n", newstr);
    fprintf(ptr2, "%s", newstr);//can use fputs(newstr,ptr2);

    //****closing files**** //imp.
    fclose(ptr);
    fclose(ptr2);

    return 0;
}