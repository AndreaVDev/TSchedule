#ifndef EXECUTEACTION_H
#define EXECUTEACTION_H
#include <QThread>
#include <QMutex>
#include <worktodo.h>
#include <vector>
#include <QDebug>

class ExecuteAction : public QThread
{
public:
    ExecuteAction();
    void addMessage(WorkToDo workToDo);

    // QThread interface
protected:
    void run();
private:
    std::vector<WorkToDo> m_jobsList;
    QMutex mutex;
    void printDebug(WorkToDo workToDo);
    void checkFile(WorkToDo workToDo);
    bool m_enqueJob;
    void executeJobSeconds(int numberOfTime,std::string unit);
    void executeJobHourly(int numberOfTime,std::string unit);
    void executeJobDaily(int numberOfTime,std::string unit);
    void executeJobWeekly(int numberOfTime,std::string unit);
    void executePersonal(int numberOfTime,std::string unit);
};

#endif // EXECUTEACTION_H
