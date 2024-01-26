void results(int _n, char _t[]){
	int i;
	for (i = 0; i <= _n; i++){
		printf("%s:\t\t%d", _t, i);
		if (_n < 400) Sleep(2); else if (_n < 800 && _n >= 400) Sleep(1);
		printf("\r");
	}
	printf("\n");
}
