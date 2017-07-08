/*
* Caesar (less comfortable)
*
* Written by Ankit R Gadiya
* CS50 Pset2
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // 2nd cli argument as key
        int key = atoi(argv[1]);

        if (key >= 0)
        {
            printf("plaintext: ");
            string text = GetString();

            // Loop to encrypt text
            printf("ciphertext: ");
            for (int j = 0; j < strlen(text); j++)
            {
                if (isupper(text[j]) && isalpha(text[j]))
                {
                    int c = (int) text[j];
                    c = ((c - 65 + key) % 26);
                    c = c + 65;
                    printf("%c", (char) c);
                }
                else if (islower(text[j]) && isalpha(text[j]))
                {
                    int c = (int) text[j];
                    c = (((c - 97 + key) % 26 ) + 97);
                    printf("%c", (char) c);
                }
                else
                {
                    printf("%c", text[j]);
                }
            }

            printf("\n");
            return 0;
        }
        // Case if key is not an integer
        else
        {
            printf("Use integer as key.\n");
            return 1;
        }
    }
    // Case if 2 cli arguments not supplied
    else
    {
        printf("Usage: /path/to/caesar <key>\n");
        return 1;
    }
}
