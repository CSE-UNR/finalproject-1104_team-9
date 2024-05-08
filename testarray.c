//Test3


#include <stdio.h>
#define ROW 20
#define COL 20
#define FILE_SIZE 50

int loadImage(FILE* fptr);
void displayImage(int rows, int cols, char mainArray[][cols]);

int main(){
	int rows = 0, cols = 0;
	FILE* fptr;
	char mainArray[ROW][COL];
	loadImage(fptr);
	displayImage(rows, cols, mainArray);
	return 0;
	
}

int loadImage(FILE* fptr){
	int rowI = 0, colI = 0;
	char fileName[FILE_SIZE];
	char loadArray[ROW][COL];
	printf("What is the name of the image file? ");
	scanf(" %s", fileName);
	fptr = fopen(fileName, "r");
	if(fptr == NULL){
		printf("Could not find an image with that file name.\n");
	}
	else{
		while(fscanf(fptr,"%c", &loadArray[rowI][colI]) == 1){
			colI++;
			if (loadArray[rowI][colI] == '\n'){
				rowI++;
			}
		}
		printf("Image loaded successfully\n");
	}
	fclose(fptr);
	//return loadArray[rowI][colI];
	
}

void displayImage(int rows, int cols, char mainArray[][cols]){
		
		char displayArray[rows][cols];
	for(int rowI = 0; rowI <= rows; rowI++){
		for(int colI = 0; colI <= cols; colI++){
			printf("%c", displayArray[rowI][colI]);
		}
	}
	printf("\n");
}


