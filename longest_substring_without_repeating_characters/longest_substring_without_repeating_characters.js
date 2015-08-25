function lengthOfLongestSubstring(s) {
    
    var max = 0;
    var map = Array(256);
    var horizen = 0;
    var strlen = s.length;
    
    var maxf = Math.max;

    for (var cursor = 0; cursor < strlen; cursor++) {

        var c = s[cursor];

        if (map[c] >= horizen) {
            max = maxf(max, cursor - horizen);
            horizen = map[c] + 1;
        }

        map[c] = cursor;

    }

    max = maxf(max, strlen - horizen);

    return max;
    
};