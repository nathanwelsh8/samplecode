#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* define cnstnts */
    int farh, celcius;
    int upper, lower, step;

    /* declare values*/
    lower = 0;
    upper = 300;
    step = 20;

    farh = lower;
    while (farh<=upper){
        celcius = 5*(farh-32)/9;
        printf("%d F\t%dC\n",farh,celcius);
        farh = farh+step;// increment
    }
}
