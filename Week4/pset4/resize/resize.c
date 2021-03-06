/*
* resize (less comfortable)
*
* CS50 Pset4
*/
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // handles 0 < n <= 100
    int n = atoi(argv[1]);
    if (n <= 0 || n > 100)
    {
        fprintf(stderr, "Try again with 0 < n <= 100.\n");
        return 2;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, nbf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, nbi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    nbf = bf;
    nbi = bi;

    // Changing height, width in header of new image
    nbi.biWidth *= n;
    nbi.biHeight *= n;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (nbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // changing image and file size in new image's header
    nbi.biSizeImage = ((sizeof(RGBTRIPLE) * nbi.biWidth) + new_padding) * abs(nbi.biHeight);
    nbf.bfSize = nbi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&nbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&nbi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        // Array to store entire row and counter
        RGBTRIPLE store[nbi.biWidth + 2];
        int counter = 0;
    
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // store RGB triple in array
            for (int l = 0; l < n; l++)
            {
                store[counter] = triple;
                counter++;
            }
        }
		    
        // Write the whole array and new padding "n" times in outfile
        for (int o = 0; o < n; o++)
        {
            for (int m = 0; m < nbi.biWidth; m++)
            {
                fwrite (&store[m], sizeof(RGBTRIPLE), 1, outptr);
		    }
	
            for (int k = 0; k < new_padding; k++)
            {
                fputc(0x00, outptr);
            }
        }
		    
        // skip over padding, if any in infile
        fseek(inptr, padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
