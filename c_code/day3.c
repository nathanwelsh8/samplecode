#include <stdio.h>

#define RETURN_SUCC 0
#define RETURN_FAIL 1
#define LENGTH(x) (sizeof(x)/sizeof(x[0]))

void swap(int *a, int *b);
void increment(void);

struct S{
    int i;double d;char c;
    char word[15];
};

int main(){

    // unsigned char bad_buffer[sizeof(struct S)];
    // _Alignas(struct S) unsigned char good_buffer[sizeof(struct S)];
    // struct S *bad_s_ptr = (struct S *)bad_buffer;// incorrect pointer alignment
    // struct S *good_s_ptr = (struct S *)good_buffer; // correct poilter alignment

    int a = 5;
    int b = 10;
    printf("a:%3d|b:%3d\n",a,b);
    swap(&a,&b);
    printf("a:%3d|b:%3d\n",a,b);
    for(int i=0; i<5;i++){
        increment();
    }

    
    puts("");
    struct S struct1;
    struct1.i =5;
    struct1.d = 420.69;
    struct1.c = 0x41;
    struct1.word[0] = 0x48; //H
    struct1.word[1] = 0x45; //E
    struct1.word[2] = 0x4C; //L
    struct1.word[3] = 0x4C; //L
    struct1.word[4] = 0x4F; //O
    struct1.word[5] = '\0'; // end of array mark

    int count = 0;
    while(struct1.word[count] != '\0'){
         
            printf("%c",struct1.word[count]);
            count++;
    }
       
    
    printf("\n %3d %3lf %c\n",struct1.i, struct1.d,struct1.c);
    return RETURN_SUCC;
}

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
    return;
}

void increment(){
    static unsigned int counter=0;
    counter++;
    printf("%d", counter);
    return;

}