#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


std::mutex mtx;
std::condition_variable cv;
bool firstThreadDone = false;

//Simple notification that a thread switch has occured.
void threadSwitch(){
    std::cout << "THREAD SWITCH" << std::endl;
}

//FOR-LOOP UpThread
void incUp() {
    for (int i = 0; i <= 20; ++i) {
        //deadlock protection. automatic lock/unlock via lock(mtx)
        std::lock_guard<std::mutex> lock(mtx);
        //print statement
        std::cout << "Count Up: " << i << std::endl;
    }

    //Race condition protection. notify incDown after completion 
    std::unique_lock<std::mutex> lock(mtx);
    firstThreadDone = true;
    cv.notify_one(); // Notify the second thread to start
}

//FOR-LOOP downThread
void incDown() {
    //authority from incUp (thread one) to proceed 
    std::unique_lock<std::mutex> lock(mtx);

    //conditional variable. waits as locked until notified true via cv.notify_one ()
    cv.wait(lock, [] { return firstThreadDone; }); 
     
    //shows thread two is in operation after unique lock is removed. 
    threadSwitch();

    //no further thread safeguards needed since this is the last operation. 
    for (int i = 20; i >= 0; --i) {
        std::cout << "Count Down: " << i << std::endl;
    }
}


int main() {
    std::thread t1(incUp);
    std::thread t2(incDown);
    
    t1.join();
    t2.join();
    
    return 0;
}
