#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Crypto.h"

int valid_file(char buff[]) {
	remove_enter(buff);
	int n = len(buff);
	if (buff[n] == 't' && buff[n - 1] == 'x' && buff[n - 2] == 't' && buff[n - 3] == '.') return 1;
	return 0;
}

int is_word(char buff[]) {
	int i;
	for (i = 0; buff[i] != '\0'; i++) {
		if (isdigit(buff[i])) return 1;
	}
	return 0;
}

void create_doc(void) {

	printf("\n// Make new file //\n");

	char buff[128];
	printf("\nInput file name: ");
	scanf("%[^\n]s", buff);

	if (valid_file(buff) != 1) {
		while ((getchar()) != '\n');
		printf("\n// Invalid file name //\n\n");
	}

	else {
		while ((getchar()) != '\n');

		FILE *fajl = fopen(buff, "w+");
		if (fajl == NULL) printf("\n// File %s creation failed //\n", buff);

		else {
			printf("\n// File %s successfully created //\n\n", buff);
			fclose(fajl);
		}
	}
}

void delete_doc(void) {

	printf("\n// Delete file //\n");

	char buff[128];
	printf("\nFile name: ");
	scanf("%[^\n]s", buff);

	int check = valid_file(buff);
	if (check != 1) {
		while ((getchar()) != '\n');
		printf("\n// Invalid file name //\n\n");
	}

	else {
		while ((getchar()) != '\n');

		FILE *fajl = fopen(buff, "r");
		if (fajl == NULL) printf("\n// File %s not found //\n\n", buff);

		else {
			fclose(fajl);
			if (remove(buff)) printf("\n// File %s couldn't be deleted //\n\n", buff);
			else printf("\n// File %s successfully deleted //\n\n", buff);
		}
	}
}

void rename_doc(void) {
	printf("\n// Rename file //\n");

	char old_name[128], new_name[128];
	printf("\nFile to rename: ");
	scanf("%[^\n]s", old_name);
	int check = valid_file(old_name);

	if (check != 1) {
		while ((getchar()) != '\n');
		printf("\n// Invalid file name //\n\n");
	}

	else {

		while ((getchar()) != '\n');
		printf("\nNew file name: ");
		scanf("%[^\n]s", new_name);
		check = valid_file(new_name);

		if (check != 1) {
			while ((getchar()) != '\n');
			printf("\n// Invalid file name //\n\n");
		}

		else {

			while ((getchar()) != '\n');
			FILE *fajl = fopen(old_name, "r");

			if (fajl == NULL) printf("\n// File %s not found //\n\n", old_name);

			else {
				fclose(fajl);
				if (rename(old_name, new_name)) printf("\n// File %s couldn't be renamed //\n\n", old_name);
				else printf("\n// File %s successfully renamed to %s //\n\n", old_name, new_name);
			}
		}
	}
}

void input_text(void) {

	printf("\n// Text input //\n");

	printf("\nFile name for text input: ");
	char buff[128];
	scanf("%[^\n]s", buff);

	if (valid_file(buff) != 1) {
		while ((getchar()) != '\n');
		printf("\n// Invalid file name //\n\n");
	}

	else {
		while ((getchar()) != '\n');

		FILE *input = fopen(buff, "a");

		if (input == NULL) printf("\n// File %s creation failed //\n\n", buff);

		else {
			printf("\nInput text\n\n");
			char buff2[512];
			fgets(buff2, 512, stdin);
			fputs(buff2, input);
			fclose(input);
			printf("\n// File saved //\n\n");
		}
	}
}

void print_file(void) {
	printf("\n// Print file //\n");
	printf("\nFile name: ");

	char name[128];
	scanf("%[^\n]s", name);
	FILE *fajl = fopen(name, "r");

	if (fajl == NULL) {
		printf("\n// File not found //\n\n");
		while ((getchar()) != '\n');
	}

	else {
		while ((getchar()) != '\n');

		printf("\n// File text //\n\n");
		char c;
		c = fgetc(fajl);
		while (c != EOF) {
			printf("%c", c);
			c = fgetc(fajl);
		}
		printf("\n\n// End of file text //\n\n");
		fclose(fajl);
	}
}

