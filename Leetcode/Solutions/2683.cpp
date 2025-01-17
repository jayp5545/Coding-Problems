class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // so basically when you xor everything , it will cancel out everything so it has to be 0 x^y^z = x^y^y^z^z^x == 0
        int ans = 0;
        for(int i=0;i<derived.size();i++){
            ans^=derived[i];
        }
        return ans==0;
    }
};