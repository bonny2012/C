//Lab8 Phone book 3 
//Xin Zheng
//Oct 18, 2016
//Section 1

//Requirement: 
//use function for all the options. 
//use pointer to structure. 
//use dynamic memory allocation. 
//check if memory allocation was successful.
//free the memory for deleted record.
//free all assigned memory before program exits. 
//NOT use global variables. 
//have input check when it is needed. (example: if there are no contacts to delete, print a message and return, else continue 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

typedef struct phonebook
{	char Lname[20];
	char Fname[20];
	char  PNum[20];
} PB;//end struct definition

//function prototype
PB* addFriend(PB*, int*);
PB* delFriend(PB*, int*);
PB* printFriend(PB*, int*);
PB* findFriend(PB*,int*);
PB* RndFriend(PB*,int*);
PB* DelAllFriend(PB*,int*);
PB* sortFriend(PB*, int );
PB* addFriendToFile(PB*,int*);
PB* showFriendFromFile(PB*,int*);	


main()
{
	PB* friends = malloc(sizeof(PB));
	int x=0;
	int i=0;
	int iPick=0;
	char choice='\0';

		
	do{	printf("\n");
		printf("\nPhone Book Application\n");
		printf("1)\t Add friend\n");
		printf("2)\t Delete friend\n");
		printf("3)\t Show phone book\n");
		printf("4)\t Show phone book with last name alphabetically \n");
		printf("5)\t Find one friend\n");
		printf("6)\t Random select one friend to call\n");
		printf("7)\t Delete all friends\n");
		printf("8)\t Add friend and store data in local file\n");
		printf("9)\t Retrive data from local file\n");
		printf("10)\t Exit");
		printf("\nWhat do you want to do: ");
		scanf("%d",&iPick);
		
		//start switch 
		switch(iPick)
		{			
				
			case 1://add entry
								
				friends = addFriend(friends, &x);
								
				printf("Record added to the phone book. ");				
			
				break;//end case 1
				
			case 2://delete entry
				
				if(x!=0)
				{
					friends=delFriend(friends,&x);						
				}
				
				else
				{
					printf("No record exist yet.");					
				}
				break;//end case 2
				
			case 3://print entry
				
				if(x!=0)
				{				
					printf("Phone Book Entries:");
					friends=printFriend(friends, &x);			
				}
				
				else
				{
					printf("No records exist.");
				}		
				
				break;//end case 3
					
			case 4://show data alphabetically
				if(x!=0)
				{				
					printf("Phone Book Entries with last name alphabetically:");
					friends = sortFriend(friends,x);			
				}
				else
				{
					printf("No records exist.");
				}				
				
				break;//End show phone book alphabetically				
				
		
			case 5://find a find with first or last name
				
				if(x!=0)
				{
					friends=findFriend(friends,&x);						
				}
					
				else
				{
					printf("No record exist yet.");					
				}
				break;
				
			case 6://random select a friend to call
				
				if(x!=0)
				{						
					friends=RndFriend(friends,&x);						
				}
				
				else
				{
					printf("No record exist yet.");					
				}
				break;
					
			case 7://delect all friends
				
				if(x!=0)
				{	
					printf("Do you want to delete all your friends? Y/N\n");
					scanf(" %c",&choice);
									
					if(choice=='Y'||choice=='y')
														
						friends=DelAllFriend(friends,&x);
					
					else					
						printf("That is OK, maybe next time\n");
											
				}//end if (x!=0)
				
				else
				{
					printf("No record exist yet.");					
				}
				break;
			
			case 8://Add data to file
		
				friends=addFriendToFile(friends,&x);	
			
				break;//end case 8
				
			case 9://retrieve data from file
									
				friends=showFriendFromFile(friends,&x);						
			
				break;				
				
				
			case 10:
				printf("Goodbye.");
				break;			
			
				
		}//end switch
		    
	}while(iPick!=10);//end while loop
	
	free(friends);//free memory
		exit(EXIT_SUCCESS);
	ErrorHandler:
		perror("The following error occurred");
		exit(EXIT_FAILURE);
	
	
}//end main function


//function definition for adding entry(case1)
PB* addFriend(PB* ph, int* count)
{
	
	 PB* tmp = (PB*) realloc(ph,((*count)+1)*sizeof(PB));
	 if(tmp==NULL)
	{
		printf("Out of memory.");
	 	return(ph);
	}//end if
	 else
	 {
	 	ph = tmp;
 		printf("\nFirst Name: ");
		scanf("%s",ph[(*count)].Fname);
		printf("\nLast Name: ");
		scanf("%s",ph[(*count)].Lname);
		printf("\nPhone Number: ");
		scanf("%s",ph[(*count)].PNum);
			
		(*count) = (*count) + 1;
	 	return(ph);
	 }//end else
	 	
}//end addFriend function


