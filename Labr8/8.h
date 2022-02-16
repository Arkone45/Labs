#ifndef mod
#define mod

class Matrix
{
private:
    int rows, cols;
    int **matr;
public:
    Matrix (int a = 0, int b = 0);
    ~Matrix ();
    Matrix (Matrix &smpl, int incr = 0);
    operator double();
    void change (int val, int row, int col);
    void printer ();
};

#endif
