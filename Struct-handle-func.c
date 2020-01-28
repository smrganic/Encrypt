#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "Crypto.h"

void input_users(User *po_auser) {
	//while ((getchar()) != '\n');
	printf("\n// Input users //\n");
	printf("\nNumber of new users: ");

	int n, check = scanf("%d", &n);
	while (1) {
		if (check != 1) {
			while ((getchar()) != '\n');
			printf("\n// Input a number //\n");
			printf("\nNumber of new users: ");
			check = scanf("%d", &n);
		}
		else break;
	}
	while ((getchar()) != '\n');

	int i;
	po_auser = (User *)malloc(n * sizeof(User));
	char buff[512];
	fputs("\n\n// If there is no data for a category press Enter //\n", stdout);
	for (i = 0; i < n; i++) {

		printf("\n\n// %d. user data //\n", i + 1);

		fputs("\nTitle: ", stdout);
		fgets(buff, 512, stdin);
		rpl_enter(buff);
		po_auser[i].name.title = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].name.title, buff);

		fputs("\nFirst name: ", stdout);
		fgets(buff, 512, stdin);
		rpl_enter(buff);
		po_auser[i].name.first = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].name.first, buff);

		fputs("\nMiddle name: ", stdout);
		fgets(buff, 512, stdin);
		rpl_enter(buff);
		po_auser[i].name.middle = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].name.middle, buff);

		fputs("\nLast name: ", stdout);
		fgets(buff, 512, stdin);
		remove_enter(buff);
		po_auser[i].name.last = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].name.last, buff);


		printf("\n// Input relevant data for %s%s%s%s //\n", po_auser[i].name.title, po_auser[i].name.first, po_auser[i].name.middle, po_auser[i].name.last);
		
		printf("\n// Address //\n");
		printf("\nStreet: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		po_auser[i].address.street = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].address.street, buff);

		printf("\nCity: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		po_auser[i].address.city = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].address.city, buff);

		printf("\nPostal number: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') {
			po_auser[i].address.postal_num = 0;
		}
		else {
			while (check_num(buff)) {
				printf("\n// Input a number //\n");
				printf("\nPostal number: ");
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') break;
			}
			po_auser[i].address.postal_num = convert_char_num(buff);
		}

		printf("\nFloor number: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') {
			po_auser[i].address.floor = 0;
		}
		else {
			while (check_num(buff)) {
				printf("\n// Input a number //\n");
				printf("\nFloor number: ");
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') break;
			}
			po_auser[i].address.floor = convert_char_num(buff);
		}

		
		printf("\nE - mail: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') {
			po_auser[i].mail = (char *)malloc(strlen(buff) * sizeof(char));
			strcpy(po_auser[i].mail, buff);
		}
		else {
			while (check_mail(buff)) {
				printf("\n// E-mail not valid //\n");
				printf("\nE - mail: ");
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') break;
			}
			po_auser[i].mail = (char *)malloc(strlen(buff) * sizeof(char));
			strcpy(po_auser[i].mail, buff);
		}


		printf("\nPassword: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		po_auser[i].password = (char *)malloc(strlen(buff) * sizeof(char));
		strcpy(po_auser[i].password, buff);


		printf("\nGender: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') {
			po_auser[i].gender = (char *)malloc(strlen(buff) * sizeof(char));
			strcpy(po_auser[i].gender, buff);
		}
		else {
			while (check_gender(buff)) {
				printf("\n// Gender input not valid //\n");
				printf("\n// Options: Male, Female, Neutral //\n");
				printf("\nGender: ");
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') break;
			}
			po_auser[i].gender = (char *)malloc(strlen(buff) * sizeof(char));
			strcpy(po_auser[i].gender, buff);
		}
		


		printf("\nBlood type: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') {
			po_auser[i].blood_type = (char *)malloc(strlen(buff) * sizeof(char));
			strcpy(po_auser[i].blood_type, buff);
		}
		else {
			while (check_blood(buff)) {
				printf("\n// Blood type input not valid //\n");
				printf("\n// Options: A+, A-, B+, B-, AB+, AB-, 0+, 0- //\n");
				printf("\nBlood type: ");
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') break;
			}
			po_auser[i].blood_type = (char *)malloc(strlen(buff) * sizeof(char));
			strcpy(po_auser[i].blood_type, buff);
		}


		fputs("\nUniversal ID number: ", stdout);
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') po_auser[i].uid = 0;
		else {
			while (is_num_10(buff)) {
				fputs("\n// Number not valid //\n", stdout);
				fputs("\n// Input must be a 10 digit number //\n", stdout);
				fputs("\nUniversal ID number: ", stdout);
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') {
					po_auser[i].uid = 0;
					break;
				}
			}
			po_auser[i].uid = convert_char_num(buff);
		}


		fputs("\nAge: ", stdout);
		check = scanf("%d", &po_auser[i].age);
		while (1) {
			if (check != 1) {
				while ((getchar()) != '\n');
				printf("\n// Input a number //\n");
				fputs("\nAge: ", stdout);
				check = scanf("%d", &po_auser[i].age);
			}
			else if (po_auser[i].age < 0 || po_auser[i].age > 150) {
				while ((getchar()) != '\n');
				printf("\n// Input a sane age //\n");
				fputs("\nAge: ", stdout);
				check = scanf("%d", &po_auser[i].age);
			}
			else break;
		}
		while ((getchar()) != '\n');


		printf("\nAge: ");
		fgets(buff, 512, stdin);
		remove_enter(buff);
		if (buff[0] == '\0') {
			po_auser[i].age = 0;
		}
		else {
			while (check_num(buff)) {
				printf("\n// Input a number //\n");
				printf("\nFloor number: ");
				fgets(buff, 512, stdin);
				remove_enter(buff);
				if (buff[0] == '\0') break;
			}
			po_auser[i].address.floor = convert_char_num(buff);
		}



		fputs("\nWeight: ", stdout);
		check = scanf("%f", &po_auser[i].weight);
		while (1) {
			if (check != 1) {
				while ((getchar()) != '\n');
				printf("\n// Input a number //\n");
				fputs("\nWeight: ", stdout);
				check = scanf("%f", &po_auser[i].weight);
			}
			else if (po_auser[i].weight < 0 || po_auser[i].weight > 600) {
				while ((getchar()) != '\n');
				printf("\n// Input a sane weight //\n");
				fputs("\nWeight: ", stdout);
				check = scanf("%f", &po_auser[i].weight);
			}
			else break;
		}
		while ((getchar()) != '\n');



		fputs("\nHeight: ", stdout);
		check = scanf("%f", &po_auser[i].height);
		while (1) {
			if (check != 1) {
				while ((getchar()) != '\n');
				printf("\n// Input a number //\n");
				fputs("\nHeight: ", stdout);
				check = scanf("%f", &po_auser[i].height);
			}
			else if (po_auser[i].height < 0 || po_auser[i].height > 400) {
				while ((getchar()) != '\n');
				printf("\n// Input a sane height //\n");
				fputs("\nHeight: ", stdout);
				check = scanf("%f", &po_auser[i].height);
			}
			else break;
		}
		while ((getchar()) != '\n');
	}
}

