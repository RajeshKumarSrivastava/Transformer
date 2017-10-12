#ifndef FLOW_H
#define FLOW_H
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
    /*! shouldn't a flow have a tree, with Action as nodes since the actions can be connected to many actions
    across modules TODO: Yet to think of a data structure*/

public:
    const std::list<unique_ptr<CModule> & AssociateModules(CModule *pCAction);
};
#endif // FLOW_H