void print_help(void) {
	printf("\n-h // --help (Show help)\n");
	printf("-u // --users (Create new user struct)\n");
	printf("-m // --make new (Make new file)\n");
	printf("-i // --input (Input text to file)\n");
	printf("-r // --remove (Delete a file)\n");
	printf("-p // --print (Print file)\n");
	printf("-c // --change name (Rename a file)\n");
	printf("-e -c // --encrypt --caesar (Encrypt using the Caesar cypher)\n");
	printf("-d -c // --decrypt --caesar (Decrypt using the Caesar cypher)\n");
	printf("-e -v // --encrypt --vigenere (Encrypt using the Vigenere cypher)\n");
	printf("-d -v // --decrypt --vigenere (Decrypt using the Vigenere cypher)\n");
	printf("-k // --kill (Kill program)\n\n");
}

void cae_encry(void) {

	printf("\n// Encryption - Caesar cypher //\n");

	printf("\nFile to encrypt: ");
	char buff[128];
	scanf("%[^\n]s", buff);
	FILE *encry = fopen(buff, "r");

	if (encry == NULL) {
		printf("\n// File not found //\n\n");
		while ((getchar()) != '\n');
	}

	else {

		while ((getchar()) != '\n');

		printf("\nOutput file name: ");
		char buff2[128];
		scanf("%[^\n]s", buff2);

		if (valid_file(buff2) != 1) {
			printf("\n// Invalid file name //\n\n");
			while ((getchar()) != '\n');
		}

		else {

			while ((getchar()) != '\n');

			FILE *out = fopen(buff2, "w");

			char c[256];
			int i;
			while (fgets(c, 256, encry) != NULL) {
				for (i = 0; c[i] != '\0'; i++) {
					if (c[i] == '\n') continue;
					c[i] += 3;
				}
				fputs(c, out);
			}

			fclose(encry);
			fclose(out);
			printf("\n// File %s successfully encrypted to file %s //\n\n", buff, buff2);
		}
	}
}

void cae_decry(void) {

	printf("\n// Decryption - Caesar cypher //\n");

	printf("\nFile to decrypt: ");
	char buff[128];
	scanf("%[^\n]s", buff);
	FILE *decry = fopen(buff, "r");

	if (decry == NULL) {
		printf("\n// File not found //\n\n");
		while ((getchar()) != '\n');
	}

	else {

		while ((getchar()) != '\n');

		printf("\nOutput file name: ");
		char buff2[128];
		scanf("%[^\n]s", buff2);

		if (valid_file(buff2) != 1) {
			printf("\n// Invalid file name //\n\n");
			while ((getchar()) != '\n');
		}

		else {

			while ((getchar()) != '\n');

			FILE *out = fopen(buff2, "w");

			char c[256];
			int i;
			while (fgets(c, 256, decry) != NULL) {
				for (i = 0; c[i] != '\0'; i++) {
					if (c[i] == '\n') {
						continue;
					}
					c[i] -= 3;
				}
				fputs(c, out);
			}

			fclose(out);
			fclose(decry);
			printf("\n// File %s successfully decrypted to file %s //\n\n", buff, buff2);
		}
	}
}

void vig_encry(void) {

	printf("\n// Encryption - Vigenere cypher //\n");

	printf("\nFile to encrypt: ");
	char file[128];
	scanf("%[^\n]s", file);
	FILE *fajl = fopen(file, "r");

	if (fajl == NULL) {
		printf("\n// File not found //\n\n");
		while ((getchar()) != '\n');
	}

	else {

		while ((getchar()) != '\n');

		printf("\nOutput file name: ");
		char output[128];
		scanf("%[^\n]s", output);

		if (valid_file(output) != 1) {
			printf("\n// Invalid file name //\n\n");
			while ((getchar()) != '\n');
		}

		else {

			while ((getchar()) != '\n');

			FILE *out = fopen(output, "w");

			printf("\nKeyword: ");
			char keyword[128];
			scanf("%[^\n]s", keyword);
			while ((getchar()) != '\n');

			while (is_word(keyword) != 0) {
				printf("\n// Keyword must be a word //\n\n");
				scanf("%[^\n]s", keyword);
				while ((getchar()) != '\n');
			}

			int i, j;
			char table[26][26], c;

			FILE *save = fopen("VIG_table.txt", "r");
			if (save == NULL) {

				save = fopen("VIG_table.txt", "w");

				for (i = 0; i < 26; i++) {
					for (j = 0; j < 26; j++) {
						c = 'A' + i + j;
						if (c > 'Z')
							c -= 26;
						table[i][j] = c;
						fprintf(save, "%c ", table[i][j]);
					}
					fprintf(save, "%c", '\n');
				}
				fclose(save);
			}

			else {
				for (i = 0; i < 26; i++) {
					for (j = 0; j < 26; j++) {
						c = 'A' + i + j;
						if (c > 'Z')
							c -= 26;
						table[i][j] = c;
					}
				}
				fclose(save);
			}

			char lt_encry[256], lt_out[256], keyword_help[256];
			int m = len(keyword);
			while (fgets(lt_encry, 256, fajl) != NULL) {

				int n = len(lt_encry);
				j = 0;
				for (i = 0; i < n; i++) {
					keyword_help[i] = keyword[j];
					j++;
					if (j > m) j = 0;
				}
				keyword_help[i] = '\0';


				int col_index = 0, row_index = 0;
				for (i = 0; i < n; i++) {
					while (toupper(lt_encry[i]) != table[row_index][0]) {
						row_index++;
						if (row_index > 39) break;
					}
					while (toupper(keyword_help[i]) != table[0][col_index]) {
						col_index++;
						if (col_index > 39) break;
					}
					if (row_index < 39 && col_index < 39) {
						lt_out[i] = table[row_index][col_index];
						row_index = 0; col_index = 0;
					}
					else {
						lt_out[i] = lt_encry[i];
						row_index = 0; col_index = 0;
					}
				}
				lt_out[i] = '\n';
				lt_out[i + 1] = '\0';

				fputs(lt_out, out);
			}
			fclose(fajl);
			fclose(out);
			printf("\n// File %s successfully encrypted to file %s //\n\n", file, output);
		}
	}
}

