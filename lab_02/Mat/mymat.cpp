#include "mymat.h"

template <typename T>
long double classicMatMult(const vector<vector<T> >& mat1, const vector<vector<T> >& mat2)
{
    vector<vector<T> > ans;
    vector<T> tmp;
    int n = mat1.size();
    int m = mat2.size();
    int q = mat2[0].size();

    tmp.resize(q, 0);
    ans.resize(n, tmp);

    unsigned long int start = clock();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            for (int k = 0; k < m; k++)
            {
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return double(clock() - start)/double(CLOCKS_PER_SEC)*1000;
}

template <typename T>
long double VinogradMatMult(const vector<vector<T> >& mat1, const vector<vector<T> >& mat2)
{
    vector<vector<T> > ans;
    vector<T> tmp;

    int n = mat1.size();
    int m = mat2.size();
    int q = mat2[0].size();

    tmp.resize(q, 0);
    ans.resize(n, tmp);

    vector<T> row_factor;
    vector<T> col_factor;

    row_factor.resize(n, 0);
    col_factor.resize(q, 0);

    int d = m/2;

    unsigned long int start = clock();

    // Row Factor calc
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            row_factor[i] += mat1[i][2*j] * mat1[i][2*j+1];
        }
    }

    // Col Factor calc
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < d; j++)
        {
            col_factor[i] += mat2[2*j][i] * mat2[2*j+1][i];
        }
    }

    // Ans calc
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            ans[i][j] = - row_factor[i] - col_factor[j];
            for (int k = 0; k < d; k++)
            {
                ans[i][j] += (mat1[i][2*k] + mat2[2*k+1][j]) * (mat1[i][2*k+1] + mat2[2*k][j]);
            }
        }
    }

    // For odd matrix
    if (m % 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q; j++)
            {
                ans[i][j] += mat1[i][m-1] * mat2[m-1][j];
            }
        }
    }

    return double(clock() - start)/double(CLOCKS_PER_SEC)*1000;
}

template <typename T>
long double betterVinogradMatMult(const vector<vector<T> >& mat1, const vector<vector<T> >& mat2)
{
    vector<vector<T> > ans;
    vector<T> tmp;

    int n = mat1.size();
    int m = mat2.size();
    int q = mat2[0].size();

    tmp.resize(q, 0);
    ans.resize(n, tmp);

    vector<T> row_factor;
    vector<T> col_factor;

    row_factor.resize(n, 0);
    col_factor.resize(q, 0);

    int d = m-1;

    unsigned long int start = clock();

    // Row Factor calc
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j += 2)
        {
            row_factor[i] += mat1[i][j] * mat1[i][j+1];
        }
    }

    // Col Factor calc
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < d; j += 2)
        {
            col_factor[i] += mat2[j][i] * mat2[j+1][i];
        }
    }

    // Ans calc
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            T buf = -row_factor[i] - col_factor[j];
            for (int k = 0; k < d; k += 2)
            {
                buf += (mat1[i][k] + mat2[k+1][j]) * (mat1[i][k+1] + mat2[k][j]);
            }
            ans[i][j] = buf;
        }
    }

    // For odd matrix
    if (m % 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q; j++)
            {
                ans[i][j] += mat1[i][m-1] * mat2[m-1][j];
            }
        }
    }

    return double(clock() - start)/double(CLOCKS_PER_SEC)*1000;
}


template <typename T>
void randFill(vector<vector<T> >& mat, const int row, const int col)
{
    matClr(mat);
    vector<T> tmp;

    for (int i = 0; i < row; i++)
    {
        tmp.clear();

        for (int j = 0; j < col; j++)
        {
            tmp.push_back(rand());
        }

        mat.push_back(tmp);
    }
}

template <typename T>
void matClr(vector<vector<T> >& mat)
{
    for (auto &x : mat)
    {
        x.clear();
    }
    mat.clear();
}
