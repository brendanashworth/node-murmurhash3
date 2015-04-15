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
                murmurhash.hash({a: new Date()}, 10);
            }, TypeError, /argument/);

            assert.throws(function() {
                murmurhash.hash('test', 'nope');
            }, TypeError, /argument/);

            assert.throws(function() {
                murmurhash.hash('test', Object.create(null));
            }, TypeError, /argument/);

            assert.throws(function() {
                murmurhash.hash('test', new Number(3));
            }, TypeError, /argument/);
        });

        it('should work correctly on simple string', function() {
            assert.equal(murmurhash.hash('hello, world!'), 1080018637);
            assert.equal(murmurhash.hash('murmurhash3'), 66054004);
        });

        it('should work with seeds', function() {
            assert.equal(murmurhash.hash('hello, world!', 1), 1080018637);
            assert.equal(murmurhash.hash('hello, world!', 283), 3198928967)
            assert.equal(murmurhash.hash('abcdefghijkl', 23), 2275871593);
            assert.equal(murmurhash.hash('brendan ashworth', 100), 2444978076);
            assert.equal(murmurhash.hash('brendan ashworth', -1), 861264453);
            assert.equal(murmurhash.hash('brendan ashworth', 0), 3210849834);
        });
    });
});
