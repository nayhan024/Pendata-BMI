#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"int_only.h"
#include"kategori.h"

//struct
struct node {
	int data;
	char nama[10];
	struct node * next;
};

void print(struct node * head) {
    struct node * current_node = head;
   	while ( current_node != NULL) {
   		printf("%s : ", current_node->nama);
        printf("%d \n", current_node->data);
        current_node = current_node->next;
    }
}

void hapus(){
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
    
    //close file
    fclose(fa);
	fclose(fb);
	
    // copy the text
    int size = i;
    
    struct node * headAddress = NULL;
	struct node * tmpAddress = NULL;
	struct node * iteratorPtr = NULL;
    
    for(i=0;i<size;i++){
		tmpAddress = malloc(sizeof(struct node));
		(*tmpAddress).data = temp[i];
		strcpy((*tmpAddress).nama, temp1[i]);
		(*tmpAddress).next = NULL;
		
		if(headAddress == NULL){
			headAddress = tmpAddress;
		}
		else{
			iteratorPtr = headAddress; //iteratorPtr adalah alamat yg akan dicek
			while(1){
				if((*iteratorPtr).next == NULL){
					(*iteratorPtr).next = tmpAddress;
					break;
				}
				else{
					iteratorPtr = (*iteratorPtr).next;
				}
			}
		}
	}
    
    //debug list
    printf("List data \n");
    print(headAddress);
    
    if(headAddress == NULL){
    	printf("Tidak ada data");
	}
    else{
    	//search
		int result = 0;
		char cari_nama[10] = {'\0'};

		printf("\nNama yang dicari : ");
		scanf(" %s", &cari_nama);
	
		//hapus
		iteratorPtr = headAddress; //iteratorPtr adalah alamat yg akan dicek
		if(strcmp(cari_nama, (*iteratorPtr).nama) == 0){
			printf("\n%s : ", (*iteratorPtr).nama);
			printf("%d -> Berhasil dihapus", (*iteratorPtr).data);
		
			headAddress = (*iteratorPtr).next;
			free(iteratorPtr);
			result++;
		}
		for(i=1;i<size;i++){
		
			if(strcmp(cari_nama, (*iteratorPtr).nama) == 0){
				printf("\n%s : ", (*iteratorPtr).nama);
				printf("%d -> Berhasil dihapus\n", (*iteratorPtr).data);
			
				free(iteratorPtr);
				(*tmpAddress).next = (*iteratorPtr).next;
				iteratorPtr = tmpAddress;
				result++;
			}	
			tmpAddress = iteratorPtr;
			iteratorPtr = (*iteratorPtr).next;
		}
	
		if(result != 1){
			printf("\nNot found\n\n");
		}
		else{
			printf("\n%d data dihapus\n", result);
		}
	
		// open the file for writing
		fa = fopen(filename1, "w"); // file data
   		if (fa == NULL){
   	    	printf("Error opening the file %s", filename);
   		}
	
		fb = fopen(filename, "w");	
    	if (fb == NULL){
    	    printf("Error opening the file %s", filename);
    	}
    
   		// write to the text file   
	   	iteratorPtr = headAddress; //iteratorPtr adalah alamat yg akan dicek
 		while(1){
			if((*iteratorPtr).next == NULL){
				fprintf(fa, "%s\n", (*iteratorPtr).nama);
        	fprintf(fb, "%d\n", (*iteratorPtr).data);
				break;
			}
			else{
				fprintf(fa, "%s\n", (*iteratorPtr).nama);
        		fprintf(fb, "%d\n", (*iteratorPtr).data);
				iteratorPtr = (*iteratorPtr).next;
			}
		}
	
  	  // close the file
  	  fclose(fa);
  	  fclose(fb);
	}
	
	
    printf("\n\n");
    system("pause");
}

void main(){
	
	hapus();
}
