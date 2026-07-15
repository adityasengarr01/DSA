class Solution {
public:
int gcd(int a, int b)
{
    int ans = 1;

    for(int i = 1; i <= min(a, b); i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            ans = i;
        }
    }

    return ans;
}
    int gcdOfOddEvenSums(int n) {
        int a = 0;
        int b=0;
        for(int i = 1; i <= n; i++)
{
    a += 2 * i - 1;
    b += 2 * i;
}


               return gcd(a, b);
 
    }
};