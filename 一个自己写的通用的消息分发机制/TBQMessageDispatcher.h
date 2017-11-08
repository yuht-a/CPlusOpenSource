/************************************************************************/
/*   TBQ基于对象的消息分发器
/************************************************************************/
#ifndef TBQMESSAGEDISPATCHER_H
#define TBQMESSAGEDISPATCHER_H

#include <QMap>
#include <QSet>
#include <QString>
#include <qmutex.h>

class TBQCustomMsg
{
public:
    virtual QString messageIdentify() = 0; //返回消息标识
    virtual QString messageData() = 0;     //返回消息的数据
};


class TBQCORE_EXPORT ITBQMessageObserver
{
public:
    virtual ~ITBQMessageObserver();
    virtual msgNotify(ITBQMessageObserver *sender, const TBQCustomMsg &msgType);   //观察者接收到消息
};

class TBQMessageDispatcher
{
public:
    void addMsgObserver(ITBQMessageObserver *obj);
    void removeMsgObserver(ITBQMessageObserver *obj);
    void checkObserver(ITBQMessageObserver *sender, ITBQMessageObserver *receiver, TBQCustomMsg *msg);
protected:
    void dispatch();
private:
    QMap<QString, QSet<ITBQMessageObserver*>>     m_map;
    QList<TBQCustomMsg*>                          m_msgs;
    QMutex                                        m_mutex;
};



extern "C" TBQCORE_EXPORT void sendTBQMessage(ITBQMessageObserver *sender, ITBQMessageObserver *receiver, TBQCustomMsg &msgType);//业务层发送消息
extern "C" TBQCORE_EXPORT QSet<ITBQMessageObserver*> getReceivers(const QString &className); //根据类名获取对象集合

#endif
