//
// Created by sarah on 9/29/17.
//

#ifndef experiment_DEFAULTCLOCK_H
#define experiment_DEFAULTCLOCK_H

#include <time.h>
#include <ostream>

namespace AccurateClock {

    class Duration {
    private:

        const double valueInSeconds;
    public:
        explicit Duration(double value);
        void print(std::ostream& out) const;
    };

    class Time {
        const timespec timeValue;
    public:
        explicit Time(const timespec& timeValue);
        const Duration operator-(const Time& a) const;
        void print(std::ostream& out) const;
        double getTotalMilliseconds() const;
    };

    class DefaultClock {
    public:
        const Time getTime();
    };

}
#endif //ACCURATECLOCK_DEFAULTCLOCK_H
