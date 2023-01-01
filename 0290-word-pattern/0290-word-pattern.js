/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    let array= s.split(' ')
    
    if (array.length !== pattern.length || new Set(array).size !== new Set(pattern).size) {
        return false;
    }
    
    let mp=new Map();
    for(let i=0;i<pattern.length;i++){
        if(mp.has(pattern[i])  && mp.get(pattern[i])!=array[i]){
            return false;
        }else {
            mp.set(pattern[i],array[i]);
        }
    }
    return true;
};