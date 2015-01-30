/*
  				Name 	: Nithin. P
  				EmailId : nithup123@gmail.com
*/

#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

char player_name[20];
char game[3][3];
int play_count=0;

int play_me();
int set_game(int,char);
int chance_to_win();
int chance_to_fail();
int iswin(char);
void first_display();
void play();
void print_game();
void reset_game();

main()
{
	int i,j,n=3;
	char choice,choice1;
	first_display();
	printf("\n Enter your name :");
	scanf("%s",player_name);
	printf("\n\n\n %s,are you ready...???\n Press 'y' for continue any other key for exit : ",player_name);
	scanf("%c",&choice);
	scanf("%c",&choice);
	while(choice=='y' || choice=='Y'){
		reset_game();
		play();
		printf("\n %s,do you want another play...???\n Press 'y' for continue any other key for exit :",player_name);
		scanf("%c",&choice);
		scanf("%c",&choice);
	}
	if(choice!='y' && choice!='Y')
		printf("\n Thank you %s for using this game. :) \n\n\n\n",player_name);
	
}

void reset_game()
{
	int i,j,n=3;
	for(i=0;i<n;i++)
        	for(j=0;j<n;j++)
          		game[i][j]='0';
	play_count=0;

}

void first_display()
{
	printf("\n--------------------TIC TAC TOE----------------------\n");
        printf("\n\n	Rules for playing\n");
        printf("     _________________________   \n\n");
        printf("\n 1 : 'O' for you and 'X' for Computer.\n");
        printf("\n 2 : Type the corresponding number given below to play\n");
	printf("\t _____ _____ _____ \n");
	printf("\t|     |     |     |\n");
	printf("\t| 1   |  2  |  3  |\n");
	printf("\t|_____|_____|_____|\n");
	printf("\t|     |     |     |\n");
	printf("\t| 4   |  5  |  6  |\n");
	printf("\t|_____|_____|_____|\n");
	printf("\t|     |     |     |\n");
	printf("\t| 7   |  8  |  9  |\n");
	printf("\t|_____|_____|_____|\n");
	printf("\n\n");
}

void play()
{
	char tmp_game[3][3],sym;
	int i,j,choice,over=0,n=3;
	while((over!=1)&&(play_count<9)){
		print_game();
		printf(" %s,Enter your choice(1-9) :",player_name);
		scanf("%d",&choice);
		sym='O';
		while(!set_game(choice,sym)){
			printf(" Invalid choice :( select another one :");
			scanf("%d",&choice);
		}
		over=iswin(sym);
		if(over==1){
			printf("\n Congrats %s..!! You won the game...!! :) :)\n\n\n",player_name);
			print_game();
		}
		else{
			if(play_count==9){
                        	printf("\n Sorry %s..!! Game over...!!\n",player_name);
				print_game();
                        	return;
                	}
			over=play_me();
			if(play_count==9){
                        	printf("\n Sorry %s..!! Game over...!!\n",player_name);
				print_game();
                        	return;
                	}

		}
		
	}
}

void print_game()
{
	int i,j,n=3;
	char tmp_game[3][3];
	for(i=0;i<n;i++){
       		for(j=0;j<n;j++){
            		if(game[i][j]=='0')
                		tmp_game[i][j]=' ';
              		else
                  		tmp_game[i][j]=game[i][j];
        	}
      	}
       	printf("\t _____ _____ _____ \n");
      	printf("\t|     |     |     |\n");
       	printf("\t| %c   |  %c  |  %c  |\n",tmp_game[0][0],tmp_game[0][1],tmp_game[0][2]);
      	printf("\t|_____|_____|_____|\n");
       	printf("\t|     |     |     |\n");
       	printf("\t| %c   |  %c  |  %c  |\n",tmp_game[1][0],tmp_game[1][1],tmp_game[1][2]);
       	printf("\t|_____|_____|_____|\n");
       	printf("\t|     |     |     |\n");
       	printf("\t| %c   |  %c  |  %c  |\n",tmp_game[2][0],tmp_game[2][1],tmp_game[2][2]);
      	printf("\t|_____|_____|_____|\n");
      	printf("\n\n");
	return;

}

