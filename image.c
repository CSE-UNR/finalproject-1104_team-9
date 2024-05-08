//Author: Christian Gogo & Austin Seaver
//Date: 05/07/24/2255
//Purpose: Group Final Project

#include <stdio.h>
#define COL 200
#define	ROW 200
#define FILE_SIZE 100


void loadImage(int rowI, int colI, char displayArray[][COL], FILE* readFilePointer);

void displayImage(int rows, int cols,char displayArray[][COL]); 

void editImage(int rowI, int colI, char displayArray[][COL], FILE* writeFilePointer);

void cropImage(int rows, int cols, char displayArray[][COL]);

void dimImage(int rows, int cols, char displayArray[][COL]);

void brightenImage(int rows, int cols, char displayArray[][COL]);

void saveImage(int rowI, int colI, char displayArray[][COL], FILE* writeFilePointer);

int main(){
	char displayArray[ROW][COL];
	char menuChoice;
	FILE* readFilePointer;
	FILE* writeFilePointer;
	
	int rows = 0, cols = 0, rowI = 0, colI = 0;
	do{
		printf("**TEAM_9_STAGRAM**\n");
		printf("1: Load image\n");
		printf("2: Display image\n");
		printf("3: Edit image\n");
		printf("0: Exit\n");
		printf("Choose from one of the options above: ");
		scanf(" %c", &menuChoice);

	
		switch(menuChoice){
			case '1':
				loadImage(rows, cols, displayArray, readFilePointer);
				break;
			case '2':
				displayImage(ROW, COL, displayArray);
				break;
			case '3':
				editImage(rows, cols, displayArray, writeFilePointer);
					break;
			case '0':
				printf("Goodbye!\n");
				break;
			default:
				printf("Invalid option\n");
				break;
		}
	}while(menuChoice != '0');	
	return 0;
}

void loadImage(int rowI, int colI, char displayArray[][colI], FILE* readFilePointer){
	char fileName[FILE_SIZE];
	printf("What is the name of the image file? ");
	scanf(" %s", fileName);
	readFilePointer = fopen(fileName, "r");
	if(readFilePointer == NULL){
		printf("Could not find an image with that file name.\n");
	}
	else{
		while(fscanf(readFilePointer,"%c", &displayArray[rowI][colI]) == 1){
			colI++;
		}
		printf("Image loaded successfully\n");
	}
	fclose(readFilePointer);
}
void displayImage(int rows, int cols, char displayArray[][COL]){
	//if(displayArray[ROW][COL] == 0){
	//	printf("Sorry, no image to display\n");
	//}
	int rowI = 0, colI = 0;
		for(int rowI = 0; rowI <= rows; rowI++){
			for(int colI = 0; colI <= cols; colI++){
				switch(displayArray[rowI][colI]){
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
		        	case '\n':
		        		printf("\n");
		        		break;
				}
			}
		}
	printf("\n");	
}
void editImage(int rowI, int colI, char displayArray[][COL], FILE* writeFilePointer){
	//if(writeFilePointer == NULL){
	//	printf("Sorry, no image to edit\n");	
	//}
	char editChoice;
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
			cropImage(ROW, COL, displayArray);
				break;
			case '2':
			dimImage(ROW, COL, displayArray);
			saveImage(rowI, colI, displayArray, writeFilePointer);
				break;
			case '3':
			brightenImage(ROW, COL, displayArray);
			saveImage(rowI, colI, displayArray, writeFilePointer);
				break;
			case '0':
			printf("\n");
				break;
			default:
				printf("Invalid option, please try again.");	
				break;
		}
	}while(editChoice == 0);	
}

//Tried to crop size, would only print double row size return
void cropImage(int rows, int cols, char displayArray[][cols]){
	int rowI = 0, colI = 0;
	int left, right, top, bottom;
	int rlDiff, tbDiff;
	printf("The image you want to crop is %d x %d.\n", rows, cols);
	printf("The row and column values start in the upper lefthand corner.\n");
	printf("Which column do you want to be the new left side? ");
	scanf("%d", &left);
	printf("Which column do you want to be the new right side? ");
	scanf("%d", &right);
	printf("Which row do you want to be the new top? ");
	scanf("%d", &top);
	printf("Which row do you want to be the new bottom? ");
	scanf("%d", &bottom);
	
	rlDiff = right - left;
	tbDiff = top - bottom;
	
	if(rlDiff < 0){
		rlDiff = left - right;
	}
	if(tbDiff < 0){
		tbDiff = bottom - top;
	}
		for(int rowI = 0; rowI <= rows; rowI++){
			for(int colI = 0; colI <= cols; colI++){				
				switch(displayArray[rowI][colI]){
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
					case '\n':
						printf("\n");
						break;
				}
			}
		}
	printf("\n");		

}

void dimImage(int rows, int cols, char displayArray[][COL]){
	int rowI = 0, colI = 0;
		for(int rowI = 0; rowI <= rows; rowI++){
			for(int colI = 0; colI <= cols; colI++){
				if(displayArray[rowI][colI] < 0){
					displayArray[rowI][colI] = 0;
				}					
				switch(displayArray[rowI][colI]){
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
					case '\n':
						printf("\n");
						break;
				}
			}
		}	
	printf("\n");
}

void brightenImage(int rows, int cols, char displayArray[][COL]){
	int rowI = 0, colI = 0;
		for(int rowI = 0; rowI <= rows; rowI++){
			for(int colI = 0; colI <= cols; colI++){				
				switch(displayArray[rowI][colI]){
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
					case '\n':
						printf("\n");
						break;
				}
			}
		}
	printf("\n");		
}

void saveImage(int rowI, int colI, char displayArray[][COL], FILE* writeFilePointer){
	char saveChoice;
	printf("Would you like to save the file? (y/n) ");
	scanf(" %c", &saveChoice);
		switch(saveChoice){
			case 'y':
				char fileName[FILE_SIZE];
				printf("What do you want to name the image file? (include the extension) ");
				scanf(" %s", fileName);
				writeFilePointer = fopen(fileName, "w");
				fprintf(writeFilePointer,"%c", displayArray[rowI][colI]);
	 			fclose(writeFilePointer);
	 			printf("Image successfully saved!\n");	
				break;
		
			case 'n':
				printf("\n");
				break;
		}
}	
