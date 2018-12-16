class Solution {
public:
        void combinationHelper(vector<int> candidates, vector<vector<int>>& result, vector<int> potentialSolution, int target) {
        if (target == 0) { // found a solution
            result.push_back(potentialSolution);
            return;
        } else if (candidates.empty()) { // did not find a solution
            return;
        }
        int firstElem = candidates[0];
        int numRecursions = target / firstElem;
        if (numRecursions == 0) { // if firstElem is bigger than the target, the rest of the numbers are also bigger than the target, so return here
            return;
        }
        vector<int> nextVector = candidates;
        nextVector.erase(nextVector.begin()); // vector without the first element
        vector<int> newPotentialSolution = potentialSolution; //firstElem will be added
        for (int i = 0; i <= numRecursions; ++i) {// from having 0 number of firstElem up to numRecursions
            if (i != 0) {
                newPotentialSolution.push_back(firstElem);
            }
            combinationHelper(nextVector, result, newPotentialSolution, target - firstElem * i);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort first to reduce time
        vector<vector<int>> result;
        combinationHelper(candidates, result, {}, target);
        return result;
    }
};
