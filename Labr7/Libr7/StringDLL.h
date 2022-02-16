#ifndef __StringDLL__
#define __StringDLL_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

//void DLL_EXPORT SomeFunction(const LPCSTR sometext);
void String_to_words (char *source, char *dest);

#ifdef __cplusplus
}
#endif

#endif // __StringDLL__
