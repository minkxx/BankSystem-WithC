#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_FIELDS 4
#define MAX_LINE_LENGTH 256

void parse_and_write_to_csv(const char *input_file, const char *output_file) {
    FILE *f_input = fopen(input_file, "r");
    FILE *f_output = fopen(output_file, "w");

    if (f_input == NULL) {
        printf("Error: Unable to open input file.\n");
        return;
    }
    if (f_output == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(f_input);
        return;
    }

    char line[MAX_LINE_LENGTH];
    char *data[MAX_USERS][MAX_FIELDS]; // Stores parsed data
    int user_count = 0;

    // Initialize data array
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_FIELDS; j++) {
            data[i][j] = NULL;
        }
    }

    // Read and parse input file
    while (fgets(line, sizeof(line), f_input)) {
        if (line[0] == '\n') { // Empty line indicates a new user
            user_count++;
            continue;
        }

        // Parse key:value format
        char *colon_pos = strchr(line, ':');
        if (colon_pos != NULL) {
            *colon_pos = '\0'; // Split the line into key and value
            char *key = line;
            char *value = colon_pos + 1;

            // Remove newline character from value
            value[strcspn(value, "\n")] = '\0';

            // Add the value to the user's data array
            int field_index = (data[user_count][0] == NULL) ? 0 : 1 + (data[user_count][1] != NULL) + (data[user_count][2] != NULL);
            data[user_count][field_index] = strdup(value);
        }
    }
    fclose(f_input);

    // Write to output CSV file
    fprintf(f_output, "Account Holder,Bank Name,Account Number,Balance\n"); // Header
    for (int i = 0; i <= user_count; i++) {
        if (data[i][0] != NULL) {
            fprintf(f_output, "%s,%s,%s,%s\n",
                    data[i][0] ? data[i][0] : "",
                    data[i][1] ? data[i][1] : "",
                    data[i][2] ? data[i][2] : "",
                    data[i][3] ? data[i][3] : "");
        }
    }
    fclose(f_output);

    // Free dynamically allocated memory
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_FIELDS; j++) {
            if (data[i][j] != NULL) {
                free(data[i][j]);
            }
        }
    }
}

int main() {
    const char *input_file = "accounts.txt";
    const char *output_file = "accounts.csv";

    parse_and_write_to_csv(input_file, output_file);

    // printf("Data has been successfully written to %s\n", output_file);
    return 0;
}
