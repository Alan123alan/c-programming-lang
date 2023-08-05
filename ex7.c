#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 45009.45;
	char initial = 'E';
	char first_name[] = "The";
	char last_name[] = "Program";
	
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awsome super powers.\n", super_power);
	printf("I have an initial  %c.\n", initial); 
	printf("I have a first name %s.\n", first_name); 
	printf("I have a last name %s.\n", last_name); 
	printf("Full name: %s %c. %s.\n",first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2f;
	unsigned int long_size_in_bytes = sizeof(long);
	unsigned int long_size_in_bits = long_size_in_bytes * 8;
	printf("The long data type has a size of %d in bytes and a size of %d in bits.\n", long_size_in_bytes, long_size_in_bits);
	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
	//trying to overflow the long integer data type
	//adding more positive values to long integer data type by using the unsigned modifier
	//for this computer long has 64 bit giving it a unsigned long range of values from 0 to 1.844674407370955e19
	unsigned long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1000000000L;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);
	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);
	double part_of_universe = expected_bugs / universe_of_defects;
	printf("This is only a %e portion of the universe.\n", part_of_universe);
	//this makes no sense just a demo of something weird
	//in C lang chars are just small ints (8 bits unsigned integers)
	//since char is stored as ints representing chars as ASCII values you can add the unsigned modifier
	char nul_byte = '\0';
	int care_percent = nul_byte * bugs;
	printf("Which means you should have %d%% care.\n", care_percent);
}
