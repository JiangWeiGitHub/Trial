#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton *GetInstance()
    {
        return const_cast <Singleton *>(m_Instance);
    }

    static void DestoryInstance()
    {
        if (m_Instance != NULL )
        {
            delete m_Instance;
            m_Instance = NULL ;
        }
    }

    int GetTest()
    {
        return m_Test;
    }

private:
    Singleton(){ m_Test = 33; }
    static const Singleton *m_Instance;
    int m_Test;
};

const Singleton *Singleton ::m_Instance = new Singleton();

int main(void)
{
    Singleton *singletonObj = Singleton ::GetInstance();
    cout<<singletonObj->GetTest()<<endl;
    Singleton ::DestoryInstance();

    return 0;
}
