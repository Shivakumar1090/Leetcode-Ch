/**
 * @param {number} n
 * @return {number}
 */
var countVowelStrings = function(n) {
    var a = 1 , e = 1 , i = 1 , o = 1 , u = 1;
    
    for(var j = 2; j <= n; j++){
        o += u;
        i += o;
        e += i;
        a += e;
    }
    
    return a+e+i+o+u;
};