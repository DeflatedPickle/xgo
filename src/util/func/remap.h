#pragma once

int remap(value, oldLow, oldHigh, newLow, newHigh) {
    return newLow + (value - oldLow) * (newHigh - newLow) / (oldHigh - oldLow);
}