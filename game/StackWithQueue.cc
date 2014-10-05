#include <iostream>
#include <queue>
#include <exception>
using namespace std;

class StackWithQueue
{
    public:
        StackWithQueue():flag(0) {}
        ~StackWithQueue() {}
        void push(int data);
        int pop();

    private:
        std::queue<int> queues[2];
        int flag;
};

void StackWithQueue::push(int data)
{
    queues[flag].push(data);
}

int StackWithQueue::pop()
{
    try
    {
        if(queues[flag].empty())
            throw "栈空";
    }
    catch(const char *e)
    {
        std::cout << e << std::endl;
    }
    while(queues[flag].size()!=1)
    {
        queues[1-flag].push(queues[flag].front());
        queues[flag].pop();
    }
    int ret = queues[flag].front();
    queues[flag].pop();
    flag = 1-flag;
    return ret;
}

int main(void)
{
    StackWithQueue stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    int ret = stack.pop();
    std::cout << ret << std::endl;
    ret = stack.pop();
    std::cout << ret << std::endl;
    stack.push(5);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    return 0;
}
