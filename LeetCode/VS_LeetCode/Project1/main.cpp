// Fig. 2.5: fig02_05.c
2 // Addition program.
3 #include <stdio.h>
4
5 // function main begins program execution
6 int main(void)
7 {
	8
		9
		10
		11 printf("Enter first integer\n"); // prompt
	12
		13
		14 printf("Enter second integer\n"); // prompt
	15
		16
		17
		18 sum = integer1 + integer2; // assign total to sum
	19
		20
		21 } // end function main
Enter first integer
45
Enter second integer
72
Sum is 117
Fig. 2.5 | Addition program.
\n \n
int integer1; // first number to be entered by user
int integer2; // second number to be entered by user
scanf("%d", &integer1); // read an integer
scanf("%d", &integer2); // read an integer
int sum; // variable in which sum will be stored
printf("Sum is %d\n", sum); // print sum