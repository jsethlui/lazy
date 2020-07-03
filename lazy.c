
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
	char* file;
	int opt;
	int py_flag, c_flag;
	py_flag = 0;
	c_flag = 0;

	static struct option long_options[] = {
		{"py", no_argument, NULL, 'p'},
		{"c", no_argument, NULL, 'c'},
		{NULL, 0, NULL, 0}
	};

	while ((opt = getopt_long(argc, argv, "p:c:", long_options, NULL)) != -1) {
		switch (opt) {
			case 'p':
				py_flag = 1;
				file = optarg;
				break;
			case 'c':
				c_flag = 1;
				file = optarg;
				break;
			default:
				printf("default");
				break;
		}
	}

	// if py flag is set
	if (py_flag == 1) {
		const char* py_header = 
			"def main()\n"
			"\tprint("Hello World")\n"
			"if __name__ == "__main__":\n"
			"\tmain()\n"
		write_to_file(file, py_header);
	}

	// if c flag is set
	if (c_flag == 1) {

	}
}