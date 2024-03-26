// Tell XOD where it can download the libraries:
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_AHTX0"

//Include C++ libraries
#include <Adafruit_AHTX0.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_AHTX0*;
    }
    // Keep Adafruit_SHT4x object in state
    Adafruit_AHTX0 sensor = Adafruit_AHTX0();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;
        emitValue<output_DEV>(ctx, &sensor);
    }
}
