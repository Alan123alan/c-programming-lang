#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_isogram(const char phrase[]);


bool is_isogram(const char phrase[]){
    if(phrase == NULL)
        return false;
    int count = strlen(phrase);
    if(count == 0)
        return true;
    printf("Total characters: %d.\n", count);
    for(int j = 0; j < count; j++){
        char temp_j = tolower(phrase[j]);
        for(int k = j+1; k < count; k++){
            char temp_k = tolower(phrase[k]);
            if(temp_k == temp_j && temp_k != ' ' && temp_k != '-'){
		return false;
            }
        }
    }
    return true; 
}

int main(int argc, char *argv[]){
    char some_phrase[] = "isogram";
    printf("%s is an isogram? %d.\n", some_phrase, is_isogram(some_phrase));
    printf("%s is an isogram? %d.\n", some_phrase, is_isogram("isograms"));
    printf("%s is an isogram? %d.\n", some_phrase, is_isogram(NULL));
}
