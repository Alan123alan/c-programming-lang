#include "grade_school.h"


// int main(void){
//     roster_t my_roster;
//     my_roster.count = 0;
//     add_student(&my_roster, "Aime", 7);
//     add_student(&my_roster, "Alan", 3);
//     add_student(&my_roster, "Alex", 1);
//     printf("There are a total of %zu students in the roster.\n", my_roster.count);
//     for(int i = 0; i < (int)my_roster.count; i++){
//         printf("Student %s from grade %d is at position %d.\n", my_roster.students[i].name, my_roster.students[i].grade, i);
//     }
//     sort_by_grade(&my_roster);
//     printf("After getting sorted by grade.\n");
//     for(int i = 0; i < (int)my_roster.count; i++){
//         printf("Student %s from grade %d is at position %d.\n", my_roster.students[i].name, my_roster.students[i].grade, i);
//     }
//     roster_t second_grade = get_grade(&my_roster, 2);
//     printf("There are a total of %zu students in second grade.\n", second_grade.count);
//     for(size_t j = 0; j < second_grade.count; j++){
//         printf("Student %s from grade %d is at position %zu.\n", second_grade.students[j].name, second_grade.students[j].grade, j);
//     }
// }

void init_roster(roster_t *roster){
    roster->count = 0;
    // student_t empty_student = {0, {}};
    // for(int i = 0; i < MAX_STUDENTS; i++){
    // }
}

//function works in place
void sort_by_grade(roster_t *roster){
    // roster_t sorted_roster;
    //implementing bubble_sort
    size_t count = roster->count;
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < (count-1)-i; j++)
        {
            if(roster->students[j].grade > roster->students[j+1].grade){
                student_t temp = roster->students[j+1];
                roster->students[j+1] = roster->students[j];
                roster->students[j] = temp;
            }
        }
    }
}

bool add_student(roster_t *roster, char name[], uint8_t grade){
    student_t student;
    student.grade = grade;
    size_t name_len = strlen(name);
    //check if a student with the same name is already in the roster
    for(size_t i = 0; i < roster->count; i++){
       if(strncmp(roster->students[i].name, name, strlen(roster->students[i].name)) == 0){
            return false;
       }
    }
    for(size_t i = 0; i < name_len; i++){
        student.name[i] = name[i];
    }
    student.name[name_len] = '\0';
    roster->students[roster->count] = student;
    roster->count += 1;
    sort_by_grade(roster);
    return true;
}

roster_t get_grade(roster_t *roster, uint8_t desired_grade){
    roster_t filtered_by_grade_roster;
    filtered_by_grade_roster.count = 0;
    for(size_t i = 0; i < roster->count; i++){
        if(roster->students[i].grade == desired_grade){
            filtered_by_grade_roster.students[filtered_by_grade_roster.count] = roster->students[i];
            filtered_by_grade_roster.count++;
        }
    }
    return filtered_by_grade_roster;
}
