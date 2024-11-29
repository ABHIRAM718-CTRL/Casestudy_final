#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define MAX 2000
// Function to generate and display a random OTP
int generateOTP() {
    srand(time(NULL));
    int otp = (rand() % 9000) + 1000; // Generates random OTP between 1000 and 9999
    printf("Your OTP is: %d\n", otp);
    return otp;
}
void Exitcase() {
    exit(0); // Function to exit
}
int searchBuses(char *location, char *filename) {
    FILE *file = fopen(filename, "r"); // Using and reading through filesystem.
    if (file == NULL) {
        printf("No data in file\n");
        return 0;
    }
    char line[MAX];
    int found = 0;
    printf("\nAvailable Buses for Location '%s':\n", location);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, location) != NULL) {
            found = 1;
            char *token = strtok(line, ",");
            while (token != NULL) {
                printf("%s\t", token);
                token = strtok(NULL, ",");
            }
            printf("\n");
        }
    }

    fclose(file);
    if (!found) {
        printf("No buses found for the specified location: %s\n", location);
    }
    return found;
}

int main() {
    int choice, choice1, nop, price, enteredOTP, otp;
    char location[MAX];
    printf("WELCOME TO BEDBUS SERVICES!!!\n");
    printf("1. Book Tickets\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("Enter the location: ");
        fgets(location, sizeof(location), stdin);
        location[strcspn(location, "\n")] = '\0';

        if (searchBuses(location, "modified_busdata.csv")) {
            printf("\nChoose a Bus:\n");
            printf("1. INDRA AC : $195/person\n");
            printf("2. METRO LUXURY : $155/person\n");
            printf("3. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice1);

            if (choice1 == 1) {
                printf("Enter number of people traveling: ");
                scanf("%d", &nop);
                price = nop * 195;
                printf("Your Tickets Price is....\n");
                printf("Ticket for total number of people: %d\n", price);
                printf("Added GST: 212.562\n");
                printf("Total Price: %.2f\n", price + 212.562);

                otp = generateOTP();
                printf("Enter OTP to proceed: ");
                scanf("%d", &enteredOTP);

                if (enteredOTP == otp) {
                    printf("Booking under process.....\n");
                    sleep(3);
                    printf("Your tickets confirmed successfully\n");
                } else {
                    printf("Invalid OTP TRY AGAIN!!!\n");
                }
            } else if (choice1 == 2) {
                printf("Enter number of people traveling: ");
                scanf("%d", &nop);
                price = nop * 155;
                printf("Your Tickets Price is....\n");
                printf("Ticket for total number of people: %d\n", price);
                printf("Added GST: 155.562\n");
                printf("Total Price: %.2f\n", price + 155.562);

                otp = generateOTP();
                printf("Enter OTP to proceed: ");
                scanf("%d", &enteredOTP);

                if (enteredOTP == otp) {
                    printf("Booking under process.....\n");
                    sleep(3);
                    printf("Your tickets confirmed successfully\n");
                } else {
                    printf("Invalid OTP TRY AGAIN!!!\n");
                }
            } else {
                Exitcase();
            }
        }
    } else {
        Exitcase();
    }

    return 0;
}

