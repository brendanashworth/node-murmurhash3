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

void Murmurhash(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // We check arguments in murmurhash.js; no need here
    Local<v8::String> key = Local<v8::String>::Cast(args[0]->ToString());

    uint32_t hash = murmurhash(reinterpret_cast<const char*>(*key), key->Length(), 1);

    args.GetReturnValue().Set(hash);
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "hash", Murmurhash);
}

NODE_MODULE(murmurhash, Initialize)

}
