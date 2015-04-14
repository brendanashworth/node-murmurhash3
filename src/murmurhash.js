var binding = require('../build/Release/murmurhash');

exports.hash = function(key) {
    if (typeof key !== 'string')
        throw new TypeError('key argument must be a string');

    return binding.hash(key);
};
