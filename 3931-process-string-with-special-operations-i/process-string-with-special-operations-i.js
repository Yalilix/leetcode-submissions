/**
 * @param {string} s
 * @return {string}
 */
var processStr = function(s) {
    const result = []

    for (const c of s) {
        if (c == '*') { result.pop() }
        else if (c == '#') { result.push(...result) }
        else if (c == '%') { result.reverse() }
        else { 
            result.push(c)
        }
    }

    return result.join("")
};