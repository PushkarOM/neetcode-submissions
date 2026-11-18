class Solution {
public:

    int process(int n){
        int temp = 0;
        while(n){
            int digit  = n % 10;
            temp += digit * digit;
            n /= 10;
        }

        return temp;
    }

    bool isHappy(int n) {
        unordered_map<int,int> seen;

        while(seen.find(n) == seen.end()){
            
            seen[n] = 1;

            n = process(n);
            
            if(n == 1) return true;
        }    

        return false;
    }
};
