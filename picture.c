#include <stdio.h>
#define ROW 100
#define COL 100
void MainMenu();
void loadImage(int PictureArray[][COL], int* row_count, int* column_count, FILE *Readptr);
void disaplyArray(int PictureArray[][COL], int row_count, int column_count);
void dimmen(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count);
void EditMenu(int PictureArray[][COL], int row_count, int column_count, FILE *Readptr);
void brighten(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count);
void crop(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count, int *row_crop, int *column_crop);
void SaveImageToFile(int PictureArray[][COL], int row_count, int column_count, FILE *Readptr);
int main(){
    FILE* Readptr;
    
  char FileName[100];
  int loop = 1;
  int choice;
  int PictureArray[ROW][COL];
  int row_count = 0, column_count = 0, total_count;
do{
    MainMenu();
    scanf("%d", &choice);
    
    switch(choice){
      case 1: 
    printf("Enter your file name: ");
    scanf("%s", FileName);
    Readptr = fopen(FileName, "r");
    if(Readptr == NULL){
        printf("Unable to load file... Please try again.\n");
        return 0;
    }
    loadImage(PictureArray, &row_count, &column_count, Readptr);
     printf("Image Loaded!\n");
     fclose(Readptr);
    break;
      case 2:
      disaplyArray(PictureArray, row_count, column_count);
      break;
      case 3: 
      EditMenu(PictureArray, row_count, column_count, Readptr);
      break;
      case 0:
            printf("Goodbye!\n");
            return 0;
      break;
      default:
      printf("Sorry not an option! try again!\n");
    }
}while(choice != 0);
    return 0;
}
void MainMenu(){
  printf("***TEAM 7STAGRAM***\n");
  printf("1: Load image\n");
  printf("2: Display Image\n");
  printf("3: Edit Image\n");
  printf("0: Exit\n");
  printf("Enter your option!: ");
}
void EditMenu(int PictureArray[][COL], int row_count, int column_count, FILE *Readptr){
    int rows = row_count;
    int cols = column_count;
    int OriginalArray[ROW][COL];
    char editChoice;
    int row_crop, column_crop;
    char saveChoice;
    char FileName[100];
    FILE* Writeptr;
do {
        printf("\n**EDITING**\n");
        printf("1: Crop picture\n");
        printf("2: Dim picture\n");
        printf("3: Brighten picture\n");
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
            case '0':
                printf("Returning to main menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        disaplyArray(OriginalArray, rows, cols);
        printf("Save image to a file? (y/n): ");
        scanf(" %c", &saveChoice);
        
        if(saveChoice == 'y' || saveChoice == 'Y'){
            printf("Enter your file name: ");
            scanf("%s", FileName);
            Writeptr = fopen(FileName, "w");
            SaveImageToFile(PictureArray, row_count, column_count, Readptr);
            fclose(Writeptr);
        }
        if(saveChoice == 'n' || saveChoice == 'N'){
            
        }
    } while (editChoice != '0');
}
void loadImage(int PictureArray[][COL], int* row_count, int* column_count, FILE *Readptr){
   char Scan;
   int rows = 0;
   int cols = 0;
   
   while (fscanf(Readptr, "%c", &Scan) == 1){
       if(Scan == '\n'){
           *column_count = cols;
           rows++;
           cols = 0;
       }else{
          PictureArray[rows][cols] = Scan - '0';
          cols++;
       }
   }
*row_count = rows;
}

void disaplyArray(int PictureArray[][COL], int row_count, int column_count){
    char Buffer;
    for(int row = 0; row < row_count; row++){
        for(int column = 0; column < column_count; column++){
            if(PictureArray[row][column] == 0){
                Buffer = ' ';
            } else if(PictureArray[row][column] == 1){
                Buffer = '.';
            } else if(PictureArray[row][column] == 2){
                Buffer = 'o';
            } else if(PictureArray[row][column] == 3){
                Buffer = 'O';
            } else if(PictureArray[row][column] == 4){
                Buffer = '0';
            }
            printf("%c", Buffer);
              }
        printf("\n");
        
    }
    printf("\n");  
}
void dimmen(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count){
    
    char Buffer;
    for(int i = 0; i < row_count; i++){
        for(int j = 0; j < column_count; j++){
            if(OriginalArray[i][j] > 0 && OriginalArray[i][j] <= 4){
                OriginalArray[i][j] = PictureArray[i][j] - 1;
}
}
}
}
void brighten(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count){
    char Buffer;
    for(int i = 0; i < row_count; i++){
        for(int j = 0; j < column_count; j++){
            if(OriginalArray[i][j] >= 0 && OriginalArray[i][j] < 4){
                OriginalArray[i][j] = PictureArray[i][j] + 1;
}
}
}
}
void crop(int PictureArray[][COL], int OriginalArray[][COL], int row_count, int column_count, int *row_crop, int *column_crop){
    char Buffer;
    int LeftCrop, RightCrop, UpCrop, DownCrop;
    
    printf("%d %d", row_count, column_count);
    
    

    
    printf("The image you want to crop is %d X %d.\n", row_count + 1, column_count);
    row_count - 1;
    printf("The row and column values start in the upper right hand corner.\n");
    
    printf("What column do you want to be the new left side?: ");
    scanf("%d", &LeftCrop);
    
    printf("What column do you want to be the new right side?: ");
    scanf("%d", &RightCrop);
    
     printf("What column do you want to be the new top?: ");
    scanf("%d", &DownCrop);
    
     printf("What column do you want to be the new bottom?: ");
    scanf("%d", &UpCrop);
    
       for(int i = UpCrop; i < row_count - DownCrop; i++){
        for(int j = LeftCrop; j < column_count - RightCrop; j++){
            OriginalArray[i-UpCrop][j-LeftCrop] = PictureArray[i][j];
        }
    }
    *column_crop = column_count - LeftCrop - RightCrop;
    *row_crop = row_count - UpCrop - DownCrop;
   
}
void SaveImageToFile(int PictureArray[][COL], int row_count, int column_count, FILE *Readptr){
     for(int i = 0; i < row_count; i++){
        for(int j = 0; j < column_count; j++){
       	    fprintf(Readptr, "%d", PictureArray[i][j]);
        }
        fprintf(Readptr, "\n");
    }
}
