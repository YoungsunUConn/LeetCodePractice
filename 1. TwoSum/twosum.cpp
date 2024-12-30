#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>



using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> return_vec;
        std::unordered_map<int,int> Map1;
        //map<int,int> Map1;
        
        // if we can't find the answer here, there is duplicate (find in advance and keep it)
        int i = 0;
        for (auto it = begin (nums); it != end (nums); ++it, ++ i) {

            auto counter_it = Map1.find( target - (*it));
            if( counter_it  == Map1.end()) {

            } else {
                return_vec.push_back(i);
                return_vec.push_back(counter_it->second);
                return return_vec;
            }

            Map1[*it] = i;    
        }
        return return_vec;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> return_vec;
        vector<int> return_vec_dup;
        //std::unordered_map<int,int> Map1;
        map<int,int> Map1;
        
        // if we can't find the answer here, there is duplicate (find in advance and keep it)

        int i = 0;
        for (auto it = begin (nums); it != end (nums); ++it, ++i) {
            if((*it == target / 2) && (target % 2 == 0)) {
                return_vec_dup.push_back(i);
            }
            Map1[*it] = i;    
        }

        if( return_vec_dup.size() == 2) {
            return return_vec_dup;
        }
        
        
    
        for (auto it = Map1.begin(); it != Map1.end(); ++it)
        {
            auto counter_it = Map1.find( target - (it->first));
            if( counter_it  == Map1.end()) {

            } else if (counter_it != it) {
                return_vec.push_back(it->second);
                return_vec.push_back(counter_it->second);
                return return_vec;
            }
        }
        

        return return_vec_dup;
    }
};

int main() {
    vector<int> input_vector;
    input_vector.push_back(3);
    input_vector.push_back(2);
    input_vector.push_back(4);
    Solution mSol;
    vector<int> output = mSol.twoSum(input_vector, 6);
    for( auto it = begin(output) ; it != end(output); ++it) {
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