int iswin(char sym)
{
	int count,i,j,k,n=3;
	count=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(game[i][j]==sym)
				count++;
		if(count==3)
			break;
		else
			count=0;
	}
	if(count!=3){
		count=0;
		for(j=0;j<n;j++){
                	for(i=0;i<n;i++)
                        	if(game[i][j]==sym)
                                	count++;
                	if(count==3)
                        	break;
                	else
                        	count=0;
		}
	}
        if(count!=3){
		count=0;
                for(i=0;i<n;i++)
                        for(j=0;j<n;j++)
				if(i==j)
                                	if(game[i][j]==sym)
                                        	count++;
	}
	if(count!=3){
		count=0;
		k=0;
		i=0;
		j=2;
		while(k<3){
			if(game[i][j]==sym)
				count++;
			i++;
			j--;
			k++;
		}
	}
        if(count==3)
		return 1;
	else
		return 0;
}

int set_game(int choice,char sym)
{
	int r,c,i,j;
	if(choice==1){
		r=0;
		c=0;
	}
        else if(choice==2){
                r=0;
                c=1;
        }
        else if(choice==3){
                r=0;
                c=2;
        }
        else if(choice==4){
                r=1;
                c=0;
        }
        else if(choice==5){
                r=1;
                c=1;
        }
        else if(choice==6){
                r=1;
                c=2;
        }
        else if(choice==7){
                r=2;
                c=0;
        }
        else if(choice==8){
                r=2;
                c=1;
        }
        else if(choice==9){
                r=2;
                c=2;
        }
	else
		return 0;
	if(game[r][c]=='0'){
		game[r][c]=sym;
		play_count++;
		return 1;
	}
	else
		return 0;
}

int play_me()
{
	int i,j,choice,over;
	char sym='X';
	make_choice();
        over=iswin(sym);
        if(over==1){
        	printf("\n Thats great!! Computer won the game...!! :) :)\n\n\n");
		print_game();
		return 1;
	}
	else{
		return 0;
	}
}

int make_choice()
{
	struct timeval tv;
	int choice,win,fail,i,j,r,c,k,count,t,get=0,n=3;
	t=0;
	win=0;
	fail=0;
        count=0;
	if(chance_to_win()==0){
		if(chance_to_fail()==0){
			if(get!=1){
		        	gettimeofday(&tv,NULL);
		        	choice=tv.tv_usec%9;
				if(choice==0)
					choice=9;
		        	while(!set_game(choice,'X')){
		                	gettimeofday(&tv,NULL);
		                	choice=tv.tv_usec%9;
		        	}
				return;
			}
		}

        }
}

int chance_to_win()
{
	int i,j,k,choice,t,win,get,r,c,count=0,n=3;
	win=0;
	get=0;
	for(i=0;i<n;i++){
		t=0;
		count=0;
		if(win==1)
			break;
		else{
			for(j=0;j<n;j++){
				if(game[i][j]=='X')
					count++;
				else if(game[i][j]=='O'){
					t=1;
					break;
				}
				else
					continue;
			}
			if(count==2 && t!=1){
				for(j=0;j<n;j++){
					if(game[i][j]=='0'){
						r=i;
						c=j;
						win=1;
						get=1;
						break;
					}
				}
			}
		}
	}
	if(win!=1){
		count=0;
		t=0;
		for(j=0;j<n;j++){
			t=0;
		        count=0;
		        if(win==1)
		                break;
		        else{
		                for(i=0;i<n;i++){
		                        if(game[i][j]=='X')
		                                count++;
		                        else if(game[i][j]=='O'){
		                                t=1;
		                                break;
		                        }
		                        else
		                                continue;
		                }
		                if(count==2 && t!=1){
		                        for(i=0;i<n;i++){
		                                if(game[i][j]=='0'){
		                                        r=i;
		                                        c=j;
		                                        win=1;
		                                        get=1;
		                                        break;
		                                }
		                        }
		                }
		        }
		}

	}
	if(win!=1){
		count=0;
		t=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					if(game[i][j]=='X')
						count++;
					else if(game[i][j]=='O'){
						t=1;
					}
					else{
					}
				}
			}
		}
		if(count==2 && t!=1){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j){
						if(game[i][j]=='0'){
							win=1;
							get=1;
							r=i;
							c=j;
							break;
						}
					}
				}
			}
		}
	}
	if(win!=1){
		count=0;
		t=0;
		i=0;
		j=2;
		k=0;
		while(k<3){
			if(game[i][j]=='X')
				count++;
			else if(game[i][j]=='O'){
				t=1;
				break;
			}
			else{
			}
			i++;
			k++;
			j--;
		}
		if(count==2 && t!=1){
			i=0;
			j=2;
			k=0;
			while(k<3){
				if(game[i][j]=='0'){
					win=1;
					get=1;
					r=i;
					c=j;
					break;
				}
				i++;
				k++;
				j--;
			}
		}
	}
	if(win==0)
		return 0;
        else{
                if(r==0 && c==0)
                        choice=1;
                else if(r==0 && c==1)
                        choice=2;
                else if(r==0 && c==2)
                        choice=3;
                else if(r==1 && c==0)
                        choice=4;
                else if(r==1 && c==1)
                        choice=5;
                else if(r==1 && c==2)
                        choice=6;
                else if(r==2 && c==0)
                        choice=7;
                else if(r==2 && c==1)
                        choice=8;
                else if(r==2 && c==2)
                        choice=9;
                else{
                }
                set_game(choice,'X');
		return choice;
        }

}

