class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            negative = true;
        }
        string s = to_string(x);
        std::reverse(s.begin(), s.end()); // reverse string
        if (negative) {
            s = "-" + s; // if input is negative, need to add - infront
            s.pop_back(); // take out '-' at the end of new string. This is not needed but nice to remove '-'
        }
        try {
            int result = stoi(s); // convert string into int
            return result;
        } catch (...){ // exception thrown when overflow occurs with stoi()
            return 0;
        }
        
    }
};
