#include <iostream>
#include <fstream>
#include "mymat.cpp"

#define REP_NUM 7           // std == 7
#define REP_SIZE_NUM 10     // std == 10

using namespace std;

template <typename T>
void timeCounter(int st_size, int d_size, int rep_size_num, ofstream& file, int rep_num,
                 long double (*f)(const vector<vector<T> >&, const vector<vector<T> >&))
{
    vector<vector<T> > mat1;
    vector<vector<T> > mat2;
    long double res;

    for (int i = 0; i < rep_size_num; i++)
    {
        randFill(mat1, st_size + d_size * i, st_size + d_size * i);
        randFill(mat2, st_size + d_size * i, st_size + d_size * i);

        res = 0;
        for (int j = 0; j < rep_num; j++)
        {
            res += f(mat1, mat2);
        }
        res /= rep_num;

        cout.setf(ios::fixed);
        cout.precision(4);
        cout << st_size+i*d_size << " : " << res << endl;

        file.setf(ios::fixed);
        file.precision(4);
        file << res << "\n";
    }
    file << "\n";
}

int main(void)
{
    srand(time(0));
    ofstream file_ev("results_even.txt");
    ofstream file_odd("results_odd.txt");

    timeCounter<double>(100, 100, REP_SIZE_NUM, file_ev, REP_NUM, classicMatMult<double>);
    timeCounter<double>(101, 100, REP_SIZE_NUM, file_odd, REP_NUM, classicMatMult<double>);

    timeCounter<double>(100, 100, REP_SIZE_NUM, file_ev, REP_NUM, VinogradMatMult<double>);
    timeCounter<double>(101, 100, REP_SIZE_NUM, file_odd, REP_NUM, VinogradMatMult<double>);

    timeCounter<double>(100, 100, REP_SIZE_NUM, file_ev, REP_NUM, betterVinogradMatMult<double>);
    timeCounter<double>(101, 100, REP_SIZE_NUM, file_odd, REP_NUM, betterVinogradMatMult<double>);

    file_ev.close();
    file_odd.close();

    return 0;
}
