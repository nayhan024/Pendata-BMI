void search(){
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
    int bmi[size];
    char nama[size][10];
    
    for(i=0;i<size;i++){
    	bmi[i] = temp[i];
    	strcpy(nama[i], temp1[i]);
	}
    	
	//search
	int menu;
	int result;
	char cari_nama[10] = {'\0'};
	int x;

	printf("Search data\n\n");

	printf("Cari berdasarkan : \n");
	printf("1. Nama\n");
	printf("2. Data\n\n");
	printf("0. Kembali\n\n");
	
		do{
			printf("Select (input berupa angka): ");
			menu = getIntegerOnly();
			if(menu < 0 || menu > 2){
				printf("Input salah\n");
			}
		}while(menu < 0 || menu > 2);
	
	switch(menu){
		case 1:
			printf("\nNama yang dicari : ");
			scanf(" %s", &cari_nama);
			
			for(i=0;i<size;i++){
				if(strcmp(cari_nama, nama[i]) == 0){
					printf("%s : %d", nama[i], bmi[i]);
					kategori(bmi[i]);
					result = 1;
				}
			}
			if(result != 1){
				printf("Not found\n");
			}
			break;
		case 2:
			printf("\nData yang dicari : ");
			x = getIntegerOnly();

			for(i = 0; i < size; i++){
        		if(x == bmi[i]){
					printf("%s : %d", nama[i], bmi[i]);
					kategori(bmi[i]);
					result = 1;
       			}
   			}
   			if(result != 1){
				printf("Not found\n");
			}
			break;
		default:
			break;
	}
	
    printf("\n\n");
    system("pause");
}
