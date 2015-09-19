char* longestCommonPrefix(char** strs, int strsSize) {
    
    char* res = (char*)malloc(sizeof(char)*1024);
    
    int cursor = 0;

    if (strsSize > 0) {
        for (; ; cursor++) {
            char var;
            int i = 0;
            for (; i < strsSize; i++) {
                if (!strs[i][cursor]) {
                    break;
                }
                if (i == 0) {
                    var = strs[i][cursor];
                } 
                else if(var != strs[i][cursor]) {
                    break;
                }
            }
            if (i != strsSize) {
                break;
            }
            res[cursor] = var;
        }
    }
    
    res[cursor] = 0;
    
    return res;
    
}