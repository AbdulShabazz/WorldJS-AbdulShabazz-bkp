﻿//
// Created by YuzukiTsuru on 2019/7/14.
//


#include "WorldJS.h"


EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::Dio(emscripten::val x_val, int fs, double frame_period) {
    return WorldNativeFun::Dio_JS(std::move(x_val), fs, frame_period);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::Harvest(emscripten::val x_val, int fs, double frame_period) {
    return WorldNativeFun::Harvest_JS(std::move(x_val), fs, frame_period);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::CheapTrick(emscripten::val x_val, emscripten::val f0_val, emscripten::val time_axis_val, int fs) {
    return WorldNativeFun::CheapTrick_JS(std::move(x_val), std::move(f0_val), std::move(time_axis_val), fs);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::D4C(emscripten::val x_val, emscripten::val f0_val, emscripten::val time_axis_val, int fft_size, int fs) {
    return WorldNativeFun::D4C_JS(std::move(x_val), std::move(f0_val), std::move(time_axis_val), fft_size, fs);
}

EMSCRIPTEN_KEEPALIVE emscripten::val WorldJS::Synthesis(emscripten::val f0_val, const emscripten::val &spectral_val, const emscripten::val &aperiodicity_val, int fft_size, int fs, const emscripten::val &frame_period) {
    return WorldNativeFun::Synthesis_JS(std::move(f0_val), spectral_val, aperiodicity_val, fft_size, fs, frame_period);
}

//-----------------------------------------------------------------------------
// The JavaScript API for C++
//-----------------------------------------------------------------------------
EMSCRIPTEN_BINDINGS(WorldJS) {
    emscripten::function("DisplayInformation", &WorldNativeIO::DisplayInformation);
    emscripten::function("WavRead_JS", &WorldNativeIO::WavRead_JS);
    emscripten::function("GetInformation", &WorldNativeIO::GetInformation);
    emscripten::function("WavWrite_JS", &WorldNativeIO::WavWrite_JS);
    emscripten::function("Dio_JS", &WorldNativeFun::Dio_JS);
    emscripten::function("Harvest_JS", &WorldNativeFun::Harvest_JS);
    emscripten::function("CheapTrick_JS", &WorldNativeFun::CheapTrick_JS);
    emscripten::function("D4C_JS", &WorldNativeFun::D4C_JS);
    emscripten::function("Synthesis_JS", &WorldNativeFun::Synthesis_JS);
    emscripten::function("DisplayInformationVal", &WorldJSWrapper::DisplayInformationVal);
    emscripten::function("GetInformationVal", &WorldJSWrapper::GetInformationVal);
    emscripten::function("Wav2World", &WorldJSWrapper::W2World);
}

