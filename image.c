//Author: Christian Gogo & Austin Seaver
//Date: 04/29/24/Mon/1458
//Purpose: Group Final Project

#include <stdio.h>
#define READ_NEW_IMAGE "new_image.txt"
#define COL 200
#define	ROW 200
#define FILE_SIZE 100


void loadImage(FILE* readFilePointer), displayImage(FILE* readFilePointer), editImage(), cropImage(), dimImage(), brightenImage(), rotateImage(), saveImage();


int main(){
	char displayArray[ROW][COL];
	char menuChoice;
	FILE* readFilePointer;
	
	

	printf("**TEAM_9_STAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	scanf(" %c", &menuChoice);
	
	switch(menuChoice){
		case '1':
			loadImage(readFilePointer);
			
			break;
		case '2':
			displayImage(readFilePointer);
			break;
		case '3':	
			break;
		case '0':
			break;
		default:
			printf("Invalid option\n");
			break;
	}


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
	if(readFilePointer == NULL){
		printf("Could not find an image with that file name.\n");
	}
	
		while(fscanf(readFilePointer,"%c", &loadArray[rowI][colI]) == 1){
			printf("%c", loadArray[rowI][colI]);
			colI++;
		if (loadArray[rowI][colI] == '\n'){
			rowI++;
			}
		}
}
void editImage(){
	char editChoice;

	printf("**EDITING**\n");
	printf("1: Crop Image\n");
	printf("2: Dim Image\n");
	printf("3: Brighten Image\n");
	printf("0: Return to main menu\n");
	scanf(" %c", &editChoice);
	
	switch(editChoice){
		case '1':
		//function call to crop
			break;
		case '2':
		//function call to dim
			break;
		case '3':
		//function call to brigten
			break;
		case '0':
		//Figure it out
			break;
		default:
			printf("Invalid option, please try again.");	
			break;
	}
}

void cropImage(){
	int left, right, top, bottom;
	//We need to make variables for the image we are going to crop
//	printf("The image you want to crop is %d x %d.\n", );
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &left);
	printf("Which column do you want to be the new right side? ");
	scanf("%d", &right);
	printf("Which row do you want to be the new top? ");
	scanf("%d", &top);
	printf("Which row do you want to be the new bottom? ");
	scanf("%d", &bottom);
}

void dimImage(){
}

void brightenImage(){
}

void rotateImage(){
}

void saveImage(){
}
