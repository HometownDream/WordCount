#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void count_char(char *str) {
    int sum = 0;
    int ch;
    FILE* fp;
    
    if ((fp = fopen(str, "r")) == NULL) {
        printf("Can't open %s\n", str);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        sum++;
    }
    printf("字符数：%d",sum);
}

void count_word(char* str) {
    int sum = 0;
    int word = 0;
    
    int ch;
    FILE* fp;

    if ((fp = fopen(str, "r")) == NULL) {
        printf("Can't open %s\n", str);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' '||ch==',')
            word = 0;
        else if (word == 0)
        {
            word = 1;
            sum++;
        }
    }
    printf("单词数：%d", sum);
}


int main(int argc, char* argv[])
{
        char* s1= argv[1];
        char* s2 = argv[2];
        char str1[] = {'-','w','\0'};
        char str2[] = { '-','c','\0' };

        if (strcmp(s1, str1)==0) {
            count_word(s2);
        }
       
        if (strcmp(s1, str2)==0) {
            count_char(s2);
        }
       
    return 0;
}
