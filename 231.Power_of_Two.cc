// key : naive,bit manipulation

/*  explain:
    you can just use the naive solution(Solution1), if the test require other method,
    try use the AND operator method(Solution2).
*/

class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        // naive
        if(n<=0) return false;
        if(n==1) return true;

        long long num = 1;
        bool ans = false;
        while(num < n){
            num *= 2;
            
            if(num == n) ans = true;
        }

        return ans;

        // AND operator
        return (n > 0 && (n & (n-1) == 0)) ? true : false;
    }
};

class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        // AND operator
        return (n > 0 && (n & (n-1)) == 0) ? true : false;
    }
};