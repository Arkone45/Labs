#include "StringDLL.h"

// a sample exported function
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}


extern "C" __declspec(dllexport) void String_to_words (char *source, char *dest)
{
    char *temp;
    int j = 0;
    boolean doubles = false;
    temp = new char[strlen(source)];
    temp[0] = '\0';
    dest[0] = '\0';
    for (int i = 0; source[i]; i++)
    {
        if (isalnum ((int)source[i]))
        {
            if (strchr(temp, source[i]))
                doubles = true;
            temp[j] = source[i];
            temp[j+1] = '\0';
            j++;
        }
        else
        {
            if ((temp[0] != '\0') && !doubles)
            {
                temp[j] = ' ';
                temp[j+1] = '\0';
                strcat (dest, (const char*)temp);
            }
            j = 0;
            temp[0] = '\0';
            doubles = false;
        }
    }
    if (temp[0] != '\0')
        strcat (dest, (const char*)temp);
    delete (temp);
}

