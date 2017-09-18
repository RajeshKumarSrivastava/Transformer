#ifndef INTCOMM_H
#define INTCOMM_H

#include <QIODevice>
/*!
\abstract IntComm is an interface which subclasses QIODevice. It gets associated with
the Module class. This provides the comm interface and should readily provide handles
for allowing that particular module to make communication with the outer world or other
modules inside the system


*/

class IntComm : public QIODevice
{
    Q_OBJECT
public:
    IntComm(QIODevice *parent);
    IntComm * RetrnCommInterface(EnumCommType enumComm);
    AssociateWithModule(CModule* pModule);
    MaintainHandlesToComm()

private:
    enum EnumCommType{ TCP, UDP, Serial};

};

#endif // INTCOMM_H
