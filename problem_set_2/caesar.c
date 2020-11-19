#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
    // Errors if none or more than one command line argument given
    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }
    else
    {
        // For use in for loop
        int n = strlen(argv[1]);
        int digit_check = 0;
        
        for (int i = 0; i < n; i++)
        {
            if isdigit(argv[1][i])
            {
                // Counts number of digits in command line argument
                digit_check += 1;
            }        
        }
        // Checks if all chars in command line argument are digits
        if (digit_check == n)
        {
            char plaintext[400];
            // Get user input, in place of CS50 get_string()
            printf("plaintext : ");
            fgets(plaintext, sizeof(plaintext), stdin);
    
            int n = strlen(plaintext);
            // Convert command line argument to int
            int key = atoi(argv[1]);

            for (int i = 0; i < n; i++)
            {
                if (isalpha(plaintext[i]))
                {
                    if (isupper(plaintext[i]))
                    {
                        // For uppercase letters create alphabet index where A = 0 and Z = 25 [0 - 25]
                        // In ascii A = 65  so -65 sets it to 0
                        int alpha_index = plaintext[i] - 65;
                        // Wrap around cipher formula ci = (pi + k) % 26
                        alpha_index = (alpha_index + key) % 26;
                        // Converts alphabet index back to ascii A-Z [65 - 90]
                        plaintext[i] = alpha_index + 65;
                        
                    }
                    if (islower(plaintext[i]))
                    {
                        // For lowercase letters create alphabet index where a = 0 and z = 25
                        // In ascii a = 97 so -97 sets it to 0
                        int alpha_index = plaintext[i] - 97;
                        alpha_index = (alpha_index + key) % 26;
                        // Converts alphabet index back to ascii a-z [97 - 122]
                        plaintext[i] = alpha_index + 97;
                    }
                }
        
            }
            printf("ciphertext: %s\n", plaintext);
        }
        else
        {
            printf("Usage: ./caeser key\n");
            return 1;
        }       
    }
   
    return 0;
}
