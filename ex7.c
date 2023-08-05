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
	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("The entire universe has %ld bugs.\n", universe_of_defects);
	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);
	double part_of_universe = expected_bugs / universe_of_defects;
	printf("This is only a %e portion of the universe.\n", part_of_universe);
	//this makes no sense just a demo of something weird
	//in C lang chars are just small ints (8 bits unsigned integers)
	char nul_byte = '\0';
	int care_percent = nul_byte * bugs;
	printf("Which means you should have %d%% care.\n", care_percent);
}
