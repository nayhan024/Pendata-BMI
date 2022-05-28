void kategori(int bmi){
	
	if(bmi < 19){
		printf("-> Underweight\n");
	}
	else if(bmi < 25){
		printf("-> Healthy\n");
	}
	else if(bmi < 30){
		printf("-> Overweight\n");
	}
	else if(bmi < 40){
		printf("-> Obese\n");
	}
	else{
		printf("-> Extremely obese\n");
	}
	
}
