#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int c;
    int mem_i = 0;
    char *s = (char *) calloc(16, sizeof(char));

    while((c = getchar()) != EOF){ 
        if( c < 0x20 || c >= 0x7E){
            s[mem_i % 16] = '.';
        }else{
            s[mem_i % 16] = c;
        }
        if(mem_i == 0x0){
            printf("%.8x ",0);
        }
        printf("%.2x ",c);
        mem_i++;
        if(mem_i % 16 == 0){
            printf("  |%s|", s);
            printf("\n");
            printf("%.8x ",mem_i);
            memset(s,0,16);
        }
        
    }
    int missing = 16 - (int)strlen(s);

    for(int i = 0; i < missing; i++) {
        printf("   "); 
    }

    printf("  |%s|\n", s);
    printf("%.8x \n",mem_i);
    free(s);
}
