
int checkSame(int _n1, int _n2, char _s1[], char _s2[]){
	if ((_n1 == _n2) && (strcmp(_s1, _s2) == 0)) {
		return 0;
	} else {
		return 1;
	}
}
