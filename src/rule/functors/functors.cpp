#include "functors.hpp"

// Functor operators
namespace Functors {
    void Base::operator()(Functors::Params params) {
        *(params.color) = BLACK;
    }

    Fill::Fill(Color fillColor, s16 start, s16 end) : fillColor(fillColor), start(start), end(end) {}
    void Fill::operator()(Functors::Params params) {
        s16 pixel = *(params.pixel);
        if (pixel >= start && pixel < end) {
            *(params.color) = fillColor;
        } else {
            *(params.color) = BLACK;
        }
    }

    Stripes::Stripes(Color* colors, u16 colorCount, u16 width) : colors(colors), colorCount(colorCount), width(width) {}
    void Stripes::operator()(Functors::Params params) {
        *(params.color) = colors[(*(params.pixel) / width) % colorCount];
    }

    Animate::Animate(double speed) : speed(speed) {
        startTime = Clock::now();
    }
    void Animate::operator()(Functors::Params params) {
        double timeElapsed = Clock::secs_since(startTime);
        s16 pixelShift = (s16) (timeElapsed * speed);
        *(params.pixel) += pixelShift;
    }
}