
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"clinc.h"


pt* head_pt=NULL;
st* head_st=NULL;



pt* find_patient(int id) 
{
    pt *current = head_pt;
    while (current != NULL) 
	{
        if (current->id == id) 
		{
            return current;
        }
        current = current->next;
    }
    return NULL;
}




void add_Patient_Record(void)
{
    pt *newPatient = (pt *)malloc(sizeof(pt));
    if (newPatient == NULL) 
	{
        printf("Error: Memory allocation failed.\n");
        return;
    }

    printf("Enter patient name: ");
    scanf("%s", newPatient->name);

    printf("Enter patient age: ");
    scanf("%d", &(newPatient->age));

    printf("Enter patient gender: ");
    scanf("%s", newPatient->gender);

    printf("Enter patient ID: ");
    scanf("%d", &(newPatient->id));
	

    newPatient->next = NULL;
	
	
	if(find_patient(newPatient->id)!=NULL)
	{
		printf("Error: Patient ID already exists.\n");
		free(newPatient);
		return;
	}

    if (head_pt == NULL) 
	{
        head_pt = newPatient;
        return;
    }
	else 
	{
		pt *current = head_pt;
		while (current->next != NULL) 
		{
			current = current->next;
		}

		current->next = newPatient;
	} 
}

void edit_Patient_Record(void) 
{
    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    pt *patient = find_patient(id);
    if (patient == NULL) 
	{
        printf("Error: Patient ID not found.\n");
        return;
    }

    printf("Enter new patient name: ");
    scanf("%s", patient->name);

    printf("Enter new patient age: ");
    scanf("%d", &(patient->age));

    printf("Enter new patient gender: ");
    scanf("%s", patient->gender);

    printf("Patient record updated successfully.\n");
}


void initialize_slots(void) 
{
    st *slot1 = (st *)malloc(sizeof(st));
    strcpy(slot1->time, "2pm to 2:30pm");
    slot1->reserved = 0;
    slot1->patientId = -1;
	slot1->index=1;

    st *slot2 = (st *)malloc(sizeof(st));
    strcpy(slot2->time, "2:30pm to 3pm");
    slot2->reserved = 0;
    slot2->patientId = -1;
	slot2->index=2;
	

    st *slot3 = (st *)malloc(sizeof(st));
    strcpy(slot3->time, "3pm to 3:30pm");
    slot3->reserved = 0;
    slot3->patientId = -1;
	slot3->index=3;

    st *slot4 = (st *)malloc(sizeof(st));
    strcpy(slot4->time, "4pm to 4:30pm");
    slot4->reserved = 0;
    slot4->patientId = -1;
	slot4->index=4;

    st *slot5 = (st *)malloc(sizeof(st));
    strcpy(slot5->time, "4:30pm to 5pm");
    slot5->reserved = 0;
    slot5->patientId = -1;
	slot5->index=5;

    slot1->next = slot2;
    slot2->next = slot3;
    slot3->next = slot4;
    slot4->next = slot5;
    slot5->next = NULL;

    head_st = slot1;
}



void reserve_slot(void) 
{
    if (head_st == NULL) 
	{
        initialize_slots();
    }

    printf("\t\t\tAvailable Slots:\n");
    st *current = head_st;
    while (current != NULL) 
	{
        if (current->reserved == 0) 
		{
			printf("\t\t\t%d) ",current->index);
            printf("%s\n", current->time);
        }
        current = current->next;
    }

    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    pt *patient = find_patient(id);
    
    if (patient == NULL) 
	{
        printf("Error: Patient ID not found.\n");
        return;
    }

	int choice;
	printf("Enter index of slot time needed: ");
	scanf("%d",&choice);
	
	current = head_st;
    while (current != NULL) 
	{
        if (current->index == choice && current->reserved == 0) 
		{
            current->reserved = 1;
            current->patientId = id;
            printf("Slot reserved successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Error: Invalid slot index or slot already reserved.\n");
}


void cancel_reservation(void) 
{
    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    st *current = head_st;
    while (current != NULL) 
	{
        if (current->reserved == 1 && current->patientId == id) 
		{
            current->reserved = 0;
            current->patientId = -1;
            printf("Reservation canceled successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Error: No reservation found for the given patient ID.\n");
}


int Check_password(void)
{
	int i=0;
	int user_pass;
	while(i<3)
	{
		printf("Enter password:");
		scanf("%d",&user_pass);
		if(user_pass == ADMIN_PASS)
		{
			printf("\t\t\tCorrect Password\n");
			return 1;
		}
		else 
		{
			printf("\t\t\tWrong Password\n");
			i++;
		}
	}
	printf("Finished Number of trial!!!!!!! Return to main page\n");
	return 0;
	
}


void Admin_mode(void)
{
	if(Check_password())
	{
		while(1)
		{
			printf("\n*****************Admin mode******************\n");
		
			printf("1.Add new patient record\n2.Edit patient record\n3.Reserve a slot with the doctor\n4.Cancel reservation\n5.Exit\n");
			
			int choice;
			printf("Enter your choice:");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1:
					add_Patient_Record();	
				break;
				case 2:
					edit_Patient_Record();
				break;
				case 3:
					reserve_slot();
				break;
				case 4:
					cancel_reservation();
				break;
				case 5:
					return ;
				break;
				default:
					printf("Wrong chice\n");
				break;
			}
		}
	}
	
	
	
}

void view_patient_record(void) 
{
    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    pt *patient = find_patient(id);
    if (patient == NULL) 
	{
        printf("Error: Patient ID not found.\n");
        return;
    }

    printf("Patient Information:\n");
    printf("Name: %s\n", patient->name);
    printf("Age: %d\n", patient->age);
    printf("Gender: %s\n", patient->gender);
    printf("ID: %d\n", patient->id);
	printf("\n");
}

void view_reservations() 
{
    printf("Today's Reservations:\n");

    st *current = head_st;
    while (current != NULL) 
	{
        if (current->reserved == 1) 
		{
            printf("Slot: %s, Patient ID: %d\n", current->time, current->patientId);
        }
        current = current->next;
    }
}

void User_mode(void)
{
	while(1)
	{
		printf("\n*****************User mode******************\n");
	
		printf("1.View patient record.\n2.View today’s reservations.\n3.Exit\n");
		
		int choice;
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				view_patient_record();
			break;
			case 2:
				view_reservations();
			break;
			case 3:
				return ;
			break;
			default:
				printf("Wrong chice\n");
			break;
		}
	}
}


int Clinc_start(void)
{
	printf("\n*****************Welcome to your clinc mangment system******************\n");
	
	printf("1.Admin mode\n2.User mode\n3.Exit\n");
	
	int choice;
	printf("Enter your choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			Admin_mode();
		break;
		case 2:
			User_mode();
		break;
		case 3:
			return 0;
		break;
		default:
			printf("Wrong chice\n");
		break;
	}
	
	return 1;
	
}