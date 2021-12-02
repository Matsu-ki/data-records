#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
//By Matsu

FILE * file;


typedef struct{
	char record_code[10];
	char name[40];
	char phone_number[50];
	char age[100];
	char gender[50];
	
}person;

person archive, record;

void registration(){
	system("cls");
	char crecord_code[10];
	char cname[40];
	char cphone_number[50];
	char cage[100];
	char cgender[50];
	char response;
	
	//creating and doing the file verification;
	
    file = fopen("archive.dat","r+b");
    if (file == NULL) {
    	printf("Creating the archive...\n");
    	Sleep(2000);
    	file = fopen("archive.dat","w+b");
    	
    	if (file == NULL) {
    		printf("Error: Something bad happened, could not create a file!\n");
        	exit(1);	
    	}
    	else {
    		printf("\nFile created successfully!\n\n");
       	}
    }
	fclose(file);
	
	file = fopen("archive.dat","a+b"); 
	
	
	do{
		printf("Number of record code: ");
		fflush(stdin);
		gets(crecord_code);
		
		printf("The client name: ");
		fflush(stdin);
		gets(cname);
		
		printf("Client phone number: ");
		fflush(stdin);
		gets(cphone_number);
		
		printf("Client age: ");
		fflush(stdin);
		gets(cage);
		
		printf("Client gender: ");
		fflush(stdin);
		gets(cgender);
		
		
		//Copiyng the variables responses to the struct variables;
		
		strcpy(record.record_code, crecord_code);
		strcpy(record.name, cname);
		strcpy(record.phone_number, cphone_number);
		strcpy(record.age, cage);
		strcpy(record.gender, cgender);		
		system("cls");
		Sleep(1500);
		puts("-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
		printf("Record code: %s\n", record.record_code);
		printf("Name: %s\n", record.name);
		printf("Phone Number: %s\n", record.phone_number);
		printf("Age: %s\n", record.age);
		printf("Gender: %s\n", record.gender);
	    puts("-=--=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-");
        
        puts("\nSuccessful registration!\n");
        fwrite(&record, sizeof(person), 1, file);
         
        printf("Do you wish to continue (Y or N)? ");
        fflush(stdin);
        scanf("%c",& response);
	}while (response == 'Y' || response == 'y');
    fclose(file);
    system("cls");
}

void search(){
	system("cls");
	char crecord_code[10];
	char cname[40];
	char cphone_number[50];
	char cage[100];
	char cgender[50];
	int found = 0;
	
	file = fopen("archive.dat","rb");
	if (file == NULL){
        printf("Error in the file!\n");
        system("pause");
        system("cls"); 
    }
    else{
        file = fopen("archive.dat","rb"); 
        rewind(file);
        printf("Type de record code: ");
        fflush(stdin);
        gets(crecord_code);
        
         while(fread(&archive, sizeof(person), 1, file) == 1){
            if(strcmp(archive.record_code, crecord_code) == 0){
                found = 1;
                puts("\nRecord number founded!\n\n");
                printf("Code: %s\n", archive.record_code);
                printf("Name: %s\n", archive.name);
				printf("Phone number: %s\n", archive.phone_number);
				printf("Age: %s\n", archive.age);
				printf("Gender: %s\n", archive.gender);
                fclose(file);
                system("pause");
                system("cls");
                break;
            }
        }
        if(found == 0){
            puts("Code not founded, verify your the correct code and try again!\n");
            fclose(file);
            system("pause");
            system("cls");
        }
    }	
}

void list(){
	file = fopen("archive.dat","rb");
	if (file == NULL){
        printf("Error in the file!\n");
        system("pause");
        system("cls"); 
    }else{
    	file = fopen("archive.dat","rb"); 
    	rewind(file);
    	 while(fread(&archive, sizeof(person), 1, file) == 1){
    	 	system("cls");
    	 	puts("-=-=-=-=-=-=- ALL CODES REGISTERED -=-=-=-=-=-=-");
            printf("\nRecord code: %s\n", archive.record_code);
        	printf("Name: %s\n", archive.name);
        	printf("Phone number: %s\n", archive.phone_number);
        	printf("Age: %s\n", archive.age);
        	printf("Gender: %s\n", archive.gender);
            printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        }
        fclose(file);
        system("pause"); 
        system("cls");
    }
}

void change(){
	system("cls");
    char crecord_code[5];
    char cname[30];
    char cphone_number[30];
    char cage[20];
    char cgender[50];
    int a = -1;
    int status = 0, found = 0;

   	file = fopen("archive.dat","rb");
	if (file == NULL){
        printf("Error in the file!\n");
        system("pause");
        system("cls"); 
	}
    else{
        printf("Type the record code: ");
        fflush(stdin);
        gets(crecord_code);
        while(fread(&archive, sizeof(person), 1, file) == 1){
            if(strcmp(archive.record_code, crecord_code) == 0){
            	found = 1;
            	break;
            }
        }
        if(found == 0){
            puts("Invalid code!\n");
            puts("Closing the program...");
            system("pause"); 
            system("cls");
        }
         
        else{
            puts("\nCode sucessfuly found!\n");
            
            printf("Code: %s\n", archive.record_code);
            printf("Name: %s\n", archive.name);
			printf("Phone number: %s\n", archive.phone_number);
			printf("Age: %s\n", archive.age);
			printf("Gender: %s\n", archive.gender);
            puts("\n");         
              
            printf("Number of the new record code [If you want]: ");
			fflush(stdin);
			gets(crecord_code);
		
			printf("New client name [If you want]: ");
			fflush(stdin);
			gets(cname);
		
			printf("New phone number [If you want]: ");
			fflush(stdin);
			gets(cphone_number);
		
			printf("New age [If you want]: ");
			fflush(stdin);
			gets(cage);
		
			printf("New gender [If you want]: ");
			fflush(stdin);
			gets(cgender);
	          
	        strcpy(record.record_code, crecord_code);
			strcpy(record.name, cname);
			strcpy(record.phone_number, cphone_number);
			strcpy(record.age, cage);
			strcpy(record.gender, cgender);	  
              
            system("cls");  
            puts("\nNew data records...");
            puts("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
            printf("\nRecord code: %s\n", archive.record_code);
        	printf("Name: %s\n", archive.name);
        	printf("Phone number: %s\n", archive.phone_number);
        	printf("Age: %s\n", archive.age);
        	printf("Gender: %s\n", archive.gender);
            
            puts("Updating data...");
            fseek(file, a*sizeof(person), SEEK_CUR);
            status = fwrite(&archive, sizeof(person), 1, file);
            fclose(file);
            if(status == 1){
                puts("Data updated successfully!");
                system("pause"); 
                system("cls");
            }
            else{
                puts("An error occurred while updating the data!");
                system("pause"); 
                system("cls");
            }
        }
	}
}


void invalid(){
	puts("\nInvalid option!\n");
    system("pause");
}


int main(){
	
		system("CHCP 1252 > NULL");
    int option = 0;
    
    while(option != 5){
    	system("cls");
		printf("|-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|");
		printf("\n|       Matsu Registration   	     |");
		printf("\n|-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|");
		printf("\n|   1 - New Record           		 ");
		printf("\n|   2 - Search            		 ");
		printf("\n|   3 - List all records    	     ");
		printf("\n|   4 - Change records         	 ");
		printf("\n|   5 - Exit                        ");
		printf("\n|-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-|\n");
		printf("\nType the number what you want realize the action: ");
		scanf("%d",&option);
		
        switch(option){
               
            case 1:
                registration();
                
            case 2:
            	search();
            	
            case 3:
            	list();
            	
            case 4:
            	change();

            default:
                invalid();
            break;
        }
    }
    getch();
	
}

/*
Translate to your language if you 
want to understand better or 
help someone

you are welcome

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
"Planning for failure is even dumber than simply planning."

Sanchez, Rick.
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

*/
