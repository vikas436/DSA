class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>res;
        for(int i=1;i<=n;i++) {
            int div_3 = (i%3==0);
            int div_5 = (i%5==0);
             if(div_3 && div_5) {
                res.push_back("FizzBuzz");
            } else if(div_3) {
                res.push_back("Fizz");
            } else if(div_5) {
                res.push_back("Buzz");
            } else {
                 res.push_back(to_string(i));
             }
        }
        return res;
    }
};
