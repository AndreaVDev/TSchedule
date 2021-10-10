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
    m_jobsList.push_back(workToDo);
}

void ExecuteAction::run()
{
    qDebug() << "RUN";
    //int size = m_jobsList.size();

    while(true)
    {

        for(unsigned int i = 0; i < m_jobsList.size(); i++)
        {
            qDebug() << "run job desc: " <<            QString::fromUtf8( m_jobsList[i].getDescription().data(), m_jobsList[i].getDescription().size());
;
            m_enqueJob = false;
            launcJob(m_jobsList[i]);
        }
    }
}



void ExecuteAction::launcJob(WorkToDo workToDo)
{
    // if another job must be done i need to go back into the for of the run or I will be executing always the same job
    if(m_enqueJob)
    {
        m_enqueJob = false;
        return;
    }
    // holds the number of time the action must be executed
    int numberOfTime = 0;
    // how many time per hour
    if(workToDo.getTimeUnit() == " s")
    {
        numberOfTime = 60 / workToDo.getDuration();
        executeJobHourly(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    if(workToDo.getTimeUnit() == " h")
    {
        numberOfTime = 24 / workToDo.getDuration();
        executeJobDaily(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    // how many time per week
    else if (workToDo.getTimeUnit() == " d") {
        numberOfTime = 7 / workToDo.getDuration();
        executeJobWeekly(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    // custom
    else if(workToDo.getTimeUnit() == " c")
    {

    }
    numberOfTime = 0;
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


void ExecuteAction::executeJobSeconds(int numberOfTime, int duration, std::string executeAction )
{


}

void ExecuteAction::executeJobHourly(int numberOfTime, int duration, std::string executeAction)
{
    Timer t;
    t.start();

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        // da aggiungere funzione per gestire ore minuti giorni mese personalizzato
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
        } else if(executeAction == "C")
        {
            // Custom Action here you can personalize it as you want
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

// qua passo le ore, ogni quante ore lo voglio fare
void ExecuteAction::executeJobDaily(int numberOfTime, int duration, std::string executeAction)
{
    Timer t;
    t.start();

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        // da aggiungere funzione per gestire ore minuti giorni mese personalizzato
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
                qDebug() << "executeJobDaily::Second job added to queue! Starting new job";
                return;
            }
        } else if(executeAction == "W")
        {

            if(checkFile())
            {

                qDebug() << "executeJobDaily::File exists!";
            }
            else
            {

                qDebug() << "executeJobDaily::File doesn't exist!";
            }
            if(m_enqueJob)
            {
                qDebug() << "executeJobDaily::Second job added to queue! Starting new job!";
                return;
            }
        } else if(executeAction == "C")
        {
            // Custom Action here you can personalize it as you want
            if(m_enqueJob)
            {
                qDebug() << "executeJobDaily::Second job added to queue! Starting new job!";
                return;
            }
        }
    }

    if(!m_enqueJob)
    {
        executeJobDaily(numberOfTime, duration, executeAction);
    }
}

// qua passo i giorni, ogni quanti giorni lo voglio fare
void ExecuteAction::executeJobWeekly(int numberOfTime, int duration, std::string executeAction)
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
        } else if(executeAction == "C")
        {
            // Custom Action here you can personalize it as you want
            if(m_enqueJob)
            {
                qDebug() << "executeJobWeekly::Second job added to queue! Starting new job!";
                return;
            }
        }
    }

    if(!m_enqueJob)
    {
        executeJobWeekly(numberOfTime, duration, executeAction);
    }
}

// qua e' possiible impostarlo personalmente ogni tot ora alle 12
void ExecuteAction::executePersonal(int numberOfTime, int duration)
{
    Timer t;
    t.start();
    int executionNumber = 0;
    while(t.elapsedSeconds()*86400 < duration)
    {
        if(m_jobsList.size() > 1)
        {
            m_enqueJob = true;
            // I wait for the jobs to execute the n-th number of time
            /*
            if(i == numberOfTime)
            {
                qDebug() << "printDebug::SECOND JOB ADDED TO QUEUE RETURNIG TO RUN!" << i;
                return;
            }
            */
        }
    }
    t.stop();

    executionNumber++;
    if(m_enqueJob)
    {
        return;
    }
    t.stop();
}



