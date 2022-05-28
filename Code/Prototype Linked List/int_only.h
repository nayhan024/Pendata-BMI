int getIntegerOnly()
{
    int num = 0, ch;
    do {
        ch = getch();
  		int ch_state;
  		
        // Checks the ASCII code of '
        // digits 0 to 9
        if (ch >= 48 && ch <= 57) {
			printf("%c", ch);
  
            // To make a digit
            num = num * 10 + (ch - 48);
            ch_state = ch;
        }
        
        // 08 is backspace
		if(ch == 8){
			printf("\b \b");
			num = (num-(ch_state-48))/10;
		}
		
        // 13 is carriage return it breaks
        // and return the input
        if (ch == 13)
            break;
    } while (1);
  	
  	printf("\n");
  	
    return (num);
}
