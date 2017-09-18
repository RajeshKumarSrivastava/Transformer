#ifndef ACTION_H
#define ACTION_H

#include<stdlib.h>



/*! Ummm, I am not sure which is best , to go for factory or interface, but here since my intention
    is to suppport different types of testcases(manual as well as scripts), but still I think factory violates OCP
class CTestCaseFactory{
private:
    CTestCaseFactory();
public:
    static CTestCase* factoryForTestCases(std::string strTestCaseType);
};

*/



/*!
    CTestCase is a particular case user wants to test in the System
    For now this should be configurable only from the transaformer GUI but
    later it should support scripts and files having test cases as well..
*/
class CTestCase{
private:
    std::string strTCLabel;
    enum eTCType{ Manual, Automation};
    std::list<std::unique_ptr<CFlow>> listTCFlows;
public:
    CTestCase(std::string strTCLabel, enum eTCType);
    AssociateFlow(CFlow *pCFlow);
};

/*!
    \abstract CFlow : Flow for any testcase , there can be multiple flows for a test case
    ListModule: There can a single or multiple Modules attached to complete a flow

    User on the UI will have an option to add a flow. He can specify which all modules will be used/needed
    for that particular flow. He should be able to select actions in that particular module.

    A data structure which would be suitable to map Actions or actions inside a particulat Module....
    When the user is trying to configure a Flow -> module -> Action , at this point he should be able to
    configure that particular action in detail. he may also be able to choose an already configured Action
    \arg <list of Actions>A flow to me should be a set of actions. When the user with the UI defines a flow, he should be able
    to choose the actions within the selected or added modules. These selected Actions then should get added in
    the particular flow
*/
class CFlow{
private:
    std::string m_strFlowName;
    bool m_bStartingPoint;
    std::list<unique_ptr<CAction>> m_upListModules;
public:
    const std::list<unique_ptr<CModule> & AssociateModules(CModule *pCAction);
};

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

/*!
 * \brief The CAction class is the most atomic behaviour and is attached to a module
 * \abstract
 * \arg strActionName: Name of the action should be such that it could identify the Module it is attached with
 */

class CAction{
private:
    std::string strActionName;
    std::unique_ptr<ICommunication> Uptr_IComm;
    enum eActionType { ManualStarterSend, ManualSend, ManualRecv, AutomationRecv};
    std::unique_ptr<CAction> m_uptModule;

public:
    CAction();
    CAction(std::string strLabel, ICommunication* p_IComm, enum eActionType);
    setActionName(std::string ActionName){ strActionName = ActionName; }
    const std::string getActionName(){ return strActionName; }
    //CAction(const CAction& rhs) delete;
};

#endif // ACTION_H
