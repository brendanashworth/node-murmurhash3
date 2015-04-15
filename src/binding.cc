// binding.cc
#include <node.h>
#include <nan.h>

#include "binding.h"
#include "../deps/murmurhash.c/murmurhash.h"

namespace murmurhashlib {
    
using v8::Object;
using v8::Local;
using v8::String;
using v8::FunctionTemplate;
using v8::Number;

NAN_METHOD(Murmurhash) {
    NanScope();

    // We check arguments in murmurhash.js; no need here
    NanUtf8String key(args[0]->ToString());
    uint32_t seed = args[1]->Int32Value();

    uint32_t hash = murmurhash(*key, key.length(), seed);

    NanReturnValue(NanNew<Number>(hash));
}

void Initialize(Local<Object> exports) {
    exports->Set(NanNew<String>("hash"),
        NanNew<FunctionTemplate>(Murmurhash)->GetFunction());
}

NODE_MODULE(murmurhash, Initialize)

}
