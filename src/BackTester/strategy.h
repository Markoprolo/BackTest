#ifndef STRATEGY_H
#define STRATEGY_H

#include "eventqueue.h"
#include "ohlcdatapoint.h"

class Strategy
{
public:   
    Strategy() = default;

    virtual ~Strategy() = default;

    // This function should add either a RETURN_TO_IDLE event or
    // SIGNAL_EVENT to the eventQueue
    virtual void ProcessDataUpdate(EventQueue& eventQueue, const OHLCDataPoint& dataPoint) = 0;
};

#endif // STRATEGY_H
