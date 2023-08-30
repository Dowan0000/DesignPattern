#include <iostream>
#include <thread>
#include <mutex>

//class Singleton
//{
//private:
//    static Singleton* _pinstance;
//    static std::mutex _mutex;
//
//protected:
//    Singleton(const std::string value) : _value(value)
//    { }
//    ~Singleton() {}
//    std::string _value;
//
//public:
//    Singleton(Singleton& other) = delete;
//    
//    void operator=(const Singleton&) = delete;
//    
//    static Singleton* GetInstance(const std::string& value)
//    {
//        std::lock_guard<std::mutex> lock(_mutex);
//        if (_pinstance == nullptr)
//        {
//            _pinstance = new Singleton(value);
//        }
//        return _pinstance;
//    }
//    
//    void SomeBusinessLogic()
//    {
//        // ...
//    }
//
//    std::string value() const 
//    {
//        return _value;
//    }
//};
//
//Singleton* Singleton::_pinstance{nullptr};
//std::mutex Singleton::_mutex;
//
//
//void ThreadFoo() 
//{
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    Singleton* singleton = Singleton::GetInstance("FOO");
//    std::cout << singleton->value() << "\n";
//}
//
//void ThreadBar() 
//{
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    Singleton* singleton = Singleton::GetInstance("BAR");
//    std::cout << singleton->value() << "\n";
//}
//
//int main()
//{
//    std::cout << "If you see the same value, then singleton was reused (yay!\n" <<
//        "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
//        "RESULT:\n";
//    std::thread t1(ThreadFoo);
//    std::thread t2(ThreadBar);
//    t1.join();
//    t2.join();
//
//    return 0;
//}