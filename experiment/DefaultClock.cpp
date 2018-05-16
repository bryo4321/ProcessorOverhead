//
// Created by sarah on 9/29/17.
//

#include "DefaultClock.h"

namespace AccurateClock {

    Time::Time(const timespec &timeValue) : timeValue(timeValue) {
    }

    void Time::print(std::ostream &out) const {
        const double oneThousand = 1000;
        auto milliseconds = getTotalMilliseconds();
        auto secondsPart = (long)(milliseconds / oneThousand);
        auto millisecondsPart = (long)(milliseconds - (secondsPart * oneThousand));
        auto nsPart = (long)(
                (milliseconds * oneThousand) -
                (secondsPart * oneThousand * oneThousand) -
                (millisecondsPart * oneThousand));
        out << secondsPart << "sec, " << millisecondsPart << "ms, " << nsPart << "ns since the computer booted";
    }

    double Time::getTotalMilliseconds() const {
        const double oneThousand = 1000;
        auto milliseconds =
                (timeValue.tv_sec * oneThousand) +
                (timeValue.tv_nsec / oneThousand) / oneThousand;
        return milliseconds;
    }

    const Duration Time::operator-(const Time &a) const {
        auto difference = ((getTotalMilliseconds() - a.getTotalMilliseconds())/1000);

        auto duration = Duration(difference);

        return duration;
    }

    const Time DefaultClock::getTime() {
        auto value = timespec();
        clock_gettime(CLOCK_BOOTTIME, &value);
        auto time = Time(value);
        return time;
    }

    Duration::Duration(double value) : valueInSeconds(value) {
    }

    void Duration::print(std::ostream &out) const {
        out << valueInSeconds << "sec";
    }
}
