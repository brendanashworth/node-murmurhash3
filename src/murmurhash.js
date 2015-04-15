var binding = require('../build/Release/murmurhash');

exports.hash = function(key, seed) {
    if (typeof key !== 'string')
        throw new TypeError('key argument must be a string');

    if (seed !== undefined && typeof seed !== 'number')
        throw new TypeError('seed argument must be a number');
    else if (seed === undefined)
        seed = 1;

    return binding.hash(key, seed);
};
