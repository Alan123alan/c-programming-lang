#include "grade_school.h"


int main(void){
    roster_t my_roster;
    my_roster.count = 0;
    add_student(&my_roster, "Aime", 2);
    add_student(&my_roster, "Alan", 3);
    add_student(&my_roster, "Alex", 2);
    printf("There are a total of %d students in the roster.\n", my_roster.count);
    for(int i = 0; i < (int)my_roster.count; i++){
        printf("Student %s from grade %d is at position %d.\n", my_roster.students[i].name, my_roster.students[i].grade, i);
    }
}

void init_roster(roster_t *roster){
    roster->count = 0;
}

void add_student(roster_t *roster, char name[], uint8_t grade){
    student_t student;
    student.grade = grade;
    uint8_t index = 0;
    size_t name_len = strlen(name);
    printf("length of name: %lu.\n", strlen(name));
    for(size_t i = 0; i < name_len; i++){
        printf("i: %d.\n", i);
        student.name[i] = name[i];
    }
    roster->students[roster->count] = student;
    roster->count += 1;
    
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade){
    roster_t filtered_by_grade_roster;

    return filtered_by_grade_roster;
}