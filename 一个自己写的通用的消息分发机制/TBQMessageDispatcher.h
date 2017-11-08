/************************************************************************/
/*   TBQ���ڶ������Ϣ�ַ���
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
    virtual QString messageIdentify() = 0; //������Ϣ��ʶ
    virtual QString messageData() = 0;     //������Ϣ������
};


class TBQCORE_EXPORT ITBQMessageObserver
{
public:
    virtual ~ITBQMessageObserver();
    virtual msgNotify(ITBQMessageObserver *sender, const TBQCustomMsg &msgType);   //�۲��߽��յ���Ϣ
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



extern "C" TBQCORE_EXPORT void sendTBQMessage(ITBQMessageObserver *sender, ITBQMessageObserver *receiver, TBQCustomMsg &msgType);//ҵ��㷢����Ϣ
extern "C" TBQCORE_EXPORT QSet<ITBQMessageObserver*> getReceivers(const QString &className); //����������ȡ���󼯺�

#endif
