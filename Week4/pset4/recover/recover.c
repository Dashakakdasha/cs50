/*
 * recover
 * 
 * CS50 Pset4
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

bool check_buffer(BYTE buffer[]);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover <raw_file>\n");
        return 1;
    }

    // assigning filename to var
    char* infile = argv[1];

    // infile pointer
    FILE* raw = fopen(infile, "r");
    if (raw == NULL)
    {
        fprintf(stderr, "Unable to open %s.\n", infile);
        return 2;
    }

    // image file pointer
    FILE* img = NULL;

    // counter for image files
    int file_count = 0;

    // buffer of 512bytes
    BYTE* buffer = malloc(sizeof(BYTE) * 512);

    // loop to iterate over raw file
    while(true)
    {
        
        // read from infile
        fread(buffer, 512, 1, raw);

        // conditional to check the EOF
        if (feof(raw))
        {
            break;
        }
        
        // checking the header
        if (check_buffer(buffer))
        {
            
            // checking if image file is open
            if (img != NULL)
            {
                fclose(img);
            }

            // new image file
            char* filename = malloc(sizeof(char) * 8);
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            free(filename);
            file_count++;
            
            // write 512 bytes in new image file
            fwrite(buffer, 512, 1, img);
        }
        
        else
        {
            
            // if image is open, then writes 512 bytes
            if (img != NULL)
            {
                fwrite(buffer, 512, 1, img);
            }
        }


    }
