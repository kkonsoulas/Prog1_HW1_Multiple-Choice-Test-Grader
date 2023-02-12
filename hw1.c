/*
 * ONOMATEPWNYMO:Konsoulas Konstantinos 02975
 * ONOMATEPWNYMO:
  *
*/
#include<stdio.h>
#include<math.h>
#include"hw1.h"


int main (int argc, char *argv[]) {

	int num_max_choice, real_max_choice, i, j;
	char user_choice, lreal_max_choice;				// letter of given max choice
	char correct_answers[NUM_QUESTIONS];
	char student_answers[NUM_STUDENTS][NUM_QUESTIONS] ={{0}};
	double stats[NUM_STUDENTS][3] ={{0}};  // column [0] =correct answers ,column[1]= wrong answers ,column[2]= grade
	double penalty =0, average=0, sd=0; 		//sd= standard deviation 
	int range[10]= {0};
	int low_grade, high_grade, given_range_students =0;
	int first_index=0, last_index=0;
	int k=0;
	
	//Code's utility
	
			//(code)//
	
	//
	
	//Number of choices reader
	num_max_choice = MAX_CHOICE +1 - MIN_CHOICE;
	
	do{
		printf("\nEnter number of choices (1-%d): ",num_max_choice);
		scanf("%d", &real_max_choice);
		
	}while((real_max_choice < 1) || (real_max_choice> num_max_choice));
	//
	
	//Correct answers reader
	printf("\nEnter answer key: ");
	
	lreal_max_choice = MIN_CHOICE-1 + real_max_choice ;
	
	
	for(i=0; i < NUM_QUESTIONS; i++){
		scanf(" %c",&correct_answers[i]);
		
		if((correct_answers[i]<MIN_CHOICE) || (correct_answers[i]>lreal_max_choice)){
			printf("\nError. Enter value %c-%c: ", MIN_CHOICE, lreal_max_choice);
			i--;
			
		}
	}
	//
	
	//Penalty reader
	printf("\nEnter wrong answer penalty: ");
	
	while(1){
		scanf("%lf", &penalty);
		if(penalty<=0){
			break;
		}
		printf("\nError. Enter non-positive value: ");
		
	}
	//
	
	//Student choices reader
	for(i=0; i<NUM_STUDENTS; i++){
		printf("\nEnter student choices: ");
		
		for(j=0; j<NUM_QUESTIONS; j++){
			scanf(" %c", &student_answers[i][j]);
			if(((student_answers[i][j]<MIN_CHOICE) || (student_answers[i][j]>lreal_max_choice)) &&( student_answers[i][j] != '-')){
				printf("\nError. Enter valid choice: ");
				j--;
			}
		}
	}
	//
	
	//Student answers checker
	for(i=0; i<NUM_STUDENTS; i++){
		
		for(j=0; j<NUM_QUESTIONS; j++){
			if((correct_answers[j] == student_answers[i][j])){
				stats[i][0]++;
			}
			else if('-'!= student_answers[i][j]){
				stats[i][1]++;
			}
		}
		
		
	}
	//
	
	//Student grade and average(mean) calculator
	for(i=0; i<NUM_STUDENTS; i++){
		stats[i][2] = ((stats[i][0] + stats[i][1]*penalty)*10) /NUM_QUESTIONS;
		if(stats[i][2] < 0){
			stats[i][2] = 0;
		}
		average = average + stats[i][2];
	}
	
	average = average/NUM_STUDENTS;
	//
	
	//Standard deviation calculator
	for(i=0; i<NUM_STUDENTS; i++){
		sd = sd +pow((stats[i][2] - average),2);
		
		
	}
	sd = sqrt(sd /NUM_STUDENTS);
	//
	
	//Range filler /grade categorization
	for(i=0; i<NUM_STUDENTS; i++){
		j = (int)floor(stats[i][2]);
		if(j==10){
			j=j-1;
		}
		range[j] =range[j] +1;
		
		}
	//
	
	
	while(1){
		
		printf("\n[M/m] Print mean");
		printf("\n[S/s] Print standard deviation");
		printf("\n[G/g] Print grade range");
		printf("\n[I/i] Print student info in range");
		printf("\n[H/h] Draw histogram");
		printf("\n[Q/q] Quit\n");
		
		scanf(" %c",&user_choice);
		
		switch(user_choice){
			case 'M':
			case 'm':{
				printf("\n%.2lf",average);
				printf("\n##\n");
				
				break;
			}
			case 'S':
			case 's':{
				printf("\n%.2lf",sd);
				printf("\n##\n");
				
				break;
			}
			case 'G':
			case 'g':{
				given_range_students =0;
				
				do{
					printf("\nEnter grade range: ");
					scanf("%d-%d",&low_grade ,&high_grade);
					
				}while(((low_grade<0) || (high_grade> 10)) || (low_grade >= high_grade));
				
				while(low_grade < high_grade){
					given_range_students = given_range_students + range[low_grade] ;
					low_grade++;
				}
				printf("\n%d",given_range_students);
				printf("\n##\n");
				
				break;
			}
			case 'I':
			case 'i':{
				do{
					printf("\nEnter index range: ");
					scanf("%d-%d",&first_index ,&last_index);
					
				}while(((first_index<0) || (last_index> NUM_STUDENTS-1)) || (first_index >= last_index));
				
				while(first_index <= last_index){
					
					printf("\n%03d:%4.lf,%4.lf,%4.lf,%6.2lf",first_index ,stats[first_index][0] ,stats[first_index][1] ,(NUM_QUESTIONS -stats[first_index][0] -stats[first_index][1]) ,stats[first_index][2]);
					
					first_index++;
				}
				printf("\n##\n");
				
				break;
			}
			case 'H':
			case 'h':{
				
				for(i=0,j=1 ;i<9 ;i++,j++){
					k=0;
					printf("[%2d,%2d): ",i,j);
					if(NUM_STUDENTS <=100){
						while(k < range[i]){
							printf("*");
							k++;
						}
					}
					else{
						while(k < range[i]/10){
							printf("*");
							k++;
						}
					}
					printf("\n");
				}
				k=0;
				printf("[ 9,10]: ");
					if(NUM_STUDENTS <=100){
						while(k < range[i]){
							printf("*");
							k++;
						}
					}
					else{
						while(k < range[i]/10){
							printf("*");
							k++;
						}
					}
				printf("\n");	
				printf("\n##\n");
				
				break;
			}
			case 'Q':
			case 'q':{
				return (0);
			}
			default:{
				printf("\nError. Invalid option.");
				
			}
		}
		
	}
	
	
	return (0);
}
