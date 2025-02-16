#ifndef DATA_HPP
#define DATA_HPP
struct Data
{
  public:
    Data(int f1, int f2);
    Data(const Data& sc);
    Data& operator=(const Data& sc);
    ~Data();
    int m_field1;
    long m_field2;
};
#endif
