#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(char *s);
int count_words(char *s);
int count_sentences(char *s);
int get_reading_grade(int letters, int words, int sentences);

int main(void)
{
    char text[400];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    //printf("%s\n", text);
    int no_of_letters = count_letters(text);
    //printf("%i letter(s)\n", no_of_letters);
    int no_of_words = count_words(text);
    //printf("%i word(s)\n", no_of_words);
    int no_of_sentences = count_sentences(text);
    //printf("%i sentence(s)\n", no_of_sentences);
    int grade = get_reading_grade(no_of_letters, no_of_words, no_of_sentences);
    if (grade <= 16)
    {
        printf("Grade %i\n", grade);    
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int count_letters(char *s)
{
    int count = 0;
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (isalpha(s[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(char *s)
{
    int count = 0;
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if isspace(s[i])
        {
            count += 1;
        }
    }
    return count;
}

int count_sentences(char *s)
{
    int count = 0;
    int n = strlen(s);
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            count += 1;
        }
    }
    return count;
}

int get_reading_grade(int letters, int words, int sentences)
{
    float L = (letters/(float) words) * 100;
    float S = (sentences/(float) words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index > 1)
    {
        return (int) round(index);
    }
    else
    {
        return 1;
    }
}
