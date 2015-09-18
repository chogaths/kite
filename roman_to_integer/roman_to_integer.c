int romanToInt(char* s) {
    
    int res = 0;
    int pre = 0;
    
    while(*s) {
        
        int cur = 0;
        
        switch(*s) {
            case 'I': cur = 1; break;
            case 'V': cur = 5; break;
            case 'X': cur = 10; break;
            case 'L': cur = 50; break;
            case 'C': cur = 100; break;
            case 'D': cur = 500; break;
            case 'M': cur = 1000; break;
        }
        
        res += cur > pre ? (cur-2*pre) : cur;
        pre = cur;
        
        s++;
        
    }
    
    return res;
    
}