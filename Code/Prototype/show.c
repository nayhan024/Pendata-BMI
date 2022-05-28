#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"int_only.h"
#include"kategori.h"

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap2(char *str1, char *str2)
{
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
  free(temp);
}  

void show(){
	char *filename = "bmi.txt";
    char *filename1 = "nama.txt";
	
    // open the file for reading
    FILE *fa;
	fa = fopen(filename1, "r"); 	
    if (fa == NULL){
        printf("Error opening the file %s", filename);
    }
    
	FILE *fb;
    fb = fopen(filename, "r");
    if (fb == NULL){
        printf("Error opening the file %s", filename);
    }
	
    // read the text file
    char text[100] = {'\0'};
    int i=0;
    
	int temp[100];
    char temp1[100][10] = {'\0'};
    
    while (fscanf(fb, "%s", text) == 1){
		temp[i] = atoi(text);
		fscanf(fa, "%s", temp1[i]);
		i++;
    }
	
    // copy the text
    int size = i;
    int bmi[size];
    char nama[size][10];
    
    for(i=0;i<size;i++){
    	bmi[i] = temp[i];
    	strcpy(nama[i], temp1[i]);
	}
	
	printf("Show data\n\n");
	
	printf("Pilih tipe sorting :\n");
	printf("1. Date created ascending\n");
	printf("2. Date created descending\n");
	printf("3. BMI ascending\n");
	printf("4. BMI descending\n");
	printf("5. Name ascending\n");
	printf("6. Name descending\n");
	printf("\n0. Kembali\n\n");
	
	int j, tempswap[10];
	int menu;
	
	do{
	printf("Select (input berupa angka): ");
	menu = getIntegerOnly();
	if(menu < 0 || menu > 6){
			printf("Input salah\n");
		}
	}while(menu < 0 || menu > 6);
	
	switch(menu){
		case 1:
			// print data
			printf("\nDate created ascending\n");
   			for (i=0; i < size; i++){
  	  			printf("%s : %d", nama[i], bmi[i]);
  	  			kategori(bmi[i]);
			}			
			printf("\n");
			break;
		case 2:
			// print data
			printf("\nDate created descending\n");
   			for (i=0; i < size; i++){
  	  			printf("%s : %d", nama[i], bmi[i]);
  	  			kategori(bmi[i]);
			}
   			printf("\n");
			break;
		case 3:
   			// sort
   			for (i = 0; i < size-1; i++)  {
    			// Last i elements are already in place  
    			for (j = 0; j < size-i-1; j++){
       				if (bmi[j] > bmi[j+1]){
           			swap(&bmi[j], &bmi[j+1]);
           			swap2(nama[j], nama[j+1]);
           			}
    			}
			}
    
    		// print data
    		printf("\nBMI ascending\n");
   			for (i=0; i < size; i++){
  	  			printf("%s : %d", nama[i], bmi[i]);
  	  			kategori(bmi[i]);
			}		
    		printf("\n");
			break;
		case 4:
   			// sort
   			for (i = 0; i < size-1; i++)  {
    			// Last i elements are already in place  
    			for (j = 0; j < size-i-1; j++){
       				if (bmi[j] < bmi[j+1]){
           				swap(&bmi[j], &bmi[j+1]);
           				swap2(nama[j], nama[j+1]);
    			 	}
    			}
			}
    
    		// print data
    		printf("\nBMI descending\n");
   			for (i=0; i < size; i++){
  	  			printf("%s : %d", nama[i], bmi[i]);
  	  			kategori(bmi[i]);
			}		
    		printf("\n");
			break;
		case 5:
			// sort
   			for(i=0; i<size; i++){
    			for(j=0; j<size-1-i; j++){
       				if(strcmp(nama[j], nama[j+1]) > 0){
           				swap(&bmi[j], &bmi[j+1]);
           				swap2(nama[j], nama[j+1]);
       			 	}
    			}
			}
    
    		// print data
   			for (i=0; i < size; i++){
  	  			printf("%s : %d", nama[i], bmi[i]);
  	  			kategori(bmi[i]);
			}		
    		printf("\n");
			break;
		case 6:
			// sort
   			for(i=0; i<size; i++){
    			for(j=0; j<size-1-i; j++){
       				if(strcmp(nama[j], nama[j+1]) < 0){
           				swap(&bmi[j], &bmi[j+1]);
           				swap2(nama[j], nama[j+1]);
       			 	}
    			}
			}
    
    		// print data
    		printf("\nName ascending\n");
   			for (i=0; i < size; i++){
  	  			printf("%s : %d", nama[i], bmi[i]);
  	  			kategori(bmi[i]);
			}		
    		printf("\n");
			break;
		default:
			break;
		}
		
	//close file
    fclose(fa);
	fclose(fb);
	
	printf("\n\n");
    system("pause");
	system("cls");
}

void main(){
	
	show();
}
