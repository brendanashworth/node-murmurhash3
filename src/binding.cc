// binding.cc
#include <node.h>

#include "../deps/murmurhash.c/murmurhash.h"

namespace murmurhashlib {
    
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Value;
using v8::Object;
using v8::Local;
using v8::Exception;
using v8::String;

void Murmurhash(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // We check arguments in murmurhash.js; no need here
    String::Utf8Value key(args[0]->ToString());
    uint32_t seed = args[1]->Int32Value();

    uint32_t hash = murmurhash(*key, key.length(), seed);

    args.GetReturnValue().Set(hash);
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "hash", Murmurhash);
}

NODE_MODULE(murmurhash, Initialize)

}
