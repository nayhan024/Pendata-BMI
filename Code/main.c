#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"
#include "search.h"
#include "show.h"
#include "int_only.h"
#include "kategori.h"
#include "Hapus.h"
#include "binary_tree.h"

void tampilan(){
	system("cls");
	printf("Program pendataan BMI\n\n");
	printf("Main Menu\n\n");
	printf("1. Input data\n");
	printf("2. Search data\n");
	printf("3. Show data\n");
	printf("4. Delete data\n");
	printf("5. Binary Search Tree\n\n");
	printf("0. Exit\n\n");
}

void main(){
	
	int menu;
	
	do{
		tampilan();
	
		do{
			printf("Select (input berupa angka): ");
			menu = getIntegerOnly();
			if(menu < 0 || menu > 5){
				printf("Input salah\n");
			}
		}while(menu < 0 || menu > 5);
	
		system("cls");
	
		switch(menu){
			case 1:
				input();
				break;
			case 2:
				search();
				break;
			case 3:
				show();
				break;
			case 4:
				hapus();
				break;	
			case 5:
				binary_tree();
				break;
			default:
				break;
		}
	}while(menu != 0);
	
}
