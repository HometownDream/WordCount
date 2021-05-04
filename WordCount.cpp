#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void count_char(char *str) {//计算字符数
    int sum = 0;
    int ch;
    FILE* fp;
    
    if ((fp = fopen(str, "r")) == NULL) {//打开文件，如果文件不存在，则输出“Can't open xxx.txt”
        printf("Can't open %s\n", str);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)//把文本文件中的每个字符取出来，然后数量加一进行统计，直到文件结尾
    {
        sum++;
    }
    printf("字符数：%d",sum);
}

void count_word(char* str) {//计算单词数
    int sum = 0;
    int word = 0;
    
    int ch;
    FILE* fp;

    if ((fp = fopen(str, "r")) == NULL) {//打开文件，如果文件不存在，则输出“Can't open xxx.txt”
        printf("Can't open %s\n", str);
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)//统计被‘,’或‘ ’分割的单词数
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


int main(int argc, char* argv[])//主函数
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
