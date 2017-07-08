/*
* Initials (more comfortable)
*
* Written by Ankit R Gadiya
* CS50 Pset2
*/

# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(void)
{

    string name = GetString();

    // Checks for blanks before characters
    for (int a = 0; a < strlen(name); a++)
    {
        if (isalpha(name[a]))
        {
            if (isblank(name[a - 1]))
            {
                printf("%c", toupper(name[a]));
            }
            else if (a == 0)
            {
                printf("%c", toupper(name[a]));
            }
        }
    }

    printf("\n");
}
