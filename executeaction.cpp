#include "executeaction.h"
#include <Timer.h>
#include <iostream>
#include <fstream>
#include <unistd.h>

ExecuteAction::ExecuteAction()
{
    m_enqueJob = false;
}

void ExecuteAction::addMessage(WorkToDo workToDo)
{
    mutex.lock();
    m_jobsList.push_back(workToDo);
    mutex.unlock();
}

void ExecuteAction::run()
{
    while(true)
    {
        for(unsigned int i = 0; i < m_jobsList.size(); i++)
        {
            m_enqueJob = false;
            launchJob(m_jobsList[i]);
        }
    }
}


// launch the job and caluclate how much time it must be executed
void ExecuteAction::launchJob(WorkToDo workToDo)
{
    // if another job must be done i need to go back into the for of the run or I will be executing always the same job
    if(m_enqueJob)
    {
        m_enqueJob = false;
        return;
    }
    // holds the number of time the action must be executed
    int numberOfTime = 0;

    if(workToDo.getTimeUnit() == " s")
    {
        numberOfTime = 60 / workToDo.getDuration();
        executeJobSeconds(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    else if(workToDo.getTimeUnit() == " h")
    {
        numberOfTime = 24 / workToDo.getDuration();
        executeJobHourly(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    else if (workToDo.getTimeUnit() == " d") {
        numberOfTime = 7 / workToDo.getDuration();
        executeJobDaily(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    // custom
    else
    {
        executePersonalDateTime(workToDo);
    }
}

void ExecuteAction::printDebug()
{
    qDebug() << "printDebug::Hello, I'm the printing job!";
}

bool ExecuteAction::checkFile()
{

    std::string fileName = "test.txt";
    std::ifstream f(fileName.c_str());
    return f.good();
}

// Execute the task each X Seconds
void ExecuteAction::executeJobSeconds(int numberOfTime, int duration, std::string executeAction)
{
    Timer t;
    t.start();

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        while(t.elapsedSeconds() < duration)
        {
            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
            }
        }
        t.stop();

        if(executeAction == "P")
        {
            printDebug();
            if(m_enqueJob)
            {
                qDebug() << "executeJobSeconds::Second job added to queue! Starting new job";
                return;
            }
        } else if(executeAction == "W")
        {

            if(checkFile())
            {

                qDebug() << "executeJobSeconds::File exists!";
            }
            else
            {

                qDebug() << "executeJobSeconds::File doesn't exist!";
            }
            if(m_enqueJob)
            {
                qDebug() << "executeJobSeconds::Second job added to queue! Starting new job!";
                return;
            }
        }
    }

    if(!m_enqueJob)
    {
        executeJobSeconds(numberOfTime, duration, executeAction);
    }
}

// Execute the task each X hours
void ExecuteAction::executeJobHourly(int numberOfTime, int duration, std::string executeAction)
{
    Timer t;
    t.start();

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        while(t.elapsedSeconds()*3600 < duration)
        {

            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
            }
        }
        t.stop();

        if(executeAction == "P")
        {
            printDebug();
            if(m_enqueJob)
            {
                qDebug() << "executeJobHourly::Second job added to queue! Starting new job";
                return;
            }
        } else if(executeAction == "W")
        {

            if(checkFile())
            {

                qDebug() << "executeJobHourly::File exists!";
            }
            else
            {

                qDebug() << "executeJobHourly::File doesn't exist!";
            }
            if(m_enqueJob)
            {
                qDebug() << "executeJobHourly::Second job added to queue! Starting new job!";
                return;
            }
        }
    }

    if(!m_enqueJob)
    {
        executeJobHourly(numberOfTime, duration, executeAction);
    }
}

// Execute the task each X days
void ExecuteAction::executeJobDaily(int numberOfTime, int duration, std::string executeAction)
{

    Timer t;
    t.start();

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        // da aggiungere funzione per gestire ore minuti giorni mese personalizzato
        while(t.elapsedSeconds()*86400 < duration)
        {

            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
            }
        }
        t.stop();

        if(executeAction == "P")
        {
            printDebug();
            if(m_enqueJob)
            {
                qDebug() << "executeJobWeekly::Second job added to queue! Starting new job";
                return;
            }
        } else if(executeAction == "W")
        {

            if(checkFile())
            {

                qDebug() << "executeJobWeekly::File exists!";
            }
            else
            {

                qDebug() << "executeJobWeekly::File doesn't exist!";
            }
            if(m_enqueJob)
            {
                qDebug() << "executeJobWeekly::Second job added to queue! Starting new job!";
                return;
            }
        }
    }

    if(!m_enqueJob)
    {
        executeJobDaily(numberOfTime, duration, executeAction);
    }
}

// Here you can execute the job once per day at a given hour
void ExecuteAction::executePersonalDateTime(WorkToDo workTodo)
{
    bool samedayAndHour = false;
    while(!samedayAndHour)
    {
        if(m_jobsList.size() > 1)
        {
            m_enqueJob = true;
        }

        QDateTime now = QDateTime::currentDateTime();

        if(workTodo.getDay() == "Monday")
        {
            if(now.date().dayOfWeek() == 1)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
        if(workTodo.getDay() == "Tuesday")
        {
            if(now.date().dayOfWeek() == 2)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
        if(workTodo.getDay() == "Wednesay")
        {
            if(now.date().dayOfWeek() == 3)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
        if(workTodo.getDay() == "Thursday")
        {
            if(now.date().dayOfWeek() == 4)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
        if(workTodo.getDay() == "Friday")
        {
            if(now.date().dayOfWeek() == 5)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
        if(workTodo.getDay() == "Saturday")
        {
            if(now.date().dayOfWeek() == 6)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
        if(workTodo.getDay() == "Sunday")
        {
            if(now.date().dayOfWeek() == 7)
            {
                if(now.time() == workTodo.getTime())
                {
                    samedayAndHour = true;
                    executePersonalTask();
                }
            }
        }
    }

    // if no other job needs to be started I restart this one
    if(!m_enqueJob)
    {
        executePersonalDateTime(workTodo);
    }
}

// here you can personalize the code for doing what you prefer
void ExecuteAction::executePersonalTask()
{
}

