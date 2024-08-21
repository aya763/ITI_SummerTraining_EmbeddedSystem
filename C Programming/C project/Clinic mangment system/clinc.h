#ifndef CLINC_H
#define CLINC_H

#define MAX_NAME_LENGTH 50
#define ADMIN_PASS  (1234ul)


typedef struct Patient {
    char name[MAX_NAME_LENGTH];
	char gender[10];
    int age;
    int id;
    struct Patient *next;
}pt;

typedef struct Slot {
    char time[20];
	int index;
    int reserved;
    int patientId;
    struct Slot *next;
}st;


int Clinc_start(void);

void Admin_mode(void);

void User_mode(void);

int Check_password(void);

void add_Patient_Record(void);

void edit_Patient_Record(void);

pt* find_patient(int id);

void initialize_slots(void);

void reserve_slot(void);

void cancel_reservation(void);

void view_patient_record(void);

void view_reservations();





#endif

