#ifndef PORTFOLIOHANDLER_H
#define PORTFOLIOHANDLER_H

#include <qobject.h>

class SignalEvent;
class MarketEvent;
class FillEvent;
class EventQueue;
class DataProvider;

class PortfolioHandler : public QObject
{
    Q_OBJECT
public:
    // Set up the portfolio with an initial capital and the volume of shares to
    // buy on each transaction, the initial capital is in GBX
    PortfolioHandler(DataProvider* dataProvider, double initialCapital = 1000000, int volumePerTransaction = 10);

    void OrderRequest(const SignalEvent& signalEvent);

    void FillUpdate(const FillEvent& fillEvent);

    // Every heartbeat we need to update the current price of our holdings
public slots:
    void ProcessMarketEvent(const MarketEvent& marketEvent);

private:
    double capital;
    int volumePerTransaction;
    int volumeInvested;
    double capitalInvested;
};

#endif // PORTFOLIOHANDLER_H
