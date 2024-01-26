int checkSuit(char _suit[]){
	if ((strcmp(_suit, "DIAMONDS") == 0) || (strcmp(_suit, "SPADES") == 0) || (strcmp(_suit, "CLUBS") == 0) || (strcmp(_suit, "HEARTS") == 0)){
		return 1;
	} else {
		return 0;
	}
}
