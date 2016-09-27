// binding.cc
#include <node.h>
#include <nan.h>

#include "binding.h"
#include "murmurhash.c/murmurhash.h"

namespace murmurhashlib {

using Nan::Utf8String;
    
using v8::Object;
using v8::Local;
using v8::String;
using v8::FunctionTemplate;
using v8::Number;

NAN_METHOD(Murmurhash) {
    // We check arguments in murmurhash.js; no need here
    Utf8String key(info[0]->ToString());
    uint32_t seed = info[1]->Int32Value();

    uint32_t hash = murmurhash(*key, key.length(), seed);

    info.GetReturnValue().Set(Nan::New<Number>(hash));
}

void Initialize(Local<Object> exports) {
    NAN_EXPORT(exports, Murmurhash);
}

NODE_MODULE(murmurhash, Initialize)

}
