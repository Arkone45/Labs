#ifndef mod
#define mod

class Matrix
{
private:
    int rows, cols;
    int **matr;
    class Matr_row
    {
    private:
        int *row;
        int len;
    public:
        Matr_row (int *r, int l);
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
    void printer ();
};

#endif
