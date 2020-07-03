
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void write_to_file(char* a_file, char* header_string) {
	FILE* f;
	f = fopen(a_file, "w");
	fprintf(f, header_string);
	fclose(f);
}

int main(int argc, const char* argv[]) {
	const char* quote = "\"";

	char* file;
	int opt;
	int py_flag, c_flag, cpp_flag;
	py_flag = 0;
	c_flag = 0;

	static struct option long_options[] = {
		{"py", no_argument, NULL, 'p'},
		{"c", no_argument, NULL, 'C'},
		{"cpp", no_argument, NULL, 'c'},
		{NULL, 0, NULL, 0}
	};

	while ((opt = getopt_long(argc, argv, "p:C:c:", long_options, NULL)) != -1) {
		switch (opt) {
			case 'p':
				py_flag = 1;
				file = optarg;
				break;
			case 'C':
				c_flag = 1;
				file = optarg;
				break;
			case 'c':
				cpp_flag = 1;
				file = optarg;
			default:
				printf("\tdefault");
				break;
		}
	}

	// if py flag is set
	if (py_flag == 1) {
		const char* py_main = "def main()\n" 
								"    print(\"Hello World\")\n\n" 
								"if __name__ == \"__main__\":\n" 
								"    main()\n";
		write_to_file(file, py_main);
	}

	// if c flag is set
	if (c_flag == 1) {
		const char* c_main = "#include <stdio.h>\n\n" 
							"int main(int argc, const char * argv[])\n" 
							"    printf(\"Hello World\")" 
							"    return 0\n" 
							"}\n";
		printf("%s", c_main);
	}

	if (cpp_flag == 1) {
		const char* cpp_main = "#include <iostream>\n\n" 
							"int main(int argc, const char * argv[]) {\n" 
							"    std::cout << \"Hello World\")" 
							"    return 0\n" 
							"}\n";
		printf("%s", cpp_main);
	}
}