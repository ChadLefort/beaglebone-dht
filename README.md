# beaglebone-dht

[![Build Status](https://travis-ci.org/ChadLefort/beaglebone-dht.svg?branch=master)](https://travis-ci.org/ChadLefort/beaglebone-dht)

Reads DHT series of temperature sensors on a Beaglebone Black.

### Setup

```
npm install beaglebone-dht --save
```

### Example

```
var dht = require('beaglebone-dht'),
    sensor = dht.sensor('DHT22'),
    read = dht.read('P9_15');

console.log(read);

/**
{
    celsius: 21.899999618530273,
    fahrenheit: 71.4199993133545,
    humidity: 53
}
**/
```

### Run Tests

```
npm test
```

### Supported Sensors

* DHT11
* DHT22
* AM2302

### GPIO Pins

The read function will take a couple of different GPIO variations as an accepted parameter.

It will take in the following:
* Head Pin
* Any name that doesn't start already with GPIO
* GPIO Number

Please refer to the wonderful PDF documents provided by [Derek Molloy](https://github.com/derekmolloy) for reference:

* [P8 Header Table](https://github.com/derekmolloy/boneDeviceTree/blob/master/docs/BeagleboneBlackP8HeaderTable.pdf)
* [P9 Header Table](https://github.com/derekmolloy/boneDeviceTree/blob/master/docs/BeagleboneBlackP9HeaderTable.pdf)

### Credits

* Based on the C code written by [Tony DiCola](https://github.com/tdicola) from his [Adafruit Python DHT Sensor Library](https://github.com/adafruit/Adafruit_Python_DHT).
