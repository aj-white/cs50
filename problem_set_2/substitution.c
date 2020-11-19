#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // raise error if no command line arguement given
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Raise error if not 26 characters in length
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    else
    {
        // Check for non-alphabetical characters
        int char_check = 0;
        for (int i = 0; i < 26;i++)
        {
            if (isalpha(argv[1][i]))
            {
                char_check += 1;
            }
        }
        if (char_check == 26)
        {
            // Make key all upper case, otherwise rest of logic fails
            for (int i = 0; i < 26; i++)
            {
                argv[1][i] = toupper(argv[1][i]);
            }

            // Check for duplicates
            int duplicates = 0;
            for (int i = 0; i < 26;i++)         
            {
                for (int j = i + 1; j < 26; j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        duplicates += 1;
                    }
                }
            }
            if (duplicates == 0)
            {
                char plaintext[400];
                // Get user input, in place of CS50 get_string()
                printf("plaintext : ");
                fgets(plaintext, sizeof(plaintext), stdin);
         
                int n = strlen(plaintext);
                // Create a key in lower case to hanndle lower case substitution
                char lower_key[26];
                for (int i = 0; i < 26; i++)
                {
                    lower_key[i] = tolower(argv[1][i]);
                
                }
                for (int i = 0; i < n; i++)
                {
                    // Only changes alphabetical characters
                    if (isalpha(plaintext[i]))
                    {
                        if (isupper(plaintext[i]))
                        {
                            // Creates a [0 - 25] index from ascii
                            // Can use new index as index for key
                            int alpha_index = plaintext[i] - 65;
                            plaintext[i] = argv[1][alpha_index];
                        }
                        if (islower(plaintext[i]))
                        {
                        
                            // Creates a [0 - 25] index from ascii
                            // Can use new index as index for key
                            int alpha_index = plaintext[i] - 97;
                            plaintext[i] = lower_key[alpha_index];
                            
                        }

                    }
                }
            
                printf("ciphertext: %s\n", plaintext);
                return 0;
            }
            else
            {
                printf("Key contains duplicate characters\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain alphabetical characters only\n");
            return 1;
        }
        
    }
}
