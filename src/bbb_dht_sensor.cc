#include <node.h>
#include "bbb_dht_read.h"

namespace dht {
  
  using v8::Handle;
  using v8::Arguments;
  using v8::HandleScope;
  using v8::Object;
  using v8::Isolate;
  using v8::Local;
  using v8::String;
  using v8::Value;
  using v8::Number;

  Handle<Value> Method(const Arguments& args) {
    HandleScope handle_scope;
    int type = args[0]->IntegerValue();
    int gpio_base = args[1]->IntegerValue();
    int gpio_number = args[2]->IntegerValue();
    float humidity = 0;
    float temperature = 0;
    int result = bbb_dht_read(type, gpio_base, gpio_number, &humidity, &temperature);
    
    Local<Object> obj = Object::New();
    obj->Set(String::New("result"), Number::New(result));
    obj->Set(String::New("humidity"), Number::New(humidity));
    obj->Set(String::New("temperature"), Number::New(temperature));
    
    return handle_scope.Close(obj);
  }

  void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "read", Method);
  }

  NODE_MODULE(dht_sensor_bbb, init)
}