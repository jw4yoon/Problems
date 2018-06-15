class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        int squareRoot = sqrt(area);
        int width = 0;
        for (int i = squareRoot; i >= 0 ; --i) {
            if (area % i == 0) {
                width = i;
                break; // break since we got the biggest width that divides area
            }
        }
        int length = area / width;
        result.push_back(length);
        result.push_back(width);
        return result;
    }
};
