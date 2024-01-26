int main(){
	printStartup();
	struct info *cards, *remaining_cards, *temp, *opponent;
	
	//reserving space in the memory
	cards = (struct info*)malloc(52 * sizeof(struct info));
	temp = (struct info*)malloc(51 * sizeof(struct info));
	remaining_cards = (struct info*)malloc(50 * sizeof(struct info));
	opponent = (struct info*)malloc(2 * sizeof(struct info));
	
	//flags and loop variables
	int i, k, j, r1, r2, check, correct = 1;
	char *descision;
	descision = (char*)malloc(20 * sizeof(char));
	
	//user cards
	char *card1_suit, *card2_suit;
	card1_suit = (char*)malloc(20 * sizeof(char));
	card2_suit = (char*)malloc(20 * sizeof(char));
	
	int card1_n, card2_n;
	
	//overall wins, losses and ties in the following session as a whole	
	float ovw = 0, ovl = 0, ovt = 0;
	
	while(strcmp(descision, "END") != 0){
		//points of user and opponent initialized for each iteration
		int pu1 = 0, pu2 = 0, pu = 0, po1 = 0, po2 = 0, po = 0, loss = 0, tie = 0;
		float win = 0;
		
		initCards(cards);
		printf("Enter your card choices one by one:\n\n");
		printf("Enter your card's number: ");
		scanf("%d", &card1_n);
		check = checkNumber(card1_n);
		//loops number is correct
		while (check == 0) {
			printf("invalid number, enter again: ");
			scanf("%d", &card1_n);
			check = checkNumber(card1_n);
		}
		
		printf("Enter your card's suit: ");
		scanf("%s", card1_suit);
		fflush(stdin);
		check = checkSuit(card1_suit);
		//loops until suit is correct
		while (check == 0) {
			printf("invalid suit, enter again: ");
			scanf("%s", card1_suit);
			fflush(stdin);
			check = checkSuit(card1_suit);
		}
		
		printf("\nEnter your card's number: ");
		scanf("%d", &card2_n);
		check = checkNumber(card2_n);
		//loops until card number is correct
		while (check == 0) {
			printf("invalid number, enter again: ");
			scanf("%d", &card2_n);
			check = checkNumber(card2_n);
		}
		
		printf("Enter your card's suit: ");
		scanf("%s", card2_suit);
		check = checkSuit(card2_suit);
		//loops until suit is correct
		while (check == 0) {
			printf("invalid suit, enter again: ");
			scanf("%s", card2_suit);
			fflush(stdin);
			check = checkSuit(card2_suit);
		}
		
		correct = checkSame(card1_n, card2_n, card1_suit, card2_suit);
		
		while (correct == 0) {
			printf("Can't select same card again!\n");
			printf("Enter number of card 2 you want: ");
			scanf("%d", &card2_n);
			check = checkNumber(card2_n);
			while (check == 0) {
				printf("invalid number, enter again: ");
				scanf("%d", &card2_n);
				check = checkNumber(card2_n);
			}
			
			printf("Enter suit of card 2 you want: ");
			scanf("%s", card2_suit);
			check = checkSuit(card2_suit);
			while (check == 0) {
				printf("invalid suit, enter again: ");
				scanf("%s", card2_suit);
				fflush(stdin);
				check = checkSuit(card2_suit);
			}
			
			correct = checkSame(card1_n, card2_n, card1_suit, card2_suit);
		}
		
		//initializing points of user
		pu1 = card1_n;
		pu2 = card2_n;
		
		//give points according to suit
		pu1 = givePoints(card1_suit, pu1);
		pu2 = givePoints(card2_suit, pu2);
		
		//total points of both cards
		pu = pu1 + pu2;
	
		//removing the first card from the deck
		for (i = 0, j = 0; i < 52; i++){
			if ((card1_n != cards[i].n) || (strcmp(card1_suit, cards[i].t) != 0)){ 
				temp[j].n = cards[i].n;
				strcpy(temp[j].t, cards[i].t);
				j++;
			}
		}
		
		//removing the second card from the deck
		for (i = 0, j = 0; i < 52; i++){
			if ((card2_n != temp[i].n) || (strcmp(card2_suit, temp[i].t) != 0)){ 
				remaining_cards[j].n = temp[i].n;
				strcpy(remaining_cards[j].t, temp[i].t);
				j++;
			}
		}
		
		srand(time(0));
		
		//monti-carlo sequence, generating 100,2530 posibilites
		for (i = 0; i < 100253; i++){
			
			//generating 2 random numbers, for two random indexes
			r1 = randomGenerator();
			r2 = randomGenerator();
			
			//making sure the second random number is not the same as the first one
			while (r2 == r1) {
				r2 = randomGenerator();
			}
			
			//random indexes give random cards
			opponent[0].n = remaining_cards[r1].n;
			strcpy(opponent[0].t, remaining_cards[r1].t);
			opponent[1].n = remaining_cards[r2].n;
			strcpy(opponent[1].t, remaining_cards[r2].t);
	
			//initializing points of opponent's cards
			po1 = opponent[0].n;
			po2 = opponent[1].n;
			
			//giving points according to suit
			po1 = givePoints(opponent[0].t, po1);
			po2 = givePoints(opponent[1].t, po2);
			
			//calculating total points of opponent's possible hand
			po = po1 + po2;
			
			//finding who won, according to points
			if (pu > po) {
				win++;
				ovw++;
			} else if (pu < po) {
				loss++;
				ovl++;
			} else if(pu==po) {
				tie++;
				ovt++;
			}
			
		}
		
		printf("\n");
		printf("-----------------------------------------------------");
		printf("\n\n");
		
		int wins = (int)win;
		results(wins, "Wins");
		
		int ls = (int)loss;
		results(ls, "Losses");
		
		int ties = (int)tie;
		results(ties, "Ties");
		
		printf("\n");
		printf("-----------------------------------------------------");
		printf("\n");
		
		printf("\nwin percentage:  \t%.2f %%\nloss percentage:\t%.2f %%\ntie percentage:  \t%.2f %%\n\n", (win)/(win+loss+tie)*100, loss/(loss+win+tie)*100, tie/(tie+loss+win)*100);	
	
		printf("Enter \"END\" if you want to stop entering more values: ");
		scanf("%s", descision);
		system("CLS");
	}
	
	printf("Your overall percentage of winning, losing, and tie this session has been:\n");
	printf("\nOverall win percentage = %.2f %%\nOverall lost percentage = %.2f %%\nOverall tie percentage = %.2f %%", (ovw)/(ovw+ovl+ovt)*100, ovl/(ovl+ovw+ovt)*100, ovt/(ovw+ovl+ovt)*100);
	
	return 0;
}	
