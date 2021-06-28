class Solution {
public:
    static int compareXY(int x, int y) {
        std::string xy = std::to_string(x).append(std::to_string(y));
        std::string yx = std::to_string(y).append(std::to_string(x));
        
        return xy.compare(yx) > 0 ? 1: 0;
    }

    string largestNumber(vector<int>& nums) {
        std::ostringstream oss;
        std::sort(nums.begin(), nums.end(), compareXY);

        if (nums[0] == 0) {
            return "0";
        }

        std::copy(nums.begin(), nums.end()-1, std::ostream_iterator<int>(oss, ""));
        oss << nums.back();
        
        return oss.str();
    }
};
