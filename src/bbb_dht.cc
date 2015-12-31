#include <nan.h>
#include "bbb_dht_read.h"

namespace dht {
  
  using Nan::FunctionCallbackInfo;
  using Nan::New;
  using Nan::SetMethod;
  using v8::Object;
  using v8::Local;
  using v8::Value;
  
  void Method(const FunctionCallbackInfo<Value>& args) {
    int type = args[0]->Int32Value();
    int gpio_base = args[1]->Int32Value();
    int gpio_number = args[2]->Int32Value();
    float humidity = 0;
    float temperature = 0;
    int result = bbb_dht_read(type, gpio_base, gpio_number, &humidity, &temperature);
    
    Local<Object> obj = New<Object>();
    obj->Set(New("result").ToLocalChecked(), New(result));
    obj->Set(New("humidity").ToLocalChecked(), New(humidity));
    obj->Set(New("temperature").ToLocalChecked(), New(temperature));
  
    args.GetReturnValue().Set(obj);
  }

  void Init(Local<v8::Object> exports) {
    SetMethod(exports, "read", Method);
  }

  NODE_MODULE(beaglebone_dht, Init)
}