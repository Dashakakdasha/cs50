/*
* vigenere (less comfortable)
*
* Written by Ankit R Gadiya
* CS50 Pset2
*/
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


bool key_check(string text);
int key_to_num(string key, int key_counter);

int main(int argc, string argv[])
{
  if (argc == 2)
  {

    string key = argv[1];
    if (key_check(key))
    {

      // Input
      printf("plaintext: ");
      string text = GetString();

      int key_counter = 0;

      printf("ciphertext: ");
      // Main loop to go over each character of text
      for (int i = 0; i < strlen(text); i++)
      {
        char c = text[i];
        if (isupper(c))
        {
          int key_num = key_to_num(key, key_counter);
          int char_num = (int) c;
          char_num = ((char_num - 65 + key_num) % 26 ) + 65;
          c = (char) char_num;
          printf("%c", c);
          key_counter++;
        }
        else if (islower(c))
        {
          int key_num = key_to_num(key, key_counter);
          int char_num = (int) c;
          char_num = ((char_num - 97 + key_num) % 26 ) + 97;
          c = (char) char_num;
          printf("%c", c);
          key_counter++;
        }
        else
        {
          printf("%c", c);
        }
      }
      printf("\n");

      return 0;
    }

    // Key including non alphabet character
    else
    {
      printf("Use only alphabets in key.\n");
      return 1;
    }
  }

  // More or less then 2 command line arguments
  else
  {
    printf("Usage: /path/to/vigenere <key>\n");
    return 1;
  }
}

// Check key for alphabet
bool key_check(string text)
{
  bool status = true;
  for (int a =0; a < strlen(text) && status; a++)
  {
    status = isalpha(text[a]);
  }
  return status;
}

// Key to number
int key_to_num(string key, int key_counter)
{
  int num;
  key_counter = key_counter % strlen(key);

  if (isupper(key[key_counter]))
  {
    num = ((int) key[key_counter]) - 65;
  }
  else
  {
    num = ((int) key[key_counter]) - 97;
  }

  return num;
}
