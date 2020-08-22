#include <stdio.h>

/* learning day 2 learning c */

#define OUT 0
#define IN 1
#define MAXLINE 1000
#define LENGTH(x) (sizeof(x)/sizeof(x[0])) // we have to make our own array size function

/* func decs */
void task1(void);
void task2(void);
void task3(void);

int getnextline(char line[], int maxline);
void copy(char to[], char from[]);



int main(int argc, char const *argv[])
{
    //task1();
    //task2();
    task3();
    return 0; 
}

int getnextline(char line[], int maxline){
    int c,i;

    for(i=0; i<maxline-1 && (c=getchar())!=EOF && c!='\n'; i++){
        printf("%d",i);
        line[i] = c;
    }
    if(c=='\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';// mark end of array
    return i;
}


void task1(){
/* code */
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother= 0;

    for(i=0;i<10;i++){
        ndigit[i] = 0;
    }
    while((c=getchar()) != EOF){
        if(c>='0' && c<='9')
            /* this is smart. increment by char value c- char value of '0' to get numerical val*/
            ++ndigit[c-'0'];
        else if(c== ' ' || c=='\n' || c=='\t')
            nwhite++;
        else
        {
            nother++;
        }
    }
    printf("digits=");
    for(i=0;i<10;i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other=%d\n", nwhite, nother);
}

void task2(){
    
    /* declarations */
    int counter, wordcount = 0;
    int counterArr[15]; //25 words max
    for(int i=0;i<LENGTH(counterArr);i++){
        counterArr[i] = 0;
    }

    char c;
    int state = OUT;

    while((c=getchar())!=EOF){

        // check if new word
        
        if(c== ' ' || c=='\n' || c=='\t'){
            state = OUT;
            
            // space does not count as word char
            wordcount--;
        }
        else if(state==OUT){
            state=IN;
            
            // first word submitted is length 0, discard this
            if (wordcount!=0){
                counterArr[counter] = wordcount;
                counter ++;
                wordcount = 0;
            }
        }
        wordcount++;
    }
    // get length of last typed word
    counterArr[counter] = wordcount;

    printf("          Histogram (word length)\n");
    for(int i=0;i<LENGTH(counterArr);i++){
        
        /* may have emptry indexes in arr -> dont print these */
        if(counterArr[i]!=0){
            printf("word %3d|",i+1);
            for (int j=0;j<counterArr[i];j++){
                printf("-");
            }
            printf("\n");
        }
    }
}


void task3(){
    
    int len,max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max=0;

    while((len=getnextline(line,MAXLINE)) > 0){
        if(len>max){
            max=len;
            copy(longest,line);
        }
    }
    if(max>0)
        printf("longest was %d",longest);
}