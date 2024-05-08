//Project 7
//By Skyler Resnick and Adam Beltran
//May 7, 2024

#include <stdio.h>
#define ROW 50
#define COL 50

void MainMenu();
void loadImage(int PictureArray[][COL], int* row_count, int* column_count, FILE *Readptr);
void displayArray(int PictureArray[][COL], int row_count, int column_count);
void dimmen(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count);
void EditMenu(int PictureArray[][COL], int row_count, int column_count);
void brighten(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count);
void crop(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count, int *row_crop, int *column_crop);
void SaveImageToFile(int PictureArray[][COL], int row_count, int column_count);

int main() {
    FILE* Readptr;
    char FileName[100];
    int choice;
    int PictureArray[ROW][COL];
    int row_count = 0, column_count = 0;

    do {
        MainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your file name: ");
                scanf("%s", FileName);
                Readptr = fopen(FileName, "r");
                if (Readptr == NULL) {
                    printf("Unable to load file... Please try again.\n");
                    return 0;
                }
                loadImage(PictureArray, &row_count, &column_count, Readptr);
                printf("Image Loaded!\n");
                fclose(Readptr);
                break;
            case 2:
                displayArray(PictureArray, row_count, column_count);
                break;
            case 3:
                EditMenu(PictureArray, row_count, column_count);
                break;
            case 0:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Sorry not an option! try again!\n");
        }
    } while (choice != 0);

    return 0;
}

void MainMenu() {
    printf("***TEAM 7STAGRAM***\n");
    printf("1: Load image\n");
    printf("2: Display Image\n");
    printf("3: Edit Image\n");
    printf("0: Exit\n");
    printf("Enter your option!: ");
}

void EditMenu(int PictureArray[][COL], int row_count, int column_count) {
    int OriginalArray[ROW][COL];
    char editChoice;
    int row_crop;
    int column_crop;
    do {
        printf("\n**EDITING**\n");
        printf("1: Crop picture\n");
        printf("2: Dim picture\n");
        printf("3: Brighten picture\n");
        printf("4: Save Image\n");
        printf("0: Return to main menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &editChoice);

        switch (editChoice) {
            case '1':
                crop(PictureArray, OriginalArray, row_count, column_count, &row_crop, &column_crop);
                break;
            case '2':
                dimmen(PictureArray, OriginalArray, row_count, column_count);
                break;
            case '3':
                brighten(PictureArray, OriginalArray, row_count, column_count);
                break;
            case '4':
                SaveImageToFile(PictureArray, row_count, column_count);
                break;
            case '0':
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (editChoice != '0');
}

void loadImage(int PictureArray[][COL], int* row_count, int* column_count, FILE *Readptr) {
    char Scan;
    int rows = 0, cols = 0;

    while (fscanf(Readptr, "%c", &Scan) == 1) {
        if (Scan == '\n') {
            *column_count = cols;
            rows++;
            cols = 0;
        } else {
            PictureArray[rows][cols] = Scan - '0';
            cols++;
        }
    }
    *row_count = rows;
}

void displayArray(int PictureArray[][COL], int row_count, int column_count) {
    char Scan;
    for (int row = 0; row < row_count; row++) {
        for (int column = 0; column < column_count; column++) {
            if (PictureArray[row][column] == 0) {
                Scan = ' ';
            } else if (PictureArray[row][column] == 1) {
                Scan = 'o';
            } else if (PictureArray[row][column] == 2) {
                Scan = '.';
            } else if (PictureArray[row][column] == 3) {
                Scan = 'O';
            } else if (PictureArray[row][column] == 4) {
                Scan = '0';
            }
            printf("%c", Scan);
        }
        printf("\n");
    }
}

void dimmen(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count) {
    char Scan;
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            if (PictureArray[i][j] >= 0 && PictureArray[i][j] < 4) {
                OriginalArray[i][j] = PictureArray[i][j] - 1;
                if (OriginalArray[i][j] == 0) {
                    Scan = ' ';
                } else if (OriginalArray[i][j] == 1) {
                    Scan = 'o';
                } else if (OriginalArray[i][j] == 2) {
                    Scan = '.';
                } else if (OriginalArray[i][j] == 3) {
                    Scan = 'O';
                } else if (OriginalArray[i][j] == 4) {
                    Scan = '0';
                }
                printf("%c", Scan);
            }
        }
        printf("\n");
    }
}

void brighten(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count) {
    char Scan;
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            if (PictureArray[i][j] >= 0 && PictureArray[i][j] < 4) {
                OriginalArray[i][j] = PictureArray[i][j] + 1;
                if (OriginalArray[i][j] == 0) {
                    printf(" ");
                } else if (OriginalArray[i][j] == 1) {
                    printf("o");
                } else if (OriginalArray[i][j] == 2) {
                    printf(".");
                } else if (OriginalArray[i][j] == 3) {
                    printf("O");
                } else if (OriginalArray[i][j] == 4) {
                    printf("0");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void crop(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count, int *row_crop, int *column_crop) {
    int LeftCrop, RightCrop, UpCrop, DownCrop;
    for (int row = 0; row < row_count; row++) {
        for (int column = 0; column < column_count; column++) {
            if (PictureArray[row][column] == 0) {
                printf(" ");
            } else if (PictureArray[row][column] == 1) {
                printf("o");
            } else if (PictureArray[row][column] == 2) {
                printf(".");
            } else if (PictureArray[row][column] == 3) {
                printf("O");
            } else if (PictureArray[row][column] == 4) {
                printf("0");
            }
        }
        printf("\n");
    }
    printf("\n");

    printf("The image you want to crop is %d X %d.\n", row_count + 1, column_count);
    row_count--;
    printf("The row and column values start in the upper right hand corner.\n");

    printf("What column do you want to be the new left side?: ");
    scanf("%d", &LeftCrop);

    printf("What column do you want to be the new right side?: ");
    scanf("%d", &RightCrop);

    printf("What column do you want to be the new top?: ");
    scanf("%d", &DownCrop);

    printf("What column do you want to be the new Bottom?: ");
    scanf("%d", &UpCrop);

    for (int i = UpCrop; i < row_count - DownCrop; i++) {
        for (int j = LeftCrop; j < column_count - RightCrop; j++) {
            OriginalArray[i - UpCrop][j - LeftCrop] = PictureArray[i][j];
        }
    }
}
void SaveImageToFile(int PictureArray[][COL], int row_count, int column_count) {
    char FileName[100];
    char choice;
    printf("Save Image to File? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the name of the file: ");
        scanf("%s", FileName);
        FILE *Writeptr = fopen(FileName, "w");
        if (Writeptr == NULL) {
            printf("Error opening file for writing.\n");
            return;
        }
        

        for (int i = 0; i < row_count; i++) {
            for (int j = 0; j < column_count; j++) {
                fprintf(Writeptr, "%d", PictureArray[i][j]);
            }
            fprintf(Writeptr, "\n");
        }
        fclose(Writeptr);
    }
}