int chance_to_fail()
{
	int i,j,k,choice,t,fail,get,r,c,count=0,n=3;
	fail=0;
	get=0;
	t=0;
	for(i=0;i<n;i++){
		t=0;
		count=0;
		if(fail==1)
			break;
		else{
			for(j=0;j<n;j++){
				if(game[i][j]=='O')
					count++;
				else if(game[i][j]=='X'){
					t=1;
					break;
				}
				else
					continue;
			}
			if(count==2 && t!=1){
				for(j=0;j<n;j++){
					if(game[i][j]=='0'){
						r=i;
						c=j;
						fail=1;
						get=1;
						break;
					}
				}
			}
		}
	}
	if(fail!=1){
		count=0;
		t=0;
		for(j=0;j<n;j++){
			t=0;
			count=0;
			if(fail==1)
			        break;
			else{
			        for(i=0;i<n;i++){
		                if(game[i][j]=='O')
			                        count++;
			                else if(game[i][j]=='X'){
			                        t=1;
			                        break;
			                }
			                else
			                        continue;
			        }
			        if(count==2 && t!=1){
			                for(i=0;i<n;i++){
			                        if(game[i][j]=='0'){
			                                r=i;
			                                c=j;
			                                fail=1;
			                                get=1;
			                                break;
			                        }
			                }
			        }
			}
		}

	}
	if(fail!=1){
		count=0;
		t=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					if(game[i][j]=='O')
						count++;
					else if(game[i][j]=='X'){
						t=1;
					}
					else{
					}
				}
			}
		}
		if(count==2 && t!=1){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i==j){
						if(game[i][j]=='0'){
							fail=1;
							get=1;
							r=i;
							c=j;
							break;
						}
					}
				}
			}
		}
	}
	if(fail!=1){
		count=0;
		t=0;
		i=0;
		j=2;
		k=0;
		while(k<3){
			if(game[i][j]=='O')
				count++;
			else if(game[i][j]=='X'){
				t=1;
				break;
			}
			else{
			}
			i++;
			k++;
			j--;
		}
		if(count==2 && t!=1){
			i=0;
			j=2;
			k=0;
			while(k<3){
				if(game[i][j]=='0'){
					fail=1;
					get=1;
					r=i;
					c=j;
					break;
				}
				i++;
				k++;
				j--;
			}
		}
	}
	if(fail==0)
		return 0;
        else{
                if(r==0 && c==0)
                        choice=1;
                else if(r==0 && c==1)
                        choice=2;
                else if(r==0 && c==2)
                        choice=3;
                else if(r==1 && c==0)
                        choice=4;
                else if(r==1 && c==1)
                        choice=5;
                else if(r==1 && c==2)
                        choice=6;
                else if(r==2 && c==0)
                        choice=7;
                else if(r==2 && c==1)
                        choice=8;
                else if(r==2 && c==2)
                        choice=9;
                else{
                }
                set_game(choice,'X');
		return choice;
        }


}
