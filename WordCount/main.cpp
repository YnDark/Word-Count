#include <stdio.h>
#include <string.h>

int main() {
    char parameter[3];
    char filename[100];
    FILE* file;
    errno_t err;

    printf("�����������-c �� -w�����ļ�·����");
    scanf_s("%s", parameter, sizeof(parameter));
    scanf_s("%s", filename, sizeof(filename));
    if ((err = fopen_s(&file, filename, "r"))!=0) {
        perror("�޷����ļ�");
        return 1;
    }

    int charnum = 0;
    int wordnum = 0;
    int inword = 0;
    char prech = 0; // ���ڼ�¼ǰһ���ַ�
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        charnum++;

        // ��鵱ǰ�ַ��Ƿ��ǿո�򶺺�
        if (ch == ' ' || ch == ',') {
            if (inword) {
                inword = 0;
                wordnum++;
            }
        }
        else if (prech == 0 || prech == ' ' || prech == ',') {
            // �����ǰ�ַ����ǿո�򶺺ţ�����ǰһ���ַ��ǿո�򶺺Ż���û��ǰһ���ַ�����prech == 0��
            inword = 1;
        }
        prech = ch; // ����ǰһ���ַ�
    }

    // ����ļ��Ե��ʽ�β�����ӵ��ʼ���
    if (inword) {
        wordnum++;
    }

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
