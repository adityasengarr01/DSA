class Solution {
public:
int n;  // global -> empty
vector<int> coins;  // global -> empty
vector<vector<int>> dp;

int solve(int idx , int amt) // (0 , 5)
{
    if(amt == 0)return 1;
    if(idx >= n)return 0;
    
    
    if(amt < 0) return 0;
    
    if(dp[idx][amt] != -1)
    {
        return dp[idx][amt];
    }
    // take 
    
    int take = solve(idx , amt - coins[idx]);
    
    // skip
    
    int skip = solve(idx + 1 , amt); 
    
    return dp[idx][amt] = take + skip;    
}
    int change(int amount, vector<int>& coins) {
        
        this->coins = coins;
        this->n = coins.size();
        
        
        dp.assign(n , vector<int>(amount + 1 , -1));
        
        // dp[idx][amt] yeh ho saktha hai ki agr mai kis path mai jarha hu aur us path ka ans mujhe already pata hai toh mai time waste kyu krunga again visit krne mai toh direct and return krunga 
        
        
        return solve(0 , amount);
    }
};
/*

TAKE + SKIP => 
MULTIPLE TIMES: NO RESTRICTION ON TAKING



COINS [ 1 , 2 , 5 ] COINS UNLIMITED COINS , AMOUNT = 5

a) [1 , 1 ,1 , 1 , 1] => 5 => 1  take 
b) [1 , 2 , 2] => 5
c) [5] => 5
d) [1 , 1 , 1 , 2] => 5  => 1 skip

4 valid options ans ane kai => hume is question mai yeh batana ki ktine tareko sai tu amount bana parah=>  

------------------------------------------------------------------------------

RECURSION -> SAARI POSSIBLITIES TRY KRNA TBH TUM RECURSION USE KRTHE HO => 

take  amt = 0 mere pass ek valid ans  1 1 1 1 1 => if(amt == 0) reutrn 1;
skip => idx + 1;
if(amt == 0){
return 1;
}

if(amt < 0)return 0;


                                                          0   1   2
                                                         [1 , 2 , 5] AMOUNT = 5 , idx = -1 
                                                       / 
                                        amt = 4 , i = 0 
                                               /  
                                        amt = 3 , i = 0  
                                            /
                                        amt = 2 , i = 0---------
                                            /                   \
                                        amt = 1 , i = 0-----     \
                                           /                \     amt = 2 , i = 1 , amt = 0
                                        amt = 0 , i = 0      \ 
                                            /                 \
                                        call krunga function    \ 
                                        base case check           \
                                        if(amt == 0)return 1;     amt = 1, idx = 1 , amt = -1
                                        
idx = 0 (skip) -> idx = 1 (skip) -> idx = 2 (skip) -> (idx = 3) ❌  

if(idx == n)return 0;                                     

take = 1 ;
skip = 1;

take + skip (two valid ways) 

take -> sai ek ans aya 
skip sai bhi ans aya 



*/