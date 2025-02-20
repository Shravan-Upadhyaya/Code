#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int evaluate_password_strength(const char *password) 
{
    int strength = 0;
    int hasupper = 0, haslower = 0, hasdigit = 0, hasspecial = 0;
    if (strlen(password) >= 8) strength++;
    for (int i = 0; password[i] != '\0'; i++) 
    {
        if (isupper(password[i])) hasupper = 1;
        else if (islower(password[i])) haslower = 1;
        else if (isdigit(password[i])) hasdigit = 1;
        else hasspecial = 1;
    }

    if (hasupper) strength++;
    if (haslower) strength++;
    if (hasdigit) strength++;
    if (hasspecial) strength++;

    return strength;
}
void identify_vulnerabilities(const char *password) 
{
    if (strlen(password) < 8) 
    {
        printf("  * Password is too short (less than 8 characters).\n");
    }
    if (strstr(password, "password") != NULL) 
    {
        printf("  * Password contains the word 'password'.\n");
    }
    if (strcmp(password, "123456") == 0 || strcmp(password, "password") == 0) 
    {
        printf("  * Password is one of the most common passwords.\n");
    }
}

int main() 
{
    FILE *input_file, *output_file;
    char line[256];
    char username[128], password[128];
    input_file = fopen("credentials.txt", "r");
    if (input_file == NULL) 
    {
        perror("Error opening input file");
        return 1;
    }
    output_file = fopen("compromised_credentials.txt", "w");
    if (output_file == NULL) 
    {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    printf("Compromised Credentials:\n");
    fprintf(output_file, "Compromised Credentials:\n");
    while (fgets(line, sizeof(line), input_file)) 
    {

        if (sscanf(line, "%127[^:]:%127s", username, password) == 2) 
        {
            printf("\nUsername: %s, Password: %s\n", username, password);

            int strength = evaluate_password_strength(password);
            printf("  Password Strength: %d/5\n", strength);

            if(strength!=5)
            {
                fprintf(output_file, "Username: %s, Password: %s\n", username, password);
            }

            printf("  Potential Vulnerabilities:\n");
            identify_vulnerabilities(password);
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("\nReports generated successfully. Check 'compromised_credentials.txt' for details.\n");
    return 0;
}