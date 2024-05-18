#include <stdio.h>
#include <string.h>

int main() {
    char parameter[3];
    char filename[100];
    FILE* file;
    errno_t err;

    printf("�����������-c �� -w�����ļ�����");
    scanf_s("%s", parameter, sizeof(parameter));
    scanf_s("%s", filename, sizeof(filename));
    if ((err = fopen_s(&file, filename, "r"))!=0) {
        perror("�޷����ļ�");
        return 1;
    }

    int charnum = 0;
    int wordnum = 0;
    int inword = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        charnum++;

        // ��鵱ǰ�ַ��Ƿ��ǿո�򶺺�
        if (ch == ' ' || ch == ',') {
            wordnum++;
        }

    }

    // ����ļ��Ե��ʽ�β�����ӵ��ʼ���
    wordnum++;

    fclose(file);

    if (strcmp(parameter, "-c") == 0) {
        printf("�ַ�����%d\n", charnum);
    }
    else if (strcmp(parameter, "-w") == 0) {
        printf("��������%d\n", wordnum);
    }
    else {
        printf("��Ч������%s\n", parameter);
        return 1;
    }

    return 0;
}
