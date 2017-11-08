#include "StdAfx.h"
#include "TBQMessageDispatcher.h"



void TBQMessageDispatcher::addMsgObserver(ITBQMessageObserver* obj)
{

}

void TBQMessageDispatcher::removeMsgObserver(ITBQMessageObserver* obj)
{

}

void TBQMessageDispatcher::dispatch()
{

}

void TBQMessageDispatcher::checkObserver(ITBQMessageObserver *sender, ITBQMessageObserver *receiver, TBQCustomMsg *msg)
{

}

ITBQMessageObserver::~ITBQMessageObserver()
{

}

ITBQMessageObserver::msgNotify(ITBQMessageObserver *sender, const TBQCustomMsg &msgType)
{

}

extern "C" TBQCORE_EXPORT void sendTBQMessage(ITBQMessageObserver *sender, ITBQMessageObserver *receiver, TBQCustomMsg &msgType)
{
    
}

extern "C" TBQCORE_EXPORT QSet<ITBQMessageObserver*> getReceivers(const QString &className)
{

}
