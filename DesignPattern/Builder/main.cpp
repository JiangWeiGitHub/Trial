#include <iostream>

using namespace std;

enum MANTYPE
{
    FatMan,
    ThinMan,
    NormalMan
};

class Man
{
public:
    void SetHead(MANTYPE type){ m_Type = type; }
    void SetBody(MANTYPE type){ m_Type = type; }
    void SetLeftHand(MANTYPE type){ m_Type = type; }
    void SetRightHand(MANTYPE type){ m_Type = type; }
    void SetLeftFoot(MANTYPE type){ m_Type = type; }
    void SetRightFoot(MANTYPE type){ m_Type = type; }
    void ShowMan()
    {
        switch (m_Type)
        {
        case FatMan:
            cout<<"I'm a fat man."<<endl;
            return;

        case ThinMan:
            cout<<"I'm a thin man."<<endl;
            return;

        default:
            cout<<"I'm a normal man."<<endl;
            return;
        }
    }

private:
    MANTYPE m_Type;
};

class Builder
{
public:
    virtual void BuildHead(){}
    virtual void BuildBody(){}
    virtual void BuildLeftHand(){}
    virtual void BuildRightHand(){}
    virtual void BuildLeftFoot(){}
    virtual void BuildRightFoot(){}
    virtual Man *GetMan(){ return NULL; }
};

class FatManBuilder : public Builder
{
public:
    FatManBuilder(){ m_FatMan = new Man(); }
    void BuildHead(){ m_FatMan->SetHead(FatMan); }
    void BuildBody(){ m_FatMan->SetBody(FatMan); }
    void BuildLeftHand(){ m_FatMan->SetLeftHand(FatMan); }
    void BuildRightHand(){ m_FatMan->SetRightHand(FatMan); }
    void BuildLeftFoot(){ m_FatMan->SetLeftFoot(FatMan); }
    void BuildRightFoot(){ m_FatMan->SetRightFoot(FatMan); }
    Man *GetMan(){ return m_FatMan; }

private:
    Man *m_FatMan;
};

class ThinManBuilder : public Builder
{
public:
    ThinManBuilder(){ m_ThinMan = new Man(); }
    void BuildHead(){ m_ThinMan->SetHead(ThinMan); }
    void BuildBody(){ m_ThinMan->SetBody(ThinMan); }
    void BuildLeftHand(){ m_ThinMan->SetLeftHand(ThinMan); }
    void BuildRightHand(){ m_ThinMan->SetRightHand(ThinMan); }
    void BuildLeftFoot(){ m_ThinMan->SetLeftFoot(ThinMan); }
    void BuildRightFoot(){ m_ThinMan->SetRightFoot(ThinMan); }
    Man *GetMan(){ return m_ThinMan; }

private:
    Man *m_ThinMan;
};

class Director
{
public:
    Director(Builder *builder) { m_Builder = builder; }
    void CreateMan();

private:
    Builder *m_Builder;
};

void Director::CreateMan()
{
    m_Builder->BuildHead();
    m_Builder->BuildBody();
    m_Builder->BuildLeftHand();
    m_Builder->BuildRightHand();
    m_Builder->BuildLeftHand();
    m_Builder->BuildRightHand();
}

int main(void)
{
    Builder *builderObj = new FatManBuilder();
    Director directorObj(builderObj);
    directorObj.CreateMan();
    Man *manObj = builderObj->GetMan();
    if (manObj == NULL)
    {
        return 0;
    }

    manObj->ShowMan();

    delete manObj;
    manObj = NULL;

    delete builderObj;
    builderObj = NULL;

    Builder *builderObj2 = new ThinManBuilder();
    Director directorObj2(builderObj2);
    directorObj2.CreateMan();
    Man *manObj2 = builderObj2->GetMan();
    if (manObj2 == NULL)
    {
        return 0;
    }

    manObj2->ShowMan();

    delete manObj2;
    manObj2 = NULL;

    delete builderObj2;
    builderObj2 = NULL;

    return 0;
}
