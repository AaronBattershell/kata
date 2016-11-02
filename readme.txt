Bowling Kata

Here are different approaches for the bowling kata exersize.

Kata programs are named sequentially in the form of bowl1, bowl2, bowl3 ect.

Test input can be found in the Test directory.

Building:

	To build a program use the command        
		$ g++ bowl1.cpp -o bowl1.out
	To run a program                          
		$ ./bowl1.out
	To run a program with input: 
		$ ./bowl1.out < data/test1.in
	To compare a program with expected answers:
		$ diff <(./bowl1.out < data/test1.in) <(cat data/test1.ans)

		Notes: 
			There are several tests in the data directory.
			To test different test sets increment the values in data/test#.in and data/test#.ans
			If no output is produced by the diff command then the files are the same.
			If output does not match then the lines that differ will display for each file.
