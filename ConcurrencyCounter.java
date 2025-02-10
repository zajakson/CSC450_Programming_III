import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ConcurrencyCounter {
    //constructors for the lock instance
    private static final Lock lock = new ReentrantLock();
    private static final Condition condition = lock.newCondition();
    //intial condition for race condition
    private static boolean firstThreadDone = false;

    public static void main(String[] args) {
        //thread constructors 
        Thread t1 = new Thread(ConcurrencyCounter::incUp);
        Thread t2 = new Thread(ConcurrencyCounter::incDown);

        //thread starts
        t1.start();
        t2.start();

        //tries thread join
        try {
            t1.join();
            t2.join();
        
        //print error occurs via e as message
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    //simple function that shows thread switch
    public static void threadSwitch(){
        System.out.println("THREAD SWITCH");
    }

    //increment function
    public static void incUp() {
        for (int i = 0; i <= 20; i++) {
            //lock instance
            lock.lock();
            //incremement with deadlock protection
            try {
                System.out.println("Count Up: " + i);
            } finally {
                //unlock deadlock condition
                lock.unlock();
            }
        }
        lock.lock(); //race condition lock 
        try {
            firstThreadDone = true;
            condition.signal(); // similar to c++ cv.notify_one()
        } finally {
            lock.unlock(); //unlock race condition
        }
    }

    public static void incDown() {
        lock.lock(); //race condition lock
        try {
            while (!firstThreadDone) { //while not true 
                condition.await(); // Wait until incUp completes
            }
        } catch (InterruptedException e) {
            e.printStackTrace(); //exception via e message 
        } finally {
            lock.unlock(); // unlocks when firstThreadDone is Ture
        }

        threadSwitch(); //simple middle point
        
        for (int i = 20; i >= 0; i--) {
            lock.lock(); //same other instances
            try {
                System.out.println("Count Down: " + i);
            } finally {
                lock.unlock(); //same as other instance
            }
        }
    }
}
