#include <stdio.h>
#include "sdb.h"

u8 top = -1;
student students[MAX]; // array of structs
//bool noStudents = False;
bool SDB_IsFull() { // checks if the students array is full
	if (top == MAX - 1) { // top is like an index so it has to be less tha MAX by 1
		return True;
	}
	return False;
}
u8 SDB_GetUsedSize() { // gets the size of the array
	return top + 1;  // simple enough top + 1
}
bool SDB_AddEntry() {

	if (SDB_IsFull()) { // if the database is full then return False
		printf("can't add more!\n");
		return False;
	}
	else { // if not then add a new student and return True!

		student newStudent;
		printf("enter the student's ID\n");
		scanf_s("%d", &newStudent.Student_ID);

		if (SDB_IsIdExist(newStudent.Student_ID)) {
			printf("The id given already Exists!\n");
			return False;
		}

		printf("enter the student's year\n");
		scanf_s("%d", &newStudent.Student_year);		
		printf("enter the student's Course1 ID\n");
		scanf_s("%d", &newStudent.Course1_ID);		
		printf("enter the student's Course1 grade\n");
		scanf_s("%d", &newStudent.Course1_grade);		
		printf("enter the student's Course2 ID\n");
		scanf_s("%d", &newStudent.Course2_ID);		
		printf("enter the student's Course2 grade\n");
		scanf_s("%d", &newStudent.Course2_grade);		
		printf("enter the student's Course3 ID\n");
		scanf_s("%d", &newStudent.Course3_ID);
		printf("enter the student's Course3 grade\n");
		scanf_s("%d", &newStudent.Course3_grade);

		students[++top] = newStudent;
		printf("added Succesfully!\n");
		return True;
	}
}
void SDB_DeleteEntry(u32 id) {
	if (SDB_GetUsedSize() > MIN) { // if the size is greater than 3 then you can delete!

		if (SDB_IsIdExist(id)) { // checks if the id given exists or not. if so then deletion starts!
			u8 i = 0;
			for (; i < top + 1; i++) { // first for loop tries to find the index of the wanted student to delete then breaks out of it!
				if (id == students[i].Student_ID) {
					break;
				}
			}

			for (; i < top + 1; i++) { // second for loop is moving the students (after determining the index of the wanted student to be deleted) to the left to delete the wanted student!
				students[i] = students[i+1];
				
			}
			top -= 1; // then simply decrease top by 1 because the array size has decreased!
			printf("Student deleted successfully!\n");
		}

	}
	else { // no deletion happens if the database still smaller than 4
		printf("Can't delete!");
		printf("The database must have more than 3 Students to be able to delete an Entry!\n");
	}
}
bool SDB_ReadEntry(u32 id) { // to read a students info
	if (SDB_IsIdExist(id)) { // checks if the id given exists or not. if so then we read the students info!
		for (u8 i = 0; i < top + 1; i++) { // goes through the array to find the index of the wanted students id
			if (id == students[i].Student_ID) { // then print it and return True!
				printf("Found!\nStudent_ID : %d\nStudent_year : %d\nCourse1_ID : %d\nCourse1_grade : %d\nCourse2_ID : %d\nCourse2_grade : %d\nCourse3_ID : %d\nCourse3_grade : %d\n", students[i].Student_ID, students[i].Student_year, students[i].Course1_ID, students[i].Course1_grade, students[i].Course2_ID, students[i].Course2_grade, students[i].Course3_ID, students[i].Course3_grade);
				return True;
			}
		}
	}
		printf("Doesn't exist!\n"); // when the id doesn't exist then it will print this message!
		return False;
}
void SDB_GetList(u8* count, u32* list) { // gets the list of ids of all students in the database
	*count = top + 1;
	if (*count != 0) { // if the count (which is top + 1) is not zero then you can fill the "list" array
		for (u8 i = 0; i < *count; i++) {
			list[i] = students[i].Student_ID;
		}
	}
	//else { // if not then the database has no students!
	//	//printf("Database has no students!\n");
	//	noStudents = True;
	//}
}
bool SDB_IsIdExist(u32 id) { // checks if the students id exist or not
	u32 idList[10];
	u8 count = top + 1;
	SDB_GetList(&count, idList); // gets the idList of all students currently on the database!
	for (u8 i = 0; i < count; i++) { // then goes through this loop to check if any of them has the same id given
		if (id == idList[i]) {
			return True; // if so, returns True
		}
	}
	return False; // else, then False
}