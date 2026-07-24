#include <cmath>

class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0 || n==1) return n;
        int power = log10(n);

        long long sum=0;
        long long x=0;

        while(power>=0){
            int digit = n/pow(10,power);
            n = n % (int)(pow(10,power));
            power--;
            sum+= digit;
            if(digit!=0)x=(x*10)+digit;
        }
        return sum*x;
    }
};