#include "executeaction.h"
#include <Timer.h>
#include <iostream>
#include <fstream>

ExecuteAction::ExecuteAction()
{

}

void ExecuteAction::addMessage(WorkToDo workToDo)
{
    m_jobsList.push_back(workToDo);
}

void ExecuteAction::run()
{
    qDebug() << "RUN";
    //int size = m_jobsList.size();
    mutex.lock();

    unsigned int jobPos = 0;
    while(true)
    {
        if(m_jobsList.size() > 0)
        {
            // se il job in posizione x i.e. 0 e' un job di stampa
            if(m_jobsList[jobPos].getDescription() == "P")
            {
                // PRINT
                qDebug() << "RUN CALLING PRINT JOB!";
                printDebug(m_jobsList[jobPos]);
                qDebug() << "RUN PRINT JOB QUITTED!";
            }
            // se il job in posizione x i.e. 0 e' un job di controllo file
            else if(m_jobsList[jobPos].getDescription() == "W")
            {
                // WRITE TO FILE
                qDebug() << "RUN CALLING CHECK TEXT JOB!";

                checkFile(m_jobsList[jobPos]);
                qDebug() << "RUN CHECK TEXT JOB QUITTED!";
            }
            jobPos++;
            // se sforo la dimensione del vettore, riparto da zero
            if(jobPos > m_jobsList.size())
            {
                jobPos = 0;
            }
        }
    }
    mutex.unlock();
}


void ExecuteAction::printDebug(WorkToDo workToDo)
{

    if(m_enqueJob)
    {
        qDebug() << "printDebug::JOB WAS EXECUTING, INTERRUPTED PREVIOUS JOB!";
        m_enqueJob = false;
    }


    // holds the number of time the action must be executed
    int numberOfTime = 0;
    // how many time per hour
    if(workToDo.getTimeUnit() == "s")
    {
        numberOfTime = 60 / workToDo.getDuration();
        executeJobHourly(numberOfTime,workToDo.getDuration(), workToDo.getDescription());

    }
    if(workToDo.getTimeUnit() == "h")
    {
        numberOfTime = 24 / workToDo.getDuration();
        executeJobHourly(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    // how many time per week
    else if (workToDo.getTimeUnit() == "d") {
        numberOfTime = 7 / workToDo.getDuration();
        executeJobHourly(numberOfTime,workToDo.getDuration(), workToDo.getDescription());
    }
    // custom
    else if(workToDo.getTimeUnit() == "c")
    {

    }



    // get the number of time
    qDebug() << "printDebug::JOB MUSTE BE DONE EACH:" << workToDo.getDuration() << " seconds, jobs times in 1 minute: " << numberOfTime;

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        // da aggiungere funzione per gestire ore minuti giorni mese personalizzato
        while(t.elapsedSeconds() < workToDo.getDuration())
        {
            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
                // per ora aspetto che finisica il job in esecuzione devo modificare affinche se si incrociano cambia
                if(i == numberOfTime)
                {
                    qDebug() << "printDebug::SECOND JOB ADDED TO QUEUE RETURNIG TO RUN!" << i;
                    return;
                }

            }
        }
        t.stop();
        qDebug() << "printDebug::Hello, I'm the printing job! Execution number: " << i;
    }

    if(!m_enqueJob)
    {
        printDebug(workToDo);
    }
}

void ExecuteAction::checkFile(WorkToDo workToDo)
{
    if(m_enqueJob)
    {
        qDebug() << "checkFile::JOB WAS EXECUTING, INTERRUPTED PREVIOUS JOB!";
        m_enqueJob = false;
    }
    // get the number of time
    int numberOfTime = 60 / workToDo.getDuration();
    qDebug() << "checkFile::JOB MUSTE BE DONE EACH:" << workToDo.getDuration() << " seconds, jobs times in 1 minute: " << numberOfTime;

    for(int i = 0; i < numberOfTime; i++)
    {
        Timer t;
        t.start();
        while(t.elapsedSeconds() < workToDo.getDuration())
        {
            if(m_jobsList.size() > 1)
            {
                m_enqueJob = true;
                if(i == numberOfTime)
                {
                    qDebug() << "checkFile::SECOND JOB ADDED TO QUEUE RETURNIG TO RUN!" << i;
                    return;
                }

            }
        }
        t.stop();
        std::ofstream outfile ("test.txt");

        outfile << "File exists and I'm writing in it!" << std::endl;

        outfile.close();
        qDebug() << "checkFile::FILE CREATED!";
        qDebug() << "checkFile::Hello, I'm the printing job! Execution number: " << i;
    }

    if(!m_enqueJob)
    {
        checkFile(workToDo);
    }
}


void ExecuteAction::executeJobSeconds(int numberOfTime, int duration, std::string executAction )
{
    Timer t;
    t.start();
    while(t.elapsedSeconds() < numberOfTime)
    {

    }
    t.stop();
}

void ExecuteAction::executeJobHourly(int numberOfTime, int duration, std::string executAction)
{
    Timer t;
    t.start();
    while(t.elapsedSeconds() < numberOfTime)
    {

    }
    t.stop();
}

// qua passo le ore, ogni quante ore lo voglio fare
void ExecuteAction::executeJobDaily(int numberOfTime, int duration, std::string executAction)
{
    Timer t;
    t.start();
    while(t.elapsedSeconds()*3600 < numberOfTime)
    {

    }
    t.stop();
}

// qua passo i giorni, ogni quanti giorni lo voglio fare
void ExecuteAction::executeJobWeekly(int numberOfTime, int duration, std::string executAction)
{
    Timer t;
    t.start();
    while(t.elapsedSeconds()*86400 < numberOfTime)
    {

    }
    t.stop();
}

// qua e' possiible impostarlo personalmente ogni tot ora alle 12
void ExecuteAction::executePersonal(int numberOfTime, int duration)
{

}



