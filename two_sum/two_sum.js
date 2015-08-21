function twoSum(nums, target) {

    var map = {};
    
    for (var i = 0, l = nums.length; i < l; i++) {
        
        var t = nums[i];
        var o = target - t;
        
        if (o in map) {
             return [map[o]+1, i+1];
        } else {
             map[t] = i;
        }
        
    }
    
};