#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"int_only.h"

void input(){
    char *filename = "bmi.txt";
    char *filename1 = "nama.txt";
	
	// open the file for writing
	FILE *fa;
	fa = fopen(filename1, "a"); 	// file name
    if (fa == NULL){
        printf("Error opening the file %s", filename);
    }
	
    FILE *fb;
	fb = fopen(filename, "a");	// file data
    if (fb == NULL){
        printf("Error opening the file %s", filename);
    }
    
    // write to the text file
    int i;
	int jumlah, bmi;
	float berat, tinggi, hasil;
	char nama[100];
    
    printf("Input Data\n\n");
    
    printf("Jumlah data (0 untuk kembali) : ");
    jumlah = getIntegerOnly();
    
    for (i = 0; i < jumlah; i++){
    	printf("Nama-%d: ", i+1);
    	scanf(" %10s", &nama);
        fprintf(fa, "%s\n", nama);
		
		printf("Tinggi-%d (cm): ", i+1);
		scanf("%f", &tinggi);
		tinggi = tinggi/100;
		
		printf("Berat-%d (kg): ", i+1);
		scanf("%f", &berat);
		
    	hasil = berat/(tinggi*tinggi);
    	bmi = (int)hasil;
        fprintf(fb, "%d\n", bmi);
    }

    // close the file
    fclose(fa);
    fclose(fb);
}

int main(){
	
	input();
}
