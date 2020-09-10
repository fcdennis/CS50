#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE; //defining that 1 byte = 8 bits

#define BLOCK_SIZE 512 //constant of the block size
#define FILE_SIZE 8 // constant of the first block of the file

bool is_start_new_jpeg(BYTE buffer[]); // call the function that verifies if it's a jpeg

int main(int argc, char *argv[])
{
    // validation if there's two argument in the command line
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //verifing if the file exist
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("FILE not found\n");
        return 1;
    }
    
    //defining the variables
    BYTE buffer[BLOCK_SIZE];
    int file_position = 0;
    bool first_jpg = false;
    FILE *outfile;
    char filename[FILE_SIZE];
    
    //the main part of the code
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        if (is_start_new_jpeg(buffer)) // start verifying if the part of the memory is a jpeg
        {
            if (!first_jpg)
            {
                first_jpg = true;
            }
            else
            {
                fclose(outfile);
            }
            
            sprintf(filename, "%03i.jpg", file_position++);
            outfile = fopen(filename, "w");
            
            if (outfile == NULL)
            {
                return 1;
            }
            
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (first_jpg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    
    //cleaning the buffer
    fclose(outfile);
    fclose(infile);
}

//verify if the fourth firsts parts of the code is a jpeg archive
bool is_start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0; 
}