void vig_decry(void) {

	printf("\n// Decryption - Vigenere cypher //\n");

	printf("\nFile to decrypt: ");
	char file[128];
	scanf("%[^\n]s", file);
	FILE *fajl = fopen(file, "r");

	if (fajl == NULL) {
		printf("\n// File not found //\n\n");
		while ((getchar()) != '\n');
	}

	else {

		while ((getchar()) != '\n');

		printf("\nOutput file name: ");
		char output[128];
		scanf("%[^\n]s", output);

		if (valid_file(output) != 1) {
			printf("\n// Invalid file name //\n\n");
			while ((getchar()) != '\n');
		}

		else {

			while ((getchar()) != '\n');

			FILE *out = fopen(output, "w");

			printf("\nKeyword: ");
			char keyword[128];
			scanf("%[^\n]s", keyword);
			while ((getchar()) != '\n');

			while (is_word(keyword) != 0) {
				printf("\n// Keyword must be a word //\n\n");
				scanf("%[^\n]s", keyword);
				while ((getchar()) != '\n');
			}

			int i, j;
			char table[26][26], c;

			FILE *save = fopen("VIG_table.txt", "r");
			if (save == NULL) {

				save = fopen("VIG_table.txt", "w");

				for (i = 0; i < 26; i++) {
					for (j = 0; j < 26; j++) {
						c = 'A' + i + j;
						if (c > 'Z') {
							c -= 26;
						}
						table[i][j] = c;
						fprintf(save, "%c ", table[i][j]);
					}
					fprintf(save, "%c", '\n');
				}

				fclose(save);
			}
			else {
				for (i = 0; i < 26; i++) {
					for (j = 0; j < 26; j++) {
						c = 'A' + i + j;
						if (c > 'Z') {
							c -= 26;
						}
						table[i][j] = c;
					}
				}
				fclose(save);
			}


			char lt_encry[256], lt_out[256], keyword_help[256];
			int m = len(keyword);
			while (fgets(lt_encry, 256, fajl) != NULL) {

				int n = len(lt_encry);
				j = 0;
				for (i = 0; i < n; i++) {
					keyword_help[i] = keyword[j];
					j++;
					if (j > m) j = 0;
				}
				keyword_help[i] = '\0';


				int col_index = 0, row_index = 0;
				for (i = 0; i < n; i++) {
					while (toupper(keyword_help[i]) != table[row_index][0]) {
						row_index++;
						if (row_index > 39) break;
					}
					while (toupper(lt_encry[i]) != table[row_index][col_index]) {
						col_index++;
						if (col_index > 39) break;
					}
					if (row_index < 39 && col_index < 39) {
						lt_out[i] = table[0][col_index];
						row_index = 0; col_index = 0;
					}
					else {
						lt_out[i] = lt_encry[i];
						row_index = 0; col_index = 0;
					}
				}
				lt_out[i] = '\n';
				lt_out[i + 1] = '\0';

				fputs(lt_out, out);
			}
			fclose(fajl);
			fclose(out);
			printf("\n// File %s successfully decrypted to file %s //\n\n", file, output);
		}
	}
}