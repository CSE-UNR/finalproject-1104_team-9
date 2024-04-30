//Author: Christian Gogo & Austin Seaver
//Date: 04/29/24/Mon/1458
//Purpose: Group Final Project

#include <stdio.h>
#define READ_NEW_IMAGE "new_image.txt"
#define COL 200
#define	ROW 200
#define FILE_SIZE 100


void loadImage(), displayImage(), editImage(), cropImage(), dimImage(), brightenImage(), rotateImage(), saveImage();


int main(){
	char displayArray[ROW][COL];
	char menuChoice;
	FILE *readFilePointer;
	

	printf("**TEAM_9_STAGRAM**\n");
	printf("1: Load image\n");
	printf("2: Display image\n");
	printf("3: Edit image\n");
	printf("0: Exit\n");
	scanf(" %c", &menuChoice);
	
	switch(menuChoice){
		case '1':
			//function call load image file
			break;
		case '2':
			//function call to display image
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

void loadImage(){
	int loadArray[ROW][COL];
	char fileName[FILE_SIZE];
	printf("What is the name of the image file? ");
	scanf(" %s", fileName);
//	readFilePointer = fopen(fileName, "r");
//	if(readFilePointer == NULL){
		printf("Could not find an image with that file name.\n");
//	}
//	else{
		for(int rowI = 0; rowI < ROW; rowI++){
			for(int colI = 0; colI < COL; colI++){
		
//			while(fscanf(readFilePointer,"%d", &loadArray[ROW][COL]) == 1){
					loadArray[ROW][COL] = loadArray[rowI][colI];
//				}
				printf("%d", loadArray[rowI][colI]);
			}	
		}
		printf("Image loaded successfully\n");
//	}
	

}

void displayImage(){
	char displayArray[ROW][COL];
		for(int rowI = 0; rowI < ROW; rowI++){
			for(int colI = 0; colI < COL; colI++){
				displayArray[ROW][COL] = displayArray[ROW][COL];
			}
			
		}
		for(int rowI = 0; rowI < ROW; rowI++){
			for(int colI = 0; colI < COL; colI++){
				printf(" %c", displayArray[rowI][colI]);
			}
			printf("\n");
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
}

void dimImage(){
}

void brightenImage(){
}

void rotateImage(){
}

void saveImage(){
}
