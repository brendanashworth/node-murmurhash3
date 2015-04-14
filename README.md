# node-murmurhash

> Binding to [jwerle's murmurhash3](https://github.com/jwerle/murmurhash.c).

## Install
```sh
$ npm i node-murmurhash3 --save
```

## Usage
```javascript
var murmurhash = require('node-murmurhash3');

murmurhash.hash('Hello, world!');
```

## `murmurhash.hash(key[, seed])`

- key (`String`) The key to input to the [Murmurhash v3](https://en.wikipedia.org/wiki/MurmurHash) algorithm.
- seed (`Number`) The optional seed to provide to the algorithm. Defaults to `0`.

Hashes the given key with the given seed (seed is optional).

## License
[MIT](./LICENSE)