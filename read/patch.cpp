
#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        sensors_event_t humidity, temp;

        auto sensor = getValue<input_DEV>(ctx);
        sensor->getEvent(&humidity, &temp);
        
        emitValue<output_RH>(ctx, humidity.relative_humidity);
        emitValue<output_Temp>(ctx, temp.temperature);
        emitValue<output_Done>(ctx, 1);
    }
}
