#ifndef INTCOMM_H
#define INTCOMM_H

#include <QIODevice>
#include <memory>
/*!
\abstract IntComm is an interface which subclasses QIODevice. It gets associated with
the Module class. This provides the comm interface and should readily provide handles
for allowing that particular module to make communication with the outer world or other
modules inside the system


*/
class CModule;

enum EnumCommType{ TCP, UDP, Serial};

auto delIoDevice = [](QIODevice * pcomm)
                    {
                        //MakeLogging(pcomm);
                        delete pcomm;
                    };

class IntComm: public QObject
{
    Q_OBJECT
public:
    explicit IntComm();
    IntComm(const IntComm& rhs);
    IntComm& operator = (const IntComm& rhs);

    /*!
      \abstract RegisterACommType registers a communication type the client is going
      to use. It should register the particular request and should return a QIODevice type which is a handle to the comm APIs
    */
    IntComm * RegisterACommType(enum EnumCommType);
    AssociateWithModule(CModule* pModule);
    MaintainHandlesToComm();

private:
    CModule* m_pModule;
    std::vector<std::unique_ptr<QIODevice, decltype(delIoDevice)>> m_vecUptrCommHandles;

};

#endif // INTCOMM_H
