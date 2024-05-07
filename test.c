//Author: Christian Gogo & Austin Seaver
//Date: 04/29/24/Mon/1458
//Purpose: Group Final Project

#include <stdio.h>
#define READ_NEW_IMAGE "new_image.txt"
#define WRITE_NEW_IMAGE "write.txt"
#define COL 200
#define	ROW 200
#define FILE_SIZE 100


void loadImage(FILE* readFilePointer), displayImage(FILE* readFilePointer), editImage(int rowI, int colI, FILE* readFilePointer), cropImage(int rowI, int colI, FILE* readFilePointer), dimImage(int rowI, int colI, FILE* readFilePointer), brightenImage(), rotateImage(), saveImage(FILE* writeFilePointer);


int main(){
	char displayArray[ROW][COL];
	char menuChoice;
	FILE* readFilePointer;
	FILE* writeFilePointer;
	
	int colI = 0, rowI = 0;
	int dimOrBright;

	do{
	printf("**TEAM_9_STAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n\n");
	printf("Choose from one of the options above: ");
	scanf(" %c", &menuChoice);

	
	switch(menuChoice){
		case '1':
	
			loadImage(readFilePointer);
			break;
		case '2':
			displayImage(readFilePointer);
			break;
		case '3':
			editImage(rowI, colI, readFilePointer);
			break;
		case '0':
			break;
		default:
			printf("Invalid option\n");
			break;
		}
	}while(menuChoice != '0');	
	return 0;
}


void loadImage(FILE* readFilePointer){
	int colI, rowI;
	char loadArray[ROW][COL];
	char fileName[FILE_SIZE];
	printf("What is the name of the image file? ");
	scanf(" %s", fileName);
	readFilePointer = fopen(fileName, "r");
	if(readFilePointer == NULL){
		printf("Could not find an image with that file name.\n");
	}
	else{

		
		while(fscanf(readFilePointer,"%c", &loadArray[rowI][colI]) == 1){
			colI++;
			if (loadArray[rowI][colI] == '\n'){
				rowI++;
			}
		}
		printf("Image loaded successfully\n");
	}
	

}

void displayImage(FILE* readFilePointer){
	int colI, rowI;
	char loadArray[ROW][COL];
	//figure out how to remove below line
	readFilePointer = fopen(READ_NEW_IMAGE, "r");
	if(readFilePointer == NULL){
		printf("Could not find an image with that file name.\n");
	}
	
		while(fscanf(readFilePointer,"%c", &loadArray[rowI][colI]) == 1){
			switch(loadArray[rowI][colI]) {
           			case '0':
           	     			printf(" ");
              	  			break;
            			case '1':
                			printf(".");
               	 			break;
            			case '2':
                			printf("o");
                			break;
            			case '3':
                			printf("O");
                			break;
            			case '4':
                			printf("0");
                			break;
            		//Error check
                	printf("X");
        		}
			colI++;
			if (loadArray[rowI][colI] == '\n'){
				printf("\n");
				rowI++;
			}
		}
	printf("\n");
}
void editImage(int rowI, int colI, FILE* readFilePointer){
	char editChoice;
	readFilePointer = fopen(READ_NEW_IMAGE, "r");
	printf("**EDITING**\n");
	printf("1: Crop Image\n");
	printf("2: Dim Image\n");
	printf("3: Brighten Image\n");
	printf("0: Return to main menu\n\n");
	printf("Choose from one of the options above: ");
	scanf(" %c", &editChoice);
	do{
	switch(editChoice){
		case '1':
		cropImage(rowI, colI, readFilePointer);
			break;
		case '2':
		dimImage(rowI, colI,readFilePointer);
			break;
		case '3':
		brightenImage(rowI, colI, readFilePointer);
			break;
		case '0':
		printf("Goodbye!");
			break;
		default:
			printf("Invalid option, please try again.");	
			break;
			}
	}while(editChoice != 0);	
}

void cropImage(int rowI, int colI, FILE* readFilePointer){
	
	int left, right, top, bottom;
	char displayArray[ROW][COL];
	//We need to make variables for the image we are going to crop
	printf("The image you want to crop is %d x %d.\n", rowI, colI);
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &left);
	printf("Which column do you want to be the new right side? ");
	scanf("%d", &right);
	printf("Which row do you want to be the new top? ");
	scanf("%d", &top);
	printf("Which row do you want to be the new bottom? ");
	scanf("%d", &bottom);
	
	for (int top; top <= bottom; top++){
		for(int left; left <= right; left++){
		
		}
	}

}

void dimImage(int rowI, int colI, FILE* readFilePointer){
	char loadArray[ROW][COL];
	//figure out how to remove below line
	readFilePointer = fopen(READ_NEW_IMAGE, "r");
	while(fscanf(readFilePointer,"%c", &loadArray[rowI][colI]) == 1){
			switch(loadArray[rowI][colI]) {
           			case '0':
           	     			printf(" ");
              	  			break;
            			case '1':
                			printf(" ");
               	 			break;
            			case '2':
                			printf(".");
                			break;
            			case '3':
                			printf("o");
                			break;
            			case '4':
                			printf("O");
                			break;         		
        		}
			colI++;
		if (loadArray[rowI][colI] == '\n'){
			printf("\n");
			rowI++;
		}
	}
}

void brightenImage(int rowI, int colI, FILE* readFilePointer){
	char loadArray[ROW][COL];
		//figure out how to remove below line
		readFilePointer = fopen(READ_NEW_IMAGE, "r");
		while(fscanf(readFilePointer,"%c", &loadArray[rowI][colI]) == 1){
			switch(loadArray[rowI][colI]) {
           			case '0':
           	     			printf(".");
              	  			break;
            			case '1':
                			printf("o");
               	 			break;
            			case '2':
                			printf("O");
                			break;
            			case '3':
                			printf("0");
                			break;
            			case '4':
                			printf("0");
                			break;
            		}
			colI++;
			if (loadArray[rowI][colI] == '\n'){
				printf("\n");
				rowI++;
			}
		}
}

void saveImage(FILE* writeFilePointer){
	char saveChoice;
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &saveChoice);
		switch(saveChoice){
			case 'y':
				char fileName[FILE_SIZE];
				printf("What do you want to name the image file? (include the extension) ");
				scanf(" %s", fileName);
				writeFilePointer = fopen(fileName, "w");
	 			fclose(writeFilePointer);
	 			printf("Image successfully saved!\n");	
				break;
		
			case 'n':
				printf("\n");
				break;
		}
}	
