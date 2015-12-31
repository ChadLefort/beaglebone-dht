var expect = require('chai').expect,
    dht = require('../index');

describe('sensor', function() {
    it('should return a sensor number value', function() {
        expect(dht.sensor('DHT22')).to.equal(22);
    });

    it('should be undefined', function() {
        expect(dht.sensor('ABC')).to.be.undefined;
    });
});

describe('current errors', function() {
    it('should return true for having timeout or checksum errors', function() {
        expect(dht.checkErrors(-1)).to.equal(true);
        expect(dht.checkErrors(-2)).to.equal(true);
    });

    it('should not be able to access a GPIO pin', function() {
        expect(function() {
            dht.checkErrors(-4);
        }).to.throw(Error, /Error accessing GPIO. Make sure program is run as root with sudo!/);
    });

    it('should throw a general current error', function() {
        expect(function() {
            dht.checkErrors(-10);
        }).to.throw(Error, /Error calling DHT test driver read: -10/);
    });

    it('should not have any errors', function() {
        expect(dht.checkErrors(10)).to.equal(false);
    });
});

describe('read', function() {
    it('should expect a GPIO pin', function() {
        expect(function() {
            dht.read();
        }).to.throw(Error, /No GPIO pin provided!/);
    });

    it('should expect a correct GPIO pin', function() {
        expect(function() {
            dht.read('P9_1000');
        }).to.throw(Error, /Pin must be a valid GPIO identifier!/);
    });

    it('should expect a sensor model', function() {
        expect(function() {
            dht.read('P9_15');
        }).to.throw(Error, /Expected DHT11, DHT22, or AM2302 sensor value./);
    });
});
