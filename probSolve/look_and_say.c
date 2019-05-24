/* Look and Say Pattern Generation:
    The pattern is generated while looking at the previous row and saying out
    the number of times the given number has occurred either before another number or
    before encountering end of line. (The pattern always starts from 1)
    
    Example of the pattern with 6 rows:
    1
    11
    21
    1211
    111221
    312211
*/

#include <stdio.h>
#include <string.h>

// Appending a character at the end of a given string
void append(char* s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

// Logic for generation of pattern
void generate_row(int n){
    char str[100] = "1";
    printf("1\n");

    // Additional character array to store the intermediate string.
    char string[100] = "";

    // To store counts of unique digit occurrence.
    int count = 1;

    for(int i = 0; i < n - 1; i++){
        strcpy(string, "");
        
        // Reset counter for every row
        count = 1;
        for (int j = 0; j < strlen(str); j++){
            if (str[j + 1]){
                if (str[j] == str[j + 1]){
                    count++;
                    continue;
                }
                else{

                    // count + '0' results in typecasting integer
                    append(string, count + '0'); // Append count
                    append(string, str[j]);      // Append character
                     
                    // Reset counter for following digit
                    count = 1;
                }
            }
            else{
                append(string, count + '0');
                append(string, str[j]);
            }
        }
        printf("%s", string);
        printf("\n");
        strcpy(str, string);
    }
}

int main(void){
    int num;
    printf("Enter the number of row to generate: ");
    scanf("%d", &num);
    generate_row(num);
    return 0;
}