#include <stdio.h>
#include <string.h>
#include "Crypto.h"

int main(void) {

	printf("\n// ENCRYPT //\n");
	printf("\n// Use -h or --help for options. //\n\n");

	char input[128];
	User *po_auser = { 0 };

	while (1) {

		fgets(input, 128, stdin);

		if (input[0] == '-' && input[1] == '-' && input[2] == 'h' && input[6]=='\n' && strstr(input, "--help") != NULL)
			print_help();

		else if (input[0] == '-' && input[1] == 'h' && input[2] == '\n')
			print_help();

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'm' && input[10] == '\n' && strstr(input, "--make new") != NULL)
			create_doc();

		else if (input[0] == '-' && input[1] == 'm' && input[2] == '\n')
			create_doc();

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'i' && input[7] == '\n' && strstr(input, "--input") != NULL)
			input_text();

		else if (input[0] == '-' && input[1] == 'i' && input[2] == '\n')
			input_text();

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'r' && input[8] == '\n' && strstr(input, "--remove") != NULL)
			delete_doc();
		
		else if (input[0] == '-' && input[1] == 'r' && input[2] == '\n')
			delete_doc();

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'c' && input[13] == '\n' && strstr(input, "--change name") != NULL)
			rename_doc();

		else if (input[0] == '-' && input[1] == 'c' && input[2] == '\n') 
			rename_doc();

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'p' && input[7] == '\n' && strstr(input, "--print") != NULL) 
			print_file();

		else if (input[0] == '-' && input[1] == 'p' && input[2] == '\n')
			print_file();

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'e' && strstr(input, "--encrypt") != NULL) {
			if (input[10] == '-' && input[11] == '-' && input[12] == 'c' && input[18] == '\n' && strstr(input, "--caesar") != NULL)
				cae_encry();

			else if (input[10] == '-' && input[11] == '-' && input[12] == 'v' && input[20] == '\n' && strstr(input, "--vigenere") != NULL)
				vig_encry();

			else
				printf("\n// Invalid input //\n\n");
		}

		else if (input[0] == '-' && input[1] == 'e' && input[2] == ' ') {
			if (input[3] == '-' && input[4] == 'c' && input[5] == '\n')
				cae_encry();

			else if (input[3] == '-' && input[4] == 'v' && input[5] == '\n')
				vig_encry();

			else
				printf("\n// Invalid input //\n\n");

		}

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'd' && strstr(input, "--decrypt") != NULL) {
			if (input[10] == '-' && input[11] == '-' && input[12] == 'c' && input[18] == '\n' && strstr(input, "--caesar") != NULL)
				cae_decry();

			else if (input[10] == '-' && input[11] == '-' && input[12] == 'v' && input[20] == '\n' && strstr(input, "--vigenere") != NULL)
				vig_decry();

			else
				printf("\n// Invalid input //\n\n");
		}

		else if (input[0] == '-' && input[1] == 'd' && input[2] == ' ') {
			if (input[3] == '-' && input[4] == 'c' && input[5] == '\n')
				cae_decry();

			else if (input[3] == '-' && input[4] == 'v' && input[5] == '\n')
				vig_decry();

			else
				printf("\n// Invalid input //\n\n");
		}

		else if (input[0] == '-' && input[1] == 'k' && input[2] == '\n') {
			printf("\n// Program terminated //\n\n");
			break;
		}

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'k' && input[6] == '\n' && strstr(input, "--kill")) {
			printf("\n// Program terminated //\n\n");
			break;
		}

		else if (input[0] == '-' && input[1] == '-' && input[2] == 'u' && input[7] == '\n' && strstr(input, "--users") != NULL)
			input_users(po_auser);

		else if (input[0] == '-' && input[1] == 'u' && input[2] == '\n')
			input_users(po_auser);

		else
			printf("\n// Invalid input //\n\n");
	}

	return 0;
}