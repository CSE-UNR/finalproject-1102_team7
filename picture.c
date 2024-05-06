#include <stdio.h>
#define ROW 50
#define COL 50
int MainMenu();
int EditMenu();
void loadImage(int ArrayPicture[][COL], int rows, int cols, int* row_count, int* column_count, int* file_size);



int main (){
int decision;
int PictureArray[ROW][COL];
int RowCount = 0;
int ColumnCount = 0;
int FileSize = 0;
decision = MainMenu();

switch (decision){				// Need to make sure that if the user doesnt click load image first, it says "sorry no Image is loaded!" 
	case 1:
	loadImage(PictureArray, ROW, COL, &RowCount, &ColumnCount, &FileSize);
	printf("rows: %d \n columns: %d \n total: %d \n", RowCount, ColumnCount, FileSize);
	break;
	case 2:
	EditMenu();
	break;
	case 3: 
	printf("Nothing here yet\n");
	break;
	case 0: 
	printf("Goodbye!\n");
	return 0;
	break;
	default: 
	printf("Sorry Not an option! Please try again!");
  }
return 0;
}
int MainMenu(){ // Just a menu that returns an integer value. Changed it from void, because it thought it'd be easier to read with everything occuring in the same function. 
int choice;
printf("Photo Editor\n");
printf("1: Load Image\n");
printf("2: Edit Image\n");
printf("3: Save Image\n");
printf("0: Exit\n");

printf("Enter your option:! ");
scanf("%d", &choice);
return choice;
}
int EditMenu(){ // Same thing for this function. I thought having the scanf in the same function, then returning that value makes more sense to do.(Over having the scanf outside the function) (Though both work)
int choice2;
printf("1: Display Image\n");
printf("2: Brighten Image\n");
printf("3: Dim Image\n");
printf("4: Crop Image\n");

printf("Enter your choice!: ");
scanf("%d", &choice2);
return choice2;
}
void loadImage(int ArrayPicture[][COL], int rows, int cols, int *row_count, int *column_count, int *file_size){
char FileName[100];
int index = 0;
int total = 0;
int column = 0;
printf("Enter the name of your file!: \n");
	scanf("%s", FileName);
	FILE *Readfile;
	
	Readfile = fopen(FileName, "r");	
	if(Readfile == NULL){
	printf("Sorry, couldn't find a file with that name.\n");
	}else{
	while(fscanf(Readfile, "%c", FileName) == 1){
	total++;
	if(FileName[0] == '\n'){
	index++;
	total--;
	}
	}
	}
	column = total / index;
	
	*row_count = index;
	*column_count = column;
	*file_size = total;
}
