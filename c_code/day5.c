#include <stdio.h>
#include <stdlib.h>

#define CHUNKSIZE 1
 
char *getword(void);
int isPallendrome(char string[]);
int dynamic_string_size(char *string);


int main(){
    char *string = NULL;
    string = getword();

    printf("\nIs pallendrome: %d",isPallendrome(string));

    return 0;
}

/* calculate size of dynamic string O(n)*/
int dynamic_string_size(char *string){
    int i=0,count=0;

    while(string[i]!='\0'){
        count++;i++;
    }
    return count;
}

/** get string input from user*/
char *getword(void){
    char *line = NULL;
    char *tmp = NULL;
    size_t size = 0, index = 0;

    int ch = EOF;

    while(ch){
        ch = getc(stdin);

        // end of input add end char \0
        if(ch == EOF || ch == '\n'){
            ch = '\0';
        }
        //expand char array if at the end of array 
        if(size<=index){
            size+=CHUNKSIZE;
            tmp = realloc(line,size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }
        line[index++] = ch;

    }
    return line;
}


/* determine whether string is a pallendrome O(n/2) */
int isPallendrome(char *string){
    /**
     * return 1 is string is pallendrome
     * 0 otherwise
     * 
    */
   int pointer_left = 0;

   // last char is \0 so ommit this
   int pointer_right = dynamic_string_size(string)-1;

    /*
        if the string is even len then left and
        right pointers will swap in the middle
        and execution stops to return true (1). 
        If the string is odd len then both pointers
        reach the middle index and true (1) is returned
    */
   while(pointer_left<pointer_right){

       if(string[pointer_left] != string[pointer_right]){
           return 0;
       }

       pointer_left ++;
       pointer_right--;
   }
   return 1;
}