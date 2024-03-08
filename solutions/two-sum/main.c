struct DupEntry {
    int val;
    int idx;
};

int hash(int val, int hashTblSz) {
    if (val < 0) {
        val = -val;
    }
    return val % hashTblSz;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = malloc(2 * sizeof(nums[0]));
    
    const int hashTblMult = 7;
    int hashTblSz = hashTblMult * numsSize;
    if (hashTblSz % 2 == 0) hashTblSz += 1; //Don't want it to be even
    int* hashTbl = malloc(hashTblSz * sizeof(int)); //Hash table
    memset(hashTbl, 0, hashTblSz * sizeof(int));
    struct DupEntry* dups = malloc(numsSize * sizeof(struct DupEntry) - 1); //Collision table
    int dups_len = 0;
    
    for (int i = 0; i < numsSize; i++) {        
        //Try hashtable lookup, then do a collisions lookup
        
        if (hashTbl[hash(target - nums[i], hashTblSz)]) {
            //Check that it is really true (I can't believe it because of collisions)
            if (nums[hashTbl[hash(target - nums[i], hashTblSz)] - 1] + nums[i] == target) {
                //easy
                result[0] = i;
                result[1] = hashTbl[hash(target - nums[i],hashTblSz)] - 1;
                //free(hashTbl);
                //free(dups);
                return result;
            }
            //Maybe its inside one of the collisions?
            for (int j = 0; j < dups_len; j++) {
                if (dups[j].val + nums[i] == target) {
                    //nice
                    result[0] = i;
                    result[1] = dups[j].idx;
                    //free(hashTbl);
                    //free(dups);
                    return result;
                }
            }
        }
        //Its not in the hashtable :((
        
        if (hashTbl[hash(nums[i], hashTblSz)]) {
            //Collision
            dups[dups_len].val = nums[i]; dups[dups_len].idx = i;
            dups_len += 1;
        } else 
            hashTbl[hash(nums[i], hashTblSz)] = i + 1;
        
    }
    
    //free(hashTbl);
    //free(dups);
    //free(result);
    *returnSize = 0;
    return 0;
}
