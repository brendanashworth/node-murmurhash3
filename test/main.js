var assert = require('chai').assert;
var murmurhash = require('../');

describe('node-murmurhash3', function() {
    describe('#hash()', function() {
        it('should TypeError on bad arguments', function() {
            assert.throws(function() {
                murmurhash.hash();
            }, TypeError, /argument/);

            assert.throws(function() {
                murmurhash.hash(42);
            }, TypeError, /argument/);

            assert.throws(function() {
                murmurhash.hash({a: new Date()});
            }, TypeError, /argument/);
        });

        it('should work correctly on simple string', function() {
            assert.equal(murmurhash.hash('hello, world!'), 1080018637);
            assert.equal(murmurhash.hash('murmurhash3'), 66054004);
        });
    });
});
