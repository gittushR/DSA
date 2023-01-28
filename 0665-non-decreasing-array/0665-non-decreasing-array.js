/**
 * @param {number[]} nums
 * @return {boolean}
 */
    const checkPossibility = (n) => {
    let count = 0;

    for (let i = 1; i < n.length; i++) {
        if (n[i] < n[i - 1]) {
            if (i - 2 >= 0 && n[i] < n[i - 2]) {
                n[i] = n[i - 1];
            }
            count++;
        }
        if (count > 1) return false;
    }

    return true;
};