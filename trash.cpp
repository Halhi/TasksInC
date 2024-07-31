#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class SharedData {
public:
    static const int SIZE = 10; // Размер буфера
    std::vector<int> data;
    int writeIndex = 0;
    int readIndex = 0;
    int filledBuffers = 0;

    std::mutex mtx;
    std::condition_variable notFull;
    std::condition_variable notEmpty;

    SharedData() : data(SIZE) {}
};

void writer(SharedData& shared) {
    int value = 0;
    while (true) {
        __gthread_mutex_lock(shared.mtx)
        shared.notFull.wait(lock, [&]() { return shared.filledBuffers < SharedData::SIZE; });

        shared.data[shared.writeIndex] = value++;
        shared.writeIndex = (shared.writeIndex + 1) % SharedData::SIZE;
        shared.filledBuffers++;

        std::cout << "Written value: " << shared.data[shared.writeIndex] << " at index " << shared.writeIndex << std::endl;

        lock.unlock();
        shared.notEmpty.notify_one();
    }
}

void reader(SharedData& shared) {
    while (true) {
        std::unique_lock<std::mutex> lock(shared.mtx);
        shared.notEmpty.wait(lock, [&]() { return shared.filledBuffers > 0; });

        int value = shared.data[shared.readIndex];
        std::cout << "Read value: " << value << " from index " << shared.readIndex << std::endl;
        shared.readIndex = (shared.readIndex + 1) % SharedData::SIZE;
        shared.filledBuffers--;

        lock.unlock();
        shared.notFull.notify_one();
    }
}

int main() {
    SharedData sharedData;

    std::thread writerThread(writer, std::ref(sharedData));
    std::thread readerThread(reader, std::ref(sharedData));

    writerThread.join();
    readerThread.join();

    return 0;
}