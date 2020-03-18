#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<int, int> record;
            for(int j = 0; j < points.size(); j++) {
                if(j != i) {
                    record[dis(points[j], points[i])];
                }
            }
            for(unordered_map<int, int>::iterator iter;
                iter != record.end(); iter++) {
                if(iter->second >= 2) {
                    res += (iter->second) * (iter->second - 1);
                }
            }
        }
        return res;
    }

private:
    int dis(const pair<int, int> &pa, const pair<int, int> &pb) {
        return (pa.first - pb.first) * (pa.first - pb.first) +
               (pa.second - pb.second) * (pa.second - pb.second);
    }
};