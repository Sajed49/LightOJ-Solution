#include <stdio.h>

int main (void) {
    int test, a=1;
    scanf("%d", &test);

    for( ; a<=test; a++) {
        long long int sum=0;
        int total,i=0;
        scanf("%d", &total);

        for( ;i<total ;i++) {
            int temp;
            scanf("%d", &temp);
            if(temp>0) sum+=temp;
        }

        printf("Case %d: %lld\n", a, sum);
    }
    return 0;
}
