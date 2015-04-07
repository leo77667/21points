// 21 point 
#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h> 
using namespace std;

int pokerset[52], j = 0;

int shuffle(){                                  // shuffle the pokerset
	int index, tmp, i;
	
    for(i = 0; i < 52; ++i)  
        pokerset[i] = i + 1; 
        
	srand(time(NULL));  
	 
    for(i = 0; i < 52; i++)  
    {  
        index = rand() % (52 - i) + i;     
        if(index != i)  
        {  
            tmp = pokerset[i];  
            pokerset[i] = pokerset[index];  
            pokerset[index] = tmp;  
        }  
}
}

int draw_pok();
char inflect_pok(int);
char inflect_color(int);

int main(){
	int i = 0, k = 4, l = 4, ran1, ran2, ran; double total = 0, sum = 0, num_set[30]; char draw_set[30], com_set[30] = {'0'}; char answer, poker, color;
    while(true)	{
	
	shuffle();                               // Player's turn
	cout << "Your Turn" << endl;
	ran1 = draw_pok();
	ran2 = draw_pok();
	draw_set[1] = inflect_pok(ran1);
	draw_set[3] = inflect_pok(ran2);
	draw_set[0] = inflect_color(ran1);
	draw_set[2] = inflect_color(ran2);   
	cout << "You got";
	
	for (i = 0; i < 4; ++i) {                // declare the pokers that player have drawn
		if(draw_set[i] == '1')
			cout << "10";
		else
			cout << draw_set[i];
	}
	cout << endl;
	
	while(true){
		cout << "Do you want to redraw ? (Y(y) or N(n))" << endl;         //find out whether the player want to redraw
		cin >> answer;
		
	 	if((answer == 'Y') || (answer == 'y')){
	 		ran = draw_pok();
	 		draw_set[k + 1] = inflect_pok(ran);
	 		draw_set[k] = inflect_color(ran);
	 		k += 2;
	 		cout << "Redraw a poker";
	 		for (i = 0; i < k ; ++i){  
	 			if (draw_set[i] == '1')
	 				cout << "10";
	 			cout << draw_set[i];
	 		}
	 		cout << endl;
	 		total = 0;
	 		for(i = 1; i < k ; i += 2){
	 			if ((draw_set[i] == 'J')||(draw_set[i] == 'Q')||(draw_set[i] == 'K'))   // count the sum of pokers
	 				num_set[i / 2] = 0.5;
	 			else
	 				if (draw_set[i] == '1')
	 					num_set[i / 2] = 10;
	 				else
	 					if (draw_set[i] == 'A')
	 						num_set[i / 2] = 1;
	 					else
	 						num_set[i / 2] = (draw_set[i] - 48);
	 			total += num_set[i / 2];
			 }	
	        }
	        
	    if (total > 21){                                    // check the validity
	    	cout << "You Lose" << endl;
	    	break;
		}
	    if ((answer == 'N') || (answer == 'n')){                                 // Computer's turn
	    	cout << "Computer's Turn" <<endl;
	    	ran1 = draw_pok();
			ran2 = draw_pok();
	    	com_set[1] = inflect_pok(ran1);
			com_set[3] = inflect_pok(ran2);
			com_set[0] = inflect_color(ran1);
			com_set[2] = inflect_color(ran2);  
			cout << "Computer got";
			
			for (i = 0; i < 4; ++i) {                           // declare the pokers that computer have drawn
				if (com_set[i] == '1')
					cout << "10";
				else
					cout << com_set[i];
			}
			cout << endl;
			
			for(i = 1; i < 4; i += 2){                                                      //count the sum of the pokers
				if ((com_set[i] == 'J')||(com_set[i] == 'Q')||(com_set[i] == 'K'))
	 				sum += 0.5;
	 			else
	 				if (com_set[i] == '1')
	 					sum += 10;
	 				else
	 					if (com_set[i] == 'A')
	 						sum += 1;
	 					else
	 						sum += (com_set[i] - 48);
	 	
			}
				
			while((sum < total)||((sum == total)&&(total < 21))){                                              // redraw and count the sum
				ran = draw_pok();
	 			com_set[l + 1] = inflect_pok(ran);
	 			com_set[l] = inflect_color(ran);
	 			l += 2;
	 			cout << "Computer redraw a poker";
	 			for (i = 1; i < l ; ++i){
	 				if (com_set[i] == '1')
	 					cout << "10";
	 				else
	 					cout << com_set[i];
	 			}
	 			cout << endl;
				if ((com_set[l - 1] == 'J')||(com_set[l - 1] == 'Q')||(com_set[l - 1] == 'K'))
	 				sum += 0.5;
	 			else
	 				if (com_set[l - 1] == '1')
	 					sum += 10;
	 				else
	 					if (com_set[l - 1] == 'A')
	 						sum += 1;
	 					else
	 						sum += (com_set[l - 1] - 48);
	 			
	 		}
	 		if ((sum == total)&&(total == 21)){
	 			if (l == k){
	 				cout << "You Tie" << endl;
	 				break;
				 }
				 if (l < k){
				 	cout << "You Win" << endl;
				 	break;
				 }
				else{
					cout << "You Lose" << endl;
					break;
				}		 
			 }
	 	
	 		if (sum > 21){                                     // determine the final result
	 			cout << "You Win!" << endl;
	 			break;
			}
			else{
				cout << "You Lose" << endl;
				break;
	    	}	    	
		}	 				 		
		 }
	cout << "Do you want to continue?(Y(y) or N(n))" << endl;
	cin >> answer;
	if ((answer == 'N') || (answer == 'n'))
	break;
	
}
return 0;
}	
 

int draw_pok(){                          // to distribute a poker to player
	int ran;
	
	ran = pokerset[j];
	++j;
	return ran;
}

char inflect_pok(int ran){              // to determine the kind of poker
	int num; char poker;
	num = ran % 13;
	switch(num){
		case 11: poker = 'J'; break;
		case 12: poker = 'Q'; break;
		case 0: poker = 'K'; break;
		case 1: poker = 'A'; break;
		case 10: poker = '1';break;
		default:{
			poker = num + 48;
			}
	}
	return poker;
}

char inflect_color(int ran){               // to determine the color of poker
	int num;  char color ;
	num = ran / 13;
	switch(num){
		case 0: color = 3; break;
		case 1: color = 4; break;
		case 2: color = 5; break;
		case 4: 
		case 3: color = 6; 		
	}
	return color;	 
}