//delFriend function definition(case 2)
PB* delFriend(PB* ph, int* count)
{	
	char last[20]={'\0'};
	char first[20]={'\0'};
	char number[20]={'\0'};
	int i,found;
	int temp;

	printf("\nFirst Name: ");
	scanf("%s",first);
	printf("\nLast Name: ");
	scanf("%s",last);
	
	// search	
	for(i=0;i<(*count);i++)
	{	
		if((strcmp(last,ph[i].Lname)==0)&&(strcmp(first,ph[i].Fname)==0))
		{				
			found=1;
			break;
		}//end if loop
							
	}//end for loop
	
	// if found
	if(found==1)
	{	

		for(i=i;i<(*count)-1; i++)
			ph[i] = ph[i+1];	
		
		// if count is not 1
		if((*count)!=1)
		{
			PB* tmp = (PB*) realloc(ph,((*count)-1)*sizeof(PB));
			
			 if(tmp==NULL)
			{
				printf("Out of memory.");
				return(ph);
			}
		 	else
			{
				ph = tmp;
				(*count)=(*count)-1;
				printf("Record deleted from the phone book");
				
				return(ph);	
			
			}
		}//end if counter is not 1
		
		else // if counter is 1
		{
			(*count)=(*count)-1;
			printf("Record deleted from the phone book");
			return(ph);
		}
	}//end if inforation can be found
	
	else // if information can not found			
	{	
		printf("Record can not be found.");
		return(ph);	
	}
				
}//end delFriend function


//printFriend function definition (case 3)
PB* printFriend(PB* ph, int* count)
{	
	int y,m;
	
	for(y=0;y<(*count);y++)
		printf("\n%s %s %s",ph[y].Fname,ph[y].Lname,ph[y].PNum);
		
	return(ph);
	
}//end printFriend function 

//print data alphabetically
PB* sortFriend(PB* ph, int count)
{	
	int m, y;
	
	PB temp;
	int swapped = 0;
	do
	{
		swapped = 0;
		for(m=1;m<(count);m++)
			if((strcmp(ph[m-1].Lname,ph[m].Lname)>0))
			{
				swapped = 1;
				temp = ph[m-1];
				ph[m-1] = ph[m];
				ph[m] = temp;	
			}//end if
	
	}while(swapped == 1);//end for loop
	
	for(y=0;y<count;y++)
		printf("\n%s %s %s",ph[y].Fname,ph[y].Lname,ph[y].PNum);
	
	return(ph);
}//end print data alphabetically

//findfriend function(case 5)
PB* findFriend(PB* ph, int* count)
{	
	char name[20]={'\0'};
	char number[20]={'\0'};
	int i,found;
	
	printf("Please enter the name you want to find: \n");
	scanf("%s",name);	
	
	// search loop	
	for(i=0;i<(*count);i++)
	{	
		if((strcmp(name,ph[i].Lname)==0)||(strcmp(name,ph[i].Fname)==0))
		{				
			found=1;
			break;
		}//end if loop
							
	}//end for loop
	
	if(found==1)
	{
		printf("You friend is found: \n %s %s %s ",ph[i].Lname,ph[i].Fname,ph[i].PNum);
	}//end if
	
	else
	{
		printf("Can not find the record.");
	}
	
	return(ph);
	
	
}//end findFriend function

// select a friend randomly function (case 6)
PB* RndFriend(PB* ph, int* count)
{
	int Rnd=0;
	srand(time(NULL));
	Rnd=rand()%(*count);
	
	printf("You random select:\n %s %s %s",ph[Rnd].Lname,ph[Rnd].Fname,ph[Rnd].PNum );
	
	return (ph);
	
}//end select a friend randomly


//delete all friends function(case 7)
PB* DelAllFriend(PB* ph, int* count)
{
	free(ph);
	(*count)=0;
	ph = malloc(sizeof(PB));
	
	printf("\n All records has been deleted.");
	
	return(ph);
	
}//end delete all friends function


//Add data into file(case 8)
 PB* addFriendToFile(PB* ph,int *count)
{	
	int i; 
	FILE *pWrite;
	pWrite=fopen("phone_book.txt","a");	
	if(pWrite!=NULL)
	{					
		for(i=0;i<(*count);i++)
		{		
			fprintf(pWrite, "%s %s %s\n",ph[i].Fname,ph[i].Lname,ph[i].PNum);	
		}
		fclose(pWrite);
		printf("Record added to the file. ");
		
	}
	else
	{
		printf("Can not find the file");
	}
	
	return(ph);
}

PB* showFriendFromFile(PB* ph,int *count)
{
	int m=0;
	FILE *pRead;
	
	pRead=fopen("phone_book.txt","r");
	
	if(pRead!=NULL)
	{
		while(!feof(pRead))
		{
			// expand memory
			PB* tmp = (PB*) realloc(ph,((*count)+1)*sizeof(PB));
			if(tmp==NULL)
			{
					printf("Out of memory.");
		 			return(ph);
			}//end if
		 	else
			{	
				ph=tmp;
				fscanf(pRead,"%s %s %s\n",ph[(*count)].Fname,ph[(*count)].Lname,ph[(*count)].PNum);
				(*count)=(*count)+1;
			}		
			
						
		}//end while loop
		printf("Data updated,please select function 3 in the menu if you want to print out the data");		
	}//end if loop
	else
	{
		printf("File can not be opened");
	}
	
	fclose(pRead);
	return (ph);
}	
