/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let str = s.split(" ")
    s = ""
    for (let i = str.length - 1; i >= 0; i--) 
        if (str[i] != "" && str[i] != " ") s += str[i] + " "
    return s.trim()
};