#include <stdio.h>


//This is the test file for load function

#define COL 30
#define	ROW 30
#define FILE_SIZE 100

int main(){

	int loadArray[ROW][COL];
	
	char menuChoice;
	FILE *readFilePointer;
	
	char fileName[FILE_SIZE];
	printf("What is the name of the image file? ");
	scanf("%s", fileName);
	readFilePointer = fopen(fileName, "r");
	if(readFilePointer == NULL){
		printf("Could not find an image with that file name.\n");
	}
	else{
		for(int rowI = 0; rowI < ROW; rowI++){
			for(int colI = 0; colI < COL; colI++){
		
				while(fscanf(readFilePointer,"%d", &loadArray[ROW][COL]) == 1){
					loadArray[ROW][COL] = loadArray[rowI][colI];
					printf(" %d", loadArray[rowI][colI]);
				}
			}	
		}
		printf("Image loaded successfully\n");
	}
////////////////////////////////////////////////////////////////////	
	char displayArray[ROW][COL];
		for(int rowI = 0; rowI < ROW; rowI++){
			for(int colI = 0; colI < COL; colI++){
				displayArray[ROW][COL] = loadArray[ROW][COL];
			}
			
		}
		for(int rowI = 0; rowI < ROW; rowI++){
			for(int colI = 0; colI < COL; colI++){
				printf(" %c", displayArray[rowI][colI]);
			}
			printf("\n");
		}









	return 0;
	
}
