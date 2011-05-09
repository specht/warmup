#include <stdio.h>
#include <string.h>


void removeChars(char* s, const char* chars)
{
    unsigned int bitmap[8];
    memset(bitmap, 0, 32);
    for (const char* p = chars; *p; ++p)
        bitmap[*p >> 5] |= ((unsigned int)1 << (*p & 31));
    char* source = s;
    char* dest = s;
    while (*source)
    {
        if (!((bitmap[*source >> 5] >> (*source & 31)) & 1))
        {
            // keep this char
            if (source != dest)
                *dest = *source;
            ++dest;
        }
        ++source;
    }
    *dest = 0;
}    



int main(int argc, char** argv)
{
    char* s = new char[256];
    strcpy(s, "Battle of the Vowels: Hawaii vs. Grozny");
    printf("%s\n", s);
    removeChars(s, "aeiou");
    printf("%s\n", s);
}