int check_gender(char buff[]) {
	if (buff[0] == 'M' || buff[0] == 'm' && buff[1] == '\0') return 0;
	else if (buff[0] == 'F' || buff[0] == 'f' && buff[1] == '\0') return 0;
	else if (buff[0] == 'N' || buff[0] == 'n' && buff[1] == '\0') return 0;
	else if (strstr(buff, "male") != NULL || strstr(buff, "Male") != NULL && buff[4] == '\0') return 0;
	else if (strstr(buff, "female") != NULL || strstr(buff, "Female") != NULL && buff[6] == '\0') return 0;
	else if (strstr(buff, "neutral") != NULL || strstr(buff, "Neutral") != NULL && buff[7] == '\0') return 0;
	else return 1;
}

int check_blood(char buff[]) {
	for (int i = 0; buff[i] != '\0'; i++) buff[i] = toupper(buff[i]);
	if (strstr(buff, "A+") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "A-") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "B+") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "B-") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "0+") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "0-") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "AB+") != NULL && buff[3] == '\0') return 0;
	else if (strstr(buff, "AB-") != NULL && buff[3] == '\0') return 0;
	else if (strstr(buff, "O+") != NULL && buff[2] == '\0') return 0;
	else if (strstr(buff, "O-") != NULL && buff[2] == '\0') return 0;
	else return 1;
}

int check_mail(char buff[]) {
	int i, at_place = 0;
	for (i = 0; buff[i] != '\0'; i++) {
		if (isalnum(buff[i])) {}
		else {
			if (buff[i] == '@') at_place = i;
			else if (buff[i] == '.') continue;
			else if (buff[i] == '-') continue;
			else return 1;
		}
	}
	if (at_place != 0) {
		if (at_place == len(buff)) return 1;
		else if (buff[len(buff)] == '.') return 1;
		else if (buff[at_place - 1] == '.' || buff[at_place + 1] == '.' || buff[at_place + 1] == ' ' || buff[at_place - 1] == ' ') return 1;
		else return 0;
	}
	else return 1;
	return 0;
}

long int convert_char_num(char buff[]) {
	int i = 0, len = strlen(buff);
	long int value = 0;
	for (len; len != 0; len--) {
		value += ((long int)pow(10, i) * (buff[len - 1] - '0'));
		i++;
	}
	return value;
}

void rpl_enter(char buff[]) {
	int i;
	if (strlen(buff) == 1) remove_enter(buff);
	else {
		for (i = 0; buff[i] != '\n'; i++) {}
		buff[i] = ' ';
	}
}

void remove_enter(char buff[]) {
	int i;
	for (i = 0; buff[i] != '\n'; i++) {}
	buff[i] = '\0';
}

int is_num_10(char buff[]) {
	int i;
	if (strlen(buff) != 10) return 1;
	for (i = 0; buff[i] != '\0'; i++)
		if (!isdigit(buff[i])) return 1;
	return 0;
}

int check_num(char buff[]) {
	int i;
	long int help = convert_char_num(buff);
	if (help < 0) return 1;
	for (i = 0; buff[i] != '\0'; i++)
		if (!isdigit(buff[i])) return 1;
	return 0;
}

void clear(char buff[]) {
	int i;
	for (i = 0; buff[i] != '\0'; i++) buff[i] = '\0';
}

int len(char buff[]) {
	int i;
	for (i = 0; buff[i] != '\0'; i++) {}
	return i - 1;
}