#include <stdio.h>

void swap(char*p,char*d){
    char temp=*p;
    *p=*d;
    *d=temp;
}

int main() {
    char str[]={"11010110110001011010101101110111011011011010101011011101010101101101"};//original string
    char ptr[]={"101101"};//string pattern that we need to find and extract from original string

    /*******************HALAL VERSION*********************/
    for (int a = 0; str[a]!='\0'; ++a) {//dummy ıteration
        for (int i = 0; str[i]!='\0'; ++i) {
            int ctrl=1;
            //check pattern
            for (int j = 0; j < 6 ; ++j) {
                if(str[i+j]!=ptr[j])
                    ctrl=0;
            }
            //slide & print process
            if(ctrl==1){
                //slide
                int l;
                for (l = i; str[l+6]!='\0' ; ++l) {
                        swap(&str[l],&str[l+6]);
                }
                str[l]='\0';
                //print
                for (int t = 0; str[t]!='\0' ; ++t) {
                    printf("%c",str[t]);
                }
                printf("\n");
            }
        }
    }
    for (int amk = 0; str[amk]!='\0' ; ++amk) {
        printf("%c",str[amk]);
    }
    printf("<---- Final String");
    return 0;
}