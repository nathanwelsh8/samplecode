#include <stdio.h>
#include <stdlib.h>

// for char array
#define length(x)(sizeof(x)/sizeof(x[0]))
#define CHUNKSIZE 1
 
char *getword(void);
int isPallendrome(char string[]);
void printString(char *str);
int dynamic_string_size(char *string);


int main(){
    char *string = NULL;
    string = getword();

    printString(string);
    printf("\nIs pallendrome: %d",isPallendrome(string));

    return 0;
}
int dynamic_string_size(char *string){
    int i=0,count=0;

    while(string[i]!='\0'){
        count++;i++;
    }
    return count;
}

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

void printString(char *str){
    
    int i = 0;
    printf("\n");
    while(str[i] != '\0'){
        printf("%c",str[i]);
        i++;
    }
}

int isPallendrome(char *string){
    /**
     * return 1 is string is pallendrome
     * 0 otherwise
     * 
    */
   printf("\nSize%d", dynamic_string_size(string));
   int pointer_left = 0;

   // last char is \0 so ommit this
   int pointer_right = dynamic_string_size(string)-1;

   while(pointer_left<pointer_right){

       if(string[pointer_left] != string[pointer_right]){
           return 0;
       }

       pointer_left ++;
       pointer_right--;
   }
   return 1;
}