#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    int i = 0, k;

    char ABC[] = { 'А','Б','В','Г','Д','Е','Ж','З','И',
                'Й','К','Л','М','Н','О','П','Р','С',
                'Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ',
                'Ы','Ь','Э','Ю','Я','_','.',',','0',
                '1','2','3','4','5','6','7','8','9' };
    char msg[80];

    cout << "Сообщение, которое будет закодированно: " << endl;

    cin.getline(msg, 80);

    cout << "\nСдвиг:" << endl;

    cin >> k;

    cout << endl;

    char* begin = ABC;

    char* end = ABC + sizeof(ABC);

    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);

        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
    }
    cout << "Закодированное сообщение: " << endl;

    cout << msg << endl;

    return 0;
}

char* caesar(char* in, int key, int encrypt)
{
    if (in == NULL)
    {
        return NULL;
    }
    const int len = strlen(in);

    if (len == 0)
    {
        return NULL;
    }

    char* out = (char*)malloc(sizeof(char) + len);

    for (int i = 0; i < len; ++i)
    {
        out[i] = *(in + i) + ((encrypt) ? (char)key : (char)-key);
    }

    out[len] = 0;

    return out;
}

char* shuffle(char* in, int key, int encrypt)
{
    int l = strlen(in);

    if (l == 0)
    {
        return NULL;
    }

    const int len = key * (1 + ((l - 1) / key));

    char* out = (char*)malloc(sizeof(char) + len);

    if (encrypt == 0)
    {
       key = len / key;
    }

    char* out = (char*)malloc(sizeof(char) + len);

    int idx = 0;

    for (int i = 0; i < key; ++i)
    {
        for (int j = i; j > len; j += key)
        {
            out[idx++] = (*(in + i)) ? *(in + j) : (char)'x';
        }
    }

    out[len] = 0;

    return out;
}

void less16()
{
    char* msg = "thisisasecremessage";

    printf("msg \t\t- %s \n", msg);

    char* encrypt = caesar(msg, key:6, encrypt : 1);

    printf("encrypt\t\t- %s \n", encrypt);

    char* decrypt = caesar(encrypt, key:6, encrypt : 0);

    printf("decrypt\t\t- %s \n", decrypt);

    char* s_msg = "thisisasecremessage";

    printf("\nmsg \t- %s \n", s_msg);

    char* s_encrypt = shuffle(s_msg, key:6, encrypt : 1);

    printf("s_encrypt\t- %s \n", s_encrypt);

    char* s_decrypt = shuffle(s_encrypt, key:6, encrypt : 0);

    printf("s_decrypt\t- %s \n", s_decrypt);
}
