int maxArea(int* height, int heightSize) {
    
    int res = 0;
    int l = 0, r = heightSize - 1;
     
    while (l < r) {
        int area = (r-l) * (height[l] < height[r] ? height[l++] : height[r--]);
        if (res < area) {
            res = area;
        }
    }
    
    return res;
    
}