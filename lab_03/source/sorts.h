#ifndef SORTS_H
#define SORTS_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template <typename T>
class Filler
{
public:
    virtual void fill(vector<T>&, T) = 0;

    virtual ~Filler() { }
};

template <typename T>
class RandFiller : public Filler<T>
{
public:
    void fill(vector<T> &, T) override;
};

template <typename T>
class UpFiller : public Filler<T>
{
public:
    void fill(vector<T> &, T) override;
};



template <typename T>
class BaseSorter
{
protected:
    Filler<T> *fl;
public:
    BaseSorter(Filler<T>*);
    virtual ~BaseSorter() { delete fl; }

    virtual long double sort(vector<T>&) = 0;
    void fill(vector<T>& in, T cnt) { fl->fill(in, cnt); }

};

template <typename T>
class GnomeSorter : public BaseSorter<T>
{
public:
    GnomeSorter(Filler<T>* in) : BaseSorter<T>::BaseSorter(in){}

    long double sort(vector<T>&) override;
};

template <typename T>
class BubbleSorter : public BaseSorter<T>
{
public:
    BubbleSorter(Filler<T>* in) : BaseSorter<T>::BaseSorter(in){}

    long double sort(vector<T>&) override;
};

template <typename T>
class ShakerSorter : public BaseSorter<T>
{
public:
    ShakerSorter(Filler<T>* in) : BaseSorter<T>::BaseSorter(in){}

    long double sort(vector<T>&) override;
};

#endif // SORTS_H
