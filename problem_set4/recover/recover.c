#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	// Ckeck if CLI arguments correct
	if (argc != 2)
	{
		printf("Usage: ./recover filename\n");
		return 1;
	}
	
	// Create pointer to data file
	char *data = argv[1];
	FILE *inptr = fopen(data, "r");
	if (inptr == NULL)
	{
		printf("Error opening file %s\n", data);
		return 2;
	}
	
	// Create a buffer to read file into
	BYTE bf[512];
		
	// Create pointer for jpeg image files
	FILE *img = NULL;
	
	// Create variable used for program
	char jpg_filename[10];
	int counter = 0;
	
	
	// Read in data 512 bytes at a time to end of card
	while (fread(&bf, sizeof(bf), 1, inptr))
	{
		// Find jpeg header
		if (bf[0] == 0xff && bf[1] == 0xd8 && bf[2] == 0xff && (bf[3] & 0xf0) == 0xe0)
		{
			
			if (counter > 0)
			{
				// Closes current jpeg file if another jpeg detected
				fclose(img);
			}
			
			// Set jepg filename template, use number from counter to increment filenames
			sprintf(jpg_filename, "%03i.jpg", counter);
			
			// Open new file to store recovered data
            img = fopen(jpg_filename, "w");
            if (img == NULL)
            {
                fclose(inptr);
                printf("Could not create file %s\n", jpg_filename);
                return 3;
            }
			
			// Write data chunk to file
			fwrite(&bf, sizeof(bf), 1, img);
			
			counter++;
		}
		else if (counter > 0)
		{
			fwrite(&bf, sizeof(bf), 1, img);
		}
		
	}
	
	fclose(img);
	fclose(inptr);
	
	return 0;	
}
