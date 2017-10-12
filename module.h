#ifndef MODULE_H
#define MODULE_H


//QtDoc
/*!
    \abstract Any module is made of actions. There can be one or many Actions in a single module
    e.g. Card reader is a module which here is a hardware/software part of the system which is under simulation
    A transaction can be flow in which the module Card reader will come into play with other modules offcourse
    Card Swipe can be a flow which is an action which is the part of any Transaction flow

    \arg Icommunication : This is an Interface to the communication module. When an Action
    is instantiaited it should also have an intatiated reference/handle to a comm object

    \arg eActionType:   ManualSarterSend --> Manually configured Action which is the start point(field:data)
                        ManualSend --> Manually configured Action to send (data)
                        ManulaRecv --> Manually configured Action to recv (data)
                        AutmationRecv --> Automatted recv (data)

    Any flow may include several modules. But the modules will have the same set actions configured.
    And will behave in the same manner. What my differ is the data. The structure of data however should
    be specific and defined by the user. The user should be able to configure it in a manner that the structure and
    also the comm interface should remain specific to the module's behaviuor and should be flow agnostic.

*/

class CModule{
private:
    std::string strModuleName;
public:
    inline setterModuleName(std::string & strName) {strModuleName = strName; }
    inline const std::string & getModuleName(){ return strModuleName;}
};
#endif // MODULE_H
