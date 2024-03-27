#include <iostream>
using namespace std;
const int Max = 50;
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main (void){
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int *returnSize;
    returnSize = twoSum(nums, 4, target, returnSize);
    cout<<"[ "<<*returnSize<<" , "<<*(returnSize+1)<<" ]"<<endl;

    return 0;

}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0, j = 0, k = 0;
    returnSize =  (int*)malloc(sizeof(int)*numsSize);
    for(i; i < numsSize; i++){
        for(j = i + 1; j < numsSize; j++){
            if(nums[i]+nums[j] == target){
                returnSize[k] = i;
                returnSize[k+1] = j;
                k+=2;
            }
        }
    }
    return returnSize;
}