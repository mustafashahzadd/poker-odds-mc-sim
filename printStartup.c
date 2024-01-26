
void printStartup(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
	
    //Save current attributes since color will be temp
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
	
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    Welcome to the monte carlo simulation project");
	Sleep(2000);
	
	//Restore original attributes
    SetConsoleTextAttribute(hConsole, saved_attributes);
	system("CLS");
	
	printf("Let's dive into what the program will be doing briefly:\n\n");
	printf("  > The program will work on a pair of cards you chose (your \"hand\")\n  > The program will check the odds of your hand winning\n  > The program will compare your hand with randomly selected realistic hands your opponent can recieve\n  > The program will return a accurate probability\n  > The program will will run approximately 100,000 times for as realistic a odd as possible");
	printf("\n\nPress any key to continue: ");
	//getch();
	system("CLS");
}
