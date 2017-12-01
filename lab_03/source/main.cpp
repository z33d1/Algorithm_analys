#include <iostream>
#include <fstream>
#include "sorts.cpp"

#define ST_NUM 100          // std == 100
#define REP_NUM 10          // std == 10
#define TIME_REP_NUM 10     // std == 10
#define D_NUM 100      // std == 100


using namespace std;

template <typename T>
int SIGN(T& in)
{
    return (in >= 0) ? (1) : (-1);
}

template <typename T>
void timeCnt(T st_num, T d_num, int rep_num, BaseSorter<T>* srtr, ofstream& file)
{
    vector<T> arr;

    for (int i = 0; i < rep_num; i++)
    {
        long double time;
        for (int j = 0; j < TIME_REP_NUM; j++)
        {
            arr.clear();
            srtr->fill(arr, (st_num + d_num*i) * SIGN(d_num));

            time += (srtr->sort(arr)/CLOCKS_PER_SEC)*1000;
        }
        time /= TIME_REP_NUM;

        cout.precision(4);
        cout.setf(ios::fixed);
        cout << st_num + d_num*i << " : " << time << endl;

        file.precision(4);
        file.setf(ios::fixed);
        file << time << "\n";
    }

    file << "\n";
    cout << "\n";

    delete srtr;
}

int main(void)
{
    srand(time(0));
    ofstream bub("bub.txt");
    ofstream shk("skr.txt");
    ofstream gnm("gnome.txt");

    timeCnt<double>(ST_NUM, D_NUM, REP_NUM, new BubbleSorter<double>(new RandFiller<double>()), bub);
    timeCnt<double>(ST_NUM, D_NUM, REP_NUM, new BubbleSorter<double>(new UpFiller<double>()), bub);
    timeCnt<double>(ST_NUM*10, -D_NUM, REP_NUM, new BubbleSorter<double>(new UpFiller<double>()), bub);

    timeCnt<double>(ST_NUM, D_NUM, REP_NUM, new ShakerSorter<double>(new RandFiller<double>()), shk);
    timeCnt<double>(ST_NUM, D_NUM, REP_NUM, new ShakerSorter<double>(new UpFiller<double>()), shk);
    timeCnt<double>(ST_NUM*10, -D_NUM, REP_NUM, new ShakerSorter<double>(new UpFiller<double>()), shk);

    timeCnt<double>(ST_NUM, D_NUM, REP_NUM, new GnomeSorter<double>(new RandFiller<double>()), gnm);
    timeCnt<double>(ST_NUM, D_NUM, REP_NUM, new GnomeSorter<double>(new UpFiller<double>()), gnm);
    timeCnt<double>(ST_NUM*10, -D_NUM, REP_NUM, new GnomeSorter<double>(new UpFiller<double>()), gnm);

    bub.close();
    shk.close();
    gnm.close();
    return 0;
}
