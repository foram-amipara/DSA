class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        double a=celsius + 273.15;
        ans.push_back(a);
        double b= celsius * 1.80 + 32.00;
        ans.push_back(b);
        return ans;
    }
};