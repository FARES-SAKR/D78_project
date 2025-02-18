#include <stdio.h>
#include <stdlib.h>
#include "sdb.h"

//extern bool noStudents;

void SDB_APP() {
	u8 choice = 0;
	while (True) {
		do {
		printf("1. Add entry\n2. Get used size in database\n3. Read student data\n4. Get the list of student IDs\n5. Check if an ID exists\n6. Delete student data\n7. Check if database is full\n8. Exit\n");
		scanf_s("%hhu", &choice);
		if (choice < 1 || choice > 8) {
			printf("Invalid Input!\n");
		}
		} while (choice < 1 || choice > 8);

		SDB_action(choice);
	}
}
void SDB_action(u8 choice) {
	u32 id;
	u32 idList[MAX];
	u8 count;

	switch (choice) {
	case 1 :
		SDB_AddEntry();
		break;
	case 2 :
		printf("Size is : %d\n",SDB_GetUsedSize());
		break;
	case 3 :
		printf("Enter the Id : ");
		scanf_s("%d", &id);
		SDB_ReadEntry(id);
		break;	
	case 4 :
		SDB_GetList(&count, idList);
		if (count == 0) {
			printf("Database has no students!\n");
			
		}
		else {
			for (u8 i = 0; i < count; i++) {
				printf("student %d : id = %d\n",i+1, idList[i]);
			}
		}
		break;	
	case 5 :
		printf("Enter the Id : ");
		scanf_s("%d", &id);
		if (SDB_IsIdExist(id)) {
			printf("Exists\n!");
		}
		else {
			printf("doesn't Exist\n!");
		}
		break;	
	case 6 :
		printf("Enter the Id : ");
		scanf_s("%d", &id);
		SDB_DeleteEntry(id);
		break;	
	case 7 :
		if (SDB_IsFull()) {
			printf("Database is Full\n");
		}
		else {
			printf("Database is not Full\n");
		}
		break;	
	case 8 :
		exit(0);
		break;
	}
}
