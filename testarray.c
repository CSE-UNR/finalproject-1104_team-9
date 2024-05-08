//Test3


#include <stdio.h>
#define ROW 50
#define COL 50
#define FILE_SIZE 200

int loadImage(FILE* fptr);
void displayImage(int rowI, int colI, char mainArray[][COL]);

int main(){
	int rows = 0, cols = 0;
	FILE* fptr;
	char mainArray[ROW][COL];
	loadImage(fptr);
	displayImage(rows, cols, mainArray);
	return 0;
	
}

int loadImage(FILE* fptr){
	int rowI = 0, colI = 0, rows = 0, cols = 0;
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
		printf("%c", loadArray[rowI][colI]);
			colI++;
			if(loadArray[rowI][colI] == '\n'){
				rowI++;	
			}
		}
		printf("Image loaded successfully\n");
	}
	rows = rowI;
	cols = colI;
	fclose(fptr);
	return loadArray[rows][cols];
}

void displayImage(int rows, int cols, char mainArray[][cols]){
		int rowI, colI;
		char displayArray[rows][cols];
		for(rowI = 0; rowI <= rows; rowI++){
			for(colI = 0; colI <= cols; colI++){
				//while(displayArray[rowI][colI] == 1){
				printf("%c", displayArray[rowI][colI]);
				//colI++;
			//	if (mainArray[rowI][colI] == '\n'){
			//		rowI++;
				
			//	}
				//}
			}
			printf("%c", displayArray[rowI][colI]);
		}
		//printf("%c", displayArray[rowI][colI]);
	//printf("\n");
}


