#include "Date.h"


#include <time.h>

//
//  Function      : YmdToJd
//
//  Author        : Todd Knarr
//
//  Creation date : 29 Nov 1995
//
//  Parameters    : int year, month, day
//
//  Return values : long julian day
//
//  Description   :
//
// Internal routine that does the physical conversion
// from YMD form to Julian day number.
//
long Date::YmdToJd(const int iYear, const int iMonth, const int iDay)
{
    long jul_day;

#ifndef JULDATE_USE_ALTERNATE_METHOD

    int a, b;
    int year = iYear, month = iMonth, day = iDay;
    float year_corr;

    if (year < 0)
        year++;
    year_corr = (year > 0 ? 0.0 : 0.75);
    if (month <= 2)
    {
        year--;
        month += 12;
    }
    b = 0;
    if (year * 10000.0 + month * 100.0 + day >= 15821015.0)
    {
        a = year / 100;
        b = 2 - a + a / 4;
    }
    jul_day = (long)(365.25 * year - year_corr) +
        (long)(30.6001 * (month + 1)) + day + 1720995L + b;

#else

    long lmonth = (long)iMonth, lday = (long)iDay, lyear = (long)iYear;

    // Adjust BC years
    if (lyear < 0)
        lyear++;

    jul_day = lday - 32075L +
        1461L * (lyear + 4800L + (lmonth - 14L) / 12L) / 4L +
        367L * (lmonth - 2L - (lmonth - 14L) / 12L * 12L) / 12L -
        3L * ((lyear + 4900L + (lmonth - 14L) / 12L) / 100L) / 4L;

#endif

    return jul_day;
}

//  Function      : JdToYmd
//
//  Author        : Todd Knarr
//
//  Creation date : 29 Nov 1995
//
//  Parameters    : long julian day, pointers to int year, month, day
//
//  Return values : none
//
//  Description   :
//
// Internal routine that reverses the conversion, turning a Julian
// day number into YMD values.
//
void Date::JdToYmd(const long lJD, int* piYear, int* piMonth, int* piDay)
{
#ifndef JULDATE_USE_ALTERNATE_METHOD

    long a, b, c, d, e, z, alpha;

    z = lJD;
    if (z < 2299161L)
        a = z;
    else
    {
        alpha = (long)((z - 1867216.25) / 36524.25);
        a = z + 1 + alpha - alpha / 4;
    }
    b = a + 1524;
    c = (long)((b - 122.1) / 365.25);
    d = (long)(365.25 * c);
    e = (long)((b - d) / 30.6001);
    *piDay = (int)b - d - (long)(30.6001 * e);
    *piMonth = (int)(e < 13.5) ? e - 1 : e - 13;
    *piYear = (int)(*piMonth > 2.5) ? (c - 4716) : c - 4715;
    if (*piYear <= 0)
        *piYear -= 1;

#else

    long t1, t2, yr, mo;

    t1 = lJD + 68569L;
    t2 = 4L * t1 / 146097L;
    t1 = t1 - (146097L * t2 + 3L) / 4L;
    yr = 4000L * (t1 + 1L) / 1461001L;
    t1 = t1 - 1461L * yr / 4L + 31L;
    mo = 80L * t1 / 2447L;
    *piDay = (int)(t1 - 2447L * mo / 80L);
    t1 = mo / 11L;
    *piMonth = (int)(mo + 2L - 12L * t1);
    *piYear = (int)(100L * (t2 - 49L) + yr + t1);

    // Correct for BC years
    if (*piYear <= 0)
        *piYear -= 1;

#endif

    return;
}


int Date::DayOfYear(void) const
{
    int y, m, d;
    long soy;

    JdToYmd(lJulianDay, &y, &m, &d);
    soy = YmdToJd(y, 1, 1);
    return (int)(lJulianDay - soy + 1);
}