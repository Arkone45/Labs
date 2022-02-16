#ifndef mod
#define mod

using namespace std;

class Matrix;
class Matr_row;


class Matrix
{
private:
    int rows, cols;
    int **matr;
    class Matr_row
    {
    private:
        Matrix *matr;
        int *row, len;
    public:
        Matr_row (Matrix *m, int *r, int l);
        ~Matr_row ();
        int operator [] (int indx);
    };
public:
    Matrix (int a = 0, int b = 0);
    ~Matrix ();
    Matrix (Matrix &smpl, int incr = 0);
    operator double();
    Matrix& operator = (const Matrix &smpl);
    int operator == (const Matrix& smpl) const;
    friend Matrix operator + (const Matrix& smpl1, const Matrix& smpl2);
    friend Matrix operator - (const Matrix& smpl1, const Matrix& smpl2);
    Matrix& operator += (int val);
    Matr_row operator [] (int indx);

    void change (int val, int row, int col);
    void printer () const;
};

class Exeption : std::exception
{
public:
    Exeption ();
    ~Exeption ();
    virtual void print_exeption();
};

class Invalid_index : public Exeption
{
private:
    int indx;
    bool is_str;
    Matrix *matr_ptr;
public:
    Invalid_index (int i, bool p, Matrix *m);
    Matrix *Get_Mptr();
    int GetIndx();
    bool GetStr();
    void print_exeption();
};

class Different_matrices_sizes : public Exeption
{
private:
    bool is_sum;
    const Matrix *matr1_ptr;
    const Matrix *matr2_ptr;
public:
    Different_matrices_sizes (bool s, const Matrix *m1, const Matrix *m2);
    const Matrix *Get_Mptr1();
    const Matrix *Get_Mptr2();
    bool GetSum();
    void print_exeption();
};

#endif
