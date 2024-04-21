//g++ -o rwp rwp3.cpp -pthread -lrt   ---> to run the code and then ./rwp
#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h> 

using namespace std;

int sharedData = 0;
sem_t mutex;   // Semaphore for mutual exclusion
sem_t rwSemaphore; // Semaphore for controlling access to reading and writing
int readersCount = 0;   // Variable to store the number of readers

void reader(int id);
void writer(int id);

int main() {
    
    
    sem_init(&mutex, 0, 1);
    sem_init(&rwSemaphore, 0, 1);

    thread readers[5];
    for (int i = 0; i < 5; ++i) {
        readers[i] = thread(reader, i + 1);
    }

    thread writers[2];
    for (int i = 0; i < 2; ++i) {
        writers[i] = thread(writer, i + 1);
    }


    for (int i = 0; i < 2; ++i) {
        writers[i].join();
    }
    
    for (int i = 0; i < 5; ++i) {
        readers[i].join();
    }

    sem_destroy(&mutex);
    sem_destroy(&rwSemaphore);

    return 0;
}

void reader(int id) {
  
    sem_wait(&mutex);       // Acquire mutex for updating reader count
    readersCount++;
    cout << "Reader " << id << " is reading: " << sharedData << endl;
    
    if(readersCount==1)
        sem_wait(&rwSemaphore); 
    sem_post(&mutex);       

    sleep(4);

    sem_wait(&mutex);      
    readersCount--;
    if (readersCount   == 0)
        sem_post(&rwSemaphore); 
    sem_post(&mutex);     
}

void writer(int id) {
    sem_wait(&rwSemaphore); 
    ++sharedData;
    cout << "Writer " << id << " is writing: " << sharedData << endl;
    sleep(2);
    sem_post(&rwSemaphore); 
}