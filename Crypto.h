#ifndef CRYPTO_H
#define CRYPTO_H

typedef struct date {
	int dd, mm, yyyy;
} Date;

typedef struct address {
	char *street, *city;
	int postal_num, floor;
} Address;

typedef struct name {
	char *first, *middle, *last, *title;
} Name;

typedef struct user {
	char *mail, *password, *gender, *blood_type;
	int age;
	long int uid;
	float height, weight;
	Name name;
	Address address;
	Date bday;
	struct user *next;
} User;

void input_users(User *po_auser);

int check_gender(char buff[]);

int check_mail(char buff[]);

long int convert_char_num(char buff[]);

int check_blood(char buff[]);

void remove_enter(char buff[]);

void rpl_enter(char buff[]);

int is_word(char buff[]);

int check_num(char buff[]);

int is_num_10(char buff[]);

void create_doc(void);

void delete_doc(void);

void rename_doc(void);

void input_text(void);

void print_file(void);

void print_help(void);

void clear(char buff[]);

int len(char buff[]);

int valid_file(char buff[]);

void cae_encry(void);

void cae_decry(void);

void vig_encry(void);

void vig_decry(void);

#endif
