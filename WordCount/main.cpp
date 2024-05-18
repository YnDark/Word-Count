#include <stdio.h>
#include <string.h>

int main() {
    char parameter[3];
    char filename[100];
    FILE* file;
    errno_t err;

    printf("请输入参数（-c 或 -w）和文件路径：");
    scanf_s("%s", parameter, sizeof(parameter));
    scanf_s("%s", filename, sizeof(filename));
    if ((err = fopen_s(&file, filename, "r"))!=0) {
        perror("无法打开文件");
        return 1;
    }

    int charnum = 0;
    int wordnum = 0;
    int inword = 0;
    char prech = 0; // 用于记录前一个字符
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        charnum++;

        // 检查当前字符是否是空格或逗号
        if (ch == ' ' || ch == ',') {
            if (inword) {
                inword = 0;
                wordnum++;
            }
        }
        else if (prech == 0 || prech == ' ' || prech == ',') {
            // 如果当前字符不是空格或逗号，并且前一个字符是空格或逗号或者没有前一个字符（即prech == 0）
            inword = 1;
        }
        prech = ch; // 更新前一个字符
    }

    // 如果文件以单词结尾，增加单词计数
    if (inword) {
        wordnum++;
    }

    fclose(file);

    if (strcmp(parameter, "-c") == 0) {
        printf("字符数：%d\n", charnum);
    }
    else if (strcmp(parameter, "-w") == 0) {
        printf("单词数：%d\n", wordnum);
    }
    else {
        printf("无效参数：%s\n", parameter);
        return 1;
    }

    return 0;
}
