#include <stdio.h>

/* day 1 learning c */

/* declare method scope */
void demo1(void);
void demo2(void);
void demo3(void);
void demo4(void);

#define     LOWER 0   // lower limit of temp scale
#define     UPPER 300 // upper limit of temp scale
#define     STEP  20  // step for temp scale   
#define     OUT 0
#define     IN 1
void main(int argc, char const *argv[])
{
    //demo1();
    //demo2();
    //demo3();
    demo4();
}

void demo1(){
    /* define cnstnts */
    float farh, celcius;
    int upper, lower, step;
      
    /* declare values*/
    lower = 0;
    upper = 300;
    step = 20;

    farh = lower;

    /* loop structure same as java/php */
    printf("Temperature");
    while (farh<=upper){
        celcius = 5*(farh-32)/9;
        printf("%3.0fF %6.1fC\n",farh,celcius);
        farh = farh+step;// increment
    }
}

void demo2(){
    float  celcius;

    /* just your average for structure */
    for(int farh = LOWER; farh<=UPPER; farh+=STEP)
        printf("%3d %6.1f\n", farh,(5.0/9.0)*(farh-32));
}

void demo3(){

    int c;

    while((c=getchar()) != EOF){
        putchar(c);
    }
}

void demo4(){
    int c, nl, nw, nc, state;
    nl=  nw = nc=0;
    state = OUT;
    while((c=getchar()) != EOF){
        nc++;
        if(c=='\n')
            ++nl;
        if (c==' ' || c == '\n' || c=='\t'){
            state = OUT;
        }
        else if(state == OUT){
            state = IN;
            nw++;
        }
    }
    printf("%d %d %d\n",nc,nl,nw);
}