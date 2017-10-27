1. To compile type gcc main.c
2. To run the compiled file, type ./a.out on terminal. This should run the program.
3. The default input file in the main.c program is input.txt and for that we are creating an output file named output.txt.
4. If we want to take input from a different file, we just simply change the file name in the line:  inFile = fopen("input.txt", "r"); from input.txt to our input file's name.
5. Further we can create a new output file by changing the name in line: outFile = fopen("out.txt", "w"); from out.txt to our desired output file name.
6. The "make"file is named as makefile and is included in the directory.

7. When the size is increased by 1, the computation time increases exponentially.
	For n= 15, the program may take days whereas for n=20, it will take years to complete.

