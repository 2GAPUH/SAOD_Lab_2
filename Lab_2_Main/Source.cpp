#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

#define FILE_NAME_SIZE 20

//struct syllable
//{
//    char word[6];
//};

int CheckGroup(char &symb)
{
    switch (symb)
    {
    case 'a':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
        return 4;

    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
        return 3;
    
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
        return 2;

    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
    case '�':
        return 1;

    case '�':
    case '�':
        return 0;

    }

}

int AddSyllable(const char fileInputName[], const char fileOutputName[])
{
    FILE* inputF, * outputF;

    if (fopen_s(&inputF, fileInputName, "r") != 0)
    {
        printf_s("Error opening file %s\n", fileInputName);
        return -1;
    }

    if(fopen_s(&outputF, fileOutputName, "w") != 0)
    {
        printf_s("Error opening file %s\n", fileInputName);
        return -1;
    }

    char buffer[20] = { 0 };
    char subbuf[20] = { 0 };
    
    while (feof(inputF) == 0)
    {
        fscanf(inputF, "%s", buffer);
        int stringLen = strlen(buffer);

        if (stringLen >= 4)
        {
            for (int i = 0; i < stringLen;i++)
                subbuf[i] = CheckGroup(buffer[i]);

            fprintf_s(outputF, "%c", buffer[0]);
            for (int i = 1; i < stringLen - 2; i++)
            {
                fprintf_s(outputF, "%c", buffer[i]);
                if ((subbuf[i] - subbuf[i + 1] == 0 && subbuf[i] == 4) ||
                    (subbuf[i] - subbuf[i + 1] > 0))
                {
                    if (subbuf[i + 1] != '�' && subbuf[i + 1] != '�')
                        if(i != stringLen - 3)
                            if(i != 1)
                                fprintf_s(outputF, "-");
                            else if(subbuf[1] == 4 || subbuf[0] == 4)
                                fprintf_s(outputF, "-");
                        else if((subbuf[stringLen - 1] == 4 || subbuf[stringLen - 2] == 4))
                            fprintf_s(outputF, "-");

                    else i++;
                }
            }
            fprintf_s(outputF, "%c%c ", buffer[stringLen - 2], buffer[stringLen-1]);

        }
        else
            fprintf_s(outputF, "%s ", buffer);

    }

    fclose(inputF);
    fclose(outputF);

    return 0;
}

int main()
{
    system("chcp 1251");

    char fileInputName[FILE_NAME_SIZE] = { 0 };
    char fileOutputName[FILE_NAME_SIZE] = { 0 };

    AddSyllable("1984.txt", "2.txt");

    return 0;
}
