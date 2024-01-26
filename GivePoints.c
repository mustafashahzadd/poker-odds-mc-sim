
int givePoints(char _suit[], int _points){
	
	if (strcmp(_suit, "HEARTS") == 0 || strcmp(_suit, "CLUBS") == 0) {
		_points += 2;
	} else {
		_points++;
	}
	
	return _points;
}
