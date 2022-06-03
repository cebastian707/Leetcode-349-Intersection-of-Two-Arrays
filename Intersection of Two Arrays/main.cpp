/*By ::Cebastian Santiago
* Leetcode 349
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


bool  intersect(int value, std::vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == value) {
			return true;
		}
	}
	return false;
}



std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
	//first thing sort the vectors
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	//create a map and temp vector
	std::map<int, int> Hash1;
	std::map<int, int> Hash2;
	std::vector<int> temp1 , temp2 ,a;


	//insert the elements into hash1 one time
	for (auto i : nums1){
		if (Hash1.find(i) ==Hash1.end()){
			Hash1.insert({ i,1 });
		}
	}

	//insert the elements into hash2 one time
	for (auto i : nums2){
		if (Hash2.find(i) == Hash2.end()) {
			Hash2.insert({ i,1 });
		}
	}

	//insert the elements into temp1 form hash1
	for (auto i : Hash1){
		temp1.push_back(i.first);
	}

	//insert the elements into temp2 form hash2
	for (auto i : Hash2){
		temp2.push_back(i.first);
	}


	//know just compare main part of the problem
	for (int i = 0; i < temp1.size(); i++) {
		if (intersect(temp1[i],temp2)){
			a.push_back(temp1[i]);
		}
	}
	return a;
}

int main(int argc, char* argv[]) {
	std::vector<int> num1 = { 1,2,2,1 };
	std::vector<int> num2 = { 2,2 };
	std::vector<int> num3;

	num3 = intersection(num1, num2);

	for (int i = 0; i < num3.size(); i++){
		std::cout << num3[i] << std::endl;
	}

	return 0;
}