#ifndef YAHOOCSVDATAPROVIDER_H
#define YAHOOCSVDATAPROVIDER_H

#include "dataprovider.h"
#include <string>
#include <vector>

class YahooCSVDataProvider : public DataProvider
{
public:
    YahooCSVDataProvider() = default;

    enum class Month {
        JANUARY = 0,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    enum class TradingPeriod {
        DAY = 'd',
        MONTH = 'm'
    };

    void Initialise(const std::string& symbol) override;

    bool DataAvailable() const override;

    void UpdateBars() override;
private:
    void PopulateBars(const std::string &symbol, const std::string& stockData);

    std::vector<OHLCDataPoint> bars;
};

std::string ConstructUrl(const std::string& symbol,
                         int fromDay,
                         YahooCSVDataProvider::Month fromMonth,
                         int fromYear,
                         int toDay,
                         YahooCSVDataProvider::Month toMonth,
                         int toYear,
                         YahooCSVDataProvider::TradingPeriod);

#endif // YAHOOCSVDATAPROVIDER_H
