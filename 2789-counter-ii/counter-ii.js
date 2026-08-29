/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let ret = init;

    return {
        increment: function() {
            return ++ret;
        }, 
        decrement: function() {
            return --ret;
        }, 
        reset: function() {
            ret = init;
            return ret;
        }, 
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */